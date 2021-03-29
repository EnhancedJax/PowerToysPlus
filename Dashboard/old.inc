[Rainmeter]
Update=1000
AccurateText=1
RIghtMOuseUpAction=[!SkinCustomMenu]
ContextTitle=Refresh
ContextAction=[!Refresh]
SkinWidth=#SCREENAREAWIDTH#
SkinHeight=#GlobalH#

[Variables]
@include=#@#DashboardVariables.inc
Scrollvar=0
WideIndex=0

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#blur#
;Acrylic | Blur


[OnActualLoad]
Measure=Calc
Formula=Counter
IfEqualValue=1
IfEqualAction=[!FadeDuration 200][!Draggable 0][!KeepOnScreen 0]["#@#Actions\Dashboard.exe"][!Move 0 0][!Delay 16][!EnableMeasureGroup NoUpdateOnLoad][!DisableMeasure #CURRENTSECTION#][!EnableMeasure Unload][!Hide]
IfAboveValue=1
IfAboveAction=[!Delay 100][!EnableMeasure Unload]
UpdateDivider=-1

[SettingImport]
Measure=String
String=#Dismisser#
IfMatch=True
IfMatchAction=[!ShowMeter Dismisser]
OnUpdateAction=[!DisableMEasure #CURRENTSECTION#]
UpdateDivider=-1

[SettingImport2]
Measure=String
String=#Wide#
IfMatch=True
IfMatchAction=[!SetVariable WideIndex 50][!UpdateMeter *][!Redraw]
OnUpdateAction=[!DisableMEasure #CURRENTSECTION#]
UpdateDivider=-1

;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                              Loading and unloading
;///////////////////////////////////////////////////////////////////////////////////////////////////

[Unload]
Measure=String
String=#Animated#
IfMatchMode=1
IfMatch=True
IfMatchAction=[!EnableMeasureGroup UpdateonLoad][!HideFade][!WriteKeyValue Variables LeftRight Left #@#DashboardVariables.inc][!ActivateConfig "PowerToys+\Animations" "Dashboard.ini"][!DisableMeasure #CURRENTSECTION#]
IfNotMatchAction=[!EnableMeasureGroup UpdateonLoad][!HideFade][!DisableMeasure #CURRENTSECTION#]
DIsabled=1
UpdateDivider=-1

[OnLoad]
Measure=String
String=#Animated#
IfMatchMode=1
IfMatch=True
IfMatchAction=[!WriteKeyValue Variables LeftRight Right #@#DashboardVariables.inc][!ActivateConfig "PowerToys+\Animations" "Dashboard.ini"][!Delay 390][!SHowFade][!ZPos 1][!EnableMeasure Unload][!DisableMeasure #CURRENTSECTION#]
IfNotMatchAction=[!SHowFade][!ZPos 1][!EnableMeasure Unload][!DisableMeasure #CURRENTSECTION#]
Disabled=1
Group=NoUpdateOnLoad | UpdateonLoad
UpdateDivider=-1

;///////////////////////////////////////////////////////////////////////////////////////////////////
;                                              Header and buttons
;///////////////////////////////////////////////////////////////////////////////////////////////////

;;=================================================================================================================================================================================================================
;; System Dashboard                                                                                     
;;====================================================================================================================================================================================================================
[Dismisser]
MEter=String
X=0
Y=0
W=#SCREENAREAWIDTH#
H=#SCREENAREAHEIGHT#
Hidden=1
SolidColor=0,0,0,1
LeftMouseUpAction=[!UpdateMeasure UNload]
UpdateDivider=-1
MouseActionCursor=0

[Background]
Meter=Shape
X=(#SCREENAREAWIDTH#-#GlobalW#)
Shape=Rectangle 0,0,(#GlobalW#+#Corner#),#GlobalH#,#Corner#,#Corner# | StrokeWidth 1 | Stroke Color #Border#,#Alpha# | Fill Color #Color#,#Alpha#
UpdateDivider=-1
DynamicVariables=1
MouseScrollDownAction=[!SetVariable "ScrollVar" "(Clamp(#Scrollvar#-#ScrollInterval#,-350,0))"][!UpdateMEter *][!Redraw]
MouseScrollUpAction=[!SetVariable "ScrollVar" "(Clamp(#Scrollvar#+#ScrollInterval#,-350,0))"][!UpdateMEter *][!Redraw]
MouseActionCursor=0
LeftMouseUpAction=[]

[GlobalContainer]
Meter=Image
X=((#SCREENAREAWIDTH#-#GlobalW#)+#XMargin#)
Y=(#YMargin#/2)
W=(#GlobalW#-#XMargin#*2)
H=#GlobalH#
SolidCOlor=0,0,0
UpdateDivider=-1

[Subtitle]
Meter=String
Y=(#Scrollvar#+#YMArgiN#/2)
DynamicVariables=1
MeasureName=MeasureComputerName
Text=System Dashboard %1
Container=GlobalContainer
MeterStyle=SemiBoldedText
InlinePattern=System Dashboard(.*)
InlineSetting=Weight | 100
InlinePattern2=System Dashboard(.*)
InlineSetting2=Size | 10
FontColor=255,255,255,150
UpdateDivider=-1

[HeaderImage]
Meter=Image
X=r
Y=20R
ImageName=#@#Images\Win.png
Container=GlobalContainer
W=100
UpdateDivider=-1

[Title]
Meter=String
X=5R
Y=23r
MeasureName=MeasureOSVersion
MeasureName2=MeasureOSBits
Text=%1 %2bits
Container=GlobalContainer
MeterStyle=RegularText
FontSize=23
H=23
UpdateDivider=-1

[UserName]
Meter=String
X=r
Y=7.5R
MeasureName=MeasureUsername
Text=%1
Container=GlobalContainer
MeterStyle=RegularText
FontSize=15
H=15
FontColor=255,255,255,230
UpdateDivider=-1

@includeMeasures=#@#DashboardMeasures.inc

[UsageDetails]
Meter=String
X=-5
Y=(50+#WideIndex#)R
Text=Usage Details
Container=GlobalContainer
DynamicVariables=1
MeterStyle=RegularText
FontSize=18
H=18
Padding=5,5,5,5
UpdateDivider=-1

;;=================================================================================================================================================================================================================
;; RAM                                                                                                  
;;====================================================================================================================================================================================================================

[MeterRAMCircleBgRing]
Meter=Roundline
X=#circlesize#
Y=#circlesize#R
StartAngle=(Rad(270))
RotationAngle=(Rad(360))
LineStart=#circlehollowsize#
LineLength=#circlesize#
Solid=1
LineColor=#DarkColor#
AntiAlias=1
UpdateDivider=-1
Container=GlobalContainer

[MeterRAMCircle]
Meter=Roundline
MeasureName=MeasurePhysMemUsed
X=r
Y=r
StartAngle=(Rad(270))
RotationAngle=(Rad(360))
LineStart=#circlehollowsize#
LineLength=#circlesize#
Solid=1
LineColor=255,255,255
AntiAlias=1
UpdateDivider=8
Container=GlobalContainer

[MeterRAMLabel]
Meter=String
Text=RAM#CRLF#[MeasureUsedPercent:0]
FontFace=#Font#
FontSize=13
X=r
Y=r
FontColor=255,255,255
StringAlign=CenterCenter
DynamicVariables=1
InlinePattern=^RAM
InlineSetting=Weight | 700
InlinePattern2=[MeasureUsedPercent:0]$
InlineSetting2=Weight | 400
AntiAlias=1
UpdateDivider=8
Container=GlobalContainer

;;;=================================================================================================================================================================================================================
;;; CPU                                                                                                  
;;;====================================================================================================================================================================================================================

[MeterCPUCircleBgRing]
Meter=Roundline
X=(#circlesize#*2+15)r
Y=r
StartAngle=(Rad(270))
RotationAngle=(Rad(360))
LineStart=#circlehollowsize#
LineLength=#circlesize#
Solid=1
LineColor=#DarkColor#
AntiAlias=1
UpdateDivider=-1
Container=GlobalContainer

[MeterCPUCircle]
Meter=Roundline
MeasureName=MeasureCPU
X=r
Y=r
StartAngle=(Rad(270))
RotationAngle=(Rad(360))
LineStart=#circlehollowsize#
LineLength=#circlesize#
Solid=1
LineColor=255,255,255
AntiAlias=1
Container=GlobalContainer

[MeterCPULabel]
Meter=String
Text=CPU#CRLF#[MeasureCPU:1]
FontFace=#Font#
FontSize=13
X=r
Y=r
FontColor=255,255,255
StringAlign=CenterCenter
DynamicVariables=1
InlinePattern=^CPU
InlineSetting=Weight | 700
InlinePattern2=[MeasureCPU:1]$
InlineSetting2=Weight | 400
AntiAlias=1
Container=GlobalContainer

;;;=================================================================================================================================================================================================================
;;; GPU                                                                                                  
;;;====================================================================================================================================================================================================================

[MeterGPUCircleBgRing]
Meter=Roundline
X=(#circlesize#*2+15)r
Y=r
StartAngle=(Rad(270))
RotationAngle=(Rad(360))
LineStart=#circlehollowsize#
LineLength=#circlesize#
Solid=1
LineColor=#DarkColor#
AntiAlias=1
UpdateDivider=-1
Container=GlobalContainer

[MeterGPUCircle]
Meter=Roundline
MeasureName=MeasureGPU
X=r
Y=r
StartAngle=(Rad(270))
RotationAngle=(Rad(360))
LineStart=#circlehollowsize#
LineLength=#circlesize#
Solid=1
LineColor=255,255,255
AntiAlias=1
Container=GlobalContainer

[MeterGPULabel]
Meter=String
Text=GPU#CRLF#[MeasureGPU:1]
FontFace=#Font#
FontSize=13
X=r
Y=r
FontColor=255,255,255
StringAlign=CenterCenter
DynamicVariables=1
InlinePattern=^GPU
InlineSetting=Weight | 700
InlinePattern2=[MeasureGPU:1]$
InlineSetting2=Weight | 400
AntiAlias=1
Container=GlobalContainer

;;;=================================================================================================================================================================================================================
;;; Misc                                                                                            
;;;=================================================================================================================================================================================================================

;===================================INTERNET

[Internetimage]
Meter=Image
X=0
Y=10R
W=70
SolidColor=0,0,0,1
Imagename=#@#Icons\Internet.png
UpdateDivider=-1
Container=GlobalContainer

[Internet]
Meter=String
Text=Internet
X=R
Y=15r
MeterStyle=SemiBoldedText
Container=GlobalContainer
UpdateDivider=8

[InternetName]
Meter=String
MeasureName=mSSID
MeasureName2=mPercent
MeasureName3=mAUTH
Text=%1: %2 - %3
X=(#GlobalW#-#XMargin#*2)
Y=r
MeterStyle=RegularText
StringAlign=RightCenter
FontColor=255,255,255,200
Container=GlobalContainer

[InternetText]
Meter=String
Measurename=InternetUploadSpeed
Measurename2=InternetDownloadSpeed
X=(70)
Y=R
Text=Upload Speed: %1b#CRLF#Download Speed: %2b
FontSize=10
StringAlign=LeftTop
MeterStyle=RegularText
Autoscale=1
Container=GlobalContainer

[Drive1]
Meter=String
Y=40R
X=5
StringAlign=Left
MeasureName=DriveCTotal
MeasureName2=DriveCFree
Text=Drive (#Drive1#:)                    Total: %1B   Free: %2B
Container=GlobalContainer
MeterStyle=RegularText
UpdateDivider=30
Autoscale=1
InlinePattern=Total:.*
InlineSetting=Size | 8
InlinePattern2=Total:.*
InlineSetting2=Color | 255,255,255,150

[Drivebar1]
Meter=Bar
X=r
Y=15R
W=(#GlobalW#-#XMargin#*2)
H=20
BarOrientation=Horizontal
MeasureName=DriveCPercent
BarColor=#DarkColor#
SolidColor=#DarkColor#,150
Container=GlobalContainer
UpdateDivider=30

[Drive2]
Meter=String
Y=10R
X=5
MeasureName=DriveDTotal
MeasureName2=DriveDFree
Text=Drive (#Drive2#:)                    Total: %1B   Free: %2B
MeterStyle=RegularText | Drive1

[Drivebar2]
Meter=Bar
MeasureName=DriveDPercent
MeterStyle=Drivebar1

;;;=================================================================================================================================================================================================================
;;; Control Center                                                                                            
;;;=================================================================================================================================================================================================================

[Controlcenter]
Meter=String
X=-5
Y=(30+#WideIndex#)R
Text=Control center
Container=GlobalContainer
MeterStyle=RegularText
FontSize=18
H=18
DynamicVariables=1
Padding=5,5,5,5
UpdateDivider=-1

[Selectdisplay]
Meter=String
Y=-10R
X=10r
StringAlign=Left
Text=Select Display
Container=GlobalContainer
MeterStyle=RegularText
UpdateDivider=-1

[OneMonButton]
Meter=Shape
X=-1r
Y=15R
Shape=Rectangle 2,2,((#GlobalW#-50)/3),29,(#Corner#/10),(#Corner#/10) | StrokeWidth 2 | Fill Color #DarkColor# | Extend this
This=Stroke Color #DarkColor#
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke Color 200,200,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke Color #DarkColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=GlobalContainer
UpdateDivider=-1

[OneMonText]
Meter=String
X=((#GlobalW#-50)/3/2+2)r
Y=(29/2+2)r
W=((#GlobalW#-50)/3)
H=29
Text=One Only
StringAlign=CenterCenter
Container=GlobalContainer
LeftMouseUpAction=["DisplaySwitch.exe" "/internal"]
MeterStyle=RegularText
UpdateDivider=-1

[OneTwoMonButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[OneTwoMonText]
Meter=String
Text=Extend
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["DisplaySwitch.exe" "/extend"]

[TwoMonButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[TwoMonText]
Meter=String
Text=Second Only
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["DisplaySwitch.exe" "/external"]

[Configureconnections]
Meter=String
Y=-10R
X=5
StringAlign=Left
Text=Configure Connections
Container=GlobalContainer
MeterStyle=RegularText
UpdateDivider=-1

[WifiButton]
Meter=Shape
X=-1r
Y=15R
MeterStyle=OneMonButton

[WifiText]
Meter=String
Text=Wifi
MeterStyle=RegularText | OneMonText
RightMouseUpAction=["control.exe" "ncpa.cpl"]
LeftMouseUpAction=["ms-availablenetworks:"]

[BlueToothButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[BlueToothText]
Meter=String
Text=Bluetooth
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:bluetooth"]

[InternetToggleButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[InternetToggleText]
Meter=String
Text=
FontSize=10
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=
ToolTipTitle=Toggle internet status
ToolTipText=It may take a while to turn the internet on / off.
UpdateDivider=1
;The blank options is determined by a measure [MeasureNetwork]

[RecycleBin]
Meter=String
MeasureName=RecycleBinSize
MeasureName2=RecycleBinFiles
Y=-10R
X=5
StringAlign=Left
Text=Recycle Bin    %1B - %2 Files
Container=GlobalContainer
MeterStyle=RegularText
Autoscale=1
InlinePattern=Recycle Bin    (.*)
InlineSetting=Size | 8
InlinePattern2=Recycle Bin    (.*)
InlineSetting2=Color | 255,255,255,150
UpdateDivider=8

[OpenButton]
Meter=Shape
Shape=Rectangle 2,2,((#GlobalW#-50)/2),29,(#Corner#/10),(#Corner#/10) | StrokeWidth 2 | Fill Color #DarkColor# | Extend this
X=-1r
Y=15R
MeterStyle=OneMonButton

[OpenText]
Meter=String
X=((#GlobalW#-50)/2/2+2)r
W=((#GlobalW#-50)/2)
Text=Open
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=[!CommandMeasure "RecycleBinSize OpenBin"]

[ClearButton]
Meter=Shape
Shape=Rectangle 2,2,((#GlobalW#-50)/2),29,(#Corner#/10),(#Corner#/10) | StrokeWidth 2 | Fill Color #DarkColor# | Extend this
X=((#GlobalW#-50)/2/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[ClearText]
Meter=String
X=((#GlobalW#-50)/2/2+2)r
W=((#GlobalW#-50)/2)
Text=Clear
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=[!CommandMeasure "RecycleBinSize EmptyBin"]

[WindowsSettings]
Meter=String
Y=-10R
X=5
StringAlign=Left
Text=Windows Settings
Container=GlobalContainer
MeterStyle=RegularText
UpdateDivider=-1

[NightLightButton]
Meter=Shape
X=-1r
Y=15R
MeterStyle=OneMonButton

[NightLightText]
Meter=String
Text=Night Light
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:nightlight"]

[PrinterButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[PrinterText]
Meter=String
Text=Printers
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:printers"]

[ThemesButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[ThemesText]
Meter=String
Text=Themes
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:themes"]

[InfoButton]
Meter=Shape
X=4
Y=(29/2+5)r
MeterStyle=OneMonButton

[InfoText]
Meter=String
Text=Your info
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:yourinfo"]

[AppsButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[AppsText]
Meter=String
Text=Apps
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:appsfeatures"]

[StartUpAppsButton]
Meter=Shape
X=((#GlobalW#-50)/3/2+5)r
Y=(-29/2-2)r
MeterStyle=OneMonButton

[StartUpAppsText]
Meter=String
Text=Start up apps
MeterStyle=RegularText | OneMonText
LeftMouseUpAction=["ms-settings:startupapps"]









[WinSpec]
Meter=String
Y=(25+#WideIndex#)R
X=-5
Text=Windows Specifications
Container=GlobalContainer
MeterStyle=RegularText
FontSize=18
H=18
Padding=5,5,5,5
InlineSetting = Size | 10
InLinePattern = copy
DynamicVariables=1
MouseOverAction=[!SetOPtion #CURRENTSECTION# SolidColor 0,0,0,50][!SetOption #CURRENTSECTION# Text "Windows Specifications copy"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOPtion #CURRENTSECTION# SolidColor 0,0,0,1][!SetOption #CURRENTSECTION# Text "Windows Specifications"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!SetClip """Edition        [MeasureProductName]#CRLF#Version        [MeasureVersion]#CRLF#OS build        [MeasureCurrentBuild].[MeasureUBR]#CRLF#"""]
UpdateDivider=-1

[WSpecList]
Meter=String
X=10r
Y=R
StringAlign=Left
Text=Edition#CRLF#Version#CRLF#OS build#CRLF#
Container=GlobalContainer
InlineSetting = Size | 15
InLinePattern = #CRLF#
MeterStyle=RegularText
UpdateDivider=-1

[WSpecData]
Meter=String
X=140
Y=r
MeasureName=MeasureProductName
MeasureName2=MeasureVersion
MeasureName3=MeasureCurrentBuild
MeasureName4=MeasureUBR
StringAlign=Left
Text=%1#CRLF#%2#CRLF#%3.%4#CRLF#
Container=GlobalContainer
InlineSetting = Size | 15
InLinePattern = #CRLF#
MeterStyle=RegularText
FontColor=255,255,255,100
UpdateDivider=-1

[DevSpec]
Meter=String
X=-5
Y=100R
Text=Device Specifications
Container=GlobalContainer
MeterStyle=RegularText
FontSize=18
H=18
Padding=5,5,5,5
InlineSetting = Size | 10
InLinePattern = copy
DynamicVariables=1
MouseOverAction=[!SetOPtion #CURRENTSECTION# SolidColor 0,0,0,50][!SetOption #CURRENTSECTION# Text "Device Specifications copy"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOPtion #CURRENTSECTION# SolidColor 0,0,0,1][!SetOption #CURRENTSECTION# Text "Device Specifications"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!SetClip """Device Name        [MeasureComputerName]#CRLF#Processor        [MeasureProcessor]#CRLF#Installed RAM        [MeasureInstalledRam] GB#CRLF#Device ID        [MeasureDeviceID]#CRLF#Product ID        [MeasureProductID]#CRLF#"""]
UpdateDivider=-1

[DSpecList]
Meter=String
X=10r
Y=R
H=(15*5+12*6)
W=140
StringAlign=Left
Text=Device Name#CRLF#Processor#CRLF#Installed RAM#CRLF#Device ID#CRLF#Product ID#CRLF#
Container=GlobalContainer
InlineSetting = Size | 15
InLinePattern = #CRLF#
MeterStyle=RegularText
UpdateDivider=-1

[DSpecData]
Meter=String
X=R
Y=r
W=(#GlobalW#-140)
MeasureName=MeasureComputerName
MeasureName2=MeasureProcessor
MeasureName3=MeasureInstalledRam
MeasureName4=MeasureDeviceID
MeasureName5=MeasureProductID
StringAlign=Left
Text=%1#CRLF#%2#CRLF#%3 GB#CRLF#%4#CRLF#%5#CRLF#
Container=GlobalContainer
InlineSetting = Size | 15
InLinePattern = #CRLF#
InlineSetting2 = Size | 8
InLinePattern2 = .*#CRLF#(.*)#CRLF#.*#CRLF#(.*)#CRLF#
MeterStyle=RegularText
FontColor=255,255,255,100
UpdateDivider=-1

;;;=================================================================================================================================================================================================================
;;; SettingButton                                                                                            
;;;=================================================================================================================================================================================================================

[Icon]
Meter=Image
ImageName=#@#Icons\Settings_large.png
X=((#GlobalW#-#XMargin#)/2-40/2)
Y=150R
W=40
SolidColor=0,0,0,1
LeftMouseUpAction=[!ToggleConfig "PowerToys+\ExternalSettingPanel" "Dashboard.ini"]
Container=GlobalContainer