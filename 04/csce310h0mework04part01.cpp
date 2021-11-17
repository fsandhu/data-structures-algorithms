/**
 * Author: Fateh Karan Singh Sandhu
 * Date: 19 November 2019
 * 
 * This program takes in a vector of weights as an input and then optimally
 * divides them into two teams with least difference in total weights
 * 
**/

#include "csce310h0mework04part01.h"
#include <vector>

using namespace std;

int tugOfWar( vector<int> weight ){

  int sumOfWeights = 0;

  for (int i = 0 ; i < weight.size() ; i++) {
    sumOfWeights += weight[i]; //get total weight
  } 

  int sizeOfMatrix = (sumOfWeights/2); //get the size of matrix

  vector< vector<int> > matrix(weight.size()+1); //create memoization vector
  vector<int> column; //create column to push in
  column.push_back(1);
  for (int i = 1 ; i <= sizeOfMatrix ; i++) {
    column.push_back(0);
  }

  for (int i = 0 ; i <= weight.size() ; i++) {
    matrix[i] = column;
  }

  for (int i = 1 ; i <= weight.size() ; i++) {
    for (int j = 1 ; j <= sizeOfMatrix ; j++) {
      if (matrix[i-1][j] == 1) {
        matrix[i][j] = 1;
      } else {
        if (weight[i-1] > j) {
          matrix[i][j] = 0;
        } else {
          matrix[i][j] = matrix[i-1][j-weight[i-1]];
        }
      }
    }
  }
  
  int c = 0;
  
  for (c = sizeOfMatrix ; c != 0 ; c--) {
    if (matrix[weight.size()][c] == 1) {
      break;
    }
  }

  return sumOfWeights-2*c; //return least difference
}
