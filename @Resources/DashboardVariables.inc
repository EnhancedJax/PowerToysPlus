[Variables]
@includeGlobal=#@#GlobalVars.inc
GlobalW=(500*#Scale#)
GlobalH=(800*#Scale#)

Location=secondLeft
ShowSec=0
OnOff=0
Animated=1
AnimatedA=255
FocusDismiss=0

focusdismissaction=
Animation=0
;focusdismissaction=[!UpdateMeasure Unload]

;;╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗
;;║ METERSTYLES                                                                                          ║
;;╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝


[BoldText]
FontFace=#Font#
FontWeight=800
AntiAlias=1
FontColor=#FontColor#
FontSize=(12*#Scale#)
SolidColor=0,0,0,1
Container=Container

[SemiBoldText]
FontFace=#Font#
FontWeight=500
AntiAlias=1
FontColor=#FontColor#
FontSize=(12*#Scale#)
SolidColor=0,0,0,1
Container=Container

[RegularText]
FontFace=#Font#
AntiAlias=1
FontColor=#FontColor#
FontSize=(12*#Scale#)
SolidColor=0,0,0,1
Container=Container
