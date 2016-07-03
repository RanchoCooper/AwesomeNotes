#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 14:12:48
@author: Rancho (rancho941110@gmail.com)
@brief : udp example
'''

import socket
import sys

host = sys.argv[1]
textport = sys.argv[2]

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

try:
    port = int(textport)
except ValueError:
    port = socket.getservbyname(textport, 'udp')

s.connect((host, port))

print "Enter data to transmit: "

data = sys.stdin.readline().strip()

s.sendall(data)

print "looking for replies\npress ctrl-c to stop"

while 1:
    buf = s.recv(2048)
    if not len(buf):
        break
    sys.stdout.write(buf)

if __name__ == '__main__':
    pass
