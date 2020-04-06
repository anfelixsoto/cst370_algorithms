/*
 * Title: hw7_2.cpp
 * Abstract: That displays the performance of three different sorting algorithms
 * Author: Antonio Felix
 * ID: 9121
 * Date: 3/24/2020
 */

#include <iostream>
#include <ctime>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <random>
#include <algorithm>
using namespace std;

void populate_arr(int *temp, int size);

void print_menu();
void print_type(string type);

void sorting(int *temp, int size, string type);

void insertion_sort(int *arr, int size, string type);

void merge_sort(int *arr,int p,int r, string type);
void ascending_merge(int *arr, int p, int q, int r);
void descending_merge(int *arr, int p, int q, int r);
void random_merge(int *arr, int p, int q, int r);

void quick_sort(int *arr, int start, int end, string type);
int ascending_partition(int *arr, int start, int end);
int descending_partition(int *arr, int start, int end);
int random_partition(int *arr, int start, int end);

void print(int *arr, int size);

int main(){
  int *temp;
  int input_size, option;
  string type;
  cout << "Enter input size: ";
  cin >> input_size;
  temp = new int[input_size];

  populate_arr(temp, input_size);

  print_menu();
  cin >> option;

  if(option == 1)
    type = "ascending";
  else if(option == 2)
    type = "descending";
  else
    type = "random";

  sorting(temp, input_size, type);
  delete [] temp;

  return 0;

}

void populate_arr(int *temp, int size){
  for(int i = 0; i < size; i++)
    temp[i] = rand() % 1000;
}

void print_menu(){
  cout << "========== Select Order of Input Numbers ==========\n";
  cout << " " << "1. Ascending Order\n";
  cout << " " << "2. Descending Order\n";
  cout << " " << "3. Random Order\n";
  cout << "Choose order: ";
}

void print_type(string type){
  cout << "============================================================\n";
  cout << "Generate input data in " << type << " order . . .\n";
  cout << "Done.";
  cout << "\n============================================================\n\n";
}

void sorting(int *temp, int size, string type){
  print_type(type);
  unsigned seed = 0;
  vector <float> time_totals;
  
  clock_t insertion_clock, merge_clock, quick_clock;
  clock_t insertion_end, merge_end, quick_end;

  float insert_total = 0.0, merge_total = 0.0, quick_total = 0.0;

  if(type == "random")
    shuffle(&temp[0], &temp[size], default_random_engine(seed));

  map <float, string> results;
  float val1, val2, val3;

  for(int i = 0; i < 3; i++){
    int *arr1, *arr2, *arr3;
    arr1 = new int[size], arr2 = new int[size], arr3 = new int[size];
    if(i == 0)
      cout << "========================== 1st Run =========================\n";
    else if(i == 1)
      cout << "========================== 2nd Run =========================\n";
    else
      cout << "========================== 3rd Run =========================\n";

    arr1 = temp, arr2 = temp, arr3 = temp;

    insertion_clock = clock();
    insertion_sort(arr1, size, type);
    insertion_end = clock();
    val1 = (insertion_end - insertion_clock) / (float)(CLOCKS_PER_SEC / 1000);
    cout << "Inseration sort: " << val1  << " milliseconds" << endl;

    merge_clock = clock();
    merge_sort(arr2, 0, size - 1, type);
    merge_end = clock();
    val2 = (merge_end - merge_clock) / (float)(CLOCKS_PER_SEC / 1000);
    cout << "Merge sort: " << val2  << " milliseconds" << endl;

    quick_clock = clock();
    quick_sort(arr3, 0, size - 1, type);
    quick_end = clock();
    val3 = (quick_end - quick_clock) / (float)(CLOCKS_PER_SEC / 1000);
    cout << "Quick sort: " << val3 << " milliseconds" << endl;

    cout << "============================================================\n\n";
    insert_total += val1, merge_total += val2, quick_total += val3;
  }
  

  time_totals.push_back(insert_total/3);
  time_totals.push_back(merge_total/3);
  time_totals.push_back(quick_total/3);

  sort(time_totals.begin(), time_totals.end());

  cout << "========================== Ranking =========================\n";
  for(int i = 0; i < time_totals.size(); i++){
    cout << "(" << i + 1 << ")";
    if(time_totals.at(i) == insert_total/3)
      cout << "Insertion Sort";
    else if(time_totals.at(i) == merge_total/3)
      cout << "Merge Sort";
    else
      cout << "Quick Sort";

    cout << " " << time_totals.at(i) << endl;
  }
  cout << "============================================================\n";
}

