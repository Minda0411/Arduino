# Import socket module 

import socket 
import random, time
from cv2 import waitKey
def Main(): 
    # local host IP '127.0.0.1' 
    host = '127.0.0.1'
	# Define the port on which you want to connect 
    port = 7000
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) 
	# connect to server on local computer 
    s.connect((host,port)) 
	# message you send to server 
    message =""
    try:
        while True:
            message = random.randrange(1, 100)
            s.send(str(message).encode()) 
            # messaga received from server 
            data = s.recv(1024)
            # print the received meyssage 
            # here it would be a reverse of sent message 
            print('Received from the server :', str(data.decode())) 
            # ask the client whether he wants to continue 
            # ans = input('\nDo you want to continue(y/n) :') 
            # if ans == 'y': 
            #     continue
            # else: 
            #     break
            # if waitKey(1) & 0xFF == ord('q'):
            #     break
            time.sleep(1)
	# close the connection 
    except:
        message=""
        s.send(str(message).encode())
        s.close() 

if __name__ == '__main__': 
	Main() 
