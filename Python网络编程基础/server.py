#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
@date  : 2016-07-03 01:54:52
@author: Rancho (rancho941110@gmail.com)
@brief : simple server
'''

import socket
import os

sep = os.sep

host = ''           # set blank to bind all interfaces
port = 51423        # if port < 1024 need admin permission

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

s.bind((host, port))
s.listen(1)

print "Server is running on port %d" % port
print "Press <c-c> to terminate."

while True:
    clientsock, clientaddr = s.accept()
    clientfile = clientsock.makefile('rw', 0)
    clientfile.write("Welcome, " + str(clientaddr) + sep)
    clientfile.write("Please enter a string: ")

    line = clientfile.readline().strip()
    clientfile.write("You entered %d characters.\n" % len(line))
    clientfile.close()
    clientsock.close()      # close them all!

if __name__ == '__main__':
    pass
