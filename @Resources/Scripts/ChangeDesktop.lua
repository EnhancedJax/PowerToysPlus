function Initialize()
	maximumDesktop = tonumber(SKIN:GetVariable('Maximum_Desktop'))
	SKIN:Bang('!CommandMeasure GetDesktopVariable "Run"')
end
oldCurrentDesktop = -1
changingDesktop = false
function Update()
	totalDesktop = tonumber(SKIN:GetVariable('Desktop_Total',-1))
	currentDesktop = tonumber(SKIN:GetVariable('Desktop_Current',-1))
	if not totalDesktop or not currentDesktop then
		SKIN:Bang('!HideMeterGroup', 'DesktopChanger_All')
		SKIN:Bang('!ShowMeter', 'DesktopError')
		return
	end
	for i = 1, maximumDesktop do
		SKIN:Bang('!ShowMeter', 'Desktop'..i)
		SKIN:Bang('!ShowMeter', 'Text'..i)
		if i <= totalDesktop then
			SKIN:Bang('!SetOption', 'Desktop'..i, 'LeftMouseUpAction', '!CommandMeasure DesktopWindowSendMessage "SendMessage 16687 2 '..i..'"') --Switch to Desktop
		else
			SKIN:Bang('!SetOption', 'Desktop'..i, 'LeftMouseUpAction', string.rep('[!CommandMeasure DesktopWindowSendMessage "SendMessage 16687 3 1"]',i-totalDesktop)) --Create new Desktop
		end
	end
	if oldCurrentDesktop ~= currentDesktop and not changingDesktop then
		changingDesktop = true
	end
end
