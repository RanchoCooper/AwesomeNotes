#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 03:03:03
@author: Rancho (rancho941110@gmail.com)
@brief : high-level gopher client with urllib
'''

import urllib
import sys

host = sys.argv[1]
file = sys.argv[2]

f = urllib.urlopen('gopher://%s%s' % (host, file))

for line in f.readlines():
    sys.stdout.write(line)

if __name__ == '__main__':
    pass
