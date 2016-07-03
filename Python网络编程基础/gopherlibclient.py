#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 02:35:42
@author: Rancho (rancho941110@gmail.com)
@brief : high-level gopher client
'''

import gopherlib
import sys

host = sys.argv[1]
file = sys.argv[2]

f = gopherlib.send_selector(file, host)

for line in f.readlines():
    sys.stdout.write(line)

if __name__ == '__main__':
    pass
