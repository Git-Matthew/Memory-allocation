#include <stdio.h>
#include <stdlib.h>

//Failsafe
void fail(void)
{
	printf("Memory could not be allocated");
	exit(EXIT_FAILURE);
}

//Sum Function
int sum(int x, int y)
{
	return(x+y);
}

//Main
int main()
{
	//Variables
	int *numbers = calloc(2, sizeof(int));
	if (numbers == NULL) {fail();}
	numbers[0] = 99;
	numbers[1] = 30;

	//Output
	printf("The sum is equal to: %d\n", sum(numbers[0], numbers[1]));
	free(numbers);
    return 0;
}
