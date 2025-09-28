#pragma once

#include "DinnCore/Application.h"
#include "DinnCore/Time.h"

// ------------- Events ------------------- //

#include "DinnCore/Events/Events.h"

// ------------- Input ------------------- //
#include "DinnCore/Input.h"
#include "DinnCore/Window.h"

// ------------- Platform Specific -------//
#ifdef DN_PLATFORM_WINDOWS
#include "Platform/Windows/WinWindow.h"
#endif // DN_PLATFORM_WINDOWS


#include "stdio.h"

// ------------- Entry Point ---------------- //
#include "DinnCore/EntryPoint.h"
// ------------------------------------------ //