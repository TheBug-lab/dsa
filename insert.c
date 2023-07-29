#include <stdio.h>
#include <stdlib.h>

void getElements(int *array, int size);
void showElements(int *array, int size);
void insertElement(int *array, int size);

int main () {

	int *array;
	int size, position, item, flag;

	printf("Enter size of the array: ");
	scanf("%d", &size);

	array = (int *)malloc(size*sizeof(int));

	getElements(array, size);
	showElements(array, size);

	insertElement(array, size);
	size++;
	showElements(array, size);

	free(array);

	return 0;

}

void getElements(int *array, int size) {
	printf("enter items: ");

	for(int i=0; i<size; i++){
		scanf("%d", &array[i]);
	}
}

void showElements(int *array, int size) {
	printf("\nNew Elements: ");

	for(int i=0; i<size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void insertElement(int *array, int size) {

	int flag, position, item;


	printf("[1] at specific position\n[2] at last\n");
	scanf("%d", &flag);

	switch(flag) {
		case 1 :
			printf("enter position of the element: ");
			scanf("%d", &position);

			printf("enter value of the element: ");
			scanf("%d", &item);

			size--;
			position--;
			int j= size;
			while(j>=position) {
				array[j+1]=array[j];
				j--;
			}
			array[position] = item;

			break;
		case 2:
			printf("enter value of the element: ");
			scanf("%d", &item);

			array[size] = item;

			break;
		default:
			printf("Invalid input");

	}
}


	
