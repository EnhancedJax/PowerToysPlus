[Variables]
GlobalW=(#SCREENAREAWIDTH#/3)
GlobalH=(#SCREENAREAHEIGHT#/100*80)
Scale=(#SCREENAREAWIDTH#/1920)

Location=Center
ShowSec=1
OnOff=1
Animated=0
@includeGlobal=#@#GlobalVars.inc


;;╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗
;;║ METERSTYLES                                                                                          ║
;;╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝

[BoldText]
FontFace=#Font#
FontWeight=800
AntiAlias=1
FontSize=(#scale#*15)
FontColor=#FontColor#
StringALign=LeftCenter

[SemiBoldedText]
FontFace=#Font#
FontWeight=500
AntiAlias=1
FontSize=(#scale#*12)
FontColor=#FontColor#
StringALign=LeftCenter

[RegularText]
FontFace=#Font#
AntiAlias=1
FontSize=(#Scale#*12)
FontColor=#FontColor#
StringALign=LeftCenter
