���������Զ�����IE���� &���������Զ�����IE���� (2010-01-19 09:06:47)
��ǩ�� ��̸	���ࣺ Work
��IE������У�û�к��õĴ����л������ÿ�����ö����鷳���л��� �л�ȥ�ġ�
�������Լ�дһ��bat�ļ����Զ����ô���
���룺
@echo off
title �Զ����ô��������
echo �Զ����ô��������
echo ��Ҫ����ͨ�û�Ȩ�ޡ�����ԱȨ�޸����б�����һ��
rem echo ������մ�����������á���
rem reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyEnable /t REG_DWORD /d 0 /f
rem reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyServer /d "" /f
rem reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyOverride /t REG_SZ /d 0 /f
rem echo ��������������Ѿ����
echo �������ô������������
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyEnable /t REG_DWORD /d 1 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyServer /d "61.155.158.67:62000" /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyOverride /t REG_SZ /d "" /f
echo ����ˢ�����á���
ipconfig /flushdns
echo ��ʾ�µ����ã�
ipconfig /all
echo ���ڹر��������
taskkill /f /t /im IEXPLORE.exe
echo ���ڿ��������
"C:\Program Files\Internet Explorer\IEXPLORE.EXE"
����Ϊ.bat�ļ����ɡ�
Ҳ�����Ƚ�bat�ļ�ת����exe�ļ���Ȼ����ͨ�����²��������ô���С���ܷŵ�ie�������У�
Ȼ�󵥻�����ʼ�����С����������Ի��������롰gpedit.msc������򿪡�����Ա༭����������ര��������չ�����û����� ��Windows ���á�Internet Explorerά����������û����桱��֧���������Ҳര����˫����������������Զ��塱�����ڵ����Ĵ����е�������ӡ���ť���롰�������������ť�� Ϣ���Ի����ڡ����������⣨���裩�������밴ť��IE����������ʾ�����֣��ڡ����������������裩����������������ť�ҵ����±��������ڵ�·������ C����Windows��Notepad.exe�����ڡ���������ɫͼ�꣨���裩���͡��������Ҷ�ͼ�꣨���裩�����ֱ����밴ť��IE����������ʾ����ɫͼ ��ͻҶ�ͼ���ļ�������·����������ͼ�������ͬ�����ѡ�Ĭ������£��ð�ťӦ��ʾ�ڹ������ϡ���ѡ��ѡ�ϼ��ɡ�
##################################################################################
����&IE��������������[.bat]
2007-12-24 11:01
//�����ҵ�,û�ù�,ֻ��ѧϰ
@echo off
color 1f
title "����&IE�������������� v1.0 - By xxxx"
echo.
echo.                   ����������������
echo.                   ��                          ��
echo.                   ��                          ��
echo.                   ��                          ��
echo.                   ��                          ��
echo.                   ��                          ��
echo.                   ����������������
echo.
echo.
echo              ʵ�ֹ��ܰ����л�xxxУ԰��������,����IE����.
echo.
echo.
goto bensla~
:bensla~
echo.
echo ��ѡ��: 1�л���У԰��, 2�л�������.
set /p choice=��������Ӧ���ֺ�س�:
if /i "%choice%" == "1" goto szunet
if /i "%choice%" == "2" goto adsl
goto bensla~
:adsl
cls
color 1f
netsh interface ip set address name="��������" source=dhcp
netsh interface ip set dns name="��������" source=dhcp
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
set /p choice=����" N "��س�������������, ֱ�ӻس�������������:
if /i "%choice%" == "N" goto proxy
cls
echo.
echo ע��,�������������������Ϊ"��������"��������������,
echo.
echo ��һ���Ƕ�Cfans��д��������ĸĽ�,�ش˸�л!
echo.
set /p var1=��������У԰��IP�ĵ���������(��192.168.110.216�е�110):
echo.
set /p var2=��������У԰��IP�ĵ��Ķ�����(��192.168.110.216�е�216):
echo.
echo.׼������ip��ַΪ192.168.%var1%.%var2%
netsh interface ip set address name="��������" source=static addr=192.168.%var1%.%var2% mask=255.255.255.0
echo.׼����������Ϊ192.168.%var1%.33
netsh interface ip set address name="��������" gateway=192.168.%var1%.33 gwmetric=0
echo.׼��������DNSΪ210.39.0.33
netsh interface ip set dns name="��������" source=static addr=210.39.0.33 register=PRIMARY
echo.׼�����ô�DNSΪ210.39.0.34
netsh interface ip add dns name="��������" addr=210.39.0.34 index=2
netsh interface ip set wins name="��������" source=static addr=none
goto proxy
:proxy
cls
color 1f
echo.
echo ��ѡ��: 1ʹ��ѧУ����, 2ʹ���Լ����Ĵ���, 3ʹ�ñ��˿��Ĵ���, 4���IE����.
echo.
set /p choice=��������Ӧ���ֻس�����, ֱ�ӻس��˳�:
if /i "%choice%" == "1" goto szuproxy
if /i "%choice%" == "2" goto localproxy
if /i "%choice%" == "3" goto internet
if /i "%choice%" == "4" goto noproxy
goto exit
:internet
cls
color 1f
echo.
set /p var=����������س�(��ʽ��192.168.113.20:9222):
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
set /p var=�������Լ�����HTTP����Ķ˿�:
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
echo                           ��ϲ!�������������.
echo.
echo                           ˮƽ����,���ָ��! ~
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
�������Զ�����ie����IP
@echo off
setlocal enabledelayedexpansion
::3c�� 01������ 03(01)��(��)���ô��� FF��ƫ����&h10(ip+prot�ַ�������,����cs)
set "head=3C0000000100000003000000FF000000"
set "regp="HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Connections""
set ip=1.1.1.1:80
::�ϱ����ô���IP��˿�
set name=�������
::�ϱ����ÿ����������
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
@rem ���д�������*****���������˴����ɾ��,��֮û�д������Ӵ���*****
@echo off
title ��ӣ�ɾ��IE���� &&MODE con COLS=30 LINES=3 &color 2e
setlocal ENABLEDELAYEDEXPANSION
@set uu=��HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings��
@for /f ��skip=3 tokens=3�� %%i in (��reg query %uu% /v ProxyEnable��) do (if ��%%i��==��0x0�� (goto sset) else (goto ddel))
:sset
setlocal ENABLEDELAYEDEXPANSION
set uu=��HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings��
reg add %uu% /v ProxyServer /t REG_SZ /d ��192.168.1.4:8090�� /f &gt;nul
reg add %uu% /v ProxyOverride /t REG_SZ /d ��&lt;local&gt;�� /f &gt;nul
reg add %uu% /v ProxyEnable /t REG_DWORD /d ��1�� /f &gt;nul
echo.&echo ����˴��� &ping -n 2 127.1 &gt;nul &&goto :eof
:ddel
setlocal ENABLEDELAYEDEXPANSION
set uu=��HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings��
reg delete %uu% /v ProxyServer /f &gt;nul
reg delete %uu% /v ProxyOverride /f &gt;nul
reg add %uu% /v ProxyEnable /t REG_DWORD /d ��0�� /f &gt;nul
echo.&echo ɾ���˴��� &ping -n 2 127.1 &gt;nul &&goto :eof