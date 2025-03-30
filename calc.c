#include <stdio.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return b != 0 ? a / b : 0; }

void displayMenu() {
  printf("\nCalculator Menu:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Exit\n");
  printf("Choose an option: ");
}

float getNumber(const char *prompt) {
  float number;
  printf("%s", prompt);
  scanf("%f", &number);
  return number;
}

int getOption() {
  int option;
  scanf("%d", &option);
  return option;
}

void processCalculation(int option) {
  float num1, num2, result;

  if (option >= 1 && option <= 4) {
    num1 = getNumber("Enter first number: ");
    num2 = getNumber("Enter second number: ");

    switch (option) {
    case 1:
      result = add(num1, num2);
      printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
      break;
    case 2:
      result = subtract(num1, num2);
      printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
      break;
    case 3:
      result = multiply(num1, num2);
      printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
      break;
    case 4:
      if (num2 == 0) {
        printf("Error: Division by zero!\n");
      } else {
        result = divide(num1, num2);
        printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
      }
      break;
    }
  }
}

int main() {
  int option;

  do {
    displayMenu();
    option = getOption();

    if (option >= 1 && option <= 4) {
      processCalculation(option);
    } else if (option != 5) {
      printf("Invalid option! Please try again.\n");
    }
  } while (option != 5);

  printf("Calculator closed. Goodbye!\n");
  return 0;
}
