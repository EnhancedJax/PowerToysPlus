#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On
Unload := 1
numberkeys := 0

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

OnMessage(16687, "RainmeterWindowMessage")

RainmeterWindowMessage(wParam, lParam) { 
  If (wParam = 1) {
    numberkeys := 1
    msgbox, 1
  }
  else {
  	numberkeys := 0
  	msgbox, 0
  }
}

IniRead, OutputVar, Hotkeys.ini, Variables, Dashboard

Hotkey,#%OutputVar%,Button
Return

Button:
Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasureGroup "UpdateOnLoad" "PowerToys+\Dashboard"""
Unload := 1
Return

~Esc::
	if (Unload = 1)
		Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "Unload" "PowerToys+\Dashboard"""
		Unload := 0
	return
return

~1::
	if (numberkeys = 1)
		msgbox, Pressed
	return
return