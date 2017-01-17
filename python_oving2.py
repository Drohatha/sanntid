
from threading import Thread 
import thread

i = 0
lock = thread.allocate_lock()

def someThreadFunction():
	global i
	for y in range(0, 1000000):
		lock.acquire()
		i += 1
		lock.release()

def someThreadFunction2():
	global i
	for x in range(0,1000000):
		lock.acquire()
		i -= 1 
		lock.release()


def main():
	someThread = Thread(target = someThreadFunction, args = (),)
	someThread2 = Thread(target = someThreadFunction2, args = (),)

	someThread.start()
	someThread2.start()
	someThread.join()
	someThread2.join()
	print(i)

	print("Hello from main!")


main()