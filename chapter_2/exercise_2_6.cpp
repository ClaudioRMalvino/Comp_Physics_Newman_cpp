/*
 * Exercise 2.6: Planetary Orbit
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// Global constants

constexpr double M{1.9891E+30}; // Mass of the sun
constexpr double G{6.6738E-11}; // Newton's gravitational constant

// Function declarations

double v2(double v1, double l1);
double l2(double v1, double l1, double v2);
double a(double l1, double l2);
double b(double l1, double l2);
double orbital_period(double a, double b, double l1, double v1);
double orbital_eccentricity(double l1, double l2);
std::string v1_input();
std::string l1_input();
void check_v1_l1(double v1, double l1);

int main() {

  std::cout << "Orbital Properties Calculator" << '\n'
            << "Input 'q' to quit" << std::endl;

  while (true) {

    auto inputv1{v1_input()};
    if (inputv1 == "q") {
      break;
    }
    double v1{std::stod(inputv1)};

    auto inputl1{l1_input()};
    if (inputl1 == "q") {
      break;
    }
    double l1{std::stod(inputl1)};

    try {

      check_v1_l1(v1, l1);

      auto v2_val{v2(v1, l1)};
      auto l2_val{l2(v1, l1, v2_val)};
      auto a_val{a(l1, l2_val)};
      auto b_val{b(l1, l2_val)};
      auto T{orbital_period(a_val, b_val, l1, v1)};
      auto ecc{orbital_eccentricity(l1, l2_val)};

      std::cout << std::scientific << std::setprecision(4) << '\n'
                << "Velocity at aphelion (v2) = " << v2_val << " m/s"
                << std::endl;

      std::cout << std::scientific << std::setprecision(4)
                << "Distance from Sun at aphelion (l2) = " << l2_val << " m"
                << std::endl;

      std::cout << std::fixed << std::setprecision(2)
                << "Orbital period (T) = " << T / (365 * 24 * 3600) << " years"
                << std::endl;

      std::cout << std::scientific << std::setprecision(4)
                << "Orbital eccentricity = " << ecc << std::endl;

    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid input. Please enter numeric value" << '\n'
                << std::endl;
    }
  }
  return 0;
}

// Function definitions

/*
 * Parameter definitions:
 * v1: velocity at perihelion
 * v2: velocity at aphelion
 * l1: distance from the Sun at perihelion
 * l2: distance from the Sun  aphelion
 * a: semi-major axis
 * b: semi-minor axis
 */

// v2 calculates the velocity of the planetary body at its aphelion
double v2(double v1, double l1) {

  std::vector<double> solutions;

  double b{-(((2 * G * M) / (v1 * l1)))};
  double c{-std::pow(v1, 2) + ((2 * G * M) / (l1))};

  // calculates v2 utilziing the quadratic formula

  double v2plus{(-b + std::sqrt(std::pow(b, 2) - 4 * c)) / 2.0};
  solutions.push_back(v2plus);

  double v2minus{(-b - std::sqrt(std::pow(b, 2) - 4 * c)) / 2.0};
  solutions.push_back(v2minus);

  return *std::min_element(solutions.begin(), solutions.end());
}

// l2 calculates the distance from the sun at aphelion
double l2(double v1, double l1, double v2) { return (l1 * v1) / std::abs(v2); }

// Function calculates the semi-major axis of the planetary bodies orbit
double a(double l1, double l2) { return (1.0 / 2.0) * (l1 + l2); }

// Function calculates the semi-minor axis of the planetary bodies orbit
double b(double l1, double l2) { return std::sqrt(l1 * l2); }

// orbital_period calculates the orbital period of the planetary body

double orbital_period(double a, double b, double l1, double v1) {

  double pi = std::acos(-1);

  double numerator = 2 * pi * a * b;
  double denominator = l1 * v1;

  return numerator / denominator;
}

// orbital_eccentricity calculates the eccentricity of the planetary bodies
double orbital_eccentricity(double l1, double l2) {
  return (l2 - l1) / (l2 + l1);
}

// Prompts user to input the velocity v1
std::string v1_input() {

  std::cout << "Input perihelion velocity in m/s (v1): ";
  std::string inputv1;
  std::cin >> inputv1;
  return inputv1;
}

// Prompts user to input distance l1
std::string l1_input() {

  std::cout << "Input perihelion distance in meters (l1): ";
  std::string inputl1;
  std::cin >> inputl1;
  return inputl1;
}

void check_v1_l1(double v1, double l1) {

  if (v1 < 0 || l1 < 0) {
    throw std::runtime_error("v1 and l1 must be greater than 0.");
  }
}
