;——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
[Variables]
;——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

GlobalW=300
GlobalH=400
VGap=10
StartH=50
BoxH=(#GlobalH#*0.1625)
ScrollInterval=50
Alpha=150
ClicktoHide=[!Hide]

OnOff=1
@includeGlobal=#@#GlobalVars.inc
;;╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗
;;║ METERSTYLES                                                                                          ║
;;╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝

[BoldText]
FontFace=#Font#
FontWeight=800
AntiAlias=1
FontColor=#FontColor#
FontSize=12
StringALign=LeftCenter

[SemiBoldText]
FontFace=#Font#
FontWeight=500
AntiAlias=1
FontColor=#FontColor#
FontSize=12
StringALign=LeftCenter

[RegularText]
FontFace=#Font#
AntiAlias=1
FontColor=#FontColor#
FontSize=12
StringALign=LeftCenter
