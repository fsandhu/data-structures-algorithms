/**
 * Author: Fateh Karan Singh Sandhu
 * Date: 19 November 2019
 * 
 * This program takes in a vector of two lane segments and time penalties
 * and returns the shortest time to finish the race
 * 
**/

#include <vector>
#include "csce310h0mework04part02.h"
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int footRace( vector<int> laneA , vector<int> laneB , vector<int> aToB , vector<int> bToA ){

  vector<int> row1; //create row1
  vector<int> row2; //create row2

  for (int a = 0 ; a <= laneA.size() ; a++) {
    row1.push_back(0);
    row2.push_back(0);
  }

  vector< vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);

  matrix[0][0] = 0;
  matrix[1][0] = 0;

  matrix[0][1] = laneA[laneA.size()-1];
  matrix[1][1] = laneB[laneB.size()-1];

    for (int j = 2 ; j <= laneA.size() ; j++) {
      matrix[0][j] = min(matrix[0][j-1]+laneA[laneA.size()-j], matrix[1][j-1] + laneA[laneA.size()-j] + aToB[aToB.size()-j+1]);
      matrix[1][j] = min(matrix[1][j-1]+laneB[laneB.size()-j], matrix[0][j-1] + laneB[laneB.size()-j] + bToA[bToA.size()-j+1]);
    }

  return min(matrix[0][laneA.size()], matrix[1][laneB.size()]); //return shortest time
}
