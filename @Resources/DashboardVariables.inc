[Variables]
@includeGlobal=#@#GlobalVars.inc
GlobalW=(500*#Scale#)
GlobalH=(800*#Scale#)

Location=bottom
ShowSec=0
OnOff=1
Animated=1
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
