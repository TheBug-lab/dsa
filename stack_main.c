#include <stdio.h>
#include "stack.h"
int main () {

	int temp, userInput;

	Stack* mystack= createStack(5);
	mystack->max = 5;
	mystack->top = -1;


	while(1) {
		printf("\n1 push\n2 pop\n3 peek\n4 show\n9 Exit\n");
		scanf("%d", &userInput);
		switch ((int)userInput) {
			case 1:
				printf("enter value for the element: ");
				scanf("%d", &temp);
				push(mystack, temp);
				break;
			case 2:
				pop(mystack);
				break;
			case 3:
				peek(*mystack);
				break;
				
			case 4:
				show(*mystack);
				break;
			case 9:
				return 0;
			default:
				printf("invalid Input");
		}
	}
	return 0;
}
