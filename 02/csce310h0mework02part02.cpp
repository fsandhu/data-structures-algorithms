/*
 * Author: Fateh Karan Singh Sandhu
 * NUID: 17286643
 *
 * This function takes in a vector of multiple values and returns the
 * closest difference between two values.
 */

#include "csce310h0mework02part02.h"
#include <vector>
#include <iostream>
#include <cmath>

    using namespace std;

    double closestNumbers( vector<double> numbers )
    {
        double closestDistance = abs(numbers[0]-numbers[1]);
        if (numbers.size() == 2) {
            return closestDistance; // if vector is of size 2, return the difference of first 2 and exit
        } else {
        for (int i = 1 ; i < numbers.size()-1 ; i++) {
            if (abs(numbers[i] - numbers[i+1]) < closestDistance) {
                closestDistance = abs(numbers[i] - numbers[i+1]); // update new closest distance
            }
        }
        return closestDistance; //return closest distance
        }
    }
