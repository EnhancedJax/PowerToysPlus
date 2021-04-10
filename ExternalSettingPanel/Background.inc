[Variables]
@includeGlobal=#@#GlobalVars.inc
@includeCV=CommVars.inc

[Background]
Meter=Shape
;31,31,31 | 247, 241, 242
Shape=Rectangle 0,0,(#PanelW#),#PanelH#,(#Corner#*#Edge#*10),(#Corner#*#Edge#*10) | StrokeWidth 0 | Fill Color #SettingColor#
;0,0,0 | 255,255,255
;
[SlideWhiteHighlight]
Meter=Shape
X=(#PanelW#-(#PanelW#/3.8333333333))
DynamicVariables=1
Shape=Rectangle 0,0,(#PanelW#/3.8333333333),#PanelH#,(#Corner#*#Edge#*10),(#Corner#*#Edge#*10) | StrokeWidth 0 | Fill RadialGradient this
this=-150,(-#PanelH#/2),0,0,500,500 | #SettingAltColor# ; 0.7 | #SettingAltColor#,100 ; 1.0
