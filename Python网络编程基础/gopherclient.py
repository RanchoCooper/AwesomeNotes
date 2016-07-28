#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 01:32:42
@author: Rancho (rancho941110@gmail.com)
@brief : simple gopher client

usage:  gopherclient <host> <filename>
result: got the file list of server
'''

import socket
import sys
import os

sep = os.linesep

port = 70               # gopher use port 70
host = sys.argv[1]
filename = sys.argv[2]

def function():
    pass

s = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM, proto=0, _sock=None)

# try:
#     s.connect((host, port))
# except socket.gaierror, e:
#     print "Error connecting to serve: %s" % e
#     sys.exit(1)

s.connect((host, port))

fd = s.makefile('rw', 0)

# s.sendall(filename + sep)
fd.write(filename + sep)

# while True:
#     buf = s.recv(2048)

#     if not len(buf):
#         break

#     sys.stdout.write(buf)
for line in fd.readlines():
    sys.stdout.write(line)

if __name__ == '__main__':
    pass
