Linux常用网络测试命令
1、 ifconfig
    可以使用ifconfig命令来配置并查看网络接口的配置情况。
    例如：
　　（1） 配置eth0的IP地址， 同时激活该设备。
　　#ifconfig eth0 192.168.1.10 netmask 255.255.255.0 up
　　（2） 配置eth0别名设备eth0:1的IP地址，并添加路由。
　　#ifconfig eth0 192.168.1.3
　　#route add –host 192.168.1.3 dev eth0:1
　　（3） 激活设备。
　　#ifconfig eth0 up
　　（4） 禁用设备。
　　#ifconfig eth0 down
　　（5） 查看指定的网络接口的配置。
　　#ifconfig eth0
　　（6） 查看所有的网络接口配置。
　　#ifconfig
2、 route
　　可以使用route命令来配置并查看内核路由表的配置情况。
　　例如：
　　（1） 添加到主机的路由。
　　#route add –host 192.168.1.2 dev eth0:0
　　#route add –host 10.20.30.148 gw 10.20.30.40
　　（2） 添加到网络的路由。
　　#route add –net 10.20.30.40 netmask 255.255.255.248 eth0
　　#route add –net 10.20.30.48 netmask 255.255.255.248 gw 10.20.30.41
　　#route add –net 192.168.1.0/24 eth1
　　（3） 添加默认网关。
　　#route add default gw 192.168.1.1
　　（4） 查看内核路由表的配置。
　　#route
　　（5）删除路由。
　　#route del –host 192.168.1.2 dev eth0:0
　　#route del –host 10.20.30.148 gw 10.20.30.40
　　#route del –net 10.20.30.40 netmask 255.255.255.248 eth0
　　#route del –net 10.20.30.48 netmask 255.255.255.248 gw 10.20.30.41
　　#route del –net 192.168.1.0/24 eth1
　　#route del default gw 192.168.1.1
　　对于1和2两点可使用下面的语句实现：
　　Ifconfig eth0 172.16.19.71 netmask 255.255.255.0
　　Route 0.0.0.0 gw 172.16.19.254
　　Service network restart
3、 traceroute
　　可以使用traceroute命令显示数据包到达目的主机所经过的路由。
　　例如：
　　#traceroute http://www.sina.com.cn/
4、 ping
　　可以使用ping 命令来测试网络的连通性。
　　例如：
　　#ping http://www.sina.com.cn/
　　#ping –c 4 192.168.1.12
5、 netstat
　　可以使用netstat命令来显示网络状态信息。
　　例如：
　　（1） 显示网络接口状态信息。
　　#netstat –i
　　（2） 显示所有监控中的服务器的Socket和正使用Socket的程序信息。
　　#netstat –lpe
　　（3） 显示内核路由表信息。
　　#netstat –r
　　#netstat –nr
　　（4） 显示TCP/UDP传输协议的连接状态。
　　#netstat –t
　　#netstat –u
6、 hostname
　　可以使用hostname命令来更改主机名。例如；
　　#hostname myhost
7、 arp
　　可以使用arp命令来配置并查看arp缓存。例如：
　　（1） 查看arp缓存。
　　#arp
　　（2） 添加一个IP地址和MAC地址的对应记录。
　　#arp –s 192.168.33.15 00:60:08:27:CE:B2
　　（3） 删除一个IP地址和MAC地址的对应缓存记录。
　　#arp –d192.168.33.15

8、ss 命令 : 查询套接字工具

9、sar 命令: 显示网络统计信息
输入以下命令 (你需要 通过sysstat包安装并启用sar):

10、
出处：http://www.cnblogs.com/sharezone/archive/2009/02/12/1389142.html