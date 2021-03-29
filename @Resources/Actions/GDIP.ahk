Gdip_Startup()
{
	Ptr := A_PtrSize ? "UPtr" : "UInt"
	pToken := 0
	if !DllCall("GetModuleHandle", "str", "gdiplus", Ptr)
		DllCall("LoadLibrary", "str", "gdiplus")
	VarSetCapacity(si, A_PtrSize = 8 ? 24 : 16, 0), si := Chr(1)
	DllCall("gdiplus\GdiplusStartup", A_PtrSize ? "UPtr*" : "uint*", pToken, Ptr, &si, Ptr, 0)
	return pToken
}

Gdip_Shutdown(pToken)
{
	Ptr := A_PtrSize ? "UPtr" : "UInt"
	
	DllCall("gdiplus\GdiplusShutdown", Ptr, pToken)
	if hModule := DllCall("GetModuleHandle", "str", "gdiplus", Ptr)
		DllCall("FreeLibrary", Ptr, hModule)
	return 0
}

If !pToken := Gdip_Startup()
{
	MsgBox "Gdiplus failed to start. Please ensure you have gdiplus on your system"
	ExitApp
}

Gdip_CreateBitmapFromHICON(hIcon)
{
	pBitmap := 0
	DllCall("gdiplus\GdipCreateBitmapFromHICON", A_PtrSize ? "UPtr" : "UInt", hIcon, A_PtrSize ? "UPtr*" : "uint*", pBitmap)
	return pBitmap
}

Gdip_SaveBitmapToFile(pBitmap, sOutput)
{
	nCount := 0
	nSize := 0
	SplitPath sOutput,,, Extension
	Extension := "." Extension
	DllCall("gdiplus\GdipGetImageEncodersSize", "uint*", nCount, "uint*", nSize)
	VarSetCapacity(ci, nSize)
	DllCall("gdiplus\GdipGetImageEncoders", "uint", nCount, "uint", nSize, "uint", &ci)
	if !(nCount && nSize)
		return -2
	If (A_IsUnicode)
	{
		StrGet_Name := "StrGet"
		Loop nCount
		{
			sString := %StrGet_Name%(NumGet(ci, (idx := (48+7*A_PtrSize)*(A_Index-1))+32+3*A_PtrSize), "UTF-16")
			if !InStr(sString, "*" Extension)
				continue
			pCodec := &ci+idx
			break
		}
	}
	else
	{
		Loop nCount
		{
			Location := NumGet(ci, 76*(A_Index-1)+44)
			nSize := DllCall("WideCharToMultiByte", "uint", 0, "uint", 0, "uint", Location, "int", -1, "uint", 0, "int",  0, "uint", 0, "uint", 0)
			VarSetCapacity(sString, nSize)
			DllCall("WideCharToMultiByte", "uint", 0, "uint", 0, "uint", Location, "int", -1, "str", sString, "int", nSize, "uint", 0, "uint", 0)
			if !InStr(sString, "*" Extension)
				continue
			pCodec := &ci+76*(A_Index-1)
			break
		}
	}
	if !pCodec
		return -3
	if !A_IsUnicode
	{
		nSize := DllCall("MultiByteToWideChar", "uint", 0, "uint", 0, "uint", &sOutput, "int", -1, "uint", 0, "int", 0)
		VarSetCapacity(wOutput, nSize*2)
		DllCall("MultiByteToWideChar", "uint", 0, "uint", 0, "uint", &sOutput, "int", -1, "uint", &wOutput, "int", nSize)
		VarSetCapacity(wOutput, -1)
		if !VarSetCapacity(wOutput)
			return -4
		E := DllCall("gdiplus\GdipSaveImageToFile", "uint", pBitmap, "uint", &wOutput, "uint", pCodec, "uint", p ? p : 0)
	}
	else
		E := DllCall("gdiplus\GdipSaveImageToFile", "uint", pBitmap, "uint", &sOutput, "uint", pCodec, "uint", p ? p : 0)
	return E ? -5 : 0
}

Gdip_GetPixels(pBitmap, size:=16)
{
	ARGB := 0
	x:=0
	pixelString := ""
	while x < size
	{
		y:=0
		while y < size
		{
			DllCall("gdiplus\GdipBitmapGetPixel", A_PtrSize ? "UPtr" : "UInt", pBitmap, "int", x, "int", y, "uint*", ARGB)
			y+=1
			if(ARGB)
				pixelString := pixelString ARGB
		}
		x+=1
	}
	return pixelString
}

