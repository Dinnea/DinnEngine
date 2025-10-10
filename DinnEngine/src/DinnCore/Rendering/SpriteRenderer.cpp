#include "dnpch.h"
#include "SpriteRenderer.h"
#include "gtc/matrix_transform.hpp"
#include "glad/glad.h"

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
		defaultShader = std::make_shared<Shader>("Shaders/default.vert", "Shaders/default.frag");
		defaultTexture = std::make_shared<Texture>("Shaders/willow.png",
			GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE); //new

		vao.Bind();
		vao.LinkVBO(*vbo, 0);
		ebo ->Bind();

		vao.Unbind();
	}

	void SpriteRenderer::InitFrame()
	{
		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		defaultShader->Activate();
		vao.Bind();
		defaultTexture->Bind();
		defaultTexture->SetUniform(*defaultShader, "tex", 0);

		defaultShader->SetMatrix4("projection", projection);

	}

	void SpriteRenderer::Draw(const Sprite& sprite)
	{
		//reset model
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(sprite.position, 0.0f));
		model = glm::rotate(model, glm::radians(sprite.angle), glm::vec3(0.0f, 0.0f, 1.0f));

		//transformations
		model = glm::scale(model, glm::vec3(sprite.scale, 1.0f));

		defaultShader ->SetMatrix4("model", model);


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
