/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw10/challenges/radix-sort-4-1/submissions/code/1323144514
 * Title: hw10_1.cpp
 * Abstract: conducts radix_sort()
 * Author: Antonio Felix
 * ID: 9121
 * Date: 4/26/2020
 */

#include <iostream>
using namespace std;

void print(int arr[], int size){
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void lets_start(int arr[], int size){
  for(int i = 0; i < size; i++)
    cin >> arr[i];
}

int max_num(int arr[], int size){
  int max = arr[0];
  for(int i = 1; i < size; i++)
    if(max < arr[i])
      max = arr[i];
  return max;
}

void count_start(int arr[], int size, int e){
  int output[size]; 
  int i, count[10] = {0}; 
   
  for (i = 0; i < size; i++) 
    count[ (arr[i]/e)%10 ]++; 
   
  for (i = 1; i < 10; i++) 
    count[i] += count[i - 1]; 
  
  for (i = size - 1; i >= 0; i--) { 
    output[count[ (arr[i]/e)%10 ] - 1] = arr[i]; 
    count[ (arr[i]/e)%10 ]--; 
  } 

  for (i = 0; i < size; i++) 
    arr[i] = output[i]; 
}

void radix_sort(int arr[], int size){
  int max = max_num(arr, size);

  for(int i = 1; max/i > 0; i *= 10){
    count_start(arr, size, i);
    print(arr, size);
  }
}

int main(){
  int size;
  cin >> size;
  int arr[size];
  
  lets_start(arr, size);
  radix_sort(arr, size);

  return 0;
}