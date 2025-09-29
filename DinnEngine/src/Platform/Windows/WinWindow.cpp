#include "C:/dev/DinnEngine/DinnEngine/CMakeFiles/DinnEngine.dir/Debug/cmake_pch.hxx"
#include "WinWindow.h"

#include "DinnCore/glfw_glad.h"


namespace Dinn 
{

	// Vertex Shader source code
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	//Fragment Shader source code
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
		"}\n\0";

	static bool GLFWInititialized = false;
	GLuint shaderProgram;

	static void GLFWErrorCallback(int error, const char* description)
	{
		DN_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProperties& props)
	{
		return new WinWindow(props);
	}

	WinWindow::WinWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WinWindow::~WinWindow()
	{
		Shutdown();
	}

	void WinWindow::Update()
	{
		//glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		glfwSwapBuffers(Window);

		if (Input::GetKeyDown(Input::Keyboard::SPACE))
			DN_CORE_INFO("Space pressed");
	}

	void WinWindow::SetVSync(bool enabled)
	{
		enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);

		data.VSync = enabled;
	}

	bool WinWindow::IsVSync() const
	{
		return data.VSync;
	}

	bool WinWindow::IsKeyDown(Input::Keyboard key)
	{
		return glfwGetKey(Window, static_cast<int>(key)) == GLFW_PRESS;
	}

	bool WinWindow::IsMouseDown(Input::Mouse btn)
	{
		return glfwGetKey(Window, static_cast<int>(btn)) == GLFW_PRESS;
	}

	void WinWindow::Init(const WindowProperties& props)
	{
		data.Title = props.Title;
		data.Width = props.Width;
		data.Height = props.Height;

		DN_CORE_INFO("Creating window {0}, ({1}, {2})", props.Title, props.Width, props.Height);

		if (!GLFWInititialized) {
			int success = glfwInit();
			DN_CORE_ASSERT(success, "Could not initialize GLFW!");

			GLFWInititialized = true;

			glfwSetErrorCallback(GLFWErrorCallback);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		Window = glfwCreateWindow((int)props.Width, (int)props.Height, data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(Window);
		glfwSetWindowUserPointer(Window, &data);
		SetVSync(true);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DN_CORE_ASSERT(status, "Failed to initalize glad!")

			//test rendering
			GLfloat vertices[] =
		{
			-0.5f, -0.5 * float(sqrt(3)) / 3, 0.0f,
			0.5f, -0.5 * float(sqrt(3)) / 3, 0.0f,
			0.0f, 0.5 * float(sqrt(3)) * 2 / 3, 0.0f
		};

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		glLinkProgram(shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		GLuint VAO, VBO;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//Set GLFW callbacks

		glfwSetWindowSizeCallback(Window, [](GLFWwindow* window, int width, int height)
				{
					WindowData& data = GrabWindowData(window);

					data.Width = width;
					data.Height = height;

					WindowResizeEvent event(width, height);
					data.EventCallback(event);
				});

		glfwSetWindowCloseCallback(Window, [](GLFWwindow* window)
			{
				WindowData& data = GrabWindowData(window);

				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = GrabWindowData(window);

				Input::Keyboard keyCode = static_cast<Input::Keyboard>(key);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressEvent event(keyCode, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(keyCode);
					data.EventCallback(event);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressEvent event(keyCode, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = GrabWindowData(window);

				Input::Mouse buttonCode = static_cast<Input::Mouse>(button);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(buttonCode);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(buttonCode);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = GrabWindowData(window);

				MouseScrolledEvent event((float)xoffset, (float)yoffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = GrabWindowData(window);

				MouseMovedEvent event((float)xpos, (float)ypos);
				data.EventCallback(event);
			});


	}

	void Dinn::WinWindow::Shutdown()
	{
		glfwDestroyWindow(Window);
	}

	WinWindow::WindowData& WinWindow::GrabWindowData(GLFWwindow* window)
	{
		return *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
	}
}

