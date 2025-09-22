#include "C:/dev/DinnEngine/DinnEngine/CMakeFiles/DinnEngine.dir/Debug/cmake_pch.hxx"
#include "WinWindow.h"

static bool GLFWInititialized = false;

Dinn::Window* Dinn::Window::Create(const WindowProperties& props)
{
	return new WinWindow(props);
}

Dinn::WinWindow::WinWindow(const WindowProperties& props)
{
	Init(props);
}

Dinn::WinWindow::~WinWindow()
{
	Shutdown();
}

void Dinn::WinWindow::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(Window);
}

void Dinn::WinWindow::SetVSync(bool enabled)
{
	enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);

	data.VSync = enabled;
}

bool Dinn::WinWindow::IsVSync() const
{
	return data.VSync;
}


void Dinn::WinWindow::Init(const WindowProperties& props)
{
	data.Title = props.Title;
	data.Width = props.Width;
	data.Height = props.Height;

	DN_CORE_INFO("Creating window {0}, ({1}, {2})", props.Title, props.Width, props.Height);

	if (!GLFWInititialized) {
		int success = glfwInit();
		DN_CORE_ASSERT(success, "Could not initialize GLFW!");

		GLFWInititialized = true;
	}

	Window = glfwCreateWindow((int)props.Width, (int)props.Height, data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(Window);
	glfwSetWindowUserPointer(Window, &data);
	SetVSync(true);
}

void Dinn::WinWindow::Shutdown()
{
	glfwDestroyWindow(Window);
}
