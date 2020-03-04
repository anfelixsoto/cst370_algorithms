/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/binary-numbs/submissions/code/1320670158
 * Title: hw3_1.cpp
 * Abstract: Program that reads a number of elements in a set and then read the elements of the set. After that, your                  program should display all possible binary numbers and corresponding subsets one by one
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/12/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
using namespace std;

vector <string> add(int size);
vector <int> set_binary(int size);
void print_subset(vector <string> vec);
void print(vector <string> vec);

int main(){
  int size;
  cin >> size;
  vector <string> string_holder = add(size);
  reverse(string_holder.begin(), string_holder.end());
  print_subset(string_holder);
  return 0;
}

vector <string> add(int size){
  string element;
  vector<string> vec;
  for(int i = 0; i < size; i++){
    cin >> element;
    vec.push_back(element);
  }
  return vec;
}

void print_subset(vector <string> vec){
  int count = pow(2, vec.size());

  if(vec.empty()){
    cout << "0:EMPTY\n";
    return;
  }

  for(int i = 0; i < count; i++){
    string binary_rep = bitset<10>(i).to_string();
    cout << binary_rep.substr(binary_rep.length() - vec.size()) << ":";
    for(int j = vec.size() - 1; j >= 0; j--){
      if(i == 0){
        cout << "EMPTY";
        break;
      }else if((i & (1 << j)) > 0){
        cout << vec.at(j) << " ";
      }
    }
    cout << '\n';
  }
}

void print(vector <string> vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec.at(i) << " ";
  }
  cout << '\n';
}