#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Failsafe
void fail(void)
{
	printf("Memory could not be allocated");
	exit(EXIT_FAILURE);
}

//Swap Function
int swap(int a, int b)
{
	int c = a; 
	a = b; 
	b = c;
	printf("a = %d\nb = %d\n",a,b);
	return(0);
}

//Main
int main()
{
	//Variables
	int *numbers = calloc(2, sizeof(int));
	if (numbers == NULL) {fail();}
	numbers[0] = 25;
	numbers[1] = 85;

	//Output	
	printf("a = %d\nb = %d\n",numbers[0],numbers[1]);
	printf("Swap...\n");
	swap(numbers[0], numbers[1]);
	free(numbers);
    return 0;
}

