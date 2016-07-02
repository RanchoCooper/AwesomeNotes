---
title: Git合集
date: 2016-07-01 01:25:02
categories:
tags:

---

## 一些init
```bash
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
$ git config --global core.editor vim               # 使用vim作为默认编辑器

```

## 常用
```
$ git status                    # 当前仓库状态
$ git diff <filename>           # 文件变更详情
$ git log                       # 版本历史记录
    + --pretty=oneline          # 简化输出信息
$ git reset --hard commit_id    # 版本退回
$ git reflog                    # HEAD变更记录
$ git checkout -- file          # 取消工作区的修改(还原成版本库里的状态)

```


## Fixed Bugs
Git 支持 utf-8 编码:

```bash
$ git config --global core.quotepath false          # 显示 status 编码
$ git config --global gui.encoding utf-8            # 图形界面编码
$ git config --global i18n.commit.encoding utf-8    # 提交信息编码
$ git config --global i18n.logoutputencoding utf-8  # 输出 log 编码
$ export LESSCHARSET=utf-8
# 因为 git log 默认使用 less 分页，所以需要 bash 对 less 命令进行 utf-8 编码
```
