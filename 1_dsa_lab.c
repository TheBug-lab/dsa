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

void insertElement(int *array, int size, int position, int item){

	size--;
	position--;
	int j= size;

	while(j>=position) {
		array[j+1] = array[j];

		j--;
	}

	array[position] = item;


}




int main () {

	int *array;
	int size, position, item;

	printf("enter size of the array: ");
	scanf("%d", &size);

	array = (int *)malloc(size *sizeof(int));

	getElements(array, size);
	showElements(array, size);

	printf("enter position of element: ");
	scanf("%d", &position);

	printf("enter value of element: ");
	scanf("%d", &item);

	insertElement(array, size, position, item);
	size++;
	showElements(array, size);

	return 0;

}
