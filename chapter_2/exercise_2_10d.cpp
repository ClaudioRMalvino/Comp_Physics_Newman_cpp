/*
 * Exercise 2.10 Part c): The semi-empirical mass formula
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <vector>

// Function declaration

double E_per_nucleon(int Z, double A, double a5);
void semi_empirical_mass();

int main()
{

    std::cout
        << "Nuclear Binding Energy Calculator (semi-empirical mass approx)"
        << std::endl;
    semi_empirical_mass();

    return 0;
}

// Function definitions

/* Function calculates the approximate nuclear binding energy per nucleon
 * of an atom with atmoic number Z and mass number A.
 * Utilizes the semi-empirical mass formula.
 *
 * Returns binding energy per nucleon (B/A) in units of MeV
 */
double E_per_nucleon(int Z, double A, double a5)
{

    const double a1{15.8};  // [MeV]
    const double a2{18.3};  // [MeV]
    const double a3{0.714}; // [MeV]
    const double a4{23.2};  // [MeV]

    double term1 = a1 * A - a2 * std::pow(A, 2.0 / 3.0);
    double term2 = a3 * ((std::pow(Z, 2)) / (std::pow(A, 1.0 / 3.0)));
    double term3 = (a4 * (std::pow(A - 2 * Z, 2))) / A;
    double term4 = a5 / std::sqrt(A);

    double B = term1 - term2 - term3 + term4;

    return B / A;
}

/* Function provides the logical steps towards defining the value a5
 *  for E_per_nucleon parameter. It further calculates the most stable nucleus
 *  by running through all values of A in [Z, 3Z].
 *
 *  Returns the max binding energy per nuclean and its corresponding isotope A
 */

void semi_empirical_mass()
{

    for (int Z : std::views::iota(1, 101))
    { // 1 to 100 inclusive
        std::vector<double> values;
        std::vector<double> A_values;
        for (double A : std::views::iota(Z, 3 * Z + 1))
        {
            double a5;
            if (std::fmod(A, 2.0) != 0.0)
            {
                a5 = 0.0;
            }
            else if (Z % 2 == 0)
            {
                a5 = 12.0;
            }
            else
            {
                a5 = -12.0;
            }
            values.push_back(E_per_nucleon(Z, A, a5));
            A_values.push_back(A);
        }

        auto max_it = std::max_element(values.begin(), values.end());
        double max_BE = *max_it;
        int index = std::distance(values.begin(), max_it);
        double most_stable_A = A_values[index];

        // Prints the calculated values for each element
        std::cout << '\n' << "Atomic number: " << Z << std::endl;
        std::cout << std::fixed << std::setprecision(4)
                  << "Highest binding energy per nucleon: " << max_BE << " MeV"
                  << std::endl;
        std::cout << std::fixed << std::setprecision(2)
                  << "Most stable isotope: " << most_stable_A << " u" << '\n'
                  << std::endl;
        std::cout << "----------------------------------------------------\n"
                  << std::endl;
    }
}
