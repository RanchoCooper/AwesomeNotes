---
title: Redis基本
date: 2016-11-25 12:34
category:
tags:
---

## 简介
Redis是完全开源免费的, 遵守BSD协议的高性能键值数据库(NoSQL).

特点
- 支持数据的持久化, .
- 提供list, set, zset, hash等数据结构的存储.
- 支持数据的备份, 即master-slave模式的数据备份.

优势:
- 性能极高: 读写分别可达11w/s, 8w/s
- 丰富的数据结构
- 所有操作都是原子性的
- 丰富的特性: 支持 publish/subscribe, 通知, key 过期等等特性

## 安装
    sudo pacman -S redis                # ArchLinux
    sudo yum install redis              # CentOS
    sudo apt-get install redis-server   # Ubuntu & Debian

    $ redis-server      # 启动服务
    $ redis-cli         # 交互环境

## 配置
配置文件在安装目录的redis.conf中

    redis > config get *    # 查看所有配置

部分参数说明:

- daemonize: 默认不是以守护进程方式运行
- pidfile: 以守护进程启动时, 会把pid写入这个文件供内核使用
- port: 指定端口
- bind: 指定主机
- timeout: 闲置自动关闭连接
- loglevel: 共有日志级别debug, verbose, notice, warning, 默认为verbose
- logfile: 默认为标准输出(守护进程+stdout -> 发送至/dev/null)
- databases: 数据库最大数量
- save <seconds> <changes>: 指定文件同步频率, 多长时间内多少次更新
- rdbcompression: 采用LZF压缩, 为节省CPU时间可以关闭, 但数据文件会变得很大
- dbfilename: 本地数据库文件名
- dir: 本地数据库存放目录
- slaveof <masterip> <masterport>: 当本机作为slav服务时, 指定master的地址和端口, 本地启动时则从主服务器同步

## Redis基本数据类型

### String(字符串)
string类型是二进制安全的, 意思是它可以包含任何数据. string类型是Redis最基本的数据类型, 一个键最大能存储512MB

- set name value
- get name

### Hash(哈希)
键值对集合, string类型的field和value的映射表, hash特别适合用于存储对象

- hmset field value
- hmgetall field

### List(列表)
列表是简单的字符串列表, 按照插入顺序排序

- lpush list-name value
- lrange list-name start stop

### Set(集合)
Set是string类型的无序集合, 是通过哈希表实现的，所以添加，删除，查找的复杂度都是O(1)

- sadd set-name member  # 若已存在返回0

### zset(有序集合)
也是string类型元素的集合, 且不允许重复的成员. 但不同的是每个元素都会关联一个double类型的score, 以此作为排序依据

成员是唯一的, 但score却可以重复

- zadd set-name score member

**列表, 哈希, 集合的元素上限都是2^32-1()40多亿**
