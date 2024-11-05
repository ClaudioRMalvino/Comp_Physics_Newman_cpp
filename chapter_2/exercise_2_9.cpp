/*
 * Exercise 2.9: The Madelung Constant
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include <cmath>
#include <iostream>
#include <ranges>

// Function declaration

double madelung_constant(int L);

int main()
{

    int L{100};
    auto result{madelung_constant(L)};

    std::cout << "Madelung constant " << result << std::endl;

    return 0;
}

// Function definition

// Function calculates the MAdelung constant for crystalline sodium chloride
double madelung_constant(int L)
{

    double M{0.0};
    for (int i : std::views::iota(-L, L + 1))
    {
        for (int j : std::views::iota(-L, L + 1))
        {
            for (int k : std::views::iota(-L, L + 1))
            {
                if (i == 0 && j == 0 && k == 0)
                {
                    continue;
                }

                double r = std::sqrt(i * i + j * j + k * k);
                int exponent = std::abs(i) + std::abs(j) + std::abs(k);
                int sign = (exponent % 2 == 0) ? 1 : -1;
                M += sign / r;
            }
        }
    }
    return M;
}
