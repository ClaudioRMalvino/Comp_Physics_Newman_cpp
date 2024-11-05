/*
 * Exercise 2.5: Quantum Potential Step
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// Global constants

const double m{0.5109989461};  // Mass of electron [eV]
const double h_bar{6.5821196}; // Reduced Planck constant [eV*s]

// Function declarations

double k1(double E);
double k2(double E, double V);
double T(double k1, double k2);
double R(double k1, double k2);
std::string E_input();
std::string V_input();

int main()
{

    std::cout << "Calculating transimission and reflection probabilities"
              << '\n'
              << "Input 'q' to quit" << '\n'
              << std::endl;

    while (true)
    {

        auto inputE{E_input()};
        if (inputE == "q")
        {
            break;
        }
        double E = std::stod(inputE);

        auto inputV{V_input()};
        if (inputV == "q")
        {
            break;
        }
        double V = std::stod(inputV);

        if (E <= V)
        {
            double k{-k1(E)};
            std::cout << std::fixed << std::setprecision(3)
                      << "wavevector: " << k
                      << ", Probability of reflection: 100%" << std::endl;
        }
        else
        {
            std::cout << "\nGiven an electron of mass " << m
                      << " eV, initial energy " << E
                      << " eV and potential step " << V << "eV:\n\n";

            double k1_val{k1(E)};
            double k2_val{k2(E, V)};

            std::cout << std::fixed << std::setprecision(1)
                      << "Probability of reflection: "
                      << R(k1_val, k2_val) * 100
                      << "% || wavevector: " << std::setprecision(3) << -k1_val
                      << '\n';

            std::cout << std::fixed << std::setprecision(1)
                      << "Probability of transmission: "
                      << T(k1_val, k2_val) * 100
                      << "% || wavevector: " << std::setprecision(3) << k2_val
                      << '\n';
        }
    }
    return 0;
}

// Function definitions

// k1 calculates initial wave vector k1
double k1(double E)
{
    return std::sqrt(2 * m * E / h_bar);
}

// k2 calculates reflected wave vector k2
double k2(double E, double V)
{
    return std::sqrt(2 * m * (E - V) / h_bar);
}

// R calculates the probability of reflecting back towards the initial source
// given k1 and k2
double R(double k1, double k2)
{
    double k_diff = k1 - k2;
    double k_sum = k1 + k2;
    return (k_diff * k_diff) / (k_sum * k_sum);
}

// T calculates the probability of transmission over the potential step
// given k1 and k2
double T(double k1, double k2)
{

    double k_sum = k1 + k2;
    return (4 * k1 * k2) / (k_sum * k_sum);
}

// Prompts user to input energy of the electron
std::string E_input()
{

    std::cout << '\n' << "Input energy of electron in eV: ";
    std::string inputE;
    std::cin >> inputE;
    return inputE;
}

// Prompts user to input the energy of the potential step
std::string V_input()
{

    std::cout << '\n' << "Input energy of potential step in eV: ";
    std::string inputV;
    std::cin >> inputV;
    return inputV;
}
