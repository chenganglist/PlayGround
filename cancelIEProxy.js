Set oShell = CreateObject("WScript.Shell")
oShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings\ProxyEnable", "00000000", "REG_DWORD"
