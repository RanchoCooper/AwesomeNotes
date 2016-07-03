#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 14:20:23
@author: Rancho (rancho941110@gmail.com)
@brief : udp connect with out connect()
'''

import socket
import struct
import time
import sys

hostname = 'time.nist.gov'
port = 37

host = socket.gethostbyname(hostname)


s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.sendto('', (host, port))

print "looking for replies; press ctrl-c to stop"

buf = s.recvfrom(2048)[0]

if len(buf) != 4:
    print "wrong-sized reply %d: s" % (len(buf), buf)
    sys.exit(1)

secs = struct.unpack("!I", buf)[0]
secs -= 2208988800

print time.ctime(int(secs))

if __name__ == '__main__':
    pass
