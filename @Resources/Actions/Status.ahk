VarSetCapacity(powerstatus, 1+1+1+1+4+4)
DllCall("LoadLibrary", "Str", "kernel32.dll", "Ptr")
power()
{
	Global powerstatus
	DllCall("kernel32\GetSystemPowerStatus", "uint", &powerstatus)
	sendBang("!SetOption acLineStatus Formula `"" ReadInteger(&powerstatus,0,1) "`"")
	sendBang("!SetOption batteryFlag Formula `"" ReadInteger(&powerstatus,1,1) "`"")
	sendBang("!SetOption batteryLifePercent Formula `"" ReadInteger(&powerstatus,2,1) "`"")
	sendBang("!SetOption SystemStatusFlag Formula `"" ReadInteger(&powerstatus,3,1) "`"")
	sendBang("!SetOption batteryLifeTime Formula `"" ReadInteger(&powerstatus,4,4) "`"")
	sendBang("!SetOption batteryFullLifeTime Formula `"" ReadInteger(&powerstatus,8,4) "`"")
	sendBang("!UpdateMeasureGroup Status")
}

INetworkListManager := ComObjCreate("{DCB00C01-570F-4A9B-8D69-199FDBA5723B}", "{DCB00000-570F-4A9B-8D69-199FDBA5723B}")
vTable := NumGet(INetworkListManager + 0, "Ptr")
;hget_IsConnected := NumGet(vTable + 11 * A_PtrSize, "Ptr")
;hget_IsConnectedToInternet := NumGet(vTable + 12 * A_PtrSize, "Ptr")
hget_IsConnected := NumGet(vTable + 12 * A_PtrSize, "Ptr")
hget_IsConnectedToInternet := NumGet(vTable + 11 * A_PtrSize, "Ptr") ;It's backwards I guess?
bIsConnected := 0
bIsConnectedToInternet := 0
network()
{
	global INetworkListManager
	global hget_IsConnected
	global hget_IsConnectedToInternet
	global bIsConnected
	global bIsConnectedToInternet
	DllCall(hget_IsConnected, "Ptr", INetworkListManager, "UShort*", bIsConnected)
	DllCall(hget_IsConnectedToInternet, "Ptr", INetworkListManager, "UShort*", bIsConnectedToInternet)
	sendBang("!SetOption IsConnected Formula `"" bIsConnected "`"")
	sendBang("!SetOption IsConnectedToInternet Formula `"" bIsConnectedToInternet "`"")
	sendBang("!UpdateMeasureGroup Status")
}
