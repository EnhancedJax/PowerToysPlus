#SingleInstance force
#NoTrayIcon

Unload := 0

+#s::
	Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasureGroup "UpdateOnLoad" "PowerToys+\SnipControl"""
	Unload := 1
	return

~Esc::
	if (Unload = 1)
		Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "Unload" "PowerToys+\SnipControl"""
		Unload := 0
	return
return