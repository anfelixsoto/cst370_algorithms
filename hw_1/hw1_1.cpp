/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw1/challenges/common-nums/submissions/code/1319940649
 * Title: hw1_1.cpp
 * Abstract: User input a size and then numbers, those numbers are then added to a vector and sorted. Then are checked                for duplicate in both vectors. 
 * Author: Antonio Felix
 * ID: 9121
 * Date: 1/27/2020
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> add(int size);
void sort(vector<int> &vec);
void print(vector<int> vec);
void repeated(vector<int> vec, vector<int> vecs);
bool check(vector <int> vec, int num);

int main(){
  vector<int> vec1;
  vector<int> vec2;
  int input;

  cin >> input;
  vec1 = add(input);

  cin >> input;
  vec2 = add(input);

  sort(vec1);
  sort(vec2);

  repeated(vec1, vec2);

  return 0;
}

vector<int> add(int size){
  vector<int> vec;
  int element;
  for(int i = 0; i < size; i++){
    cin >> element;
    vec.push_back(element);
  }

  return vec;
}

void sort(vector <int> &vec){
  int temp, i, j;
  for(i = 0; i < vec.size() - 1; i++){
    for(j = i + 1; j < vec.size(); j++){
      if(vec.at(j) < vec.at(i)){
        temp = vec.at(j);
        vec.at(j) = vec.at(i);
        vec.at(i) = temp;
      }
    }
  }
}

void repeated(vector<int> vec, vector<int> vecs){
  int i, j;
  vector<int> repeat;
  for(i = 0; i < vec.size(); i++){
    for(j = 0; j < vecs.size(); j++){
      if(vec.at(i) == vecs.at(j)){
        if(!check(repeat, vec.at(i))){
          repeat.push_back(vec.at(i));
        }
      }
    }
  }
  cout << "Answer:";
  if(repeat.empty()){
    cout <<  "NONE\n";
  }else{
    print(repeat);
  }
}

bool check(vector <int> vec, int num){
  int i;
  if(vec.empty()){
    return false;
  }else{
    for(i = 0; i < vec.size(); i++){
      if(vec.at(i) == num){
        return true;
      }
    }
  }
  return false;
}

void print(vector <int> vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec.at(i) << " ";
  }
}