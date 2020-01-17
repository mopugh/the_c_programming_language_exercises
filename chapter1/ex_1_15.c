#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_celsius(float f);
float celsius_to_fahr(float c);

int main(int argc, char **argv) {
  float fahr, celsius, f2;

  printf("Fahrenheit\tCelsius\tFahrenheit\n");

  fahr = LOWER;
  while (fahr <= UPPER) {
    celsius = fahr_to_celsius(fahr);
    f2 = celsius_to_fahr(celsius);
    printf("%3.0f\t\t%6.1f\t%6.1f\n", fahr, celsius, f2);
    fahr += STEP;
  }

  return 0;
}

float fahr_to_celsius(float f) {
  float c;

  c = 5.0 * (f - 32.0) / 9.0;
  return c;
}

float celsius_to_fahr(float c) {
  float f;

  f = (9.0 / 5.0) * c + 32.0;
  return f;
}
