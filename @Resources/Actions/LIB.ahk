IsWindowCloaked(hwnd)
{
	cloaked := 0
	static gwa := DllCall("GetProcAddress", "ptr", DllCall("LoadLibrary", "str", "dwmapi", "ptr"), "astr", "DwmGetWindowAttribute", "ptr")
	return (gwa = 0 & DllCall(gwa, "ptr", hwnd, "int", 14, "int*", cloaked, "int", 4) = 0) ? cloaked : 0
}

SplitPath(A_ScriptDir,, SkinDir)
SplitPath(SkinDir, SkinName)

send_WM_COPYDATA(ByRef StringToSend, ByRef TargetWindow)
{
	VarSetCapacity(CopyDataStruct, 3*A_PtrSize, 0)
	SizeInBytes := (StrLen(StringToSend) + 1) * (A_IsUnicode ? 2 : 1)
	NumPut(1, CopyDataStruct)
	NumPut(SizeInBytes, CopyDataStruct, A_PtrSize)
	NumPut(&StringToSend, CopyDataStruct, 2*A_PtrSize)
	SendMessage(0x4a, 0, &CopyDataStruct,, TargetWindow)
	return ErrorLevel
}

sendBang(command)
{
	Global SkinName
	commandWrap := command " `"" SkinName "`""
	send_WM_COPYDATA(commandWrap, "i)\Q" SkinDir "\taskbar.ini ahk_class RainmeterMeterWindow ahk_exe Rainmeter.exe\E")
}

hasKeyArray(array1,array2)
{
	windows := Map()
	for each, hWND in array1
		windows[hWND] := ""
	for each, hWND in array2
	{
		if !(windows.Has(hWND))
			return true
		windows.Delete(hWND)
	}
	for each, hWND in windows
		return true
	return false
}

hasValue(haystack, needle) 
{
	if(!isObject(haystack))
		return false
	if(haystack.Length==0)
		return false
	for k,v in haystack
		if(v==needle)
			return true
	return false
}

exit(*)
{
	Global pToken
	Global iconDir
	DirDelete(iconDir, 1)
	Gdip_Shutdown(pToken)
	;DllCall("RegisterShellHookWindow", "Ptr", A_ScripthWnd)
	DetectHiddenWindows(1)
	WinShow "ahk_class Shell_TrayWnd"
	WinShow "Start ahk_class Button"
	WinSetTransparent(255, "ahk_class Shell_TrayWnd")
	WinSetTransparent(Off, "ahk_class Shell_TrayWnd")
	ExitApp
}

ReadInteger(p_address, p_offset, p_size)
{
	value := 0
	loop(p_size)
		value := value + (NumGet((p_address + p_offset) + (a_Index - 1),, "UChar") << (8 * (a_Index - 1)))
	return value
}
