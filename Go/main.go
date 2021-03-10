package main

import (
	"fmt"
	"time"
)
//Funcion de buscar en la lista
func linearSearch(numbers []int, item int) int {

	if numbers != nil && len(numbers) > 0 {

		for i := 0; i < len(numbers); i++ {

			if numbers[i] == item {
				return numbers[i]
			}
		}
	}
	return -1
}
//Funcion Main
func main() {
	start := time.Now()
	//Crea lista y le pone el numero 42 a toda la lista
	numbers := make([]int, 500000)
	for i := range numbers {
		numbers[i] = 42
	}

	result := linearSearch(numbers, 46)


	if result == -1 {
		fmt.Println("Posicion", result)
	}
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Println(elapsed)
}
