local options = {
    doubleEdit = "F",
}

function updateConsole()
    console.clear()

    print("")
    print("   \x1B[32m┌── Fortnite macros ────────────────┐")
    print("   \x1B[32m│  Double edit: \x1B[37m" .. options.doubleEdit .. "\t\t       \x1B[32m│")
    print("   \x1B[32m└───────────────────────────────────┘")
end

function fastKey(key)
    keyboard.setKeyState(key, true)
    engine.wait(10)
    keyboard.setKeyState(key, false)
end

function fastClick(button)
    mouse.setState(button, true)
    engine.wait(10)
    mouse.setState(button, false)
end

updateConsole()

while true do
    if keyboard.getAsyncKeyState(_G["VK_" .. options.doubleEdit]) then
        fastKey(VK_X)
        fastClick(1)
    end
end