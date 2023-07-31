#include <stdio.h>
#include "header/que_arr.h"

int main () {

	queue* myQueue = createQueue();
	int userInput, temp;

	while(1) {
		printf("1 enqueue\n2 dequeue\n3 show\n4 exit\n");
		scanf("%d", &userInput);

		switch(userInput){
			case 1:
				printf("value for the element: ");
				scanf("%d", &temp);

				enqueue(myQueue, temp);
				break;
			case 2:	
				isempty(*myQueue)?printf("Empty"):printf("%d removed",dequeue(myQueue));
				break;
			case 3:
				printf("\n");
				show(*myQueue);
				break;
			case 4:
				return 0;

		}	
		system("clear");
		printf("\n");
		show(*myQueue);
		printf("\n");

	}

	return 0;
}
