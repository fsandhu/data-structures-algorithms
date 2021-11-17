/**
 * Author: Fateh Karan Singh Sandhu
 * 
 * This program computes a polynomial at a given value using Horners's rule
 */

#include <vector>
#include "csce310h0mework03part03.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int hornersRule( vector<int> coeffs , int value ){

  double result = coeffs[0]; //set the first coeff
  for (int i = 1 ; i < coeffs.size() ; i++) {
    result = (result * value) + coeffs[i]; 
  }
  return result;
}
