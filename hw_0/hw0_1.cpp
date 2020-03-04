/*
 * hackerrank link:https://www.hackerrank.com/contests/cst370-s20-hw0/challenges/370-hw0-1/submissions/code/1319710652
 * Title: hw0_1.cpp
 * Abstract: Allows user to choose 1 or 2. Allowing them to enter two numbers after giving the sum or difference of those two numbers
 * Name: Antonio Felix 
 * ID: 9121
 * Date: 1/22/2020
 */

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

int addition(int n, int m);
int difference(int n, int m);

int main() {
  int input = 0;
  int m, n;
  vector<int> vec;

  while(input != 9){
    cin >> input;
    if(input == 1){
      cin >> m >> n;
      vec.push_back(addition(m,n));
    }else if(input == 2){
      cin >> m >> n;
      vec.push_back(difference(m,n));
    }
  }

  for(auto i = vec.begin(); i != vec.end(); i++){
    cout << *i << endl;
  }

  return 0;
}

int addition(int n, int m){
  return n + m;
}

int difference(int n, int m){
  if(m > n){
    return m - n;
  }

  return n - m;
}