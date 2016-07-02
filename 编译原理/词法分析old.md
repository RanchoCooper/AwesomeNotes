---
title: 词法分析_old
date: 2016-06-13 00:47:32
categories: 编译原理
tags: Program
---

`词法分析器`(Lexical Analyzer) 又称`扫描器`(Scanner), 是执行词法分析的程序

## 词法分析的任务
从左至右逐个字符地对源程序进行扫描，产生一个个的单词符号，把作为字符串的源程序改造成为单词符号串的中间程序


(输入)字符流: 原始字符集, 和被编译的语言有关(ASCII, Unicode)
(输出)记号流: 内部数据结构, 编译器所识别出的词法单元

内部流程:
RE -> NFA -> DFA -> 词法分析器代码

```c
enum kind {IF, LPAREN, ID, INTLIT, ... }
struct token {
    enum kind k;
    char *lexeme;
};
```
**词法分析就是完成从字符流到记号流的转换**

```c
if (x > 5)
    y = "hello";
else
    z = 1;

    ||
    ||
    \/

IF LPAREN IDENT(x) GT INT(5) RPAREN
    IDENT(y) ASSIGN STRING("hello") SEMICOLON
ELSE
    IDENT(z) ASSIGN INT(1) SEMICOLON EOF
```

<!--more-->

## 词法分析的手工制造

### 手工编码实现法
- 相对复杂, 容易出错
- 目前非常流行: GCC, LLVM

### 词法分析的生成器
- 快速原型, 代码量少
- 较难控制细节

### 转移图和转移算法

### 标识符的转移图

### 标识符和关键字
很多语言中的标识符和关键字有交集, 从词法分析的角度来看 关键字是标识符的一部分

### 关键字表算法
- 构造给定语言所有关键字构成的哈希表H
- 对所有的标识符和关键字, 先统一按标识符的转移图来识别
- 识别完成后再进一步查表(H)区分是否为关键字
- *完美哈希可以在O(1)时间内完成构造工作

## 正则表达式
![归纳定义](//正则表达式归纳定义.png)

## 有限状态自动机(FA)
工作机制: 判断当前输入的串是否可以被接受
输入的字符 --> FA --> {yes, no}
工作流程:

RE ----> NFA `Thompson算法`
NFA----> DFA `子集构造算法`
DFA ----> 词法分析器代码`Hopcroft最小化算法`

### RE 转 NFA (Thompson算法)
五种基本转换模式:
e --> ε
  --> c
  --> 连接: e1 e2
  --> 选择: e1 | e2
  --> 闭包: e1 *

### NFA 转 DFA
#### 算法思想
子集化每一节点n上的 ε闭包, 并加入到DFA的状态转换中
#### 算法实现

```python
/*子集构造算法, 工作表算法*/
q0 = eps_closure(n0) # 获取首节点的全部eps闭包
Q = {q0} # 将闭包加入FA的状态集
workList.append(q0) # 将当前闭包加入工作队列
while workList != []
    remove q from workList # 移除队列首元素
    for c in Character: # 遍历字符集
        t = e_closure((q, c)) # 获取q,c转换得到的闭包
        D.append(t) # 将转换闭包加入DFA状态集
        if t not in Q:
            workList.append(t) # 去重加入FA的状态集
```
#### 算法讨论
子集构造是一个不动点算法, 最坏情况为O(2^N), 但实际工作效率远高于此, 因为不是每个子集都会出现

#### ε闭包的计算
```
// 基于深度优先的遍历
set closure = {}

void eps_closure(x)
    closure += {x} // assert += operator
    foreach (y: x--ε--> y)
        if (!visited(y))
            eps_closure(y)
```

### DFA的最小化(Hopcroft算法)
#### 算法思想
从当前的DFA种找出等价类(对某些输入串得到相同的状态集)
目的在于减少实现中得到的FA状态, 减少程序所占内存和遍历的代价

#### Hopcroft实现

```
// 基于等价类的思想
split(s)
    foreach(character c)
        if (c can split s) // 对于输入串c得到不同的等价类
            split s into T1, T2...Tk

hpcroft()
    split all nodes intto N, A // 将当前DFA划分为转换前与转换后两部分
    while (set if still changes) // 可以继续切分
        split(s)
```
一些直观的小技巧:
把状态转换图视作一颗树, 划分的界限产生在树的某一深度, 也就是说等价类思想就是对兄弟节点作合并(复杂的转换图需要进一步分析)

## 从DFA生成分析算法
严格地讲, DFA就是一个有向图(权值为输入串), 所以类似图的表示, DFA的表示方法有:
- 转移表(类似邻接矩阵)
- 哈希表(构造哈希映射)
- 跳转表(直接的代码实现): 不需要维护状态信息

### 转移表驱动代码
 最长匹配

### 跳转表


<p align="center">
[前文时光机](http://rancho1110.com/)
</p>

<p align="center">
[后续传送门](http://rancho1110.com/)
</p>
