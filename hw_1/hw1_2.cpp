/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw1/challenges/max-events/submissions/code/1319987818
 * Title: hw1_2.cpp
 * Abstract: The amount of events happening and the times they are occuring. The code then takes that info and figures out how many events are occuring at the same time.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 1/28/2020
 */
#include <iostream>
#include <vector>
using namespace std;

vector <int> set();
void print(vector <int> vec);
void sort(vector <int> &vec);

int main(){
  int input, start, end;
  int count = 0;
  vector <int> time;
  time = set();

  cin >> input;
  while(count < input){
    cin >> start >> end;

    for(int i = start; i <= end; i++){
      int temp = time.at(i);
      temp++;
      time.at(i) = temp;
    }
    count++;
  }

  sort(time);
  cout << "Answer:" << time.at(23);
  
}

vector <int> set(){
  vector <int> vec;
  for(int i = 0; i < 24; i++){
    vec.push_back(0);
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
