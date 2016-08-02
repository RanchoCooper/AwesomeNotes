---
title: Git合集
date: 2016-07-01 01:25:02
categories: 札记
tags: Git

---

## 初次安装
```bash
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
$ git config --global core.editor vim               # 使用vim作为默认编辑器
```

## 本地管理

```bash
$ git init <folder>             # 初始化空仓库
$ git add filename              # 添加文件到暂存区
$ git commit                    # 提交修改到分支
$ git status                    # 当前仓库状态
$ git diff <filename>           # 文件变更详情, 工作区与版本库相比较
$ git log                       # 版本历史记录, 即commit记录
$ git reset --hard commit_id    # 版本退回
$ git reflog                    # 查看HEAD变更记录
```
### 撤销修改
```bash
$ git checkout -- filename      # 撤销工作区的修改(仅仅修改了文件的情形)
$ git reset && git checkout..   # 撤销暂存区的修改(修改并add到暂存区时)
# 如果已经提交到分支, 那就版本退回
```

## 配置远端
```bash
$ ssh-keygen -t rsa -C "email@xxx.com"
$ git remote add origin git@github.com:user/repo.git
$ git remote -v
$ git remote set-url
$ git push -u origin master
```

## 分支管理
```bash
$ git branch                    # 查看分支
$ git branch bra-name           # 创建分支
$ git checkout bra-name         # 切换分支
$ git checkout -b bra-name      # 创建并切换分支

$ git merge bra-name            # 合并分支到当前分支
$ git merge --no-ff bra-name    # 禁用Fast Forward(在分支树中新建节点)
$ git branch -d bra-name        # 删除分支
$ git branch -D bra-name        # 强制删除还没合并的分支

$ git stash                     # 临时保存工作区
$ git stash list                # 查看保存的工作区
$ git stash apply               # 恢复工作区但不删除stash中的节点
$ git stash pop                 # 恢复并删除节点
```

### 多人协作
```bash
$ git pull                      # 从远端获取更新
$ git branch --set-upstream dev origin/dev # 远端有新分支时
```

### 标签管理
```bash
$ git tag tname         # 对当前分支的最新提交打标签, -a指定标签名, -m指定说明文字
$ git show tname        # 查看标签信息
$ git tag -s tname passwd   # 带私钥签名的标签

$ git tag -d tname                  # 删除标签
$ git push origin tname             # 推送标签
$ git push origin --tags            # 推送所有标签
$ git push origin :refs/tags/tname  # 删除远端的标签

```


## 自定义
Git 支持 utf-8 编码:

```bash
$ git config --global core.quotepath false          # 显示 status 编码
$ git config --global gui.encoding utf-8            # 图形界面编码
$ git config --global i18n.commit.encoding utf-8    # 提交信息编码
$ git config --global i18n.logoutputencoding utf-8  # 输出 log 编码
$ export LESSCHARSET=utf-8
# 因为 git log 默认使用 less 分页，所以需要 bash 对 less 命令进行 utf-8 编码
```
```
[user]
    name = ranchocooper
    email = ranchocooper@gmail.com
[core]
    quotepath = false
[color]
    ui = true
[alias]
    c = commit
    b = branch
    com = commit
    bra = branch
    che = checkout
    unstage = reset HEAD
    logg = log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit
    last = log -1
    sta = status
```


## 总结若干
commit是一棵树, 每条路径是一个branch
分支指针, 如master, dev, feature等, 标识了不同分支
HEAD指针指向某个特定的分支指针, 所以切换分支只是HEAD指针改变了指向
