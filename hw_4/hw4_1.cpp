/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/matching-form/submissions/code/1320871967
 * Title: hw4_1.cpp
 * Abstract: Reads a string and check if it’s well-formed or not.
 * Author: Antonio Felix
 * ID: 9121
 * Date:2/16/2020
 * https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/ as an example to get the case check and the checks that are needed to check if it is well formated.
 */


#include <iostream>
#include <vector>
using namespace std;

bool well_formated(string element);

int main(){
  string element;
  cin >> element;
  if(well_formated(element))
    cout << "TRUE";
  else
    cout << "FALSE";
}

bool well_formated(string element){
  vector <char> char_holder;
  char some_char;
  for(int i = 0; i < element.length(); i++){
    if(element[i] == '(' || element[i] == '[' || element[i] == '{'){
      char_holder.push_back(element[i]);
    }

    switch(element[i]){
      case ')':
        some_char = char_holder.at(char_holder.size() - 1);
        char_holder.pop_back();
        if(some_char == '[' || some_char == '{')
          return false;
        break;
      case '}':
        some_char = char_holder.at(char_holder.size() - 1);
        char_holder.pop_back();
        if(some_char == '(' || some_char == '[')
          return false;
        break;
      case ']':
        some_char = char_holder.at(char_holder.size() - 1);
        char_holder.pop_back();
        if(some_char == '(' || some_char == '{')
          return false;
        break;
    }
  }

  return (char_holder.empty());
}

void remove(vector <char> &vec, char charchar){
  for (vector<char>::iterator it = vec.begin(); it != vec.end(); ) {
    if (*it == charchar) {
      it = vec.erase(it);
      return;
    } else {
      ++it;
    }
  }
}