/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/partitioning-numbers/submissions/code/1320868753
 * Title: hw4_2.cpp
 * Abstract: Reads a number of input values and the values themselves. Then, your program should put all negative numbers in front of all positive numbers.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/16/2020
 */

#include <iostream>
#include <vector>
using namespace std;

vector <int> add();
void approach_one(vector <int> vec);
void approach_two(vector <int> vec);
void print(vector <int> vec);

int main(){
  vector <int> int_holder = add();
  approach_one(int_holder);
  approach_two(int_holder);
  //print(int_holder);
  return 0;
}

vector <int> add(){
  int size, elements;
  cin >> size;
  vector <int> vec;
  for(int i = 0; i < size; i++){
    cin >> elements;
    vec.push_back(elements);
  }
  return vec;
}

void approach_one(vector <int> vec){
  int temp;
  for(int j = vec.size() - 1; j > 0; j--){
    for(int i = 0; i < j; i++){
      if(vec.at(i) > 0 && vec.at(j) < 0){
        temp = vec.at(i);
        vec.at(i) = vec.at(j);
        vec.at(j) = temp;
      }
    }
  }
  print(vec);
}

void approach_two(vector <int> vec){
  int temp;
  for(int i = 0; i < vec.size() - 1; i++){
    for(int j = i; j < vec.size(); j++){
      if(vec.at(i) > 0 && vec.at(j) < 0){
        temp = vec.at(i);
        vec.at(i) = vec.at(j);
        vec.at(j) = temp;
      }
    }
  }
  print(vec);
}

void print(vector <int> vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec.at(i) << " ";
  }
  cout << "\n";
}