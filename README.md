Commands: 

```
!runfile [absolute path]
!runfile [relative path]
!run [code]
```

You can run file by dragging it onto LuaEngine.exe

Functions:
```lua
console.print(string: text)
console.rawline(string: text)
console.clear()

mouse.setPosition(int: x, int: y)
mouse.getPosition()
mouse.smoothMove(int: x, int: y, int: time, int: interpolations)
mouse.setState(int: button, bool: state)
mouse.click(int: x, int: y, int: button, int:time)

keyboard.getKeyState(int: key)
keyboard.getAsyncKeyState(int: key)
keyboard.setKeyState(int: key, bool: state)

screen.getDimensions()
screen.getPixelColor(int: x, int: y)
screen.findPixelByColor(int: x, int: y, int: w, int: h, int: r, int: g, int: b, int: variation)

engine.wait(int: time)
engine.messageBox(string: title, string: info, int: type)
```

Examples:
```lua
local sx, sy = screen.getDimensions()
mouse.smoothMove(sx/2, sy/2, 1000)
```

```lua
local input = ""

function updateConsole()
    console.clear()
    print("\x1B[31mInput text:")
    console.rawline("\x1B[32m" .. input)
end

while true do
    for k,v in pairs(_G) do
        if k:sub(1, 3) == "VK_" and #k == 4 then
            if keyboard.getAsyncKeyState(v) then
                input = input .. k:sub(4, 4):lower()
                updateConsole()
            end
        end
    end
    if keyboard.getAsyncKeyState(VK_BACK) then
        input = input:sub(1, #input-1)
        updateConsole()
    end
    if keyboard.getAsyncKeyState(VK_RETURN) then
        console.clear()
        print("\x1B[33mResult: " .. input)
        input = ""
    end
end
```

