#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 12:43:08
@author: Rancho (rancho941110@gmail.com)
@brief : download example
'''

import urllib
import sys

f = urllib.urlopen(sys.argv[1])

while True:
    buf = f.read(2048)

    if not len(buf):
        break
    sys.stdout.write(buf)


if __name__ == '__main__':
    pass
