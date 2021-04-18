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
