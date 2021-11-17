#include "csce310h0mework01part01.h"
#include <string>

using namespace std;

string commonLetters( string word01 , string word02 ){
  string common = "";
  int temp = 0;

   for (int i = 0 ; i < word01.length() ; i++) {
    for (int j = temp ; j < word02.length() ; j ++) {
      if (word01[i] == word02[j]) {
        common += word01[i]; //add common letter to string
        temp = j + 1; //to skip to the next letter
        break;
      }
    }
  }

  return common;
}
