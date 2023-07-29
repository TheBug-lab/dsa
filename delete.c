#include <stdio.h>
#include <stdlib.h>

void getElements(int *array, int size);
void showElements(int *array, int size);
void deleteElement(int *array, int size);

int main () {

	int *array;
	int size, position, item, flag;

	printf("Enter size of the array: ");
	scanf("%d", &size);

	array = (int *)malloc(size*sizeof(int));

	getElements(array, size);
	showElements(array, size);

	deleteElement(array, size);
	size--;
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

void deleteElement(int *array, int size) {

	int position, j;
	printf("enter position of the item to delete: ");
	scanf("%d", &position);
	
	position--;
	size--;
	j=size;

	while(position<size) {
		array[position]=array[position+1];
		position++;
	}

	array[j]=0;
}

