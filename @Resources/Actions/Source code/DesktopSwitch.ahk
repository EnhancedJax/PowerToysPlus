#SingleInstance force
#NoTrayIcon

IniRead, OutputVar, Hotkeys.ini, Variables, DesktopSwitch

Hotkey,#%OutputVar%,Button
Return

Button:
Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasureGroup "UpdateOnLoad" "PowerToys+\DesktopSwitch"""
Return
	
$Esc::
	Send {Esc down}
	Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "Unload" "PowerToys+\DesktopSwitch"""
	KeyWait, Esc
	Send {Esc up}
	return