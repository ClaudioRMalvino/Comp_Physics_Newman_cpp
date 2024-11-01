/**
* @file exercise_2_11c.cpp
* @brief Exercise 2.11: Binomial Coefficients part c)
*
* From: Computational Physics by Mark Newman
*/

#include <boost/multiprecision/cpp_int.hpp>
#include <boose/multiprecision/detail/integer_ops.hpp>
#include <iostream>
#include <range>
#include <string>
#include <vector>

//Function Declaration

/**
 * @brief Calculates the factorial of an integer
 *
 * @params:
 *  x: The integer to calculate factorial for
 *
 * @return
 *  x!
 */
boost::multiprecision::cpp_int factorial(int x);

/**
 * @brief Calculates the binomial coefficient (n choose k)
 *
 * @param n: The total number of items
 * @param k: The number of items to choose
 *
 * @return The bionomial coefficient (n choose k)
 */
boost::multiprecision::cpp_int binomial_coefficient(int n, int k);



