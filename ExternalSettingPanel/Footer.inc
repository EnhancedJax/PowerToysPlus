[SlideBackground]
Meter=Shape
DynamicVariables=1
Group=Slides
Shape=Rectangle 0,0,(#AniSlide#),(#PanelH#),(#Corner#*#Edge#*10),(#Corner#*#Edge#*10) | StrokeWidth 0 | Fill Color #SettingAltColor#
MouseOverAction=[!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
MouseLeaveAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]

[SlideContainer]
Meter=Shape
DynamicVariables=1
Group=Slides
Shape=Rectangle 0,0,(#AniSlide#),(#PanelH#) | StrokeWidth 0 | Fill color 255,255,255

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Repeat SlideIn,8.165,10
ActionList2=Repeat SlideOut,8.165,10
SlideIn=[!SetVariable AniSlide "(Clamp((#AniSlide#+25),60,220))"][!UpdateMeterGroup Slides][!UpdateMeasure ActionTimer][!Redraw]
SlideOut=[!SetVariable AniSlide "(Clamp((#AniSlide#-25),60,220))"][!UpdateMeterGroup Slides][!UpdateMeasure ActionTimer][!Redraw]

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

[Cross]
Meter=Image
ImageName=#@#Icons\#IconPack#\Cross.png
X=20
Y=20
W=20
LeftMouseUpAction=[!DeactivateConfig]
SolidColor=0,0,0,1
ImageTint=#FontColor#

[GlobalBox]
Meter=Shape
X=0
Y=120
Shape=Rectangle 0,0,#AniSlide#,50,(#Corner#/4*10),(#Corner#/4*10) | StrokeWidth 0 | Extend This | Extend That
This=Fill Color #Accent#,0
DynamicVariables=1
Group=Slides
MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Accent#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Accent#,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "Global.ini"]

[Global]
Meter=Image
ImageName=#@#Icons\#IconPack#\Settings.png
X=20r
Y=15r
W=20
ImageTint=#FontColor#

[TextStyle]
X=r
Y=50r
FontSize=10
StringAlign=LeftCenter
Container=SlideContainer

[GlobalText]
Meter=String
Text=General
X=([Global:X]+50)
Y=([Global:Y]+10)
MeterStyle=RegularText | TextStyle

[RunBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "MultiRun.ini"]

[Run]
Meter=Image
ImageName=#@#Icons\#IconPack#\Run.png
MeterStyle=Global

[RunText]
Meter=String
Text=MultiRun
FontWeight=
MeterStyle=RegularText | TextStyle

[ClipboardBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "PermaClip.ini"]

[Clipboard]
Meter=Image
ImageName=#@#Icons\#IconPack#\PermaClip.png
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
ImageName=#@#Icons\#IconPack#\dashboard.png
MeterStyle=Global

[DashboardText]
Meter=String
Text=Dashboard
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
ImageName=#@#Icons\#IconPack#\Snip.png
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
ImageName=#@#Icons\#IconPack#\ImageOverlay.png
MeterStyle=Global

[ImageOverlayText]
Meter=String
Text=ImageOverlay
FontWeight=
MeterStyle=RegularText | TextStyle

[StartBox]
Meter=Shape
Y=15R
MeterStyle=GlobalBox
This=Fill Color #Accent#,0
LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "StartCenter.ini"]

[Start]
Meter=Image
ImageName=#@#Icons\#IconPack#\Start.png
MeterStyle=Global

[StartText]
Meter=String
Text=StartCenter
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
ImageName=#@#Icons\#IconPack#\DesktopSwitch.png
MeterStyle=Global
ImageAlpha=100

[DesktopSwitchText]
Meter=String
Text=Deswitch
FOntColor=255,255,255,100
FontWeight=
MeterStyle=RegularText | TextStyle

;[()Box]
;Meter=Shape
;Y=15R
;MeterStyle=GlobalBox
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\ExternalSettingPanel" "().ini"]

;[()]
;Meter=Image
;ImageName=#@#Icons\#IconPack#\().png
;MeterStyle=Global

;[()Text]
;Meter=String
;Text=()
;FontWeight=
;MeterStyle=RegularText | TextStyle
[CyclerBox]
Meter=Shape
Y=(#PanelH#-60)
MeterStyle=GlobalBox | Cycler1
This=Fill Color #Accent#,0
[Cycler1]
LeftMouseUpAction=[!WriteKeyValue Variables PanelW (#SCREENAREAWIDTH#/2) "CommVars.inc"][!WriteKeyValue Variables PanelH (#SCREENAREAHEIGHT#) "CommVars.inc"][!WriteKeyValue CyclerBox MeterStyle "GlobalBox | Cycler2" "Footer.inc"][!Refresh]
[Cycler2]
LeftMouseUpAction=[!WriteKeyValue Variables PanelW 920 "CommVars.inc"][!WriteKeyValue Variables PanelH 620 "CommVars.inc"][!WriteKeyValue CyclerBox MeterStyle "GlobalBox | Cycler3" "Footer.inc"][!Refresh]
[Cycler3]
LeftMouseUpAction=[!WriteKeyValue Variables PanelW 1150 "CommVars.inc"][!WriteKeyValue Variables PanelH 775 "CommVars.inc"][!WriteKeyValue CyclerBox MeterStyle "GlobalBox | Cycler1" "Footer.inc"][!Refresh]

[Cycler]
Meter=Image
ImageName=#@#Icons\#IconPack#\Window.png
X=20
Y=(#PanelH#-45)
W=20
MeterStyle=Global

[CyclerText]
Meter=String
Text=Cycle window type
Y=(#PanelH#-35)
FontWeight=
MeterStyle=RegularText | TextStyle

[BarHandler]
Meter=Shape
Shape=Rectangle 0,0,3,25 | Fill Color #Accent# | StrokeWidth 0
X=5
Y=(#BarHandler#+12)

;[Cross]
;Meter=Image
;ImageName=#@#Icons\#IconPack#\Cross.png
;X=20
;Y=(#PanelH#-35)
;W=20
;LeftMouseUpAction=[!DeactivateConfig]
;SolidColor=0,0,0,1

;[SlideArea]
;Meter=Image
;W=#AniSlide#
;H=#PanelH#
;SolidColor=0,0,0,1
;DynamicVariables=1
;MouseOverAction=[!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
;MouseLeaveAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]