Gdip_RGBA(ARGB)
{
	return [(0x00ff0000 & ARGB) >> 16,(0x0000ff00 & ARGB) >> 8,0x000000ff & ARGB,(0xff000000 & ARGB) >> 24]
}

Gdip_AFromARGB(ARGB)
{
	return (0xff000000 & ARGB) >> 24
}

Gdip_RFromARGB(ARGB)
{
	return (0x00ff0000 & ARGB) >> 16
}

Gdip_GFromARGB(ARGB)
{
	return (0x0000ff00 & ARGB) >> 8
}

Gdip_BFromARGB(ARGB)
{
	return 0x000000ff & ARGB
}

Gdip_GetAvg(pBitmap, size:=16)
{
	ARGB := 0
	x:=0
	rTop := ""
	gTop := ""
	bTop := ""
	dominantLevel := ""
	dominantRGB := ""
	while x < size
	{
		y:=0
		while y < size
		{
			DllCall("gdiplus\GdipBitmapGetPixel", A_PtrSize ? "UPtr" : "UInt", pBitmap, "int", x, "int", y, "uint*", ARGB)
			y+=4
			if(ARGB)
			{
				rgbchans := Gdip_RGBA(ARGB)
				rgblevel := ( rgbchans[1] + rgbchans[2] + rgbchans[3])
				if(rgblevel < 650)
					if(rgblevel > dominantLevel)
					{
						dominantLevel := rgblevel
						dominantRGB := rgbchans[1] "," rgbchans[2] "," rgbchans[3]
					}
			}
		}
		x+=4
	}
	if(!dominantRGB)
		dominantRGB := "200,200,200"
	return dominantRGB
}

SaveHICONtoFile(hicon, iconFile)
{
	Gdip_SaveBitmapToFile(Gdip_CreateBitmapFromHICON(hicon), iconFile)
}

extractIconFromExe(FileName)
{
	ptr := A_PtrSize=8?"ptr":"uint" 
	hIcon := DllCall("Shell32\ExtractAssociatedIcon" (A_IsUnicode ? "W" : "A"), ptr, DllCall("GetModuleHandle", ptr, 0, ptr), "Str", FileName, "ushort*", lpiIcon, ptr) ;only supports 32x32
	return hIcon
}
 
MD5(string, caseUpper := False)
{
	static MD5_DIGEST_LENGTH := 16
	hModule := DllCall("LoadLibrary", "Str", "advapi32.dll", "Ptr")
	, MD5_CTX := BufferAlloc(104), DllCall("advapi32\MD5Init", "Ptr", MD5_CTX)
	, DllCall("advapi32\MD5Update", "Ptr", MD5_CTX, "AStr", string, "UInt", StrLen(string))
	, DllCall("advapi32\MD5Final", "Ptr", MD5_CTX)
	loop (MD5_DIGEST_LENGTH)
	{ 
		 o .= Format("{:02" (caseUpper?"X":"x") "}", NumGet(MD5_CTX, 87 + A_Index, "UChar"))
	}
	DllCall("FreeLibrary", "Ptr", hModule)
	return o
}

SplitRGBColor(RGBColor, NoAlpha := false)
{
	BaseHex := SubStr(RGBColor, 3)
	Red := Format("{:i}", "0x" SubStr(BaseHex, 1,2))
	Green := Format("{:i}", "0x" SubStr(BaseHex, 3,2))
	Blue := Format("{:i}", "0x" SubStr(BaseHex, 5,2))
	if(NoAlpha)
		Return Red "," Green "," Blue
	else
		Return Red "," Green "," Blue ",255"
}

HexToDecimal(RGBColor)
{
	BaseHex := SubStr(RGBColor, 3)
	Red := Format("{:i}", "0x" SubStr(BaseHex, 1,2))
	Green := Format("{:i}", "0x" SubStr(BaseHex, 3,2))
	Blue := Format("{:i}", "0x" SubStr(BaseHex, 5,2))
	Return Red + Green + Blue
}

GetRgbChannels(RGBColor, NoAlpha := false)
{
	BaseHex := SubStr(RGBColor, 3)
	Red := Format("{:i}", "0x" SubStr(BaseHex, 1,2))
	Green := Format("{:i}", "0x" SubStr(BaseHex, 3,2))
	Blue := Format("{:i}", "0x" SubStr(BaseHex, 5,2))
	if(NoAlpha)
		Return [Red,Green,Blue]
	else
		Return [Red,Green,Blue,"255"]
}