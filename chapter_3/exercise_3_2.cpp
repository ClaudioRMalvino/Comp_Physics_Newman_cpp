/**
 * @file exercise_3_2.cpp
 * @brief Exercise 3.2: Curve Plotting
 *
 * Textbook: Computational Physics by Mark Newman
 */

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    plt::plot({1,3,2,4});
    plt::show();
}
