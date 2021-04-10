#Persistent
#SingleInstance Ignore
#NoTrayIcon
ListLines(0)
DetectHiddenWindows(1)
SetTitleMatchMode("RegEx")
ProcessSetPriority("Realtime")
CoordMode "Mouse", "Screen"
#Include GDIP.ahk
#Include LIB.ahk
#Include Status.ahk
OnMessage(5100, "sortWindows")
OnMessage(5202, "taskControl")
OnMessage(5201, "taskItemMenu")
OnMessage(5200, "taskSwitch")
OnMessage(5400, "getWindows")
OnMessage(10000, "exit")
OnExit("exit")

iconDir := A_Temp "\anfTaskbarIcons\"
DirCreate(iconDir)
;Prevent Rainmeter from taking focus
WinSetExStyle(+0x8000080, "i)\Q" SkinDir "\taskbar.ini ahk_class RainmeterMeterWindow ahk_exe Rainmeter.exe\E")
WinMoveTop()
WinSetAlwaysOnTop(1)

;Hide taskbar
WinHide "ahk_class Shell_TrayWnd"
WinHide "Start ahk_class Button"

selectedTask := ""
ActiveHwnd := ""
taskList := []
lastTasks := []
;flashingIds := Map()
;DllCall("RegisterShellHookWindow", "Ptr", A_ScripthWnd)
;OnMessage(DllCall("RegisterWindowMessage", "Str", "SHELLHOOK"), "ShellMessage")
;lastWindows := WinGetList(,, "Program Manager")

