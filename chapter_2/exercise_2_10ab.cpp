/*
 * Exercise 2.10 Parts a) & b): The semi-empirical mass formula
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// Function declaration

double semi_empirical_mass_formula(int Z, double A, double a5);
double semi_empirical_mass(int Z, double A);
std::string Z_input();
std::string A_input();
void check_A_Z(int Z, double A);
void print_results(int Z, double A, double B);

int main()
{

    std::cout
        << "Nuclear Binding Energy Calculator (semi-empirical mass approx)"
        << std::endl;
    std::cout << "Input 'q' to quit" << std::endl;

    while (true)
    {

        auto Zinput{Z_input()};
        if (Zinput == "q")
        {
            break;
        }
        int Z = std::stoi(Zinput);

        auto Ainput{A_input()};
        if (Ainput == "q")
        {
            break;
        }
        double A = std::stod(Ainput);

        try
        {

            check_A_Z(Z, A);
            auto B = semi_empirical_mass(Z, A);
            print_results(Z, A, B);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid input. Please enter a numeric value" << '\n'
                      << std::endl;
        }
    }
    return 0;
}

// Function definitions

/* Function calculates the approximate nuclear binding energy B of an atomic
 * nuclear with atmoic number Z and mass number A.
 *
 * Returns binding energy in units of MeV
 */
double semi_empirical_mass_formula(int Z, double A, double a5)
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

    return B;
}

/* Function provides the logical steps towards defining the value a5
 *  within the semi_emperical_formula function.
 *
 *  Returns the result of the semi_emperical_mass_formula
 */

double semi_empirical_mass(int Z, double A)
{

    double a5;

    if (std::fmod(A, 2.0) != 0.0)
    {
        double a5{0.0};
    }
    else if (Z % 2 == 0)
    {
        double a5{12.0};
    }
    else
    {
        double a5{-12.0};
    }

    return semi_empirical_mass_formula(Z, A, a5);
}

// Function prompts user to input a value for Z
std::string Z_input()
{

    std::cout << "Input atomic number (Z): ";
    std::string input;
    std::cin >> input;

    return input;
}

// Function prompts user to input a value for A
std::string A_input()
{

    std::cout << "Input atomic mass (A): ";
    std::string input;
    std::cin >> input;

    return input;
}

// Function checks if the input values for A and Z are within bounds
void check_A_Z(int Z, double A)
{

    if (A <= 0 || Z <= 0)
    {
        throw std::runtime_error("A and Z must be > 0");
    }
}

void print_results(int Z, double A, double B)
{

    double B_per_nucleon{B / A};

    std::cout << '\n' << "Atomic number: " << Z << std::endl;
    std::cout << "Mass number: " << A << " u" << std::endl;
    std::cout << std::fixed << std::setprecision(2)
              << "Approx nuclear binding energy: " << B << " MeV" << std::endl;
    std::cout << std::fixed << std::setprecision(2)
              << "Binding energy per nucleon: " << B_per_nucleon << " MeV"
              << '\n'
              << std::endl;
}
