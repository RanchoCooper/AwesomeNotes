#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-01 15:29:28
@author: Rancho (rancho941110@gmail.com)
@brief : read and display text file
'''

# get file name
fname = raw_input('Enter file name: ')
print

# attempt to open file for reading
try:
    fobj = open(fname, 'r')
except IOError, e:
    print '*** file open fail: ', e
else:
    # display contents to the screen
    for eachline in fobj:
        print eachline,
    fobj.close()

if __name__ == '__main__':
    pass
