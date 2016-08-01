setparams 'CentOS Linux, with Linux 3.10.0-123.el7.x86_64'

        load_video
        set gfxpayload=keep
        insmod gzio
        insmod part_msdos
        insmod xfs
        set root='hd0,msdos1'
        if [ x$feature_platform_search_hint = xy ]; then
          search --no-floppy --fs-uuid --set=root --hint-bios=hd0,msdos1 --hint-efi=hd0,msdos1 --hint-baremetal=ahci0,msdos1 --hint='hd0,msdos1'  7b5bff8d-06c0-4337-89c5-14288e6c1165
        else
          search --no-floppy --fs-uuid --set=root 7b5bff8d-06c0-4337-89c5-14288e6c1165
        fi
        linux16 /vmlinuz-3.10.0-123.el7.x86_64 root=UUID=a3eb8dec-8296-42d4-9e40-bc8a1e75a6d3 ro vconsole.keymap=jp106 rd.lvm.lv=centos_bravo/swap vconsole.font=latarcyrheb-sun16 rd.lvm.lv=centos_bravo/usr rd.lvm.lv=centos_bravo/root crashkernel=auto  rhgb  %quiet%
        initrd16 /initramfs-3.10.0-123.6.3.el7.x86_64.img


GRUB_TIMEOUT=5
GRUB_DISTRIBUTOR="$(sed 's, release .*$,,g' /etc/system-release)"
GRUB_DEFAULT=saved
GRUB_DISABLE_SUBMENU=true
GRUB_TERMINAL_OUTPUT="console"
GRUB_CMDLINE_LINUX="rd.lvm.lv=centos_bravo/swap vconsole.keymap=jp rd.lvm.lv=centos_bravo/usr rd.lvm.lv=centos_bravo/root crashkernel=auto  vconsole.font=latarcyrheb-sun16 rhgb"
GRUB_DISABLE_RECOVERY="true"