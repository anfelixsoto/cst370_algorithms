/*
 * HackerRank link:       https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/adjacency-list/submissions/code/1320639108
 * Title: hw3_3.cpp 
 * Abstract: User inputs vecrtice and edge, the program then creates the 2D array containing all the vectices. Then the user enters their edges. The program see if the vectices connect. If they do their value then becomes 1. Meaning they are connected, the program then prints all the vectices and other vectices that are connected too.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/11/2020
 */

#include <iostream>
using namespace std;

void print(int **arr, int size);

int main(){
  int vertices, edges, i, j, start, end;
  cin >> vertices >> edges;
  int **graph_holder;
  graph_holder = new int *[vertices];

  for(i = 0; i < vertices; i++){
    graph_holder[i] = new int[vertices];
    for(j = 0; j < vertices; j++){
      graph_holder[i][j] = 0;
    }
  }

  for(i = 0; i < edges; i++){
    cin >> start >> end;
    graph_holder[start][end] = 1;
  }

  print(graph_holder, vertices); 

  return 0;
}

void print(int **arr, int size){
  cout << '\n';
  int i, j;
   for(i = 0; i < size; i++){
     cout << i;
     for(j = 0; j < size; j++){
       if(arr[i][j] == 1){
         cout << "->" << j;
       }
     }
     cout << '\n';
   }
}