#include <iostream>

int bubblesort(int numbers[]){
	int size = sizeof(*numbers);
	int sortedList[size];
	
	for(int i = (size - 1); i >= 0; i--){
		int biggest = numbers[0];
		for(int j = 0; j < size; j++){
			if(biggest < numbers[j]){ biggest = numbers[j]; }
		}
		sortedList[i] = biggest;
	}

	return *sortedList;
}

int main(){
	return 0;
}
