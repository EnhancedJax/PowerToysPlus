#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On

CloseScript(Name)
	{
	DetectHiddenWindows On
	SetTitleMatchMode RegEx
	IfWinExist, i)%Name%.* ahk_class AutoHotkey
		{
		WinClose
		WinWaitClose, i)%Name%.* ahk_class AutoHotkey, , 2
		If ErrorLevel
			return "Unable to close " . Name
		else
			return "Closed " . Name
		}
	else
		return Name . " not found"
	}

if WinExist("StartCenter.ahk" . " ahk_class AutoHotkey")
{
	CloseScript("StartCenter.ahk")
	Sleep 100
	Run, AHKOld.exe "Source code\StartCenter.ahk"
}

IniRead, OutputVar, Hotkeys.ini, Variables, AppTray

Hotkey,#%OutputVar%,Button
Return

Button:
Run, AHK.exe Tray.ahk
Return