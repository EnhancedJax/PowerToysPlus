;——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
[Variables]
;——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

@includeGlobal=#@#GlobalVars.inc
Gap=10
IndivW=(90*#Scale#)
GlobalW=(#IndivW#*3+#Gap#*4)
GlobalH=(70*#Scale#)
IndivH=(#GlobalH#-#Gap#*2)
Icon=1

OnOff=0
;;╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗
;;║ METERSTYLES                                                                                          ║
;;╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝

[BoldText]
FontFace=#Font#
FontWeight=800
AntiAlias=1
FontColor=#FontColor#
FontSize=(12*#Scale#)
StringALign=LeftCenter

[SemiBoldText]
FontFace=#Font#
FontWeight=500
AntiAlias=1
FontColor=#FontColor#
FontSize=(12*#Scale#)
StringALign=LeftCenter

[RegularText]
FontFace=#Font#
AntiAlias=1
FontColor=#FontColor#
FontSize=(12*#Scale#)
StringALign=LeftCenter
