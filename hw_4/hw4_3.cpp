/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/tsp-2-1/submissions/code/1320894061
 * Title: hw4_3.cpp
 * Abstract: Reads an input graph data from a user first. Then, it should present a path for the travelling salesman problem (TSP). 
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/16/2020
 */

#include <iostream>
#include <vector>
#include<iomanip>
#include <algorithm>
#include <string.h>
using namespace std;


vector <string> find_permutations(int n);
string permutations_string(int a[], int n);
void answer(int **arr, vector <string> vec, vector <string> cities);
int min_finder(vector <int> vec);

int main(){
  int vertices, edges, i, j, cost;
  string start, end;
  string city;

  cin >> vertices;
  int **graph_holder;

  vector <string> village_holder;
  graph_holder = new int *[vertices];

  for(i = 0; i < vertices; i++){
    cin >> city;
    village_holder.push_back(city);
    graph_holder[i] = new int[vertices];
    for(j = 0; j < vertices; j++){
      graph_holder[i][j] = 0;
    }
  }

  vector <string> permutations_holder = find_permutations(vertices);

  cin >> edges;

  for(i = 0; i < edges; i++){
    cin >> start >> end >> cost;
    for(int m = 0; m < village_holder.size(); m++){
      for(int n = 0; n < village_holder.size(); n++){
        if(village_holder.at(m) == start && village_holder.at(n) == end){
          graph_holder[m][n] = cost;
        }
      }
    }
  }

  answer(graph_holder, permutations_holder, village_holder);

  return 0;
}

/*
*Using Dr. Byun's permutation code, but updated some things to get the correct answers.
*/
vector <string> find_permutations(int n){
  vector <string> vec;
  int size = n - 1;
  int a[size];
  for(int i = 0; i < size; i++){
    a[i] = i + 1;
  } 
	do 
	{ 
		vec.push_back(permutations_string(a, size)); 
	} while (next_permutation(a, a + size)); 
  return vec;
}

string permutations_string(int a[], int n){
  string temp = "0";
  for(int i = 0; i < n; i++){
    temp += to_string(a[i]);
  }
  temp += "0";
  return temp;
}

void answer(int **arr, vector <string> vec, vector <string> cities){
  string temp;
  vector <int> cost_holder;
  int cost, j;
  int m = 0, n = 0;
  for(int i = 0; i < vec.size(); i++){
    temp = vec.at(i);
    cost = 0;
    for(j = 0; j < temp.length() - 1; j++){
      m = temp[j] - '0';
      n = temp[j + 1] - '0';
      if(arr[m][n] == 0){
        cost = -1;
        break;
      }else{
        cost += arr[m][n];
      }
    }
    cost_holder.push_back(cost);
  }
  
  cout << "Path:"; 
  if(min_finder(cost_holder) == -1){
    cout << "\nCost:-1";
  }else{
    string answer = vec.at(min_finder(cost_holder));
    for(int i = 0; i < answer.length(); i++){
      m = answer[i] - '0';
      cout << cities.at(m);
      if(i < answer.length() - 1){
        cout << "->";
      }
    }
    cout << endl;
    cout << "Cost:" << cost_holder.at(min_finder(cost_holder));
  }
}

int min_finder(vector <int> vec){
  int min = 0, i = 0;

  if(vec.size() == 1 && vec.at(0) > 0){
    return 0;
  }

  while(i < vec.size()){
    if(min == 0 && vec.at(i) > 0){
      min = i;
    }else if(min != 0 && vec.at(i) < min && vec.at(i) > 0){
      min = i;
    }
    i++;
  }

  if(min == 0){
    return -1;
  }else{
    return min;
  }
}