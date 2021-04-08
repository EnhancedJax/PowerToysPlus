[MeasureComputerName]
Measure=Plugin
Plugin=SysInfo
SysInfoType=COMPUTER_NAME
UpdateDivider=-1

[MeasureTime]
Measure=Time
Format=%H%M
[MeasureSec]
Measure=Time
Format=%S
MaxValue=60
[MeasureDate]
Measure=Time
Format=%a, %#b %#d
;[MeasureOSVersion]
;Measure=Plugin
;Plugin=SysInfo
;SysInfoType=OS_VERSION
;Substitute="Windows 10":"Win10"
;UpdateDivider=-1
[MeasureOSBits]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_BITS
UpdateDivider=-1
[MeasureMonitors]
Measure=Plugin
Plugin=SysInfo
SysInfoType=NUM_MONITORS
UpdateDivider=-1
;[MeasureUsername]
;Measure=Plugin
;Plugin=SysInfo
;SysInfoType=USER_NAME
;UpdateDivider=-1

[MeasureProductName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=ProductName
UpdateDivider=-1
[MeasureVersion]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=DisplayVersion
UpdateDivider=-1
[MeasureCurrentBuild]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=CurrentBuild
UpdateDivider=-1
[MeasureUBR]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=UBR
UpdateDivider=-1

[MeasureGPUName]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic path win32_VideoController get name
State=Hide
OutputType=ANSI
OutputFile=#CURRENTPATH#GPUName.txt
RegExpSubstitute=1
Substitute="Name.*#CRLF#":"","#CRLF#.*":"","  ":"","Radeon":"AMD Radeon#CRLF#","NVIDIA GeForce":"NVIDIA GeForce#CRLF#"
UpdateDivider=-1
[MeasureCPUName]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
UpdateDivider=12000
RegExpSubstitute=1
Substitute="CPU":"","\(TM\)|\(tm\)|\(Tm\)":"","Processor":"","(\w{1,4}[\s\S]Core[s]?)":"","(Intel Core|Intel\(R\) Core)":"Intel(R) Core#CRLF#","@.*":"","AMD Ryzen ":"AMD Ryzen#CRLF# R"
UpdateDivider=-1
[MeasureMotherboardname]
Measure=Plugin
Plugin=RunCommand
Parameter=wmic baseboard get product
State=Hide
OutputType=ANSI
OutputFile=#CURRENTPATH#MBName.txt
RegExpSubstitute=1
Substitute="Product.*#CRLF#":"","#CRLF#.*":"","  ":"","\(":"#CRLF#("
UpdateDivider=-1

;[MeasureProcessor]
;Measure=Registry
;RegHKey=HKEY_LOCAL_MACHINE
;RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
;RegValue=ProcessorNameString
;UpdateDivider=-1
[MeasurePhysMemTotal]
Measure=PhysicalMemory
Total=1
UpdateDivider=-1
[MeasureInstalledRam]
Measure=Calc
Formula=[MeasurePhysMemTotal]/1000/1000/1000
;DynamicVariables=1
;UpdateDivider=-1
;[MeasureDeviceID]
;Measure=Registry
;RegHKey=HKEY_LOCAL_MACHINE
;RegKey=SOFTWARE\Microsoft\SQMClient
;RegValue=Machineid
;UpdateDivider=-1
;Substitute="{":"","}":""
;[MeasureProductID]
;Measure=Registry
;RegHKey=HKEY_LOCAL_MACHINE
;RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
;RegValue=Productid
;UpdateDivider=-1

[MeasurePhysMemUsed]
Measure=PhysicalMemory
UpdateDivider=5
[MeasureUsedPercent]
Measure=Calc
Formula=(MeasurePhysMemUsed / MeasurePhysMemTotal) * 100
UpdateDivider=5
[MeasureCPU]
Measure=Plugin
Plugin=UsageMonitor
Alias=CPU
Index=0
Substitute="^0$":"0.000001"
[MeasureGPU]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Index=0
Blacklist=dwm
DynamicVariables=1
;OnChangeAction=[!SetVariable CPUAnimated [MeasureCPU:]][!SetVariable GPUAnimated [MeasureGPU:]][!Delay 1000][!SetVariable OldGPU [MeasureGPU:]][!COmmandMeasure ActionTimer "Execute 1"][!SetVariable OldCPU [MeasureCPU:]]

;[InternetOff]
;Measure=Plugin
;Plugin=RunCommand
;Parameter=ipconfig /release
;State=Hide
;[InternetOn]
;Measure=Plugin
;Plugin=RunCommand
;Parameter=ipconfig /renew
;State=Hide
;[MeasureNetwork]
;Measure=Plugin
;Plugin=SysInfo
;SysInfoType=INTERNET_CONNECTIVITY
;SysInfoData=Best
;IfCondition=MeasureNetWork = -1
;IfTrueAction=[!SetOption InternetToggleText Text "Turn on internet"][!SetOption InternetToggleText LeftMouseUpAction """[!CommandMeasure InternetOn "Run"]"""]
;IfFalseAction=[!SetOption InternetToggleText Text "Turn off internet"][!SetOption InternetToggleText LeftMouseUpAction """[!CommandMeasure InternetOff "Run"]"""]
;UpdateDivider=1

[RecycleBinFiles]
Measure=RecycleManager
RecycleType=COUNT
Drives=ALL
UpdateDivider=60
Group=Bin
Substitute=".0":""
[RecycleBinSize]
Measure=RecycleManager
RecycleType=SIZE
Drives=ALL
UpdateDivider=60
Group=Bin
[MeasureUptime]
Measure=Uptime
Format="%4!i! days, %3!i! hours, %2!i! minutes %1!i! seconds"

[InternetType]
Measure=Plugin
Plugin=SysInfo
SysInfoType=ADAPTER_TYPE
SysInfoData=Best
UpdateDivider=-1
IfCondition=InternetType=6
IfTrueAction=[!SetVariable NetType Ethernet][!UpdateMeasure InternetStatus]
IfCondition2=InternetType=71
IfTrueAction2=[!SetVariable NetType Wifi][!UpdateMeasure InternetStatus]
[InternetName]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=SSID
Substitute="-1":""
[InternetStatus]
Measure=PLUGIN
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
Substitute="-1.0":"Offline","1.0":"Connected"
DynamicVariables=1
IfCondition=InternetStatus = -1
IfTrueAction=[!SetOption Mbox6T Text "%1#CRLF#Click here to connect to the internet"][!SetOption Mbox6I ImageName "#@#Icons\#IconPack#\#NetType#-0.png"][!UpdateMeter Mbox6T][!UpdateMeter Mbox6I][!Redraw]
IfFalseAction=[!SetOption Mbox6T Text "%1 %2-%3 #CRLF#Dl %4b | Ul %5b"][!SetOption Mbox6I ImageName "#@#Icons\#IconPack#\#NetType#-1.png"][!UpdateMeter Mbox6T][!UpdateMeter Mbox6I][!Redraw]
[mAUTH]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=AUTH
Substitute="-1":""
[InternetDownloadSpeed]
Measure=NetIn
Interface=Best
MinValue=0
AverageSize=5
[InternetUploadSpeed]
Measure=NetOut
Interface=Best
MinValue=0
AverageSize=5

[DriveCTotal]
Measure=FreeDiskSpace
Total=1
Drive=#Drive1#:
UpdateDivider=120
Substitute=^0$":"0.000001"
[DriveDTotal]
Measure=FreeDiskSpace
Total=1
Drive=#Drive2#:
UpdateDivider=120
Substitute=^0$":"0.000001"
[DriveETotal]
Measure=FreeDiskSpace
Total=1
Drive=#Drive3#:
UpdateDivider=120
Substitute=^0$":"0.000001"
[DriveCFree]
Measure=FreeDiskSpace
Drive=#Drive1#:
UpdateDivider=120
Substitute="^0$":"0.000001"
[DriveDFree]
Measure=FreeDiskSpace
Drive=#Drive2#:
UpdateDivider=120
Substitute=^0$":"0.000001"
[DriveEFree]
Measure=FreeDiskSpace
Drive=#Drive3#:
UpdateDivider=120
Substitute=^0$":"0.000001"
[DriveCPercent]
Measure=Calc
Formula=([DriveCTotal:]-[DriveCFree])/[DriveCTotal:]
DynamicVariables=1
UpdateDivider=120
[DriveDPercent]
Measure=Calc
Formula=([DriveDTotal:]-[DriveDFree])/[DriveDTotal:]
DynamicVariables=1
UpdateDivider=120
[DriveEPercent]
Measure=Calc
Formula=([DriveETotal:]-[DriveEFree])/[DriveETotal:]
DynamicVariables=1
UpdateDivider=120

[MeasureCPUHigh]
Measure=Plugin
Plugin=UsageMonitor
Alias=CPU
Index=1
Substitute="^0$":"0.000001"
;[MeasureCPUHigh2]
;Measure=Plugin
;Plugin=UsageMonitor
;Alias=CPU
;Index=2
;Disabled=1
;Substitute="^0$":"0.000001"
;[MeasureCPUHigh3]
;Measure=Plugin
;Plugin=UsageMonitor
;Alias=CPU
;Index=3
;Disabled=1
;Substitute="^0$":"0.000001"

[MeasureRAMHigh]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Index=1
Substitute="^0$":"0.000001"
;[MeasureRAMHigh2]
;Measure=Plugin
;Plugin=UsageMonitor
;Alias=RAM
;Index=2
;Disabled=1
;Substitute="^0$":"0.000001"
;[MeasureRAMHigh3]
;Measure=Plugin
;Plugin=UsageMonitor
;Alias=RAM
;Index=3
;Disabled=1
;Substitute="^0$":"0.000001"

[MeasureGPUHigh]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Index=1
Substitute="^0$":"0.000001"
;[MeasureGPUHigh2]
;Measure=Plugin
;Plugin=UsageMonitor
;Alias=GPU
;Index=2
;Disabled=1
;Substitute="^0$":"0.000001"
;[MeasureGPUHigh3]
;Measure=Plugin
;Plugin=UsageMonitor
;Alias=GPU
;Index=3
;Disabled=1
;Substitute="^0$":"0.000001"

[MeasureWin7Audio]
Measure=Plugin
Plugin=Win7AudioPlugin
Substitute="^-1$":"0"

[MeasureAudioIcon]
Measure=Calc
Formula=MeasureWin7Audio
IfCondition=(MeasureAudioIcon > 0)
IfTrueAction=[!SetOption Mbox15I ImageName #@#Icons\#IconPack#\Sound.png][!UpdateMEter Mbox15I][!Redraw]
IfFalseAction=[!SetOption Mbox15I ImageName "#@#Icons\#IconPack#\No Sound.png"][!UpdateMEter Mbox15I][!Redraw]