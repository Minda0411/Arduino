# import socket programming library 
import socket 

# import thread module 
from _thread import *
import threading 
import numpy as np
import matplotlib.pyplot as plt
from multiprocessing import Process, Manager, Queue
import sched, time, threading

#print_lock = threading.Lock() 
data_list = []

# This function is responsible for displaying the data
# it is run in its own process to liberate main process
# q: queue data
def display_xy_pyqtgraph(name, q, plot_title ="X-Y plot", win_title = "iVi Lab Taipei Tech." ):
    from pyqtgraph.Qt import QtGui, QtCore
    import pyqtgraph as pg
    app2 = QtGui.QApplication([])

    win2 = pg.GraphicsWindow(title= plot_title)
    win2.resize(1000,600)
    win2.setWindowTitle(win_title)
    p2 = win2.addPlot(title="Updating plot")
    curve = p2.plot(pen='y')
    x_np = []
    y_np = []
	## define a local used function
    def updateInProc(curve,q,x,y):
        item = q.get()
        x.append(item[0])
        y.append(item[1])
        curve.setData(x,y)

    timer = QtCore.QTimer()
    timer.timeout.connect(lambda: updateInProc(curve,q,x_np,y_np))
    timer.start(50)
    QtGui.QApplication.instance().exec_()
    return

## Due to thread, cannot draw plt in thread, so use pyqtgraph
# def plot_xy_data(data_list): ## loss_list  [(train_loss, test_loss)]
#     import matplotlib.pyplot as plt
#     plt.ion()
#     plt.clf()
#     plt.tight_layout()
#     plt.title('The collected data')
#     data = np.asarray(data_list)
#     x = [i for i in range(1, len(data_list)+1)]
#     plt.plot(x, data, color="red", marker = '.')
#     #plt.pause(1)
#     #plt.show()  
#     # if not os.path.isdir('./model'):
#     #     os.mkdir('./model') 
#     # plt.savefig("./model/Loss_figure.png")
#     return

# thread function 
## args: c socket connection
def socket_reading_data(c, addr, q ): 
	t = 0
	try:
		while True: 
			# data received from client 
			data = c.recv(1024) 
			if not data: 
				print('Bye') 
				# lock released on exit 
				#print_lock.release() 
				break
			## append data into list, and draw
			d = data.decode() ## decode into string
			if d.isdigit():
				t += 1
				q.put([t, float(d)])  ## put data into Queue
				#plot_xy_data(data_list)
			# send back reversed string to client 
			#print(data)
			c.send(data) ##echo back to client
	except:
		# connection closed 
		c.close() 
		print("connection is closed")
		

def Main(): 
	host = "192.168.43.64" 
	port = 7000
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
	s.bind((host, port)) 
	print("socket binded to port", port) 

	# put the socket into listening mode 
	s.listen(5) 
	print("socket is listening") 

	# a forever loop until client wants to exit 
	while True: 
		# establish connection with client 
		con, addr = s.accept() 
		print("Accept: ", addr)
		## mp: queue
		q = Queue()
		print('Connected to :', addr[0], ':', addr[1]) 

		# Run reading_data function in a thread
		t = threading.Thread(target=socket_reading_data, args=(con, addr, q))
		t.start()
		# # Start display process with pyqtgraph: using process
		p = Process(target=display_xy_pyqtgraph, args=('Tien', q))
		p.start()
	s.close() 


if __name__ == '__main__': 
	Main() 
