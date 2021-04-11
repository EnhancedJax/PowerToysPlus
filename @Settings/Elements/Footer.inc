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
Container=SlideContainer

[crosstext]
Meter=String
Text=Powertoys+ Config
X=25R
y=10r
FontWeight=600
MeterStyle=RegularText | TextStyle

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "Global.ini"]

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "MultiRun.ini"]

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "PermaClip.ini"]

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "Dashboard.ini"]

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "SnipControl.ini"]

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "ImageOverlay.ini"]

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
LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "StartCenter.ini"]

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
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "DesktopSwitch.ini"]

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
;LeftMouseUpAction=[!ActivateConfig "PowerToys+\@settings" "().ini"]

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
MeterStyle=GlobalBox | Cycler3
This=Fill Color #Accent#,0
[Cycler1]
LeftMouseUpAction=[!WriteKeyValue Variables PanelW (#SCREENAREAWIDTH#/2) "elements\variables.inc"][!WriteKeyValue Variables PanelH (#SCREENAREAHEIGHT#) "elements\variables.inc"][!WriteKeyValue CyclerBox MeterStyle "GlobalBox | Cycler2" "elements\footer.inc"][!Refresh]
[Cycler2]
LeftMouseUpAction=[!WriteKeyValue Variables PanelW 920 "elements\variables.inc"][!WriteKeyValue Variables PanelH 620 "elements\variables.inc"][!WriteKeyValue CyclerBox MeterStyle "GlobalBox | Cycler3" "elements\footer.inc"][!Refresh]
[Cycler3]
LeftMouseUpAction=[!WriteKeyValue Variables PanelW 1150 "elements\variables.inc"][!WriteKeyValue Variables PanelH 775 "elements\variables.inc"][!WriteKeyValue CyclerBox MeterStyle "GlobalBox | Cycler1" "elements\footer.inc"][!Refresh]

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
