#SingleInstance force
#NoTrayIcon

Unload := 0

IniRead, OutputVar, Hotkeys.ini, Variables, PermaClip

Hotkey,#%OutputVar%,Button
Return

Button:
Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasureGroup "UpdateOnLoad" "PowerToys+\PermaClip"""
Unload := 1
Return

~Esc::
	if (Unload = 1)
		Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "Unload" "PowerToys+\PermaClip"""
		Unload := 0
	return
return