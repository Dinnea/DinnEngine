#include "dnpch.h"
#include "WinWindow.h"

#include "DinnCore/glfw_glad.h"


namespace Dinn 
{
	static bool GLFWInititialized = false;

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
		glfwPollEvents();
		glfwSwapBuffers(Window);
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

		Window = glfwCreateWindow((int)props.Width, (int)props.Height, data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(Window);
		glfwSetWindowUserPointer(Window, &data);
		SetVSync(true);


		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DN_CORE_ASSERT(status, "Failed to initalize glad!")

		glViewport(0, 0, (int)props.Width, (int)props.Height);
			//Set GLFW callbacks

			glfwSetWindowSizeCallback(Window, [](GLFWwindow* window, int width, int height)
				{
					WindowData& data = GrabWindowData(window);

					data.Width = width;
					data.Height = height;

					WindowResizeEvent event(width, height);
					data.EventCallback(event);
					glViewport(0, 0, width, height);

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

