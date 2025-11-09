#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Application.h"

namespace Dinn::Input
{
    using Key = int;

    /// <summary>
    /// D0 ... D9 for digit keys
    /// </summary>
    enum class Keyboard : Key
    {
        UNKNOWN = GLFW_KEY_UNKNOWN,
        SPACE = GLFW_KEY_SPACE,
        APOSTROPHE = GLFW_KEY_APOSTROPHE,
        COMMA = GLFW_KEY_COMMA,
        MINUS = GLFW_KEY_MINUS,
        PERIOD = GLFW_KEY_PERIOD,
        SLASH = GLFW_KEY_SLASH,
        D0 = GLFW_KEY_0,
        D1 = GLFW_KEY_1,
        D2 = GLFW_KEY_2,
        D3 = GLFW_KEY_3,
        D4 = GLFW_KEY_4,
        D5 = GLFW_KEY_5,
        D6 = GLFW_KEY_6,
        D7 = GLFW_KEY_7,
        D8 = GLFW_KEY_8,
        D9 = GLFW_KEY_9,
        SEMICOLON = GLFW_KEY_SEMICOLON,
        EQUAL = GLFW_KEY_EQUAL,
        A = GLFW_KEY_A,
        B = GLFW_KEY_B,
        C = GLFW_KEY_C,
        D = GLFW_KEY_D,
        E = GLFW_KEY_E,
        F = GLFW_KEY_F,
        G = GLFW_KEY_G,
        H = GLFW_KEY_H,
        I = GLFW_KEY_I,
        J = GLFW_KEY_J,
        K = GLFW_KEY_K,
        L = GLFW_KEY_L,
        M = GLFW_KEY_M,
        N = GLFW_KEY_N,
        O = GLFW_KEY_O,
        P = GLFW_KEY_P,
        Q = GLFW_KEY_Q,
        R = GLFW_KEY_R,
        S = GLFW_KEY_S,
        T = GLFW_KEY_T,
        U = GLFW_KEY_U,
        V = GLFW_KEY_V,
        W = GLFW_KEY_W,
        X = GLFW_KEY_X,
        Y = GLFW_KEY_Y,
        Z = GLFW_KEY_Z,
        LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,
        BACKSLASH = GLFW_KEY_BACKSLASH,
        RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
        GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT,
        WORLD_1 = GLFW_KEY_WORLD_1,
        WORLD_2 = GLFW_KEY_WORLD_2,
        ESCAPE = GLFW_KEY_ESCAPE,
        ENTER = GLFW_KEY_ENTER,
        TAB = GLFW_KEY_TAB,
        BACKSPACE = GLFW_KEY_BACKSPACE,
        INSERT = GLFW_KEY_INSERT,
        DEL = GLFW_KEY_DELETE,
        RIGHT = GLFW_KEY_RIGHT,
        LEFT = GLFW_KEY_LEFT,
        DOWN = GLFW_KEY_DOWN,
        UP = GLFW_KEY_UP,
        PAGE_UP = GLFW_KEY_PAGE_UP,
        PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
        HOME = GLFW_KEY_HOME,
        END = GLFW_KEY_END,
        CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
        SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
        NUM_LOCK = GLFW_KEY_NUM_LOCK,
        PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
        PAUSE = GLFW_KEY_PAUSE,
        F1 = GLFW_KEY_F1,
        F2 = GLFW_KEY_F2,
        F3 = GLFW_KEY_F3,
        F4 = GLFW_KEY_F4,
        F5 = GLFW_KEY_F5,
        F6 = GLFW_KEY_F6,
        F7 = GLFW_KEY_F7,
        F8 = GLFW_KEY_F8,
        F9 = GLFW_KEY_F9,
        F10 = GLFW_KEY_F10,
        F11 = GLFW_KEY_F11,
        F12 = GLFW_KEY_F12,
        F13 = GLFW_KEY_F13,
        F14 = GLFW_KEY_F14,
        F15 = GLFW_KEY_F15,
        F16 = GLFW_KEY_F16,
        F17 = GLFW_KEY_F17,
        F18 = GLFW_KEY_F18,
        F19 = GLFW_KEY_F19,
        F20 = GLFW_KEY_F20,
        F21 = GLFW_KEY_F21,
        F22 = GLFW_KEY_F22,
        F23 = GLFW_KEY_F23,
        F24 = GLFW_KEY_F24,
        F25 = GLFW_KEY_F25,
        KP_0 = GLFW_KEY_KP_0,
        KP_1 = GLFW_KEY_KP_1,
        KP_2 = GLFW_KEY_KP_2,
        KP_3 = GLFW_KEY_KP_3,
        KP_4 = GLFW_KEY_KP_4,
        KP_5 = GLFW_KEY_KP_5,
        KP_6 = GLFW_KEY_KP_6,
        KP_7 = GLFW_KEY_KP_7,
        KP_8 = GLFW_KEY_KP_8,
        KP_9 = GLFW_KEY_KP_9,
        KP_DECIMAL = GLFW_KEY_KP_DECIMAL,
        KP_DIVIDE = GLFW_KEY_KP_DIVIDE,
        KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
        KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
        KP_ADD = GLFW_KEY_KP_ADD,
        KP_ENTER = GLFW_KEY_KP_ENTER,
        KP_EQUAL = GLFW_KEY_KP_EQUAL,
        LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
        LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
        LEFT_ALT = GLFW_KEY_LEFT_ALT,
        LEFT_SUPER = GLFW_KEY_LEFT_SUPER,
        RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
        RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
        RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
        RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER,
        MENU = GLFW_KEY_MENU,
    };

