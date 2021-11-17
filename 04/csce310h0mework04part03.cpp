/**
 * Author: Fateh Karan Singh Sandhu
 * Date: 19 November 2019
 * 
 * This program takes in a grid  as an input and returns the most
 * money that can be made
 * 
**/

#include "csce310h0mework04part03.h"
#include <vector>

using namespace std;

int collectWithLoss( vector< vector<int> > grid ){

  //set all -1's to 0's
  for (int i = 0 ; i < grid.size() ; i++) {
    for (int j = 0 ; j < grid[i].size() ; j++) {
      if (grid[i][j] == -1) {
        grid[i][j] = 0;
      }
    }
  }

  for (int i = 1 ; i < grid.size() ; i++) {
   if(grid[i][0] != 0) {
    grid[i][0] = grid[i-1][0] + grid[i][0];
   }
  }
  
  for (int i = 1 ; i < grid[0].size() ; i++) {
   if(grid[0][i] != 0) {
    grid[0][i] = grid[0][i-1] + grid[0][i];
   }
  }

  for (int i = 1 ; i < grid.size() ; i++) {
    for (int j = 1 ; j < grid[i].size() ; j++) {
      if (grid[i][j] != 0) {
        grid[i][j] = max(grid[i-1][j]+grid[i][j], grid[i][j-1] + grid[i][j]);
      }
    }
  }
  
  return grid[grid.size()-1][grid[0].size()-1]; 
}
