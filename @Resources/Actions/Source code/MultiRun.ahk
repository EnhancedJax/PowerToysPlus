#SingleInstance force
#NoTrayIcon

;Unload := 0

IniRead, OutputVar, Hotkeys.ini, Variables, MultiRun

Hotkey,#%OutputVar%,Button
Return

Button:
Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasureGroup "UpdateOnLoad" "PowerToys+\MultiRun"""
;Unload := 1
Return

;~Esc::
;	if (Unload = 1)
;		Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "Unload" "PowerToys+\MultiRun"""
;		Unload := 0
;	return
;return