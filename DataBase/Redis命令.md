---
title: Redis命令
date: 2016-11-25 13:10
category:
tags:
---

## 启动客户端并测试
    $ redis-cli
    127.0.0.1:6379> ping
    PONG

    远程启动
    $ redis-cli -h host -p port -a password

一下用 `>` 表示redis-cli的交互环境

## key
Redis键命令用于管理数据库中的键(key)
基本语法为

    > command key-name

序号  | 命令 | 描述|
:----:|:-----|:----:|
1| del key|key存在则删除
2| dump key| 序列化给定的key, 返回被序列化的值
3| exists key| 检查给定 key 是否存在
4| expire key seconds|为给定 key 设置过期时间
5| expireta key timestamp| 时间参数是 UNIX 时间戳
6| pexpire key milliseconds| 过期时间以毫秒计
7| pexpireta key milliseconds-timestamp|时间戳以毫秒计
8| keys pattern| 查找所有符合给定模式的 key
9| move key db| 将当前数据库的 key 移动到给定的数据库 db 当中
10| persist key| 移除过期时间, 持久保持
11| pttl key| 剩余的过期时间, 毫秒
12| ttl key| 剩余的过期时间, 秒
13| randomkey| 从当前数据库中随机返回一个 key
14| rename key newkey| 重命名
15| renamenx key newkey| 仅当newkey不存在才重命名
16| type key| 返回储存的值的类型

## String

只读操作
- get key value
- getrange key start end: 返回子字符
- getbit key offset: 获取偏移值上的值
- mget keys: 获取多个key的值

写操作
- set key value
- getset key value: 更新并返回旧值
- setbit key offset value: 设置或清除指定偏移值上的位
- setnx key value: 仅当key不存在时赋值
- setex key seconds value: 关联key-value, 并设置过期时间
- setrange key offset value: 子字符串更新
- mset keys values
- msetnx keys values
- incr key
- incrby key increment
- decr key
- decrby key decrement
- append key value


## Hash

只读操作
- hexists key field: 查看字段是否存在
- hget key field: 获取字段的值
- hgetall key: 获取全部字段和值
- hkeys key: 获取全部字段
- hlen key: 获取字段数量
- hmget key fields: 多字段取值

写操作
- hdel key fields: 字段删除
- hincrby key field increment: 指定字段的整数增量操作
- hincrbyfloat key field increment: 浮点数增量操作
- hset key field value: 字段赋值
- hmset key fields values: 多字段赋值
- hsetnx key field value: 仅当字段不存在时赋值
- hscan key cursor [match pattern] [count count]: 哈希表迭代

不难发现这些命令都是一些二元值的组合: 读或写, 单个或批量, 存在与否等等

## List

## Set

## Sorted Set

## HyperLogLog

## 发布订阅
发布订阅(pub/sub)是一种消息通信模式: 发送者(pub)发送消息, 订阅者(sub)接收消息

对于某个频道, 允许多个客户端订阅这个频道
![](redis-订阅.png)

当有新消息通过频道发布时, 这个消息就会被发送至客户端
![](redis-发布.png)

创建并订阅频道

    > Reading messages... (press Ctrl-C to quit)
    1) "subscribe"
    2) "cha1"
    3) (integer) 1  ubscribe channel

向频道发送消息

    > publish cha1 "message"

其他命令
- psubscribe pattern: 订阅多个符合模式的频道
- pubsub subcommand [argument]: 订阅发布系统的状态查询
- unsubscribe chanel: 退订频道
- punsubscribe pattern: 退订多个频道

## 事务
Redis事务可以一次执行多个命令, 且保证一下两点:

- 事务是一个单独的隔离操作: 事务中的所有命令都会序列化, 并按序执行. 在整个事务过程中, 不会因其他客户端的命令请求而被打断
- 事务操作是原子的: 要么全部执行完毕, 要么全部都没执行

一个事务的生命周期会经历一下三个阶段: 开始事务, 命令入队, 执行事务

一个完整的事务以multi-exec指令对定义

    > MULTI
    OK
    > SET book-name "Mastering C++ in 21 days"
    QUEUED
    > GET book-name
    QUEUED
    > SADD tag "C++" "Programming" "Mastering Series"
    QUEUED
    > SMEMBERS tag
    QUEUED
    > EXEC
    1) OK
    2) "Mastering C++ in 21 days"
    3) (integer) 3
    4) 1) "Mastering Series"
       2) "C++"
       3) "Programming"

其他指令:
- discard: 取消事务
- watch keys: 监视keys, 如果在事务执行之前keys被修改, 那么事务将被打断
- unwatch: 取消watch命令中的所有监视

## 脚本
Redis 脚本使用 Lua 解释器来执行脚本.  Reids 2.6 版本通过内嵌支持 Lua 环境, 执行脚本的常用命令为 EVAL

## 连接

- ping: 测试服务
- quit: 关闭当前连接
- auth password: 密码验证
- echo message:
- select index: 数据库切换

## 服务器

    # 获取redis服务器全部统计信息
    > info
