#include <stdio.h>
#include <stdlib.h>

void getElements(int *array, int size) {

	printf("enter Elements: ");

	for(int i = 0; i<size; i++ ){

		scanf("%d", &array[i]);
	}
}

void showElements(int *array, int size) {

	printf("\nNew Elements: ");

	for(int i =0; i<size; i++) {

		printf("%d ", array[i]);
	}
		printf("\n");

}

void deleteElement(int *array, int size, int position){

	size--;
	position--;

	int j = size;

	while(j>=position){
		array[position] = array[position+1];

		position++;
	}

}


int main () {

	int *array;
	int size, position;

	printf("enter size of the array: ");
	scanf("%d", &size);

	array =(int *)malloc(size*sizeof(int));

	getElements(array, size);
	showElements(array, size);

	printf("enter position of the element: ");
	scanf("%d", &position);

	deleteElement(array, size, position);
	size--;
	showElements(array, size);

	return 0;

}
