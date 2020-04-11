#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = -20;
	upper = 100;
	step = 20;
	celsius = lower;
	
	printf("Celsius\tFahr\n");
	
	while (celsius <= upper) {
		fahr = (celsius * 9/5) + 32;
		printf("%3.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