Loop 50
{
	sendBang("!SetOption " A_Index " Text `"`"")
	sendBang("!SetOption " A_Index " ToolTipTitle `"`"")
	sendBang("!SetOption " A_Index " ToolTipText `"`"")
	sendBang("!SetOption " A_Index " Group `"Task|TextAuto|Hide`"")
}

if (A_IsCompiled)
{
	WinSetTitle(A_ScriptFullPath, "ahk_id " A_ScriptHwnd)
	sendBang("!SetOption AHK WindowName `"" A_ScriptFullPath "`"")
}
else
	sendBang("!SetOption AHK WindowName `"" A_ScriptFullPath " - AutoHotkey v" A_AhkVersion "`"")
sendBang("!UpdateMeasure `"AHK`"")

;SetTimer("updateWindows", 50)
SetTimer("power", 1000)
SetTimer("network", 1000)
;SetTimer("taskbarState", 50)

getWindows()

hover := 0
While WinExist("i)\Q" SkinDir "\taskbar.ini ahk_class RainmeterMeterWindow ahk_exe Rainmeter.exe\E")
{
	WinSetTransparent(0, "ahk_class Shell_TrayWnd")
	MouseGetPos(, mY)
	Width := 0
	Height := 0
	WinGetPos(,, Width, Height, "ahk_id " WinGetID("A"),, "NxDock|Program Manager|Task Switching|^$")
	if ((Width != A_ScreenWidth) | (Height != A_ScreenHeight))
	{
		if (mY = A_ScreenHeight - 1 && hover == 0)
		{
			hover := 1
			if ((Width != A_ScreenWidth) | (Height != A_ScreenHeight))
			{
				sendBang("!SetOptionGroup TextAuto Y 0")
				sendBang("!UpdateMeterGroup TextAuto")
				sendBang("!SetOptionGroup IconAuto Y 5")
				sendBang("!UpdateMeterGroup IconAuto")
				sendBang("!Redraw")
				;sendBang("!UnpauseMeasure MeasureSec")
				;sendBang("!UpdateMeasure MeasureSec")
				;sendBang("!Move 0 " A_ScreenHeight - 15)
			}
		}
		else if (mY < A_ScreenHeight - 16 && hover == 1)
		{
			hover := 0
			sendBang("!SetOptionGroup TextAuto Y 15")
			sendBang("!UpdateMeterGroup TextAuto")
			sendBang("!SetOptionGroup IconAuto Y 20")
			sendBang("!UpdateMeterGroup IconAuto")
			sendBang("!Redraw")
			;sendBang("!PauseMeasure MeasureSec")
			;sendBang("!Hide")
			;sendBang("!Move 0 " A_ScreenHeight)
		}
		sendBang("!Show")
	}
	else
		sendBang("!Hide")
	Sleep 100
}
ExitApp

loadIconCache(iconDir)
{
	iconCache := []
	Loop Files, iconDir "*.bmp"
		iconCache.push(A_LoopFileName)
	return iconCache
}

loadColorCache(iconDir)
{
	colorCache := Map()
	colorArray := StrSplit(IniRead(iconDir "colors.ini", "iconColors"), "`n")
	Loop colorArray.Length
	{
		thisPair := StrSplit(colorArray[A_Index], "=")
		if (thisPair.Has(2))
			colorCache[thisPair[1]] := thisPair[2]
		else
			colorCache[thisPair[1]] := ""
	}
	return colorCache
}

getDominantIconColor(colorCache, taskExeName, hicon)
{
	Global iconDir
	dominantColor := ""
	if (!colorCache.Has(taskExeName))
	{
		dominantColor := Gdip_Getavg(Gdip_CreateBitmapFromHICON(hicon)) ",128"
		IniWrite dominantColor, iconDir "colors.ini", "iconColors", taskExeName
	}
	else
		dominantColor := colorCache[taskExeName]
	return dominantColor
}

sortWindows(wParam, lParam, *)
{
	if (wParam = 0)
		DllCall("CascadeWindows", "UInt",0, "Int",4, "Int",0, "Int",0, "Int",0)
	else if (wParam = 1)
		DllCall("TileWindows", "UInt",0, "Int",0, "Int",0, "Int",0, "Int",0)
	else if (wParam = 2)
		DllCall("TileWindows", "UInt",0, "Int",1, "Int",0, "Int",0, "Int",0)
}

taskItemMenu(wParam, lParam, *)
{
	Global taskList
	Global selectedTask := taskList[wParam]
	menuTaskItem := MenuCreate()
	menuTaskItem.Add "Close", "taskManage"
	menuTaskItem.Add
	menuTaskItem.Add "Minimize", "taskManage"
	menuTaskItem.Add "Maximize", "taskManage"
	menuTaskItem.Add
	menuTaskItem.Add "Properties", "taskManage"
	menuTaskItem.Show
}

taskSwitch(wParam, lParam, *)
{ 
	Global taskList
	IDVar := taskList[wParam]
	minMax := WinGetMinMax("ahk_id " IDVar)
	Global ActiveHwnd
	if (minMax < 0)
	{
		WinActivate("ahk_id " IDVar)
		ActiveHwnd := IDVar
		return
	}
	else if (ActiveHwnd = IDVar)
		WinMinimize("ahk_id " IDVar)
	else
	{
		WinActivate("ahk_id " IDVar)
		ActiveHwnd := IDVar
	}
}

taskManage(wParam, lParam, *)
{
	Global taskList
	Global selectedTask
	if (wParam = "minimize")
		WinMinimize("ahk_id " selectedTask)
	else if (wParam = "maximize")
		WinMaximize("ahk_id " selectedTask)
	else if (wParam = "properties")
		Run("properties " WinGetProcessPath("ahk_id " selectedTask))
	else if (wParam = "close")
		WinClose("ahk_id " selectedTask)
}

taskControl(wParam, lParam, *)
{
	Global taskList
	try task := taskList[wParam]
	if (task)
	{
		if (lParam = 1)
		{
			if !(WinActive("ahk_id " task))
				WinActivate("ahk_id " task)
			else if (WinGetMinMax("ahk_id " task) = -1)
			{
				WinRestore("ahk_id " task)
				WinActivate("ahk_id " task)
				;WinRedraw("ahk_id " task)
				;WinHide("ahk_id " task)
				;WinShow("ahk_id " task)
			}
			else
				WinMinimize("ahk_id " task)
		}
		else if (lParam = 2)
		{
			if (WinGetMinMax("ahk_id " task))
			{
				WinRestore("ahk_id " task)
				WinActivate("ahk_id " task)
				;WinRedraw("ahk_id " task)
				;WinHide("ahk_id " task)
				;WinShow("ahk_id " task)
			}
			else
			{
				WinMaximize("ahk_id " task)
				WinActivate("ahk_id " task)
				;WinRedraw("ahk_id " task)
				;WinHide("ahk_id " task)
				;WinShow("ahk_id " task)
			}
		}
		else if (lParam = 3)
			WinClose("ahk_id " task)
	}
}

getIconHandle(taskExePath){
	VarSetCapacity(fileInfo, fileSize := A_PtrSize + 688)
	if DllCall("shell32\SHGetFileInfoW", "WStr", taskExePath, "UInt", 0, "Ptr", &fileInfo, "UInt", fileSize, "UInt", 0x100)
		return NumGet(fileInfo, 0, "Ptr")
}

getWindows(*)
{
	Global lastTasks
	Global taskList
	Global iconDir
	;Global flashingIds
	iconCache := loadIconCache(iconDir)
	colorCache := loadColorCache(iconDir)
	DetectHiddenWindows(0)
	id := WinGetList(,, "NxDock|Program Manager|Task Switching|^$")
	DetectHiddenWindows(1)
	activeTask := ""
	activeID := WinGetID("A")
	flashingTasks := Map()
	lastTask := ""
	WindowArray := []
	Loop id.Length
	{
		thisId := id[A_Index]
		WinGetPos(,,, Height,"ahk_id " thisId)
		thisStyle := WinGetExStyle("ahk_id " thisId)
		if (thisStyle is "integer")
			if ((thisStyle & 0x00000080) || !Height || WinGetTitle("ahk_id " thisId) = "VirtualDesktopSwitcher" || IsWindowCloaked(thisId))
				continue
		sortString := sortString WinGetProcessName("ahk_id " thisId) ":" thisId ","
	}
	sortArray := StrSplit(Sort(sortString,"D,"),",")
	Loop sortArray.Length{
		thisId := StrSplit(sortArray[A_Index],":")
		if (thisId.Length != 0)
			if (thisId[(thisId.Length)])
				windowArray.push(thisId[(thisId.Length)])
	}
	taskList := windowArray
	;if a window closes during loop, don't throw an error
	Try Loop taskList.Length
	{
		thisId := taskList[A_Index]
		thisTitle := WinGetTitle("ahk_id " thisId)
		;thisStyle := WinGetStyle("ahk_id " thisId)
		;thisExStyle := WinGetExStyle("ahk_id " thisId)
		;if (!(thisStyle & 0x80000000) && !(thisStyle & 0x40000000) && !(thisStyle & 0x80000) && !(thisExStyle & 0x100) && !(thisExStyle & 0x80) && (thisStyle & 0xC00000))
		;{
		;	WinSetStyle(-0xC00000, "ahk_id " thisId)
		;	;WinRedraw("ahk_id " thisId)
		;	;WinHide("ahk_id " thisId)
		;	;WinShow("ahk_id " thisId)
		;}
		SplitPath WinGetProcessPath("ahk_id " thisId), OutFileName, OutDir, OutExtension, OutNameNoExt
		hicon := getIconHandle(WinGetProcessPath("ahk_id " thisId))
		dominantColor := getDominantIconColor(colorCache, OutNameNoExt, hicon)
		if (!hasValue(iconCache, OutNameNoExt ".bmp"))
			SaveHICONtoFile(hicon, iconDir OutNameNoExt ".bmp")
		;if (flashingIds.Has(thisId))
		;{
		;	if (flashingIds.Has(activeID))
		;	{
		;		flashingIds.Delete(activeId)
		;		sendBang("!SetOption " A_Index " SolidColor `"00000001`"")
		;	}
		;	else
		;	{
		;		flashingTasks[A_Index] := ""
		;		sendBang("!SetOption " A_Index " SolidColor `"ff00ffff`"")
		;	}
		;}
		if (thisId = activeID)
		{
			activeTask := A_Index
			activeColor := dominantColor
		}
		if (OutNameNoExt = "ApplicationFrameHost")
			OutNameNoExt := thisTitle
		sendBang("!SetOption " A_Index " Text `"`"`"" OutNameNoExt "`"`"`"")
		sendBang("!SetOption " A_Index " X `"1R`"")
		sendBang("!SetOption " A_Index " ToolTipText `"`"`"" thisTitle "`"`"`"")
		sendBang("!SetOption " A_Index " Group `"Task|TextAuto|Show`"")
		lastTask := OutNameNoExt
	}
	Try if (lastTasks.Length > taskList.Length)
	{
		Loop (lastTasks.Length - taskList.Length)
		{
			sendBang("!SetOption " (A_Index + taskList.Length) " Text `"`"")
			sendBang("!SetOption " (A_Index + taskList.Length) " X `"R`"")
			sendBang("!SetOption " (A_Index + taskList.Length) " ToolTipText `"`"")
			sendBang("!SetOption " (A_Index + taskList.Length) " Group `"Task|TextAuto|Hide`"")
		}
	}
	sendBang("!UpdateMeterGroup Task")
	sendBang("!ShowMeterGroup Show")
	sendBang("!HideMeterGroup Hide")
	if (activeTask)
	{
		if (activeID)
		{
			sendBang("!SetVariable domcol `"" activeColor "`"")
			sendBang("!SetOption TaskIndicator X `"[" activeTask ":X]`"")
			sendBang("!SetOption TaskIndicator W `"[" activeTask ":W]`"")
		}
		else
			sendBang("!SetOption TaskIndicator W `"0`"")
	}
	else
		sendBang("!SetOption TaskIndicator W `"0`"")
	sendBang("!UpdateMeter TaskIndicator")
	sendBang("!UpdateMeter BG")
	sendBang("!Redraw")
	lastTasks := taskList
}

;ShellMessage(wParam, lParam, *)
;{
;	Global flashingIds
;	if (wParam = 32776)
;	{
;		flashingIds[lParam] := ""
;		getWindows()
;	}
;}

;updateWindows()
;{
;	Global curWindows
;	Global lastWindows
;	Global lastActive
;	Global traySwitch
;	curWindows := WinGetList(,, "Program Manager")
;	updateSwitch := 0
;	if (hasKeyArray(curWindows,lastWindows))
;	{
;		lastWindows := curWindows
;		updateSwitch := 1
;	}
;	if (lastActive != WinExist("A",,RainmeterMeterWindow))
;	{
;		lastActive := WinExist("A",,RainmeterMeterWindow)
;		updateSwitch := 1
;	}
;	if (updateSwitch = 1)
;		getWindows()
;}

;taskbarState()
;{
;	Global windowMax
;	Global windowFull
;	program := WinGetList(,, "Program Manager")
;	activeMax := 0
;	activeFull := 0
;	Loop program.Length
;	{
;		if (WinGetMinMax("ahk_id " program[A_Index]) = 1)
;			activeMax := 1
;		WinGetPos(,, w, h, "A")
;		wwwh := w . h
;		swsh := a_screenwidth . a_screenheight
;		Style := WinGetStyle("ahk_id " program[A_Index])
;		c := WinGetClass(Style)
;		if (WinGetTitle("A") = DllCall("GetDesktopWindow") or (c = "Progman") or (c = "WorkerW") or (Style = ""))
;			break
;		if !(Style & 0xC00000)
;			if (wwwh = swsh)
;				activeFull := 1
;	}
;}
