[Variables]
AnimatedA=0
ActualBlur=None
@include=#@#dashboardVariables.inc


[Bisector]
X=0
Shape=Line 0,0,#GlobalW#,0 | StrokeWidth 1 | Stroke Color #BoxColor#
UpdateDivider=-1

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#ActualBlur#
DynamicVariables=1
UpdateDivider=-1
;Acrylic | Blur

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
UpdateDivider=-1
ActionList1=Show | Repeat In,6,10 | BlurOn
ActionList2=Showfade
ActionList3=BlurOff | Repeat Out,6,10 | Hide
ActionList4=Hidefade
In=[!SetVariable Animation "(Clamp((#Animation#-10),0,100))"][!SetVariable AnimatedA "(Clamp((#AnimatedA#+26),0,255))"][!UpdateMeter Container][!UpdateMeasure ActionTimer][!Redraw]
Out=[!SetVariable Animation "(Clamp((#Animation#+10),0,100))"][!SetVariable AnimatedA "(Clamp((#AnimatedA#-40),0,255))"][!UpdateMeter Container][!UpdateMeasure ActionTimer][!Redraw]
Show=[!UpdateMeasure ActionTimer][!Show][!ZPos 1][!EnableMeasure Unload][!DisableMeasure OnLoad]["#@#Actions\RainFocus.exe" "#CURRENTCONFIG#"]
Showfade=[!SHowFade][!ZPos 1][!EnableMeasure Unload][!DisableMeasure OnLoad]["#@#Actions\RainFocus.exe" "#CURRENTCONFIG#"]
HideFade=[!EnableMeasureGroup UpdateonLoad][!EnableMeasure OnLoad][!HideFade][!DisableMeasure Unload]
Hide=[!EnableMeasureGroup UpdateonLoad][!Hide][!DisableMeasure Unload]
BlurON=[!SetVariable ActualBlur #Acrylic#][!UpdateMeasure FrostedGlass][!UpdateMeasure ActionTimer]
BlurOff=[!SetVariable ActualBlur None][!UpdateMeasure FrostedGlass][!UpdateMeasure ActionTimer]

[OnActualLoad]
Measure=Calc
Formula=Counter
OnUpdateAction=[!SetVariable AnimatedA 255][!UpdateMeter Container][!SetVariable ActualBlur #Acrylic#][!UpdateMeasure FrostedGlass][!Delay 16][!EnableMeasureGroup NoUpdateOnLoad][!DisableMeasure #CURRENTSECTION#]
UpdateDivider=-1


;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                              Loading and unloading
;///////////////////////////////////////////////////////////////////////////////////////////////////

[Unload]
Measure=String
String=#Animated#
IfMatchMode=1
IfMatch=1
IfMatchAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 3"]
IfNotMatchAction=[!CommandMeasure ActionTimer "Execute 4"]
Disabled=1
Group=NoUpdateOnLoad
UpdateDivider=-1

[OnLoad]
Measure=String
String=#Animated#
IfMatchMode=1
IfMatch=1
IfMatchAction=[!CommandMeasure ActionTimer "Stop 3"][!CommandMeasure ActionTimer "Execute 1"]
IfNotMatchAction=[!CommandMeasure ActionTimer "Execute 2"]
DynamicVariables=1
Disabled=1
Group=NoUpdateOnLoad | UpdateonLoad
UpdateDivider=-1

[SettingImport1]
Measure=String
String=#Location#
IFmatch=bottom
IfMatchAction=[!Move (#SCREENAREAWIDTH#-#globalw#) (#WORKAREAHEIGHT#-#GlobalH#)]
IfNotMatchAction=[!Move (#SCREENAREAWIDTH#-#globalw#) (#WORKAREAHEIGHT#/2-#GlobalH#/2)]
UpdateDivider=-1

[SettingImport2]
Measure=String
String=#ShowSec#
IfMatch=1
IfMatchAction=[!SetOption Date Text "%1%2"]
UpdateDivider=-1

[SettingImport3]
Measure=String
String=#animated#
IfMatch=0
IfMatchAction=[!SetVariable AnimatedA "255"][!SetVariable ActualBlur #Acrylic#][!UpdateMeasure FrostedGlass]
UpdateDivider=-1


;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                              Start
;///////////////////////////////////////////////////////////////////////////////////////////////////
[Container]
Meter=Image
Y=#Animation#
DynamicVariables=1
W=#GlobalW#
H=#GlobalH#
UpdateDivider=-1
SolidColor=0,0,0,#AnimatedA#

[Background]
Meter=Shape
Container=Container
Shape=Rectangle 0,0,#GlobalW#,#GlobalH#,(#Corner#*#Edge#*15),(#Corner#*#Edge#*15) | StrokeWidth 1 | Stroke Color #Border#,#Alpha# | Fill Color #Color#,#Alpha#
UpdateDivider=-1

[WinIcon]
Meter=Image
ImageTint=#FontColor#
X=(22*#Scale#)
Y=(22*#Scale#)
W=(#scale#*25)
H=(#scale#*25)
Container=Container
UpdateDivider=-1

[SectionHeader]
Meter=String
X=(65*#Scale#)
Y=(20*#Scale#)
MeasureName=MeasureTime
FontSize=(#scale#*15)
FontWeight=500
MeterStyle=RegularText
UpdateDivider=-1
Container=Container

[Date]
Meter=String
X=(#GlobalW#-25*#Scale#)
Y=r
Text=%1
StringAlign=Right
FontSize=(#scale#*15)
FontWeight=500
MeasureName=MeasureTime
MeasureName2=MeasureSec
LeftMouseUpAction=["#@#Actions\AHKOld.exe" "#@#Actions\Source code\Calendar.ahk"]
MeterStyle=RegularText
FontColor=#DarkColor#









[pageImageStyle]
w=(30*#Scale#)
h=(30*#Scale#)
x=(10*#Scale#)R
y=r
SolidColor=0,0,0,1
Container=Container
[pageGeneral]
meter=image
x=(#GlobalW#/2-(10*#Scale#*1+30*#Scale#*4)/2)
Y=(#GlobalH#-50*#Scale#)
ImageName=#@#icons\#IconPack#\menu.png
meterstyle=pageImageStyle
LeftMouseUpAction=[!ActivateConfig "PowerToys+\Dashboard" "general.ini"]
[pageResource]
meter=image
ImageName=#@#icons\#IconPack#\resource.png
meterstyle=pageImageStyle
LeftMouseUpAction=[!ActivateConfig "PowerToys+\Dashboard" "resource.ini"]
[pageDisplay]
meter=image
ImageName=#@#icons\#IconPack#\monitor.png
meterstyle=pageImageStyle
LeftMouseUpAction=[!ActivateConfig "PowerToys+\Dashboard" "display.ini"]
[pageInfo]
meter=image
ImageName=#@#icons\#IconPack#\important.png
meterstyle=pageImageStyle
LeftMouseUpAction=[!ActivateConfig "PowerToys+\Dashboard" "info.ini"]

[pageIndicator]
meter=shape
x=(#GlobalW#/2-(10*#Scale#*1+30*#Scale#*4)/2+#barhandler#*40*#Scale#)
y=(5*#Scale#)R
Container=Container
Shape=Rectangle (2.5*#Scale#),0,(25*#Scale#),(4*#Scale#),(#Corner#*2),(#Corner#*2) | StrokeWidth 0 | Fill Color #Accent#

;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                              Measures
;///////////////////////////////////////////////////////////////////////////////////////////////////

[MeasureTime]
Measure=Time
Format=%H%M
[MeasureSec]
Measure=Time
Format=%S
MinValue=0
MaxValue=60
[MeasureDate]
Measure=Time
Format=%a, %#b %#d
