/**
 * Author: Fateh Karan Singh Sandhu
 * 
 * This program uses Prim's algorithm to produce a maximum spanning tree
 * from a given adjacency matrix
 */

#include <vector>
#include "csce310h0mework03part01.h"
#include <cmath>
#include <iostream>
#include<algorithm>

using namespace std;

double maximumST( vector< vector<double> > adjacencyMatrix ){

  double maximumSpanningTree = 0;
  vector<int> nodesVisited; //initialize vector
  nodesVisited.push_back(0); //start at the first node
  int maxElement = 0;
  int row = 0;
  int column = 0;

 for (int l = 0 ; l < adjacencyMatrix.size() ; l++) {
  for (int i = 0 ; i < nodesVisited.size() ; i++) {
    for (int j = 0 ; j < adjacencyMatrix.size() ; j++) {
      if (adjacencyMatrix[nodesVisited[i]][j] > maxElement) {
        maxElement = adjacencyMatrix[nodesVisited[i]][j]; //get max
        row = i;
        column = j;
      }
    }
  }
  maximumSpanningTree += maxElement; //add maxEdge to Tree
  for (int k = 0 ; k < adjacencyMatrix.size() ; k++) {
    if (l == 0) {
      adjacencyMatrix[k][row] = 0; //take column 0 out of consideration for first node
    }
    adjacencyMatrix[k][column] = 0; //take columns out of consideration
  }
  nodesVisited.push_back(column); //push back node visited
  row = 0;
  column = 0;
  maxElement = 0;
  }

  return maximumSpanningTree;
}
