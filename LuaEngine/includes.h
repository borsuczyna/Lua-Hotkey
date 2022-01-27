#pragma once

#pragma warning(disable:4244)
#pragma warning(disable:4305)
#pragma warning(disable:4309)
#pragma warning(disable:4005)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <memory>
#include <iostream>
#include "Windows.h"
#include "time.h"
#include <format>
#include <cstdarg>
#include <string>

// Lua
extern "C" {
#include "../lua/lua.h"
#include "../lua/lualib.h"
#include "../lua/lauxlib.h"
}

#include "Mouse.h"
#include "Keyboard.h"
#include "LuaConsole.h"
#include "KeyCodes.h"
#include "Screen.h"
#include "Engine.h"

#include "CConsole.h"
#include "CLua.h"