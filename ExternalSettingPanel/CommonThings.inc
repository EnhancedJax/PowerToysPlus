[Variables]
@includeGlobal=#@#GlobalVars.inc
@includeCV=CommVars.inc


[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#

[Background]
Meter=Shape
DynamicVariables=1
Shape=Rectangle 0,0,(#AniSlide#+#Corner#*2*10),(#PanelH#),(#Corner#*#Edge#*10),(#Corner#*#Edge#*10) | StrokeWidth 0 | Fill Color #SettingAltColor#,#Alpha#
;31,31,31 | 247, 241, 242
Shape2=Rectangle (#AniSlide#),0,(#PanelW#-#AniSlide#),#PanelH#,(#Corner#*#Edge#*10),(#Corner#*#Edge#*10) | StrokeWidth 0 | Fill Color #SettingColor#
;0,0,0 | 255,255,255

[SlideContainer]
Meter=Shape
DynamicVariables=1
Shape=Rectangle 0,0,(#AniSlide#),(#PanelH#) | StrokeWidth 0 | Fill color 255,255,255

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Repeat SlideIn,8.165,10
ActionList2=Repeat SlideOut,8.165,10
SlideIn=[!SetVariable AniSlide "(Clamp((#AniSlide#+25),60,250))"][!UpdateMeter *][!UpdateMeasure ActionTimer][!Redraw]
SlideOut=[!SetVariable AniSlide "(Clamp((#AniSlide#-25),60,250))"][!UpdateMeter *][!UpdateMeasure ActionTimer][!Redraw]

[OnLoad]
Measure=String
OnUpdateAction=[!SetOption #CURRENTSETTING# FOntWeight 630][!Zpos 1][!FadeDuration 200][!KeepOnScreen 0][!DisableMeasure #CURRENTSECTION#][!Delay 50][!EnableMeasureGroup NoUpdateOnLoad]

;[TitleBar]
;Meter=String
;Text=PowerToys+ Settings
;Padding=40,5,5,5
;MeterStyle=RegularText
;FontSize=9
;StringAlign=LEft

[SlideWhiteHighlight]
Meter=Shape
X=(#PanelW#-300)
Shape=Rectangle 0,0,300,#PanelH#,(#Corner#*#Edge#*10),(#Corner#*#Edge#*10) | StrokeWidth 0 | Fill RadialGradient this
this=-150,(-#PanelH#/2),0,0,500,500 | #SettingAltColor# ; 0.7 | #SettingAltColor#,100 ; 1.0

[Cross]
Meter=Image
ImageName=#@#Icons\Cross.png
X=20
Y=20
W=20
LeftMouseUpAction=[!DeactivateConfig]
SolidColor=0,0,0,1
ImageTint=#FontColor#

;[Crossbackground]
;Meter=Image
;X=(#PanelW#-18-10-10)
;W=40
;H=(18+10)
;SolidColor=0,0,0,1
;MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "232, 17, 35"][!SetOption Cross ImageAlpha 255][!UpdateMeter *][!Redraw]
;MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "0,0,0,1"][!SetOption Cross ImageAlpha 150][!UpdateMeter *][!Redraw]
;LeftMouseUpAction=[!DeactivateConfig]


;[Cross]
;Meter=Image
;ImageName=#@#Icons\Cross.png
;X=(#PanelW#-18-10)
;Y=5
;W=18
;SolidColor=0,0,0,1
;ImageAlpha=150



;[HomeBox]
;Meter=Shape
;X=0
;Y=100
;Shape=Rectangle 0,0,250,50,(#Corner#/4*10),(#Corner#/4*10) | StrokeWidth 0 | Extend This | Extend That
;This=Fill Color #Accent#,0
;MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Accent#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
;MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Accent#,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "Main.ini"]

;[Home]
;Meter=Image
;ImageName=#@#Icons\Home.png
;X=20r
;Y=15r
;W=20

;[HomeText]
;Meter=String
;X=30R
;Y=10r
;FontSize=10
;Text=Home
;MeterStyle=RegularText

[GlobalBox]
Meter=Shape
X=0
Y=120
Shape=Rectangle 0,0,#AniSlide#,50,(#Corner#/4*10),(#Corner#/4*10) | StrokeWidth 0 | Extend This | Extend That
This=Fill Color #Accent#,0
DynamicVariables=1
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Accent#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Accent#,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "Global.ini"]

[Global]
Meter=Image
ImageName=#@#Icons\Options.png
X=20r
Y=15r
W=20
ImageTint=#FontColor#

[TextStyle]
X=r
Y=50r
FontSize=10
Container=SlideContainer

[GlobalText]
Meter=String
Text=General
X=([Global:X]+50)
Y=([Global:Y]+10)
MeterStyle=RegularText | TextStyle

[ClipboardBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "PermaClip.ini"]

[Clipboard]
Meter=Image
ImageName=#@#Icons\PermaClip.png
MeterStyle=Global

[ClipboardText]
Meter=String
Text=PermaClip
FontWeight=
MeterStyle=RegularText | TextStyle

[DashboardBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "Dashboard.ini"]

[Dashboard]
Meter=Image
ImageName=#@#Icons\dashboard.png
MeterStyle=Global

[DashboardText]
Meter=String
Text=Dashboard
FontWeight=
MeterStyle=RegularText | TextStyle

[DesktopSwitchBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "DesktopSwitch.ini"]

[DesktopSwitch]
Meter=Image
ImageName=#@#Icons\DesktopSwitch.png
MeterStyle=Global
ImageAlpha=100

[DesktopSwitchText]
Meter=String
Text=Deswitch
;FOntColor=255,255,255,100
FontWeight=
MeterStyle=RegularText | TextStyle

[SnipControlBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "SnipControl.ini"]

[SnipControl]
Meter=Image
ImageName=#@#Icons\Snip.png
MeterStyle=Global

[SnipControlText]
Meter=String
Text=SnipControl
FontWeight=
MeterStyle=RegularText | TextStyle

[ImageOverlayBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "ImageOverlay.ini"]

[ImageOverlay]
Meter=Image
ImageName=#@#Icons\ImageOverlay.png
MeterStyle=Global

[ImageOverlayText]
Meter=String
Text=ImageOverlay
FontWeight=
MeterStyle=RegularText | TextStyle

;[TaskbarBox]
;Meter=Shape
;Y=15R
;MeterStyle=GlobalBox
;;LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "Taskbar.ini"]

;[Taskbar]
;Meter=Image
;ImageName=#@#Icons\Taskbar.png
;MeterStyle=Global
;ImageAlpha=100

;[TaskbarText]
;Meter=String
;Text=Taskbar
;FontWeight=
MeterStyle=RegularText | TextStyle

[StartBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "Start.ini"]

[Start]
Meter=Image
ImageName=#@#Icons\Start.png
MeterStyle=Global
ImageAlpha=100

[StartText]
Meter=String
Text=StartCenter
FontWeight=
MeterStyle=RegularText | TextStyle
;FOntColor=255,255,255,100

[RunBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "MultiRun.ini"]

[Run]
Meter=Image
ImageName=#@#Icons\Run.png
MeterStyle=Global

[RunText]
Meter=String
Text=MultiRun
FontWeight=
MeterStyle=RegularText | TextStyle

;[()Box]
;Meter=Shape
;Y=15R
;MeterStyle=GlobalBox
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "().ini"]

;[()]
;Meter=Image
;ImageName=#@#Icons\().png
;MeterStyle=Global

;[()Text]
;Meter=String
;Text=()
;FontWeight=
MeterStyle=RegularText | TextStyle

[BarHandler]
Meter=Shape
Shape=Rectangle 0,0,3,25 | Fill Color #Accent# | StrokeWidth 0
X=5
Y=(#BarHandler#+12)

;[Cross]
;Meter=Image
;ImageName=#@#Icons\Cross.png
;X=20
;Y=(#PanelH#-35)
;W=20
;LeftMouseUpAction=[!DeactivateConfig]
;SolidColor=0,0,0,1

[SlideArea]
Meter=Image
W=#AniSlide#
H=#PanelH#
SolidColor=0,0,0,1
DynamicVariables=1
MouseOverAction=[!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
MouseLeaveAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]