/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw2/challenges/reverse-number-13/submissions/code/1320169271
 * Title: hw2_1.cpp
 * Abstract: Reads a positive integer number from a user and displays the                   reverse of the number.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 1/31/2020
 */

#include <iostream>
#include<math.h>
using namespace std;

bool negative(int num);
int reverse(int num);

int main(){
  int output;
  int input;
  cin >> input;

  if(negative(input)){
    input *= -1;
    output = reverse(input) * -1;
  }else{
    output = reverse(input);
  }
  cout << output;

}

bool negative(int num){
  if(num < 0){
    return true;
  }
  return false;
}

int reverse(int num){
  int digit = (int) log10(num);

  if(num == 0){
    return 0;
  }
  return ((num % 10 * pow(10, digit)) + reverse(num/10));
}