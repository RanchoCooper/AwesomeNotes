---
title: landslide制作PPT
date: 2016-08-03 11:02
category: 札记
tags:

---

## 前言
landslide是基于python的PPT生产工具, 可以把markdown, ReST 
或者texttile格式的文本生成可以演示的HTML文档

## 依赖
- jinja2
- pygments      # 提供语法高亮

## 安装
    pip install landslide

## 书写格式

### Markdown

- 分页: ---
- 标题: #
- 生成: $ landslide file.md -i -o > slide.html
-i: 整合CSS等依赖文件
-o: 输出重定向

快捷键:
```
h:          显示帮助
ESC:        展示目录
左/右:      幻灯片切换
n:          幻灯片页数
b:          屏幕全黑
e:          幻灯片最大化
3:          伪3D展示
c:          取消前后幻灯片预览
```

其他


因为一般只用markdown写文档, 下列详情可以参考
[这里](https://github.com/adamzap/landslide)
### ReStructuredText

### Textile



