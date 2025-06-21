/**
 * Exercise 5.2: Utilizing the Extended Simpson Rule
 *
 * Textbook: Computational Physics by Mark Newman
 */
#include<array>
#include<cmath>
#include <iomanip>
#include<iostream>

// Namespaces
namespace Constant
{
    constexpr double actual { 4.4 };
    constexpr double upper_bound { 2.0 };
    constexpr double lower_bound { 0.0 };
    constexpr std::array<double, 3> num_slices = {10.0, 100.0, 1000.0};
}

// Forward declarations

/**
 * Function calculates the value for f(x) = x^4 - 2*x + 1
 * @param val
 * @return
 */
double func(double val);

/**
 * Function calculates an integral utilziing the Extended Simpson Rule
 * @param upper_bound Upper limit of integrations
 * @param lower_bound Lower limit of integration
 * @param num_slices  Number of slices
 * @return The area under the function
 */
double extSimpsonRule(
                        double upper_bound,
                        double lower_bound,
                        double num_slices );

/**
 * Function calculates the percent error between the numerical value and the
 * actual value
 * @param numerical
 * @param actual
 * @return percent error
 */
double per_error(double numerical, double actual);

/**
 * Prints the results of the calculations
 */
void print_results();

int main()
{
    print_results();
    return 0;
}

// Function definitions

double func( double val)
{
    return std::pow(val, 4) - 2*val + 1;
}
double extSimpsonRule(
    double upper_bound,
    double lower_bound,
    double num_slices)
{

    double width = (upper_bound-lower_bound)/num_slices;
    double constant = width / 3.0;
    double integral = constant * (func(lower_bound ) + func(upper_bound));
    double odds { 0.0 };
    double evens { 0.0 };

    for (int i = 1; i < num_slices; i += 2)
    {
        odds += func(lower_bound+ (i*width));
    }
    for (int i = 2; i < num_slices; i += 2)
    {
        evens += func(lower_bound+ (i*width));
    }
    integral += constant * (4*odds + 2*evens);
    return integral;
}

double per_error(double numerical, double actual)
{
    return (std::abs(numerical - actual) / actual ) * 100.0;
}

void print_results()
{
    for (double i : Constant::num_slices)
    {
        double result = extSimpsonRule(
                                    Constant::upper_bound,
                                    Constant::lower_bound,
                                    i);
        double percent_error = per_error(result, Constant::actual);

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "For N = " << i << '\n';
        std::cout << "Result = " << result << '\n';
        std::cout << "Error = " << percent_error << " % " << '\n';
    }

}
