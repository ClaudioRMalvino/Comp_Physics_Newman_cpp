/*
 * Exercise 2.3: Converting Cartesian coordinates to polar coordinates
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <tuple>

// cart_to_polar calculates the radius (r) from the origin of point (x,y)
// and the angle theta. Returns a tuple (r, theta).
std::tuple<double, double> cart_to_polar(double x, double y)
{

    const double pi{std::acos(-1)};

    // Calculates the distance from the origin at point (x,y)
    double r = std::sqrt(std::pow(x, 2) + std::pow(y, 2));

    // Calculates the angle at point (x/y) from the axis and converts to degrees
    double theta = std::atan(y / x) * (180.0 / pi);

    return std::make_tuple(r, theta);
}

// get_x_pos asks for user input to define the x position and returns a string
std::string get_x_pos()
{

    std::cout << "Enter x: ";
    std::string inputx;
    std::cin >> inputx;
    return inputx;
}
// get_y_pos asks for user input to define the y position and returns a string
std::string get_y_pos()
{

    std::cout << "Enter y: ";
    std::string inputy;
    std::cin >> inputy;
    return inputy;
}

int main()
{

    std::cout << "Cartesian Coordinate to Polar Coordinate Converter" << '\n';

    // Loop which performs the required actions to take define (x,y) and returns
    // values for (r, theta).
    while (true)
    {

        auto inputx{get_x_pos()};
        if (inputx == "q")
        {
            break;
        }

        auto inputy{get_y_pos()};
        if (inputy == "q")
        {
            break;
        }

        try
        {

            // Converts our stings to doubles for the purpose of cart_to_polar(x,y)
            double x = std::stod(inputx);
            double y = std::stod(inputy);

            auto [r, theta] = cart_to_polar(x, y);

            std::cout << '\n' << "(r: " << r << ", theta: " << theta << ")" << '\n' << std::endl;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid input. Please enter numeric value" << std::endl;
        }
    }
    return 0;
}
