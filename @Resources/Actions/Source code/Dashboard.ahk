#SingleInstance force
#NoTrayIcon

Unload := 0

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