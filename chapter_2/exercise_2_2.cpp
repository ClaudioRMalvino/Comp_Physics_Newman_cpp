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
float altitude_of_satellite(float period)
{
    const float G{6.67E-11};  // Newton's gravitational constant
    const float mass{5.97E+24}; // Mass of the earth [kg]
    const float radius_e{6.37E+6};  // Earth's radius [m]
    const float pi{static_cast<float>(std::acos(-1))};

    // Calculates the orbital height necessary to sustain
    // an orbital period
    float height= std::pow((G * mass * std::pow(period, 2)) / (4.0 * std::pow(pi, 2)), 1.0 / 3.0) - radius_e;

    return height;
}

// convert_to_sec converts the input for the orbital period
// provides in minutes into seconds to properly calculates orbital height
float convert_to_sec(float minutes)
{
    float sec{minutes * 60};
    return sec;
}

int main()
{

    std::cout << "Input a orbital period in units of minutes: ";

    float minutes{};
    std::cin >> minutes;

    float period{convert_to_sec(minutes)};

    std::cout << '\n'
              << "For orbital period of " << minutes << " minutes" << '\n'
              << "Required orbital height: " << altitude_of_satellite(period) << " m" << std::endl;
    return 0;
}
