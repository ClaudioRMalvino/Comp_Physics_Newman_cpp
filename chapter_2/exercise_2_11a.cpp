/**
 * @file binomial_coefficient.cpp
 * @brief Exercise 2.11: Binomial Coefficients Part a)
 *
 * From: Computational Physics by Mark Newman
 */

#include <boost/multiprecision/cpp_int.hpp> // Dealing with large factorials
#include <iostream>
#include <ranges>
#include <string>

// Function Declaration
/**
 * @brief Calculates the factorial of an integer
 * @param x The integer to calculate factorial for
 * @return The factorial as a boost::multiprecision::cpp_int
 */
boost::multiprecision::cpp_int factorial(int x);

/**
 * @brief Calculates the binomial coefficient (n choose k)
 * @param n The total number of items
 * @param k The number of items to choose
 * @return The binomial coefficient as a boost::multiprecision::cpp_int
 */
boost::multiprecision::cpp_int binomial_coefficient(int n, int k);

/**
 * @brief Prompts for and reads the value of n from user input
 * @return The input string (which may be a number or 'q' to quit)
 */
std::string n_input();

/**
 * @brief Prompts for and reads the value of k from user input
 * @return The input string (which may be a number or 'q' to quit)
 */
std::string k_input();

/**
 * @brief Checks if the input values n and k are valid
 * @param n The total number of items
 * @param k The number of items to choose
 * @throws std::runtime_error if inputs are invalid
 */
void check_values(int n, int k);

int main() {

  std::cout << "Binomial Coefficient Calculator" << std::endl;

  while (true) {
    auto ninput{n_input()};
    if (ninput == "q") {
      break;
    }
    int n{std::stoi(ninput)};

    auto kinput{k_input()};
    if (kinput == "q") {
      break;
    }
    int k{std::stoi(kinput)};

    try {

      check_values(n, k);
      auto result = binomial_coefficient(n, k);

      std::cout << "Binomial coefficient for (" << n << ", " << k
                << "): " << result << std::endl;
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid input. PLease enter a numeric value" << '\n'
                << std::endl;
    }
  }
  return 0;
}

// Function Definitions

boost::multiprecision::cpp_int factorial(int x) {

  boost::multiprecision::cpp_int f = 1;
  for (int i : std::views::iota(1, x + 1)) {
    f *= i;
  }
  return f;
}

boost::multiprecision::cpp_int binomial_coefficient(int n, int k) {

  if (k == 0) {
    return 1;
  } else {
    boost::multiprecision::cpp_int numerator = factorial(n);
    boost::multiprecision::cpp_int denominator =
        factorial(k) * factorial(n - k);
    boost::multiprecision::cpp_int binomial_coef = numerator / denominator;
    return binomial_coef;
  }
}

std::string n_input() {
  std::cout << "Input an integer for n: ";
  std::string input;
  std::cin >> input;

  return input;
}

std::string k_input() {
  std::cout << "Input an integer for k: ";
  std::string input;
  std::cin >> input;

  return input;
}

void check_values(int n, int k) {
  if (n <= 0) {
    throw std::runtime_error("n must be a positive integer");
  }
  if (k < 0 || k > n) {
    throw std::runtime_error(
        "k must be a non-negative integer not greater than n");
  }
}