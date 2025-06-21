/**
 * Exercise 3.1: Plotting experimental data
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <fstream>
#include <iostream>
#include <ranges>
#include <vector>

// Function Declarations

std::vector<double> running_avg(int window_radius,
                                const std::vector<double> &y_k);

int main()
{
    return 0;
}

// Function Definitions

std::vector<double> running_avg(int window_radius,
                                const std::vector<double> &y_k)
{
    std::vector<double> Y_k;
    Y_k.reserve(y_k.size() - 10);

    double mu = 1.0 / (2 * r + 1);

    for (int k = 5; k < y_k.size() - 5; ++k)
    {
        double y_sum = 0.0;
        for (int m = -window_radius; m <= window_radius; ++m)
        {
            y_sum += y_k[k + m];
        }
        Y_k.push_back(mu * y_sum);
    }
    return Y_k;
}
