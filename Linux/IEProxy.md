用批处理自动设置IE代理 &用批处理自动设置IE代理 (2010-01-19 09:06:47)
标签： 杂谈	分类： Work
在IE浏览器中，没有好用的代理切换插件，每次设置都很麻烦，切换来 切换去的。
但可以自己写一个bat文件来自动设置代理：
代码：
@echo off
title 自动设置代理服务器
echo 自动设置代理服务器
echo 需要以普通用户权限、管理员权限各运行本程序一次
rem echo 正在清空代理服务器设置……
rem reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyEnable /t REG_DWORD /d 0 /f
rem reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyServer /d "" /f
rem reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyOverride /t REG_SZ /d 0 /f
rem echo 代理服务器设置已经清空
echo 正在设置代理服务器……
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyEnable /t REG_DWORD /d 1 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyServer /d "61.155.158.67:62000" /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyOverride /t REG_SZ /d "" /f
echo 正在刷新设置……
ipconfig /flushdns
echo 显示新的设置：
ipconfig /all
echo 正在关闭浏览器：
taskkill /f /t /im IEXPLORE.exe
echo 正在开启浏览器
"C:\Program Files\Internet Explorer\IEXPLORE.EXE"
保存为.bat文件即可。
也可以先将bat文件转换成exe文件，然后在通过如下操作将设置代理小功能放到ie工具栏中：
然后单击“开始→运行”命令，并在其对话框中输入“gpedit.msc”命令，打开“组策略编辑器”。在左侧窗口中依次展开“用户配置 →Windows 设置→Internet Explorer维护→浏览器用户界面”分支，接着在右侧窗口中双击“浏览器工具栏自定义”，并在弹出的窗口中单击“添加”按钮进入“浏览器工具栏按钮信 息”对话框，在“工具栏标题（必需）”处输入按钮在IE工具栏上显示的文字，在“工具栏操作（必需）”处点击“浏览”按钮找到记事本程序所在的路径（如 C：＼Windows＼Notepad.exe），在“工具栏颜色图标（必需）”和“工具栏灰度图标（必需）”处分别输入按钮在IE工具栏上显示的颜色图 标和灰度图标文件的完整路径，这两个图标可以相同。最后把“默认情况下，该按钮应显示在工具栏上”复选框选上即可。
##################################################################################
网卡&IE代理设置批处理[.bat]
2007-12-24 11:01
//网上找的,没用过,只当学习
@echo off
color 1f
title "网卡&IE代理设置批处理 v1.0 - By xxxx"
echo.
echo.                   ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
echo.                   ☆                          ☆
echo.                   ☆                          ☆
echo.                   ☆                          ☆
echo.                   ☆                          ☆
echo.                   ☆                          ☆
echo.                   ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
echo.
echo.
echo              实现功能包括切换xxx校园网和外网,设置IE代理.
echo.
echo.
goto bensla~
:bensla~
echo.
echo 请选择: 1切换到校园网, 2切换到外网.
set /p choice=请输入相应数字后回车:
if /i "%choice%" == "1" goto szunet
if /i "%choice%" == "2" goto adsl
goto bensla~
:adsl
cls
color 1f
netsh interface ip set address name="本地连接" source=dhcp
netsh interface ip set dns name="本地连接" source=dhcp
cls
goto noproxy
:noproxy
@echo    Windows Registry Editor Version 5.00>>1.reg
@echo    [HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings]>>1.reg
@echo    "ProxyEnable"=dword:00000000>>1.reg
@echo    "ProxyServer"="">>1.reg
@echo    "ProxyOverride"="">>1.reg
regedit /s 1.reg
del 1.reg
goto exit
:szunet
cls
color 1f
echo.
set /p choice=输入" N "后回车跳过网卡设置, 直接回车继续网卡设置:
if /i "%choice%" == "N" goto proxy
cls
echo.
echo 注意,本批处理命令仅对名称为"本地连接"的网卡进行设置,
echo.
echo 这一段是对Cfans所写的批处理的改进,特此感谢!
echo.
set /p var1=请输入您校园网IP的第三段内容(如192.168.110.216中的110):
echo.
set /p var2=请输入您校园网IP的第四段内容(如192.168.110.216中的216):
echo.
echo.准备设置ip地址为192.168.%var1%.%var2%
netsh interface ip set address name="本地连接" source=static addr=192.168.%var1%.%var2% mask=255.255.255.0
echo.准备设置网关为192.168.%var1%.33
netsh interface ip set address name="本地连接" gateway=192.168.%var1%.33 gwmetric=0
echo.准备设置主DNS为210.39.0.33
netsh interface ip set dns name="本地连接" source=static addr=210.39.0.33 register=PRIMARY
echo.准备设置从DNS为210.39.0.34
netsh interface ip add dns name="本地连接" addr=210.39.0.34 index=2
netsh interface ip set wins name="本地连接" source=static addr=none
goto proxy
:proxy
cls
color 1f
echo.
echo 请选择: 1使用学校代理, 2使用自己开的代理, 3使用别人开的代理, 4清空IE代理.
echo.
set /p choice=请输入相应数字回车继续, 直接回车退出:
if /i "%choice%" == "1" goto szuproxy
if /i "%choice%" == "2" goto localproxy
if /i "%choice%" == "3" goto internet
if /i "%choice%" == "4" goto noproxy
goto exit
:internet
cls
color 1f
echo.
set /p var=请输入代理后回车(格式如192.168.113.20:9222):
@echo    Windows Registry Editor Version 5.00>>1.reg
@echo    [HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings]>>1.reg
@echo    "ProxyEnable"=dword:00000001>>1.reg
@echo    "ProxyServer"="%var%">>1.reg
@echo    "ProxyOverride"="*.szu.edu.cn;210.39.*.*;192.168.*.*;<local>">>1.reg
regedit /s 1.reg
del 1.reg
goto exit
:localproxy
cls
color 1f
echo.
set /p var=请输入自己开的HTTP代理的端口:
@echo    Windows Registry Editor Version 5.00>>1.reg
@echo    [HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings]>>1.reg
@echo    "ProxyEnable"=dword:00000001>>1.reg
@echo    "ProxyServer"="127.0.0.1:%var%">>1.reg
@echo    "ProxyOverride"="*.szu.edu.cn;210.39.*.*;192.168.*.*;<local>">>1.reg
regedit /s 1.reg
del 1.reg
goto exit
:szuproxy
cls
color 1f
@echo    Windows Registry Editor Version 5.00>>1.reg
@echo    [HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings]>>1.reg
@echo    "ProxyEnable"=dword:00000001>>1.reg
@echo    "ProxyServer"="proxy.szu.edu.cn:8080">>1.reg
@echo    "ProxyOverride"="*.szu.edu.cn;210.39.*.*;192.168.*.*;<local>">>1.reg
regedit /s 1.reg
del 1.reg
goto exit
:exit
cls
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo                           恭喜!已完成所有设置.
echo.
echo                           水平有限,请多指教! ~
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
pause
exit
##################################################################################
批处理自动设置ie代理IP
@echo off
setlocal enabledelayedexpansion
::3c标 01计数器 03(01)是(否)启用代理 FF行偏移量&h10(ip+prot字符串长度,变量cs)
set "head=3C0000000100000003000000FF000000"
set "regp="HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Connections""
set ip=1.1.1.1:80
::上边设置代理IP与端口
set name=宽带连接
::上边设置宽带连接名称
call :binary 0
reg add %regp% /v %name% /t REG_BINARY /d %head%%hex% /f
pause
goto :eof
:binary
set var=!ip:~%cs%,1!||set hex=%hex:.=2E%&& set hex=!hex::=3A!&&goto :eof
if %var%. GEQ 0 set /a var+=30
set hex=%hex%%var%
set /a cs+=1
call :binary %cs%
goto :eof
##################################################################################
@rem 运行此批处理*****【如果添加了代理就删除,反之没有代理就添加代理】*****
@echo off
title 添加／删除IE代理 &&MODE con COLS=30 LINES=3 &color 2e
setlocal ENABLEDELAYEDEXPANSION
@set uu=“HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings“
@for /f “skip=3 tokens=3“ %%i in (‘reg query %uu% /v ProxyEnable‘) do (if “%%i“==“0x0“ (goto sset) else (goto ddel))
:sset
setlocal ENABLEDELAYEDEXPANSION
set uu=“HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings“
reg add %uu% /v ProxyServer /t REG_SZ /d “192.168.1.4:8090“ /f &gt;nul
reg add %uu% /v ProxyOverride /t REG_SZ /d “&lt;local&gt;“ /f &gt;nul
reg add %uu% /v ProxyEnable /t REG_DWORD /d “1“ /f &gt;nul
echo.&echo 添加了代理 &ping -n 2 127.1 &gt;nul &&goto :eof
:ddel
setlocal ENABLEDELAYEDEXPANSION
set uu=“HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings“
reg delete %uu% /v ProxyServer /f &gt;nul
reg delete %uu% /v ProxyOverride /f &gt;nul
reg add %uu% /v ProxyEnable /t REG_DWORD /d “0“ /f &gt;nul
echo.&echo 删除了代理 &ping -n 2 127.1 &gt;nul &&goto :eof