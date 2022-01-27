#include "Keyboard.h"

int Keyboard::GeyKeyState(lua_State* L)
{
	int key = luaL_checkinteger(L, 1);
	lua_pushboolean(L, (GetKeyState(key) & 0x8000));

	return 1;
}

int Keyboard::GeyAsyncKeyState(lua_State* L)
{
	int key = luaL_checkinteger(L, 1);
	lua_pushboolean(L, (GetAsyncKeyState(key) & 0x01));

	return 1;
}

int Keyboard::SetKeyState(lua_State* L)
{
	int key = luaL_checkinteger(L, 1);
	bool state = lua_toboolean(L, 2);

	INPUT input;
	WORD vkey = (WORD)key;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = vkey;
	input.ki.dwFlags = (state ? 0 : KEYEVENTF_KEYUP);
	SendInput(1, &input, sizeof(INPUT));

	return 0;
}