#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-01 15:09:38
@author: Rancho (rancho941110@gmail.com)
@brief : make text file
'''

import os
ls = os.linesep

while True:
    fname = raw_input('enter new file name: ')
    if os.path.exists(fname):
        print "ERROR: '%s' already exists" % fname
    else:
        break

# get file content
content = []
print "Enter lines(dot to quit)\n"

while True:
    entry = raw_input('> ')
    if entry == '.':
        break
    else:
        content.append(entry)

# write lines to file with proper line-ending
fobj = open(fname, 'w')
fobj.writelines(['%s%s' % (x, ls) for x in content])
fobj.close()

print 'Done!'

if __name__ == '__main__':
    pass
