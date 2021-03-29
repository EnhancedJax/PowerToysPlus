[Box1]
Meter=shape
X=1
Y=(#Scrollvar#+1)
DynamicVariables=1
Shape=Rectangle 0,0,(#GlobalW#-20*2),#BoxH#,(#Corner#*3),(#Corner#*3) | StrokeWidth 2 | Fill Color #BoxColor#,#Alpha# | Extend This
This=Stroke Color #BoxBorder#,#Alpha# 
Container=BoxContainer
MouseOverAction=[!SetOPtion #CURRENTSECTION# This "Stroke Color #Accent#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOPtion #CURRENTSECTION# This "Stroke Color #BoxBorder#,#Alpha# "][!UpdateMeter #CURRENTSECTION#][!Redraw]

[String1]
Meter=String
Text=#1#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!Delay 100][!setvariable editing 1][!setoption input DefaultValue "#1#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#1#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run1]
Meter=Image
Imagename=#@#icons\powershell.png
x=(#GlobalW#-20*2-15-7)
y=5r
w=15
ToolTipText=Run the line of text in a standard rainmeter bang [""].
ToolTipTitle=Run as bang
LEftMouseUpAction=["#1#"]
ImageAlpha=50
SolidColor=0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 250][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 50][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=BoxContainer

[Search1]
Meter=Image
Imagename=#@#icons\search.png
w=15
x=r
Y=15R
ToolTipText=Search the phrase copied online.
ToolTipTitle=Search online
LEftMouseUpAction=["https://www.google.com/search?q=#1#"]
ImageAlpha=50
SolidColor=0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 250][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 50][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=BoxContainer

[Box2]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String2]
Meter=String
Text=#2#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 2][!setoption input DefaultValue "#2#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#2#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run2]
Meter=Image
LEftMouseUpAction=["#2#"]
MeterStyle=Run1

[Search2]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#2#"]
MeterStyle=Search1

[Box3]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String3]
Meter=String
Text=#3#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 3][!setoption input DefaultValue "#3#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#3#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run3]
Meter=Image
LEftMouseUpAction=["#3#"]
MeterStyle=Run1

[Search3]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#3#"]
MeterStyle=Search1

[Box4]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String4]
Meter=String
Text=#4#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 4][!setoption input DefaultValue "#4#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#4#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run4]
Meter=Image
LEftMouseUpAction=["#4#"]
MeterStyle=Run1

[Search4]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#4#"]
MeterStyle=Search1

[Box5]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String5]
Meter=String
Text=#5#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 5][!setoption input DefaultValue "#5#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#5#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run5]
Meter=Image
LEftMouseUpAction=["#5#"]
MeterStyle=Run1

[Search5]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#5#"]
MeterStyle=Search1

[Box6]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String6]
Meter=String
Text=#6#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 6][!setoption input DefaultValue "#6#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#6#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run6]
Meter=Image
LEftMouseUpAction=["#6#"]
MeterStyle=Run1

[Search6]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#6#"]
MeterStyle=Search1

[Box7]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String7]
Meter=String
Text=#7#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 7][!setoption input DefaultValue "#7#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#7#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run7]
Meter=Image
LEftMouseUpAction=["#7#"]
MeterStyle=Run1

[Search7]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#7#"]
MeterStyle=Search1

[Box8]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String8]
Meter=String
Text=#8#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 8][!setoption input DefaultValue "#8#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#8#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run8]
Meter=Image
LEftMouseUpAction=["#8#"]
MeterStyle=Run1

[Search8]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#8#"]
MeterStyle=Search1

[Box9]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String9]
Meter=String
Text=#9#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 9][!setoption input DefaultValue "#9#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#9#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run9]
Meter=Image
LEftMouseUpAction=["#9#"]
MeterStyle=Run1

[Search9]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#9#"]
MeterStyle=Search1

[Box10]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String10]
Meter=String
Text=#10#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 10][!setoption input DefaultValue "#10#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#10#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run10]
Meter=Image
LEftMouseUpAction=["#10#"]
MeterStyle=Run1

[Search10]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#10#"]
MeterStyle=Search1

[Box11]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String11]
Meter=String
Text=#11#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 11][!setoption input DefaultValue "#11#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#11#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run11]
Meter=Image
LEftMouseUpAction=["#11#"]
MeterStyle=Run1

[Search11]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#11#"]
MeterStyle=Search1

[Box12]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String12]
Meter=String
Text=#12#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 12][!setoption input DefaultValue "#12#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#12#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run12]
Meter=Image
LEftMouseUpAction=["#12#"]
MeterStyle=Run1

[Search12]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#12#"]
MeterStyle=Search1

[Box13]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String13]
Meter=String
Text=#13#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 13][!setoption input DefaultValue "#13#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#13#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run13]
Meter=Image
LEftMouseUpAction=["#13#"]
MeterStyle=Run1

[Search13]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#13#"]
MeterStyle=Search1

[Box14]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String14]
Meter=String
Text=#14#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 14][!setoption input DefaultValue "#14#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#14#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run14]
Meter=Image
LEftMouseUpAction=["#14#"]
MeterStyle=Run1

[Search14]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#14#"]
MeterStyle=Search1

[Box15]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String15]
Meter=String
Text=#15#
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
StringAlign=Left
Container=BoxContainer
RightMouseUpAction=[!DisableMeasure Unload][!setvariable editing 15][!setoption input DefaultValue "#15#"][!setOption Input X (19+5)][!setOption Input Y ([#CURRENTSECTION#:Y])][!CommandMeasure Input "ExecuteBatch ALL"]
LeftMouseDownAction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
LeftMouseUpAction=[!SetClip """#15#"""][!Setoption #CURRENTSECTION# fontweight 400][!updatemeter #currentsection#][!redraw][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"]

[Run15]
Meter=Image
LEftMouseUpAction=["#15#"]
MeterStyle=Run1

[Search15]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=#15#"]
MeterStyle=Search1

[Input]
Measure=Plugin
Plugin=InputText
SolidColor=#BoxColor#
FontColor=#FontColor#
FontFace=Seqoe
FontSize=10
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
DefaultValue=""
DynamicVariables=1
OnDismissAction=["#@#Actions\RainFocus.exe" "#CURRENTCONFIG#"][!EnableMeasure UNload]
Command1=!WriteKeyValue Variables #Editing# "$UserInput$"
Command2=!Refresh #CURRENTCONFIG#
