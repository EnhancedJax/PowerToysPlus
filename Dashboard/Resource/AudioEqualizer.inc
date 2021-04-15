
[AppVolumeParent]
Measure=Plugin
Plugin=AppVolume
IgnoreSystemSound=0

[GeneratorScript]
Measure=Script
ScriptFile =resource\AudioLua.lua
IncFile    =resource\AudioMeasures.inc
MeasureName=AppVolumeParent
AutoRefresh=0
S1  =AppVol%%
S1K1=Measure=Plugin
S1K2=Plugin=AppVolume
S1K3=Parent=AppVolumeParent
S1K4=Index=%%
S1K5=Substitute=".exe":""
S2  =AppPeak%%
S2K1=Measure=Plugin
S2K2=Plugin=AppVolume
S2K3=Parent=AppVolumeParent
S2K4=Index=%%
S2K5=NumberType=Peak
S2K6=StringType=FilePath
S3  =MeterShape%%
S3K1=Meter=Shape
S3K2=MeterStyle=ShapeStyle
S3K3=Y={(%% - 1) * 55 + 10}
S3K4=PeakWidth=Scale ([AppPeak%%:] > 0 ? [AppPeak%%:] : 0), 1, 0, 0
S3K5=VolWidth=Scale ([AppVol%%:] > 0 ? [AppVol%%:] : 0), 1, 0, 0
S3K6=LeftMouseUpAction=!CommandMeasure AppVol%% "ToggleMute"
S3K7=MouseScrollUpAction=!CommandMeasure AppVol%% "SetVolume +5"
S3K8=MouseScrollDownAction=!CommandMeasure AppVol%% "SetVolume -5"
S4  =MeterText%%
S4K1=Meter=String
S4K2=MeterStyle=TextStyle
S4K3=MeasureName=AppVol%%

[ShapeStyle]
Y=10R
X=10
Shape =Rectangle 0, 0, 250, 20, 5 | StrokeWidth 0 | Fill Color 757575
Shape2=Rectangle 0, 0, 250, 20 | StrokeWidth 0 | Fill Color DE867A | Extend VolWidth
Shape3=Rectangle 0, 0, 250,  3 | StrokeWidth 0 | Fill Color 7FBEE0 | Extend PeakWidth
Shape4=Rectangle 0, 0, 250, 20, 5
Shape5=Combine Shape2 | Intersect Shape4
Shape6=Combine Shape3 | Intersect Shape4
ToolTipText=Click to toggle mute#CRLF#Scroll to change
container=container
DynamicVariables=1

[TextStyle]
X=15
Y=3R
FontSize  =12
FontWeight=400
FontFace  =Cabliri
FontColor =D4D3CD
container=container
AntiAlias =1

@include=resource\AudioMeasures.inc