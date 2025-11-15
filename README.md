# DinnEngine

## Overview  
DinnEngine is a personal project to build a simple but structured 2D game engine in C++ from scratch.
The goal is to learn both game engine architecture and modern C++ practices by implementing the core systems manually - rather than relying on high-level frameworks.
Currently only supports Windows and Visual Studio. Uses C++ 20

## Current Features 
### Core Engine
- Main Game Loop with fixed framerate control
- Delta Time System for frame-independent movement and animation
- Currently there is no scene / layer separation - everything is done in the overarching Application class
- Logging system based on spdlog

### Object Model
- Unity-like GameObject + Component architecture
- Built-in components:
  - Transform (position, scale, rotation)
  - Sprite (2D textured quad)
- Support for adding custom user-defined components
- GameObject functionality can currently only be added by creating a new class, inheriting from GameObject and overriding the Update method.

### Rendering
- OpenGL-based 2D sprite renderer
- Uses GLAD for OpenGL loading
- Uses GLFW for window creation & input handling
- Basic shader system:
 - Load custom GLSL vertex & fragment shaders
 - Default textured sprite shader included
- Handles per-object textures + shader overrides (each sprite may specify its own shader and texture)
  
### Asset Management
- Central AssetManager for:
 - Loading / caching textures and shaders
 - Managing default fallback assets
 - Uses shared_ptr / weak_ptr lifetime management patterns
   
### Screenshots
<img width="441" height="478" alt="image" src="https://github.com/user-attachments/assets/4feb87ce-3d0d-4192-87b3-13cc51144cf2" />

![Moving object](https://github.com/user-attachments/assets/cbb66200-7de1-4e7c-ae96-fbf9bbe2e370)



### Dependencies

| Library       | Used For                             |
| ------------- | ------------------------------------ |
| **GLFW**      | Windowing + Input                    |
| **GLAD**      | OpenGL function loading              |
| **OpenGL**    | Rendering backend                    |
| **glm**       | Math (matrices, vectors, transforms) |
| **stb_image** | Texture loading                      |
| **spdlog**    | Logging                              |


## How to Build & Run

1. **Clone the repository**

   ```bash
   git clone <repo-url>
   cd DinnEngine
   ```

2. **Generate project files**
   Run the provided batch script:

   ```
   generate-projects.bat
   ```

   This will configure the project using CMake and generate a Visual Studio solution, which then will open automatically.
   
3. **Create**

   * New code is supposed to be added in the Example Game project, using what is provided in the Engine project as a base.
   
4. **Build & Run**

   * Press **F5** (Run with Debugger)
     or
   * Press **Ctrl + F5** (Run without Debugger)
  
## Next steps
To be decided. Physics, sound support, better structure (using scenes, rendering layers etc), camera system, graphics batching, UI support...? Maybe I will attempt ECS again?

## Resources & Influences

This project was developed while learning from and referencing various graphics and engine development resources, including:

- The Cherno — *Game Engine Series (Hazel)*  
- Victor Gordan — *OpenGL Tutorials*
- Joey de Vries — *learnopengl.com*
- glfw.org & glad documentation
- glm mathematics library documentation


