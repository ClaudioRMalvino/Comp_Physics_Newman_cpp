/*
 * Exercise 2.4: Calculating travel time form two different reference frames
 * at relativistic speeds.
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

// Global constant
double c = 299792458.0; // Speed of light [m/s]

// Function calculates the time it takes to travel distance x at a fraction
// of the speed of light from Earth reference point.
double earth_ref_frame(double x, double v)
{
    double x_meters{x * 9.460730E+15};
    double beta = v * c;
    return x_meters / beta;
}

// Function calculates the proper time from the reference cframe of the
// passenger on the ship traversing a distance x at a velocity a fraction of
// the speed of light.
double ship_ref_frame(double x, double v)
{
    double gamma = 1 / std::sqrt(1 - std::pow(v, 2));
    return earth_ref_frame(x, v) / gamma;
}

// get_distance asks for user input to define the distance travelled
// in light years and returns a string
std::string get_distance()
{

    std::cout << "Enter distance in lightyears: ";
    std::string inputx;
    std::cin >> inputx;
    return inputx;
}

// get_velocity asks for user input to define the velocity of the spaceship
// and returns a string
std::string get_velocity()
{

    std::cout << '\n'
              << "Enter velocity as a fraction of the speed"
              << " of light (number from (0, 1]) ): ";
    std::string inputv;
    std::cin >> inputv;
    return inputv;
}

void check_velocity(double v)
{
    if (v <= 0 || v > 1)
    {
        throw std::runtime_error("Velocity must be between (0,1]");
    }
}

void check_distance(double x)
{
    if (x < 0)
    {
        throw std::runtime_error("Velocity must be between > 0");
    }
}

int main()
{

    const double conversion{31556952.}; // conversion from seconds to years

    std::cout << "Calculating travel time from Earth reference frame and"
              << " passenger reference frame." << '\n'
              << "Input 'q' to quit" << std::endl;

    while (true)
    {

        auto inputx{get_distance()};
        if (inputx == "q")
        {
            break;
        }

        auto inputv{get_velocity()};
        if (inputv == "q")
        {
            break;
        }

        try
        {

            double x = std::stod(inputx);
            double v = std::stod(inputv);

            check_distance(x);
            check_velocity(v);

            auto earth_frame{earth_ref_frame(x, v) / conversion};
            auto ship_frame{ship_ref_frame(x, v) / conversion};

            std::cout << '\n'
                      << "Travel time from Earth reference frame: "
                      << std::fixed << std::setprecision(2) << earth_frame
                      << " years" << '\n'
                      << "Travel time from ship reference frame: " << std::fixed
                      << std::setprecision(2) << ship_frame << " years"
                      << std::endl;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid input. Please enter numeric value" << '\n'
                      << std::endl;
        }
    }
    return 0;
}
