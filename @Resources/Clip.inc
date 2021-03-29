[Box1]
Meter=shape
X=1
Y=(#Scrollvar#+1)
DynamicVariables=1
Shape=Rectangle 0,0,(#GlobalW#-20*2),#BoxH#,#Corner#,#Corner# | StrokeWidth 2 | Fill Color #BoxColor#,#Alpha# | Extend This
This=Stroke Color #BoxBorder#,#Alpha# 
Container=BoxContainer
MouseOverAction=[!SetOPtion #CURRENTSECTION# This "Stroke Color 250,250,250 "][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOPtion #CURRENTSECTION# This "Stroke Color #BoxBorder#,#Alpha# "][!UpdateMeter #CURRENTSECTION#][!Redraw]
UpdateDivider=-1

[String1]
Meter=String
Text=[MeasureLine1]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne1" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run1]
Meter=Image
Imagename=#@#icons\powershell.png
x=(#GlobalW#-20*2-15-7)
y=5r
w=15
ToolTipText=Run the line of text in a standard rainmeter bang [""].
ToolTipTitle=Run as bang
ImageAlpha=50
SolidColor=0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 250][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 50][!UpdateMeter #CURRENTSECTION#][!Redraw]
LEftMouseUpAction=["[MeasureLIne1]"]
Container=BoxContainer
UpdateDivider=-1

[Search1]
Meter=Image
Imagename=#@#icons\search.png
w=15
x=r
Y=15R
ToolTipText=Search the phrase copied online.
ToolTipTitle=Search online
ImageAlpha=50
SolidColor=0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha 250][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha 50][!UpdateMeter #CURRENTSECTION#][!Redraw]
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne1]"]
Container=BoxContainer
UpdateDivider=-1

[Box2]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String2]
Meter=String
Text=[MeasureLine2]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne2" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run2]
Meter=Image
LEftMouseUpAction=["[MeasureLIne2]"]
MeterStyle=Run1

[Search2]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne2]"]
MeterStyle=Search1

[Box3]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String3]
Meter=String
Text=[MeasureLine3]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne3" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run3]
Meter=Image
LEftMouseUpAction=["[MeasureLIne3]"]
MeterStyle=Run1

[Search3]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne3]"]
MeterStyle=Search1

[Box4]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String4]
Meter=String
Text=[MeasureLine4]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne4" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run4]
Meter=Image
LEftMouseUpAction=["[MeasureLIne4]"]
MeterStyle=Run1

[Search4]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne4]"]
MeterStyle=Search1

[Box5]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String5]
Meter=String
Text=[MeasureLine5]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne5" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run5]
Meter=Image
LEftMouseUpAction=["[MeasureLIne5]"]
MeterStyle=Run1

[Search5]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne5]"]
MeterStyle=Search1

[Box6]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String6]
Meter=String
Text=[MeasureLine6]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne6" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run6]
Meter=Image
LEftMouseUpAction=["[MeasureLIne6]"]
MeterStyle=Run1

[Search6]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne6]"]
MeterStyle=Search1

[Box7]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String7]
Meter=String
Text=[MeasureLine7]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne7" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run7]
Meter=Image
LEftMouseUpAction=["[MeasureLIne7]"]
MeterStyle=Run1

[Search7]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne7]"]
MeterStyle=Search1

[Box8]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String8]
Meter=String
Text=[MeasureLine8]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne8" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run8]
Meter=Image
LEftMouseUpAction=["[MeasureLIne8]"]
MeterStyle=Run1

[Search8]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne8]"]
MeterStyle=Search1

[Box9]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String9]
Meter=String
Text=[MeasureLine9]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne9" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run9]
Meter=Image
LEftMouseUpAction=["[MeasureLIne9]"]
MeterStyle=Run1

[Search9]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne9]"]
MeterStyle=Search1

[Box10]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String10]
Meter=String
Text=[MeasureLine10]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne10" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run10]
Meter=Image
LEftMouseUpAction=["[MeasureLIne10]"]
MeterStyle=Run1

[Search10]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne10]"]
MeterStyle=Search1

[Box11]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String11]
Meter=String
Text=[MeasureLine11]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne11" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run11]
Meter=Image
LEftMouseUpAction=["[MeasureLIne11]"]
MeterStyle=Run1

[Search11]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne11]"]
MeterStyle=Search1

[Box12]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String12]
Meter=String
Text=[MeasureLine12]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne12" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run12]
Meter=Image
LEftMouseUpAction=["[MeasureLIne12]"]
MeterStyle=Run1

[Search12]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne12]"]
MeterStyle=Search1

[Box13]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String13]
Meter=String
Text=[MeasureLine13]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne13" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run13]
Meter=Image
LEftMouseUpAction=["[MeasureLIne13]"]
MeterStyle=Run1

[Search13]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne13]"]
MeterStyle=Search1

[Box14]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String14]
Meter=String
Text=[MeasureLine14]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne14" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run14]
Meter=Image
LEftMouseUpAction=["[MeasureLIne14]"]
MeterStyle=Run1

[Search14]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne14]"]
MeterStyle=Search1

[Box15]
Meter=shape
Y=(#Vgap#+10)R
MeterStyle=Box1

[String15]
Meter=String
Text=[MeasureLine15]
X=5r
Y=5r
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
SolidColor=0,0,0,1
MeterStyle=RegularText
FontSize=10
Clipstring=1
Dynamicvariables=1
StringAlign=Left
Container=BoxContainer
leftmousedownaction=[!Setoption #CURRENTSECTION# fontweight 800][!updatemeter #currentsection#][!redraw]
leftmouseupaction=[!CommandMeasure "MeasureLIne15" "Set"][!Hide]["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Paste.ahk"][!refresh]

[Run15]
Meter=Image
LEftMouseUpAction=["[MeasureLIne15]"]
MeterStyle=Run1

[Search15]
Meter=Image
LEftMouseUpAction=["https://www.google.com/search?q=[MeasureLIne15]"]
MeterStyle=Search1

[Input]
Measure=Plugin
Plugin=InputText
SolidColor=#BoxColor#
FontColor=255,255,255
FontFace=Seqoe
FontSize=10
W=(#GlobalW#-20*2-45)
H=(#BoxH#-5*2)
DefaultValue=""
DynamicVariables=1
Command1=!WriteKeyValue Variables #Editing# "$UserInput$"
Command2=!Refresh #CURRENTCONFIG#
