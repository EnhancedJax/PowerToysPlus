#SingleInstance Force
#NoTrayIcon

IniRead, OutputVar, Hotkeys.ini, Variables, AppTray

Hotkey,#%OutputVar%,Button
Return

Button:
Run, AHK.exe Tray.ahk
Return