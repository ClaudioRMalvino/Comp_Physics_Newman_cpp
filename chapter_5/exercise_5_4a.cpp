/**
* Exercise 5.4 Part a): The diffraction limit of a telescope
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <array>
#include <cmath>
#include <iostream>
#include "../third_party/matplotlibcpp.h"

#include <any>
#include <numbers>
#include <vector>

// Namespaces

namespace plt = matplotlibcpp;

// Forward function declarations

/**
 * Function calculates the vales of the Bessel function of the
 *  first kind J_m(x) in the integral representation:
 * (1/pi) * ( cos( m*theta - x*sin(theta) )
 *
 * @param n
 * @param x
 * @param theta
 * @return
 */
constexpr double bessel_j(double n, double x, double theta);

/**
 * Function utilizes the extended Simpson Rule to calculate the integral
 * representation of the Bessel function of the first kind bessel_j(n, x, theta)
 * @param n
 * @param x
 * @return
 */
double ext_simpson_rule(double n, double x);

/**
 * Function plots the values for bessel_j() from x: [0, 21) and n: [0, 3)
 * @param xs
 * @param values
 */
void plot_bessel_function(std::vector<double> xs, auto values);

int main()
{

    std::vector<double> xs, ns;

    for (int i = 0; i < 21; i += 1)
    {
        xs.push_back(i);
    }
    for (double i = 0; i < 3; i += 1)
    {
        ns.push_back(i);
    }
    std::array<std::array<double, 21>, 3> values;

    for (int i = 0; i < 3; i += 1)
    {
        for (int j = 0; j < 21; j += 1)
        {
            values[i][j] = ext_simpson_rule(static_cast<double>(i),
                                                static_cast<double>(j));
        }
    }
    plot_bessel_function(xs, values);
    return 0;
}

// Function definitions

constexpr double bessel_j(double n, double x, double theta)
{
    return std::cos( n * theta - x * std::sin(theta) );
}

double ext_simpson_rule(double n, double x)
{
    constexpr double coeff { 1.0 / std::numbers::pi };
    constexpr double num_slices { 5000.0 };
    constexpr double lower_bound { 0.0 };
    constexpr double upper_bound { std::numbers::pi };
    constexpr double width_slices { (upper_bound - lower_bound) / num_slices };
    constexpr double const_C { coeff * width_slices / 3.0 };
    double integral { const_C * ( bessel_j(n, x, lower_bound) +
                            bessel_j(n, x, upper_bound) )};
    double odds { 0.0 };
    double evens { 0.0 };

    for (int i = 1; i < num_slices; i += 2)
    {
        odds += bessel_j(n, x, i * width_slices);
    }
    for (int i = 2; i < num_slices; i += 2)
    {
        evens += bessel_j(n, x, i * width_slices);
    }

    integral +=  const_C * (4 * odds + 2 * evens);
    return integral;
}

void plot_bessel_function(std::vector<double> xs, auto values)
{
    plt::backend("Agg");
    try
    {
        plt::title( "Bessel Functions $J_{0}(x), J_{1}(x), J_{2}(x)$");
        plt::plot(xs, values[0], "b-", xs, values[1], "r-", xs, values[2], "g-");
        // plt::legend( {"$J_{0}(x)$", "$J_{1}(x)$", "$J_{2}(x)$"} );
        plt::xlabel("x");
        plt::ylabel("J(x)");
        plt::ylim(-1.5, 1.5);
        plt::show();
        plt::save("../chapter_5/exercise_5_4a_plot.png");
        std::cout << "Plot saved as exercise_5_4a_plot.svg" << '\n';
    } catch (const std::exception &e)
    {
        std::cerr << "Could not create plot: " << e.what() << '\n';
    }
}