void insertion_sort(int *arr, int size, string type){
  int j, temp;
  for(int i = 0; i < size; i++){
    j = i;
    if(type == "ascending"){
      while(j > 0 && arr[j] < arr[j - 1]){
        temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
      }
    }else if(type == "descending"){
     while(j > 0 && arr[j] > arr[j - 1]){
        temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
      } 
    }else{
      while(j > 0 && arr[j] % 2 != 0){
        temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
      }
    }
  }
}

void merge_sort(int *arr,int p,int r, string type){
  int q;                                
  if(p<r){
    q=(p+r)/2;
    merge_sort(arr,p,q, type);
    merge_sort(arr,q+1,r, type);
    if(type == "ascending")
      ascending_merge(arr,p,q,r);
    else if(type == "descending")
      descending_merge(arr, p, q, r);
  }
}

void ascending_merge(int *arr, int p, int q, int r){
  
  int n1,n2,i,j,k; 
  int *L, *R;

  n1=q-p+1;
  n2=r-q;  

  L = new int[n1], R = new int[n2]; 

  for(i=0; i<n1; i++){
    L[i] = arr[p+i];
  }

  for(j = 0; j < n2; j++){
    R[j] = arr[q+j+1];
  }
  
  i=0, j=0;

  for(k = p; i < n1 && j < n2; k++){
    if(L[i] < R[j]){
      arr[k] = L[i++];
    }else{
      arr[k] = R[j++];
    }
  }

  while(i < n1){
    arr[k++] = L[i++];
  }

  while(j < n2){
    arr[k++] = R[j++];
  }
}

void descending_merge(int *arr, int p, int q,int r){

  int n1,n2,i,j,k; 
  int *L, *R;

  n1=q-p+1;
  n2=r-q;  

  L = new int[n1], R = new int[n2]; 

  for(i = 0; i < n1; i++){
    L[i] = arr[p+i];
  }

  for(j = 0; j < n2; j++){
    R[j] = arr[q+j+1];
  }
  
  i=0, j=0;

  for(k = p; i < n1 && j < n2; k++){
    if(L[i] > R[j]){
      arr[k] = L[i++];
    }else{
      arr[k] = R[j++];
    }
  }

  while(i < n1){
    arr[k++] = L[i++];
  }

  while(j < n2){
    arr[k++] = R[j++];
  }
}

void random_merge(int *arr, int p, int q,int r){
  int n1,n2,i,j,k; 
  int *L, *R;

  n1=q-p+1;
  n2=r-q;  

  L = new int[n1], R = new int[n2]; 
  
  for(i = 0; i < n1; i++){
    L[i] = arr[p+i];
  }

  for(j = 0; j < n2; j++){
    R[j] = arr[q+j+1];
  }
  
  i=0, j=0;

  for(k = p; i < n1 && j < n2; k++){
    if(L[i] % R[j == 0]){
      arr[k] = L[i++];
    }else{
      arr[k] = R[j++];
    }
  }

  while(i < n1){
    arr[k++] = L[i++];
  }

  while(j < n2){
    arr[k++] = R[j++];
  }
}

void quick_sort(int *arr, int start, int end, string type){
  int p_index;
  if(start < end){
    if(type == "ascending")
      p_index = ascending_partition(arr, start, end);
    else if(type == "descending")
      p_index = descending_partition(arr, start, end);
    else
      p_index = random_partition(arr, start, end);

    if(p_index - end < start - p_index){
      quick_sort(arr, start, p_index - 1, type);
      end = p_index + 1;
    }else{
      quick_sort(arr, p_index + 1, end, type);
      start = p_index - 1;
    }
  }
}

int ascending_partition(int *arr, int start, int end){
  int pivot = arr[end];
  int p_index = start;
  int i, temp;

  for(i = start; i < end; i++){
    if(arr[i] <= pivot){
      temp = arr[i];
      arr[i] = arr[p_index];
      arr[p_index] = temp;
      p_index++;
    }
  }

  temp = arr[end];
  arr[end] = arr[p_index];
  arr[p_index] = temp;

  return p_index;
}

int descending_partition(int *arr, int start, int end){
  int pivot = arr[end];
  int p_index = start;
  int i, temp;

  for(i = start; i < end; i++){
    if(arr[i] >= pivot){
      temp = arr[i];
      arr[i] = arr[p_index];
      arr[p_index] = temp;
      p_index++;
    }
  }

  temp = arr[end];
  arr[end] = arr[p_index];
  arr[p_index] = temp;

  return p_index;
}

int random_partition(int *arr, int start, int end){
  int pivot = arr[end];
  int p_index = start;
  int i, temp;

  for(i = start; i < end; i++){
    if(arr[i] % 2 != 0){
      temp = arr[i];
      arr[i] = arr[p_index];
      arr[p_index] = temp;
      p_index++;
    }
  }

  temp = arr[end];
  arr[end] = arr[p_index];
  arr[p_index] = temp;

  return p_index;
}

void print(int *arr, int size){
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}