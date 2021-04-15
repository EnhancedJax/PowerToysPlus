[AppVol1]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=1
Substitute=".exe":""
[AppPeak1]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=1
NumberType=Peak
StringType=FilePath
[MeterText1]
Meter=String
MeterStyle=TextStyle
MeasureName=AppVol1
Y=400
[MeterShape1]
Meter=Shape
MeterStyle=ShapeStyle
PeakWidth=Scale ([AppPeak1:] > 0 ? [AppPeak1:] : 0), 1, 0, 0
VolWidth=Scale ([AppVol1:] > 0 ? [AppVol1:] : 0), 1, 0, 0
LeftMouseUpAction=!CommandMeasure AppVol1 "ToggleMute"
MouseScrollUpAction=!CommandMeasure AppVol1 "SetVolume +5"
MouseScrollDownAction=!CommandMeasure AppVol1 "SetVolume -5"
[AppVol2]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=2
Substitute=".exe":""
[AppPeak2]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=2
NumberType=Peak
StringType=FilePath
[MeterText2]
Meter=String
MeterStyle=TextStyle
MeasureName=AppVol2
Y=435
[MeterShape2]
Meter=Shape
MeterStyle=ShapeStyle
PeakWidth=Scale ([AppPeak2:] > 0 ? [AppPeak2:] : 0), 1, 0, 0
VolWidth=Scale ([AppVol2:] > 0 ? [AppVol2:] : 0), 1, 0, 0
LeftMouseUpAction=!CommandMeasure AppVol2 "ToggleMute"
MouseScrollUpAction=!CommandMeasure AppVol2 "SetVolume +5"
MouseScrollDownAction=!CommandMeasure AppVol2 "SetVolume -5"
[AppVol3]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=3
Substitute=".exe":""
[AppPeak3]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=3
NumberType=Peak
StringType=FilePath
[MeterText3]
Meter=String
MeterStyle=TextStyle
MeasureName=AppVol3
Y=470
[MeterShape3]
Meter=Shape
MeterStyle=ShapeStyle
PeakWidth=Scale ([AppPeak3:] > 0 ? [AppPeak3:] : 0), 1, 0, 0
VolWidth=Scale ([AppVol3:] > 0 ? [AppVol3:] : 0), 1, 0, 0
LeftMouseUpAction=!CommandMeasure AppVol3 "ToggleMute"
MouseScrollUpAction=!CommandMeasure AppVol3 "SetVolume +5"
MouseScrollDownAction=!CommandMeasure AppVol3 "SetVolume -5"
[AppVol4]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=4
Substitute=".exe":""
[AppPeak4]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=4
NumberType=Peak
StringType=FilePath
[MeterText4]
Meter=String
MeterStyle=TextStyle
MeasureName=AppVol4
Y=505
[MeterShape4]
Meter=Shape
MeterStyle=ShapeStyle
PeakWidth=Scale ([AppPeak4:] > 0 ? [AppPeak4:] : 0), 1, 0, 0
VolWidth=Scale ([AppVol4:] > 0 ? [AppVol4:] : 0), 1, 0, 0
LeftMouseUpAction=!CommandMeasure AppVol4 "ToggleMute"
MouseScrollUpAction=!CommandMeasure AppVol4 "SetVolume +5"
MouseScrollDownAction=!CommandMeasure AppVol4 "SetVolume -5"
[AppVol5]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=5
Substitute=".exe":""
[AppPeak5]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=5
NumberType=Peak
StringType=FilePath
[MeterText5]
Meter=String
MeterStyle=TextStyle
MeasureName=AppVol5
Y=540
[MeterShape5]
Meter=Shape
MeterStyle=ShapeStyle
PeakWidth=Scale ([AppPeak5:] > 0 ? [AppPeak5:] : 0), 1, 0, 0
VolWidth=Scale ([AppVol5:] > 0 ? [AppVol5:] : 0), 1, 0, 0
LeftMouseUpAction=!CommandMeasure AppVol5 "ToggleMute"
MouseScrollUpAction=!CommandMeasure AppVol5 "SetVolume +5"
MouseScrollDownAction=!CommandMeasure AppVol5 "SetVolume -5"
[AppVol6]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=6
Substitute=".exe":""
[AppPeak6]
Measure=Plugin
Plugin=AppVolume
Parent=AppVolumeParent
Index=6
NumberType=Peak
StringType=FilePath
[MeterText6]
Meter=String
MeterStyle=TextStyle
MeasureName=AppVol6
Y=575
[MeterShape6]
Meter=Shape
MeterStyle=ShapeStyle
PeakWidth=Scale ([AppPeak6:] > 0 ? [AppPeak6:] : 0), 1, 0, 0
VolWidth=Scale ([AppVol6:] > 0 ? [AppVol6:] : 0), 1, 0, 0
LeftMouseUpAction=!CommandMeasure AppVol6 "ToggleMute"
MouseScrollUpAction=!CommandMeasure AppVol6 "SetVolume +5"
MouseScrollDownAction=!CommandMeasure AppVol6 "SetVolume -5"
