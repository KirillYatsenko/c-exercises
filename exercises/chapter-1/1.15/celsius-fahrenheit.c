#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */

float convertCelsiusToFahrenheit(float);

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = -20;
	upper = 100;
	step = 20;
	celsius = lower;

	printf("Celsius\t  Fahr\n");

	while (celsius <= upper)
	{
		fahr = convertCelsiusToFahrenheit(celsius);
		printf("%3.0f %10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

float convertCelsiusToFahrenheit(float celsius)
{
	return (celsius * 9 / 5) + 32;
}
