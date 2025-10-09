#include "dnpch.h"
#include "Renderer2D.h"
#include "gtc/matrix_transform.hpp"
#include "glad/glad.h"

namespace Dinn
{
	Renderer2D::Renderer2D()
	{
		Initialize();
	}
	Renderer2D::~Renderer2D()
	{
		Shutdown();
	}

	void Renderer2D::Initialize()
	{
		float vertices[] =
		{
			// pos			// tex
			-0.5f, -0.5f,   0.0f, 0.0f,  // bottom-left
			0.5f,  -0.5f,   0.0f, 1.0f,  // bottom-right
			0.5f,  0.5f,	1.0f, 1.0f,  // top-right
			-0.5f, 0.5f,	1.0f, 0.0f   // top-left
		};

		GLuint indices[] =
		{
			0, 1, 2,
			0, 2, 3,
		};
		vao = VAO();
		vbo = std::make_unique<VBO>(vertices, sizeof(vertices));
		ebo = std::make_unique<EBO>(indices, sizeof(indices));
		shader = std::make_shared<Shader>("Shaders/default.vert", "Shaders/default.frag");

		vao.Bind();
		vao.LinkVBO(*vbo, 0);
		ebo ->Bind();

		vao.Unbind();
	}

	void Renderer2D::Draw()
	{
		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->Activate();

		//reset model
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(150.0f, 150.0f, 0.0f));

		//transformations
		model = glm::scale(model, glm::vec3(100.0f, 100.0f, 1.0f));

		shader ->SetMatrix4("model", model);
		shader->SetMatrix4("projection", projection);

		vao.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void Renderer2D::Shutdown()
	{
		vao.Delete();
		vbo->Delete();
		ebo->Delete();
		shader->Delete();
	}

	void Renderer2D::SetProjection(float width, float height)
	{
		projection = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 1.0f);

		DN_CORE_INFO("Changed projection; window => {0}, {1}", width, height);
	}
}
