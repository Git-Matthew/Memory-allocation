#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Failsafe
void fail(void)
{
	printf("Memory could not be allocated");
	exit(EXIT_FAILURE);
}

//Hypotenuse Function
float hypotenuse(float x, float y) //float type function that uses two possibly fractionary values x and y
{
	return sqrt((x*x)+(y*y));	//The function returns the square root of the sum of x squared and y squared
}

//Main
int main()
{
	//Variables
	float *numbers = calloc(2, sizeof(float));
	if (numbers == NULL) {fail();}
	numbers[0] = 25.5;
	numbers[1] = 85.5;

	//Output
	printf("The hypotenuse is equal to: %.2f\n", hypotenuse(numbers[0], numbers[1]));
	free(numbers);
    return 0;
}
