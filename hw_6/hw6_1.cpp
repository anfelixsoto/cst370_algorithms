/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/divide-and-conquer-max/submissions/code/1321588747
 * Title: hw6_1.cpp
 * Abstract: Displays the biggest number in an array with n integer numbers using a divide-and-conquer technique
 * Author: Antonio Felix
 * ID: 9121
 * Date: 3/7/2020
 */

#include <iostream>
#include <vector>
using namespace std;

void lets_start(vector <int> &vec);
int divide_conquer_max(vector <int> &vec, int l, int m);
void print(vector <int> &vec);

int main(){
  vector <int> int_holder;
  lets_start(int_holder);
  cout << divide_conquer_max(int_holder, 0, int_holder.size() - 1) << endl;
  return 0;
}

void lets_start(vector <int> &vec){
  int size, value;
  cin >> size;
  for(int i = 0; i < size; i++){
    cin >> value;
    vec.push_back(value);
  }
}


/*
https://stackoverflow.com/questions/7320188/divide-and-conquer-algorithms-to-find-the-maximum-element-of-an-array
*/
int divide_conquer_max(vector <int> &vec, int val1, int val2){
  if(val1 == val2){
    return vec.at(val1);
  }

  int size = (val1 + val2)/ 2;
  int val3 = divide_conquer_max(vec, val1, size);
  int val4 = divide_conquer_max(vec, size + 1, val2);
  return val3 > val4 ? val3 : val4;
}

void print(vector <int> &vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec.at(i) << " ";
  }
  cout << endl;
}