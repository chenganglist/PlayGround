Set oShell = CreateObject("WScript.Shell")

oShell.RegWrite "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings\ProxyServer",  "127.0.0.1:1080","REG_SZ"



