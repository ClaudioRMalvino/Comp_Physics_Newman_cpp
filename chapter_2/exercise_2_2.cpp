/*
 * Exercise 2.2: Altitude of a satellite
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>

//Global constants

const double G{6.67E-11};       // Newton's gravitational constant
const double mass{5.97E+24};    // Mass of the earth [kg]
const double radius_e{6.37E+6}; // Earth's radius [m]


// altitude_of_satellite takes the orbital period as parameter,
// and returns the orbital height necessary
double altitude_of_satellite(double period)
{
    //
    // Calculates the orbital height necessary to sustain
    // an orbital period
    double numerator{G * mass * std::pow(period, 2)};
    double denominator{4.0 * std::pow(std::numbers::pi, 2)};

    double height = std::cbrt((numerator / denominator)) - radius_e;

    return height;
}

// convert_to_sec converts the input for the orbital period
// provides in minutes into seconds to properly calculates orbital height
double convert_to_sec(double minutes)
{
    double sec{minutes * 60.0};
    return sec;
}

int main()
{

    std::cout << "Input a orbital period in units of minutes: ";

    double minutes{};
    std::cin >> minutes;

    double period{convert_to_sec(minutes)};

    std::cout << '\n'
              << std::setprecision(3) << "For orbital period of " << minutes
              << " minutes" << '\n'
              << "Required orbital height: " << altitude_of_satellite(period)
              << " m" << '\n';
    return 0;
}
