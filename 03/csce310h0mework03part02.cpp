/**
 * Author: Fateh Karan Singh Sandhu
 * 
 * This program uses Floyds's algorithm to produce a all pairs shortest path tree
 * from a given adjacency matrix, output is computed upto the i'th stage.
 */

#include <vector>
#include "csce310h0mework03part02.h"
#include <cmath>
#include <iostream>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){

  for (int k = 0 ; k < i ; k++) {
    for (int j = 0 ; j < adjacencyMatrix.size() ; j++) {
      for (int l = 0 ; l < adjacencyMatrix.size() ; l++) {
        if (adjacencyMatrix[j][l] == -1) {
          adjacencyMatrix[j][l] = 100000; //set -1 to a large value
        }
        adjacencyMatrix[j][l] = min(adjacencyMatrix[j][l], adjacencyMatrix[j][k]+adjacencyMatrix[k][l]);
      }
    }
  }

  for (int a = 0 ; a < adjacencyMatrix.size() ; a++) {
      for (int b = 0 ; b < adjacencyMatrix.size() ; b++) {
        if (adjacencyMatrix[a][b] == 100000) {
          adjacencyMatrix[a][b] = -1; //change large value back to -1
        }
      }
    }

  return adjacencyMatrix;
}
