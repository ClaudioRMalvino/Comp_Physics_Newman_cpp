/*
 * Exercise 2.2: Altitude of a satellite
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <iomanip>
#include <iostream>

// altitude_of_satellite takes the orbital period as parameter,
// and returns the orbital height necessary
int altitude_of_satellite(double T) {
  const double G{6.67E-11}; // Newton's gravitational constant
  const double M{5.97E+24}; // Mass of the earth [kg]
  const double R{6.37E+6};  // Earth's radius [m]
  const double pi{std::acos(-1)};

  // Calculates the orbital height necessary to sustain
  // an orbital period T
  double h = std::pow((G * M * std::pow(T, 2)) 
            / ( 4.0 * std::pow(pi, 2)), 1.0/3.0) - R;

  return h;
}

// convert_to_sec converts the input for the orbital period
// provides in minutes into seconds to properly calculates orbital height
double convert_to_sec(double minutes) {
  double sec{minutes * 60};
  return sec;
}

int main() {

  std::cout << "Input a orbital period in units of minutes: ";

  double min{};
  std::cin >> min;

  double T{convert_to_sec(min)};

  std::cout << '\n' << "For orbital period of " << min << " minutes" << '\n'
            << "Required orbital height: " << altitude_of_satellite(T) 
            << " m" << std::endl;
  return 0;
}
