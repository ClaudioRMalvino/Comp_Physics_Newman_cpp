/*
Exercise 2.1: Another ball dropped from a tower

Textbook: Computational Physics by Mark Newman
*/

#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{

    double g{9.81}; // gravity of earth [m/s]

    std::cout << "Input height in meters: ";

    double h{}; // height [m]
    std::cin >> h;

    double t = sqrt((2 * h) / g); // calculates trave; time

    std::cout << "Total travel time: " << std::fixed << std::setprecision(2)
              << t << " s";

    return 0;
}
