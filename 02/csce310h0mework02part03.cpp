/*
 * Author: Fateh Karan Singh Sandhu
 * NUID: 17286643
 *
 * This function takes an array as an input and returns the average number
 * of comparisons in a binary search of the array
 */

#include "csce310h0mework02part03.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

double averageComparisons( vector<int> numbers )
{
    //handle edge case for array size 1 and 2
    if (numbers.size() == 1) {
        return 1;
    }

    double averageComparisons = 0.0;
    int depthOfTree = ceil(log2(numbers.size())); //assume every array is a perfect BST
    int countOfLeaves = 0;
    if (depthOfTree - floor(log2(numbers.size())) == 0) {
        //if arraysize != 2 and is a perfect log2, add 1 depth for the last node
        depthOfTree++;
    }
    for (int i = 1 ; i < depthOfTree ; i++) {
        averageComparisons += i * pow(2, i-1); //increment averageComparisons
        countOfLeaves += pow(2, i-1); //update count of leaves in tree
    }
    int leavesAtLast = numbers.size() - countOfLeaves; //count leaves at last level since BST may not be fully filled
    averageComparisons += depthOfTree * leavesAtLast; //add comparisons for last level

    return (averageComparisons/numbers.size());
}
