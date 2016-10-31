#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @author   : Rancho Cooper
# @date     : 2016-10-26 00:02
# @email    : ranchocooper@gmail.com

"""fix file name of softlink"""
import os.path

workdir = '/home/rancho/AwesomeNotes/操作系统'
# get the list of files
all_files = os.listdir(workdir)

changes = [name for name in all_files if len(name) > 1 and name[:2] == '0x']

if changes:
    print(changes)
    todo = input("\nConfirm? n for cancle")
    if todo != 'n':
        for name in changes:
            os.rename(name, name[2:])
else:
    print("nothing todo.")
