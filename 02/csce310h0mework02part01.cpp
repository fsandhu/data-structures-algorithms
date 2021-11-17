/*
 * Author: Fateh Karan Singh Sandhu
 * NUID: 17286643
 *
 * This function takes in a vector and string of signs and outputs a new vector
 * with all values placed in accordance with the signs
 */

#include "csce310h0mework02part01.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> placeNumbers( vector<int> numbers , string signs ){

    int numbersPlacedFromEnd = 0; //count for numbers placed from the end of the vector
    vector<int> numbersPlaced; //new vector with numbers placed in accordance to signs
    for (int i = 0 ; i < numbers.size() ; i++) {
        if (signs[i] == '>') {
            numbersPlaced.push_back(numbers[numbers.size()-1-numbersPlacedFromEnd]); //add to new vector
            numbersPlacedFromEnd++; //iterate variable for every number added from end
        } else if (signs[i] == '<') {
            numbersPlaced.push_back(numbers[i-numbersPlacedFromEnd]);
        }
    }
    numbersPlaced.push_back(numbers[numbers.size()-1-numbersPlacedFromEnd]); //insert last number into the vector
    return numbersPlaced; //return new vector
}
