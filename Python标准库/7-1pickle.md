---
title: pickle-对象串行化
date: 2016-11-29 19:57
category:
tags:
---

pickle模块负责将任意的Python对象转化为二进制数据(这一过程称为串行化对象)
串行化后的表示对象的字节流可以用来存储或传输, 然后在以后重新还原为Python对象

cPickle与其使用了相同的算法, 由于是C扩展, 所以有一定速度优势, 通常会优先导入

```python
try:
    import cPickle as pickle
except:
    import pickle
```

数据的编码和解码

    pickle.dumps(data)
    pickle.loads(data)

不可串行化的对象
    详见标准库文档
