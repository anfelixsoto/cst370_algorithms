/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/dfs-4/submissions/code/1321572996
 * Title: hw5_3.cpp
 * Abstract: Implements the Depth-First Search (DFS) algorithm using a stack and a mark array as you learned in the class
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/29/2020
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> create_mark(int size);
void create_matrix(int **arr, int size);
void add_matrix(int **arr, int size);
void dfs(int **arr, vector <int> marks);
void print_matrix(int **arr, int size);
void print_vector(vector <int> vec);

int main(){
  int vertices, edges;
  int **matrix;
  cin >> vertices;

  matrix = new int *[vertices];

  vector <int> mark = create_mark(vertices);

  create_matrix(matrix, vertices);
  cin >> edges;

  add_matrix(matrix, edges);

  if(edges == 0){
    print_vector(mark);
  }else{
    dfs(matrix, mark);
  }

  return 0;
}

vector <int> create_mark(int size){
  vector <int> vec;
  for(int i = 0; i < size; i++){
    vec.push_back(0);
  }
  return vec;
}

void create_matrix(int **arr, int size){
  for(int i = 0; i < size; i++){
    arr[i] = new int[size];
    for(int j = 0; j < size; j++){
      arr[i][j] = 0;
    }
  }
}

void add_matrix(int **arr, int size){
  int start, end;
  for(int i = 0; i < size; i++){
    cin >> start >> end;
    arr[start][end] = 1;
  }
}

void dfs(int **arr, vector <int> marks){
  int counter = 0, i = 0;
  stack <int> visited_stacked;
  visited_stacked.push(0);
  marks.at(0) = ++counter;
  while(!visited_stacked.empty()){
    for(i = 0; i < marks.size(); i++){
      if(arr[visited_stacked.top()][i] == 1 && marks.at(i) == 0){
        visited_stacked.push(i);
        marks.at(i) = ++counter;
      }
    }
    visited_stacked.pop();
  }
  print_vector(marks);
}

void print_matrix(int **arr, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void print_vector(vector <int> vec){
  for(int i = 0; i < vec.size(); i++){
    cout << "Mark[" << i << "]:" << vec.at(i) << endl;
  }
}