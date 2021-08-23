## TCP client -- send msg
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket

HOST = "127.0.0.1"  ##'0.0.0.0'
PORT = 7000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

while True:
    outdata = input('please input message: ')
    if outdata == "":
        print("Please input data before enter...")
        continue
    print('send: ', outdata)
    s.send(outdata.encode())
    
    indata = s.recv(1024)
    print(len(indata))
    if len(indata) == 0: # connection closed
        s.close()
        print('server closed connection.')
        break
    print('recv: ' + indata.decode())