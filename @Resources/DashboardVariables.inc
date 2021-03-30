[Variables]
GlobalW=(360*#Scale#)
GlobalH=#ScreenAreaHeight#
Alpha=190
XMargin=(12*#Scale#)
YMargin=(10*#Scale#)
Animated=1
Drive1=C
Drive2=D
Drive3=E
LeftRight=Left
ONOff=1
ActualBlur=None
ShowSec=1
time=(1)
;OldGPU=0
;Starter=1
;GPUAnimated=0
;OldCPU=0
;CPUAnimated=0
Animation=0
Div3W=((#GlobalW#-#Xmargin#*2-1)/3-13/3)
NetType=
ContextAni=0
@includeGlobal=#@#GlobalVars.inc

;;╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗
;;║ METERSTYLES                                                                                          ║
;;╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝

[BoldText]
FontFace=#Font#
FontWeight=800
AntiAlias=1
FontColor=#DarkColor#
FontSize=(15*#scale#)
SolidColor=0,0,0,1
StringALign=LeftCenter

[SemiBoldedText]
FontFace=#Font#
FontWeight=500
AntiAlias=1
FontColor=#DarkColor#
FontSize=(12*#scale#)
H=(12*#scale#)
SolidColor=0,0,0,1
StringALign=LeftCenter

[RegularText]
FontFace=#Font#
AntiAlias=1
FontColor=#DarkColor#
FontSize=(12*#scale#)
H=(12*#scale#)
SolidColor=0,0,0,1
StringALign=LeftCenter
