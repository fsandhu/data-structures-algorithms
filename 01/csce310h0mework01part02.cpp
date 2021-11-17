#include "csce310h0mework01part02.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void printPermutations(string word, int permutations) {

  int index1 = 0; // create variable for index1 in algorithm
  int index2 = 0; // create variable for index2 in algorithm
  int loop = 0; //flag for loop
  int temp = permutations;

  // if word is of length 1, print the word out and end
  if (word.length() == 1 && permutations == 1) {
    cout << word[0] << endl;
    return;
  }

  // see if any characters are in decreasing order
  for (int m = 0; m < word.length() - 1; m++) {
    if (word[m] >= word[m + 1]) {
      loop = 1;
      break;
    } else {
      loop = 0;
    }
  }

  while (loop == 1 && permutations != 0) {
    if (temp == permutations) {
      cout << word << endl; //print out the word and not the first permutation
      permutations--;
    } else {
      for (int k = 0; k < word.length() - 1; k++) {
        if (word[k] > word[k + 1]) {
          index1 = k; //index such that a[index1]>a[index1+1]
        }
      }

      for (int l = 0; l < word.length(); l++) {
        if (word[index1] > word[l])
          index2 = l; //index such than a[index1]>a[index2]
      }

      swap(word[index1], word[index2]);
      //reverse order from a[index1+1] to a[word.length()]
      reverse(word.begin() + index1 + 1, word.end());
      permutations--; //decrease by 1 for each permutation printed
      cout << word << endl; //print permutation

      for (int m = 0; m < word.length() - 1; m++) {
        if (word[m] >= word[m + 1]) {
          loop = 1;
          break; 
        } else {
          loop = 0;
        }
      }
    }
  }
}