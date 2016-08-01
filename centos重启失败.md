setparams 'centos linux'
 load_video
 set gfxpayload=keep
 insmod gzio
 insmod part_msdos
 insmod xfs
 set root='hd0,msdos1'

vmlinuz initrd=initrd.img inst.stage2=hd:/dev/sdc4 quiet

vmlinuz initrd=initrd.img linux dd quiet

这里注意了：网上很多文章都说这一步改成“>vmlinuz initrd=initrd.img inst.stage2=hd:/dev/sdb
quiet”什么的，然后失败了再cd
/dev命令查看U盘盘符啥的，别这样了，我就是在这里浪费了好多时间，把dev目录下的所有设备都试了几遍也没成功，主要是笔记本硬盘就有两个，再加上U盘，搞得我实在是不认识哪个设备是哪个啊。。。

所以这里我们直接将按TAB键之后出来的文字修改为：>vmlinuz initrd=initrd.img linux dd quiet。改好之后回车，然后就会列出你的设备列表了，在这个列表里面，不懂Linux的我都能很清楚的辨认哪个是我的U盘，不信你看下面这张图：

    vim /etc/default/grub 

    GRUB_TIMEOUT=0
    GRUB_DEFAULT=saved
    GRUB_DISABLE_SUBMENU=true
    GRUB_TERMINAL_OUTPUT="console"
    GRUB_CMDLINE_LINUX="rd.lvm.lv=centos/swap rd.lvm.lv=centos00/root rd.lvm.lv=centos00/swap rhgb quiet clocksource=tsc"
    GRUB_DISABLE_RECOVERY="true"


sudo grub2-mkconfig -o /boot/grub2/grub.cfg 
sudo reboot

grub无法引导ubuntu分区的解决方法
|浏览：911|更新：2014-05-21 09:56|标签：ubuntu 
最近在看grub的相关教程。

手贱在终端里输入了，

update-grub

grub-install /dev/sda

reboot

我都还没有搞明白是什么情况，重启电脑就进不去系统了。
黑底白字的显示

grub>

一下就愣了。

接下来的几天一直找方法和折腾中，如果没能挽救我的电脑，我最后肯定就重装了。

原因分析，这是因为grub没能找到正确的Ubuntu分区的原因，我们可以通过设置解决。

输入：ls

会显示分区
输入：set

显示现在的grub设置，我的显示了

prefix=(hd0,msdos1)/boot/grub

root=hd0,msdos1

显然不对，我的ubuntu分区在(hd0,msdos8)，这里主要还是看你自己的系统在哪个分区，不清楚可以一个个试。
输入：set prefix=(hd0,msdos8)/boot/grub

输入：set root=hd0,msdos8
再一次

输入：set

查看一下是不是设置好了。
显示

prefix=(hd0,msdos8)/boot/grub

root=hd0,msdos8

设置正确了。

输入：insmod normal
输入：normal

应该可以看到grub成功引导了。不要以为这样就完了，如果最后一步没做，重启后你就又要郁闷了。
输入：update-grub

输入：grub-install /dev/sda

更新grub，写入磁盘。

亲试，绝对没有问题，因为这个问题困扰了我三天了，终于解决了。爽。



Centos系统进入Grub应该如何解决听语音
|浏览：1690|更新：2015-07-15 16:37|标签：操作系统 
Centos系统进入Grub应该如何解决1Centos系统进入Grub应该如何解决2Centos系统进入Grub应该如何解决3Centos系统进入Grub应该如何解决4Centos系统进入Grub应该如何解决5Centos系统进入Grub应该如何解决6Centos系统进入Grub应该如何解决7
分步阅读
一些刚接触Linux的新手，对linux还是不太了解，在遇到系统启动后进入grub，不知道如何解决，一般都是重新安装操作系统，这不失为一个解决措施，但是前提得是我们没有需要备份的数据，要是有一大推重要的数据，重新安装系统会全部丢失呦，本文就介绍下如果遇到开机进入Grub应该如何修复。

方法/步骤
Grub是Linux系统默认使用的引导程序，当grub的配置文件丢失，或者配置出现错误，MBR记录中的引导程序遭到破坏时，Linux主机启动后可能只出现“grub>”的提示符，无法完成进一步的系统启动过程。如图所示：
Centos系统进入Grub应该如何解决
如果你不知道你的引导分区所在的位置，那么咱们只能输入root (hd0,然后按tab键，会有如下显示，那么咱们需要把type 0x83的分区位置都得试一下，因为0x83的分区都有可能是/root分区即0,1,4分区位置
Centos系统进入Grub应该如何解决
那么咱们就从root (hd0,0)开始试验，然后输入kernel /vm 按tab键如果可以补全则说明是正确的，接着输入 ro root=/dev/sda1,注意(hd0,0)=/dev/sda1 (hd0,1)=/dev/sda2如图
Centos系统进入Grub应该如何解决
接着输入initrd /ini 按tab键补全
Centos系统进入Grub应该如何解决
然后输入boot命令
Centos系统进入Grub应该如何解决
如果出现以下信息，说明选择的根分区不对，请重启继续。
Centos系统进入Grub应该如何解决
由于刚才写的内容都是暂时写入内存的，所以还需要重新写一遍。将root=/dev/sda1 改成root=/dev/sda2,然后输入boot
Centos系统进入Grub应该如何解决
接着就可以进入系统啦。
Centos系统进入Grub应该如何解决



