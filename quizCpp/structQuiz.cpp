#include <iostream>

struct Fraction
{
  int numerator{};
  int denominator{};
};

Fraction fractionValues()
{
  Fraction value{};
  std::cout << "Enter the value of numerator: \n";
  std::cin >> value.numerator;
  std::cout << "Enter the value of denominator: \n";
  std::cin >> value.denominator;

  return value;
}

Fraction fractionProduct(const Fraction& value, const Fraction& anotherValue)
{
  return { value.numerator * anotherValue.numerator, value.denominator * anotherValue.denominator };
}

void printFraction(const Fraction& fractionResult)
{
  std::cout << fractionResult.numerator << "/" << fractionResult.denominator;
}

int main()
{
  // Let's do the quizzes
  // Fraction fractionDetails{fractionValues()};
  Fraction firstFraction{fractionValues()};
  Fraction secondFraction{fractionValues()};

  std::cout << "The fractions multiplied together is: ";
  printFraction(fractionProduct(firstFraction, secondFraction));

  return 0;
}
