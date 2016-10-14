---
title: 引导系统
date: 2016-10-15 02:12
category:
tags:
---

## 何为引导
计算机内存是断电易失的介质, 如何在CPU通电后正确加载磁盘上的操作系统, 就是引导系统要完成的任务. 从计算机通电到操作系统完全接管计算机, 这一过程称为引导计算机. 这个引导加载程序, 通常叫做BootLoader

## 引导顺序
在BootLoader正式工作之前, 实际上是BIOS完成了一部分工作. 它的代码存储在ROM, EEPROM或闪存等非易失性存储器里. 当计算机通电, 首先将BIOS载入内存, 首先执行开机自检(POST)来检查机器, 从而确定loader所在的驱动器. 这里的驱动器包括传统硬盘驱动器, 固态硬盘驱动器, USB等块设备等, 并从该驱动器的MBR加载一个扇区(512字节)的数据, 实际可能只有400多字节, 其中就包含分区表(旧有的分区格式是每个表项占16字节, MBR大小为64字节).

MS DOS, PC DOS和Windos操作系统所使用的驱动器MBR会检查分区表, 查找标为active的主分区, 并加载该分区的第一个扇区, 并将控制权传递到已加载的代码的开头处. 这部分代码会继续加载操作系统的其余部分

显然, 引导过程是和平台紧密相关的, 所以针对x86, x86_64, IA64等不同架构系统实际的引导过程会略有差别, 但理论过程是一致的

## BIOS和UEFI
BIOS是经典的, 但因为在一开始它就被设计成只读一个扇区(512字节)的内容, 导致分区受限(主分区至多四个). 随着2TB等大容量驱动器的流行, UEFI的优势就显现出来了. UEFI前身是Intel 开发的EFI

- BIOS: basic input output service基本输入输出服务
- EFI : extensible firmware interface可扩展固件接口
- UEFI: unified extensible firmware interface 统一可扩展固件接口
- MBR : master boot record 主引导记录
- GPT : MBR的替代物

常见的BootLoader: LILO, GRUB Legacy, GRUB2, Syslinux
GRUB2是linux发行版中很常见. 话说不知道Windows是啥loader, M$自己写的?

## 引导过程
总结一下
1. 机器通电, 加载BIOS执行自检
2. BIOS加载MBR, 即引导驱动器的第一个扇区(UEFI加载GPT)
3. MBR查找活动分区, 同样读取第一个扇区(预加载)
4. 加载程序加载操作系统

## GRUB2引导菜单
GRUB2的配置文件: /boot/grub/grub.cfg  # 可以在这里自定义开机的系统选项, 等待时间和默认启动项等, 还有单用户模式,

题外话, 我的电脑Ubuntu是grub2引导的, 转Arch之后是grub, 初次装系统时设了一个target=i386的参数才成功引导了

## init进程
系统内核完成加载后, 便会启动/sbin/init进程. 在 *nix世界里, init进程就是进程树的根节点, 其pid永远为1. 在很多发行版上它其实链接到systemd

![init进程](LPIC-0x01Linux引导系统_init.png)

## 引导事件
Linux引导过程中, 会向控制台发出大量信息, 来描述引导内核, 硬件适配等信息, 方便开发人员调试和排查. 就像好比是服务器日志一样

### dmesg
可以通过dmesg来退回检查内核消息, 只在装输入法的时候看过这部分消息

    # dmesg | head -n 30
    # dmesg | tail -n 20

## 系统事件
在运行init进程之后, 内核会通过一个守护进程记录系统事件.
在传统的System V init系统中, 这个进程是syslogd, 而基于Systemd 的系统使用systemd-journald进程

### journalctl
由systemd-journald守护进程管理的日志,

	$ journalctl -xb  显示当前引导的日志条目



