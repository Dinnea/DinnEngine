#include "dnpch.h"
#include "Renderer2D.h"
#include <glad/glad.h>

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
			// pos        // tex
		   -0.5f, -0.5f,   0.0f, 0.0f,  // bottom-left
		   -0.5f,  -0.5f,   0.0f, 1.0f,  // bottom-right
			0.5f,  0.5f,   1.0f, 1.0f,  // top-right
			-0.5f, 0.5f,   1.0f, 0.0f   // top-left
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

		ebo ->Bind();

		vao.LinkVBO(*vbo, 0);
		vao.Unbind();
	}

	void Renderer2D::Draw()
	{
		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		shader->Activate();

		vao.Bind();

		glDrawElements(GL_TRIANGLES, 4, GL_UNSIGNED_INT, 0);

	}
	void Renderer2D::Shutdown()
	{
		vao.Delete();
		vbo->Delete();
		ebo->Delete();
		shader->Delete();
	}
}
