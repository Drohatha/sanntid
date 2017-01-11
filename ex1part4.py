


from threading import Thread 

i = 0


def someThreadFunction():
	global i
	for y in range(0, 100000):
		i += 1

def someThreadFunction2():
	global i
	for x in range(0,1000000):
		i -= 1 


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

