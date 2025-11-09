#include "dnpch.h"
#include "DinnCore/Application.h"
#include "glad/glad.h"
#include "gtc/matrix_transform.hpp"
#include "SpriteRenderer.h"
#include "Texture.h"
#include "DinnCore/Sprite.h"

namespace Dinn
{
	SpriteRenderer::SpriteRenderer()
	{
		Initialize();
	}
	SpriteRenderer::~SpriteRenderer()
	{
		Shutdown();
	}

	void SpriteRenderer::Initialize()
	{
		float vertices[] =
		{
			// pos			// tex
			-0.5f, -0.5f,   0.0f, 0.0f,  // bottom-left
			0.5f,  -0.5f,   1.0f, 0.0f,  // bottom-right
			0.5f,  0.5f,	1.0f, 1.0f,  // top-right
			-0.5f, 0.5f,	0.0f, 1.0f   // top-left
		};

		GLuint indices[] =
		{
			0, 1, 2,
			0, 2, 3,
		};

		vao = VAO();
		vbo = std::make_unique<VBO>(vertices, sizeof(vertices));
		ebo = std::make_unique<EBO>(indices, sizeof(indices));
		
		AssetManager& assetManager = Application::Instance().GetAssetManager();

		defaultShader = assetManager.GetDefaultShader();
		defaultTexture = assetManager.GetDefaultTexture();

		vao.Bind();
		vao.LinkVBO(*vbo, 0);
		ebo ->Bind();

		vao.Unbind();
	}

	void SpriteRenderer::InitFrame()
	{
		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		vao.Bind();
	}

	void SpriteRenderer::Draw(const Sprite& sprite, const Transform& transform)
	{
		auto shader = sprite.GetShader();
		if (!shader) shader = defaultShader;

		auto texture = sprite.GetTexture();
		if (!texture) texture = defaultTexture;

		shader->Activate();
		texture->Bind();
		texture->SetUniform(*shader, "tex", 0);

		shader ->SetMatrix4("projection", projection);

		//reset model
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(transform.position, 0.0f));
		model = glm::rotate(model, glm::radians(transform.angle), glm::vec3(0.0f, 0.0f, 1.0f));

		//transformations
		model = glm::scale(model, glm::vec3(transform.scale, 1.0f));

		shader ->SetMatrix4("model", model);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void SpriteRenderer::EndFrame()
	{
	}

	void SpriteRenderer::Shutdown()
	{
		vao.Delete();
		vbo->Delete();
		ebo->Delete();
		defaultShader->Delete();
	}

	void SpriteRenderer::SetProjection(float width, float height)
	{
		projection = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 1.0f);

		DN_CORE_INFO("Changed projection; window => {0}, {1}", width, height);
	}
}
