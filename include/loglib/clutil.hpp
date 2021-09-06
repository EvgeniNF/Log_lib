//
// Created by User on 06.09.2021.
//

#ifndef TEST_COLOR__CLUTIL_HPP_
#define TEST_COLOR__CLUTIL_HPP_

//Include for std::cin, std::cout
#include <iostream>
#include <string>
#include <string_view>
#include <compare>

#ifdef WIN32
// Windows
#include <windows.h> // for WinAPI

#else
// UNIX
#endif // WIN32

// Namespace for functions
namespace clutil{

// Change color Linux
#if !(defined(WIN32))
    #define CLUTIL(str) { std::cout << st; }
#endif

// Consts: ANSI escape strings
#if !(defined(WIN32))
namespace ANSI{
[[maybe_unused]] constexpr std::string_view CLS                = "\033[2J\033[3J";
[[maybe_unused]] constexpr std::string_view ATTRIBUTE_RESET    = "\033[0m";
[[maybe_unused]] constexpr std::string_view CURSOR_HOME        = "\033[H";
[[maybe_unused]] constexpr std::string_view BLACK              = "\033[22;30m";
[[maybe_unused]] constexpr std::string_view RED                = "\033[22;31m";
[[maybe_unused]] constexpr std::string_view GREEN              = "\033[22;32m";
[[maybe_unused]] constexpr std::string_view BROWN              = "\033[22;33m";
[[maybe_unused]] constexpr std::string_view BLUE               = "\033[22;34m";
[[maybe_unused]] constexpr std::string_view MAGENTA            = "\033[22;35m";
[[maybe_unused]] constexpr std::string_view CYAN               = "\033[22;36m";
[[maybe_unused]] constexpr std::string_view GREY               = "\033[22;37m";
[[maybe_unused]] constexpr std::string_view DARKGREY           = "\033[01;30m";
[[maybe_unused]] constexpr std::string_view LIGHTRED           = "\033[01;31m";
[[maybe_unused]] constexpr std::string_view LIGHTGREEN         = "\033[01;32m";
[[maybe_unused]] constexpr std::string_view YELLOW             = "\033[01;33m";
[[maybe_unused]] constexpr std::string_view LIGHTBLUE          = "\033[01;34m";
[[maybe_unused]] constexpr std::string_view LIGHTMAGENTA       = "\033[01;35m";
[[maybe_unused]] constexpr std::string_view LIGHTCYAN          = "\033[01;36m";
[[maybe_unused]] constexpr std::string_view WHITE              = "\033[01;37m";
[[maybe_unused]] constexpr std::string_view BACK_BLACK         = "\033[40m";
[[maybe_unused]] constexpr std::string_view BACK_RED           = "\033[41m";
[[maybe_unused]] constexpr std::string_view BACK_GREEN         = "\033[42m";
[[maybe_unused]] constexpr std::string_view BACK_YELLOW        = "\033[43m";
[[maybe_unused]] constexpr std::string_view BACK_BLUE          = "\033[44m";
[[maybe_unused]] constexpr std::string_view BACK_MAGENTA       = "\033[45m";
[[maybe_unused]] constexpr std::string_view BACK_CYAN          = "\033[46m";
[[maybe_unused]] constexpr std::string_view BACK_WHITE         = "\033[47m";
};
#endif

// Color codes
enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARKGREY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

// Return ANSI color if not def WIN32
#if !(defined(WIN32))
[[maybe_unused]] std::string_view _getANSIColor(int c) {
    switch (c) {
        case BLACK       : return ANSI::BLACK;
        case BLACK       : return ANSI::BLACK;
        case BLUE        : return ANSI::BLUE;
        case GREEN       : return ANSI::GREEN;
        case CYAN        : return ANSI::CYAN;
        case RED         : return ANSI::RED;
        case MAGENTA     : return ANSI::MAGENTA;
        case BROWN       : return ANSI::BROWN;
        case GREY        : return ANSI::GREY;
        case DARKGREY    : return ANSI::DARKGREY;
        case LIGHTBLUE   : return ANSI::LIGHTBLUE;
        case LIGHTGREEN  : return ANSI::LIGHTGREEN;
        case LIGHTCYAN   : return ANSI::LIGHTCYAN;
        case LIGHTRED    : return ANSI::LIGHTRED;
        case LIGHTMAGENTA: return ANSI::LIGHTMAGENTA;
        case YELLOW      : return ANSI::YELLOW;
        case WHITE       : return ANSI::WHITE;
        default: return "";
    }
}
#endif

// Return ANSI background color if not def WIN32
#if !(defined(WIN32))
[[maybe_unused]] std::string_view _getANSIBackgroundColor(int c) {
    switch (c) {
        case BLACK  : return ANSI::BACK_BLACK;
		case BLUE   : return ANSI::BACK_BLUE;
		case GREEN  : return ANSI::BACK_GREEN;
		case CYAN   : return ANSI::BACK_CYAN;
		case RED    : return ANSI::BACK_RED;
		case MAGENTA: return ANSI::BACK_MAGENTA;
		case BROWN  : return ANSI::BACK_YELLOW;
		case GREY   : return ANSI::BACK_WHITE;
		default: return "";
    }
}
#endif

// Save default color
WORD _saveDefaultColor_() {
    static bool init_flag = false;
    static WORD start_attrib;
    if (!init_flag) {
        CONSOLE_SCREEN_BUFFER_INFO scr_buff;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &scr_buff);
        start_attrib = scr_buff.wAttributes;
        init_flag = true;
    }
    return start_attrib;
}

// Set text color in console
[[maybe_unused]] void setColor(int c){
#if defined(WIN32)
    _saveDefaultColor_();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO scr_buff;
    GetConsoleScreenBufferInfo(hConsole, &scr_buff);
    SetConsoleTextAttribute(hConsole, (scr_buff.wAttributes & 0xFFF0) | static_cast<WORD>(c));
#else
    CLUTIL(_getANSIColor(c));
#endif
}

// Set background color in console
[[maybe_unused]] void setBackgroundColor(int c){
#if defined(WIN32)
    _saveDefaultColor_();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO scr_buff;
    GetConsoleScreenBufferInfo(hConsole, &scr_buff);
    SetConsoleTextAttribute(hConsole, (scr_buff.wAttributes & 0xFF0F) | (static_cast<WORD>(c) << 4));
#else
    CLUTIL(_getANSIBackgroundColor(c));
#endif
}

// Clear console
[[maybe_unused]] void cls() {
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO scr_buff;
    GetConsoleScreenBufferInfo(hConsole, &scr_buff);
    DWORD dwConSize = scr_buff.dwSize.X * scr_buff.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &scr_buff);
    FillConsoleOutputAttribute(hConsole, scr_buff.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
#else
    CLUTIL(ANSI::CLS);
	CLUTIL(ANSI::CURSOR_HOME);
#endif
}

// Reset color
[[maybe_unused]] void resetColor(){
#if defined(_WIN32)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _saveDefaultColor_());
#else
    CLUTIL(ANSI::ATTRIBUTE_RESET);
#endif
}

}

#endif //TEST_COLOR__CLUTIL_HPP_
