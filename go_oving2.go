

package main

import (

	. "fmt"
	"runtime"
	"time"
)

//var i = 0

func someGoroutine(ch chan int) {
	//Println("Hello from a goruoutine!")
	for j := 0; j < 1000000; j++{
		temp := <- ch
		temp = temp +1
		ch <- temp
	}
	
}

func someGoroutine2(ch chan int){
	for m := 0; m < 1000000; m++ {
		temp := <- ch
		temp = temp -1
		ch <- temp
	}
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	ch := make(chan int, 1)
	ch <- 0
	go someGoroutine(ch)
	go someGoroutine2(ch)
	
	
	time.Sleep(1000*time.Millisecond)
	i := <-ch
	Println(i)	
}