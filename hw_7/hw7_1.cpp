/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw7/challenges/apple-collection/submissions/code/1322091366
 * Title: hw7_1.cpp
 * Abstract: That collects the maximum number of apples in boxes
 * Author: Antonio Felix
 * ID: 9121
 * Date: 3/24/2020
 */

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <bitset>
using namespace std;

void populate_boxes(vector <int> &v);
void subset_finder(vector <string> &vec, int size);
void answer(vector <string> &subsets, vector<int> &apples);
void find_max(vector <int> &vec);\

int main(){
  vector <int> boxes;
  vector <string> subsets;
  populate_boxes(boxes);
  subset_finder(subsets, boxes.size());
  answer(subsets, boxes);\
  return 0;
}

void populate_boxes(vector <int> &v){
  int boxes, apples;
  cin >> boxes;
  for(int i = 0; i < boxes; i++){
    cin >> apples;
    v.push_back(apples);
  }
  return;
}

void subset_finder(vector <string> &vec, int size){
  int count = pow(2, size);
  vector <string> temp;

  for(int i = 0; i < count; i++){
    string binary_rep = bitset<10>(i).to_string();
    temp.push_back(binary_rep.substr(binary_rep.length() - size));
  }

  for(int i = 0; i < temp.size(); i++){
    string temper = temp.at(i);
    bool checker = false;
    for(int i = 0; i < temper.length() - 1; i++){
      if(temper[i] == '1' && temper[i + 1] == '1'){
        checker = true;
      }
    }
    if(!checker)
      vec.push_back(temper);
  }
}

void answer(vector <string> &subsets, vector<int> &apples){
  vector <int> apple_holder;
  for(int i = 0; i < subsets.size(); i++){
    string temp = subsets.at(i);
    int total = 0;
    for(int i = 0; i < temp.length(); i++){
      if(temp[i] == '1'){
        total += apples.at(i);
      }
    }
    apple_holder.push_back(total);
  }
  find_max(apple_holder);
}

void find_max(vector <int> &vec){
  int max = vec.at(0);
  for(int i = 1; i < vec.size(); i++){
    if(max < vec.at(i)){
      max = vec.at(i);
    }
  }
  cout << "Max Apples: " << max << endl;
}