

package main

import (

	. "fmt"
	"runtime"
	"time"
)

var i = 0

func someGoroutine() {
	//Println("Hello from a goruoutine!")
	for j := 0; j < 1000000; j++{
		i ++
	}
	
}

func someGoroutine2(){
	for m := 0; m < 1000000; m++ {
		i -- 
	}
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	go someGoroutine()
	go someGoroutine2()
	
	time.Sleep(100*time.Millisecond)
	Println(i)	
}