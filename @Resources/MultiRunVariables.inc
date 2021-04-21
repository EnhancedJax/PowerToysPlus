;——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
[Variables]
;——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

GlobalW=400
GlobalH=100
engine=https://www.google.com/search?q=
enginename=Google
browserlink=["#engine#[ArgsFilter]"]
browser=Default
dictlink=https://dictionary.cambridge.org/dictionary/english-chinese-traditional/
Icon=1
Animated=0
Prefix=\/

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
