---
title: 快速入门
date: 2016-07-01 14:45:28
categories: Python核心编程
tags:
- Python
---

## 程序输出
print语句调用str()来显示对象
交互解释器调用repr()来显示对象

print会默认插入换行符, 逗号可以取消这种行为

## for迭代
同时迭代索引和元素
```python
for index, char in enumerate(Iter):
    print char, '(%d)' %index
```

## 新手实用函数
dir() 显示对象的属性
help() 显示对象的文档字符串
str() 把对象转换成字符串
type() 返回对象的类型
