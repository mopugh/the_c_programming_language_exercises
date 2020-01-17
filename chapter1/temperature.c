#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(int argc, char **argv) {
  float fahr, celsius;

  printf("Fahrenheit\tCelsius\n");

  fahr = LOWER;
  while (fahr <= UPPER) {
    celsius = 5.0 * (fahr-32.0) / 9.0;
    printf("%3.0f\t\t%6.1f\n", fahr, celsius);
    fahr = fahr + STEP;
  }

  printf("Celsius\t\tFahrenheit\n");
  celsius = LOWER;
  while (celsius <= UPPER) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%3.0f\t\t%6.1f\n", celsius, fahr);
    celsius += STEP;
  }

  return 0;
}
