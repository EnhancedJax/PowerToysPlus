#NoTrayIcon
XPosition := A_ScreenWidth / 2

CoordMode, Mouse, Screen
MouseGetPos, xPos, yPos
MouseMove, %XPosition%, 60
Click
MouseMove, %xPos%, %yPos%
ExitApp