    /// <summary>
    /// LMB, RMB, MMB for left, right and middle mouse buttons
    /// </summary>
    enum class Mouse : Key
    {
        /// <summary>
        /// Left mouse button
        /// </summary>
        LMB = GLFW_MOUSE_BUTTON_1,

        /// <summary>
        /// Right mouse button
        /// </summary>
        RMB = GLFW_MOUSE_BUTTON_2,

        /// <summary>
        ///Middle mouse button
        /// </summary>
        MMB = GLFW_MOUSE_BUTTON_3,

        MB_4 = GLFW_MOUSE_BUTTON_4,
        MB_5 = GLFW_MOUSE_BUTTON_5,
        MB_6 = GLFW_MOUSE_BUTTON_6,
        MB_7 = GLFW_MOUSE_BUTTON_7,
        MB_8 = GLFW_MOUSE_BUTTON_8,
    };

    inline std::string ToString(Keyboard key)
    {
        switch (key)
        {
            // --- punctuation / symbols ---
        case Keyboard::SPACE:        return "Space";
        case Keyboard::APOSTROPHE:   return "Apostrophe";
        case Keyboard::COMMA:        return "Comma";
        case Keyboard::MINUS:        return "Minus";
        case Keyboard::PERIOD:       return "Period";
        case Keyboard::SLASH:        return "Slash";
        case Keyboard::SEMICOLON:    return "Semicolon";
        case Keyboard::EQUAL:        return "Equal";
        case Keyboard::LEFT_BRACKET: return "Left Bracket";
        case Keyboard::BACKSLASH:    return "Backslash";
        case Keyboard::RIGHT_BRACKET:return "Right Bracket";
        case Keyboard::GRAVE_ACCENT: return "Grave Accent";
        case Keyboard::WORLD_1:      return "World 1";
        case Keyboard::WORLD_2:      return "World 2";

            // --- control / navigation ---
        case Keyboard::ESCAPE:       return "Escape";
        case Keyboard::ENTER:        return "Enter";
        case Keyboard::TAB:          return "Tab";
        case Keyboard::BACKSPACE:    return "Backspace";
        case Keyboard::INSERT:       return "Insert";
        case Keyboard::DEL:          return "Delete";
        case Keyboard::RIGHT:        return "Right Arrow";
        case Keyboard::LEFT:         return "Left Arrow";
        case Keyboard::DOWN:         return "Down Arrow";
        case Keyboard::UP:           return "Up Arrow";
        case Keyboard::PAGE_UP:      return "Page Up";
        case Keyboard::PAGE_DOWN:    return "Page Down";
        case Keyboard::HOME:         return "Home";
        case Keyboard::END:          return "End";

            // --- locks / system ---
        case Keyboard::CAPS_LOCK:    return "Caps Lock";
        case Keyboard::SCROLL_LOCK:  return "Scroll Lock";
        case Keyboard::NUM_LOCK:     return "Num Lock";
        case Keyboard::PRINT_SCREEN: return "Print Screen";
        case Keyboard::PAUSE:        return "Pause";

            // --- function keys ---
        case Keyboard::F1:  return "F1";   case Keyboard::F2:  return "F2";
        case Keyboard::F3:  return "F3";   case Keyboard::F4:  return "F4";
        case Keyboard::F5:  return "F5";   case Keyboard::F6:  return "F6";
        case Keyboard::F7:  return "F7";   case Keyboard::F8:  return "F8";
        case Keyboard::F9:  return "F9";   case Keyboard::F10: return "F10";
        case Keyboard::F11: return "F11";  case Keyboard::F12: return "F12";
        case Keyboard::F13: return "F13";  case Keyboard::F14: return "F14";
        case Keyboard::F15: return "F15";  case Keyboard::F16: return "F16";
        case Keyboard::F17: return "F17";  case Keyboard::F18: return "F18";
        case Keyboard::F19: return "F19";  case Keyboard::F20: return "F20";
        case Keyboard::F21: return "F21";  case Keyboard::F22: return "F22";
        case Keyboard::F23: return "F23";  case Keyboard::F24: return "F24";
        case Keyboard::F25: return "F25";

            // --- keypad ---
        case Keyboard::KP_DECIMAL:   return "Keypad .";
        case Keyboard::KP_DIVIDE:    return "Keypad /";
        case Keyboard::KP_MULTIPLY:  return "Keypad *";
        case Keyboard::KP_SUBTRACT:  return "Keypad -";
        case Keyboard::KP_ADD:       return "Keypad +";
        case Keyboard::KP_ENTER:     return "Keypad Enter";
        case Keyboard::KP_EQUAL:     return "Keypad =";

            // --- modifiers ---
        case Keyboard::LEFT_SHIFT:   return "Left Shift";
        case Keyboard::LEFT_CONTROL: return "Left Control";
        case Keyboard::LEFT_ALT:     return "Left Alt";
        case Keyboard::LEFT_SUPER:   return "Left Super";
        case Keyboard::RIGHT_SHIFT:  return "Right Shift";
        case Keyboard::RIGHT_CONTROL:return "Right Control";
        case Keyboard::RIGHT_ALT:    return "Right Alt";
        case Keyboard::RIGHT_SUPER:  return "Right Super";
        case Keyboard::MENU:         return "Menu";

        default:
            // digits
            if (key >= Keyboard::D0 && key <= Keyboard::D9)
                return std::string(1, char('0' + (static_cast<int>(key) - static_cast<int>(Keyboard::D0))));
            // letters
            if (key >= Keyboard::A && key <= Keyboard::Z)
                return std::string(1, char('A' + (static_cast<int>(key) - static_cast<int>(Keyboard::A))));
            // keypad digits
            if (key >= Keyboard::KP_0 && key <= Keyboard::KP_9)
                return "Keypad " + std::to_string(static_cast<int>(key) - static_cast<int>(Keyboard::KP_0));
            return "Unknown";
        }
    }

    inline std::string ToString(Mouse button)
    {
        switch (button)
        {
        case Mouse::LMB:  return "Mouse Left";
        case Mouse::RMB:  return "Mouse Right";
        case Mouse::MMB:  return "Mouse Middle";
        case Mouse::MB_4: return "Mouse 4";
        case Mouse::MB_5: return "Mouse 5";
        case Mouse::MB_6: return "Mouse 6";
        case Mouse::MB_7: return "Mouse 7";
        case Mouse::MB_8: return "Mouse 8";
        default:          return "Unknown Mouse";
        }
    }

    inline static bool GetKeyDown(const Keyboard key)
    {
        return ::Dinn::Application::Instance().GetWindow().IsKeyDown(key);
    }
    inline static bool GetKeyDown(const Mouse btn)
    {
        return ::Dinn::Application::Instance().GetWindow().IsMouseDown(btn);
    }
}
