/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/kahns-topological-sort/submissions/code/1322456279
 * Title: hw8_2.cpp
 * Abstract: that conducts the topological sorting based on the source removal algorithm 
 * Author: Antonio Felix
 * ID: 9121
 * Date: April 4, 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void create(vector < vector <int> > &v){
  int nodes, edges, from, to;
  cin >> nodes >> edges;
  v.resize(nodes);

  for(int i = 0; i < edges; i++){
    cin >> from >> to;
    v[from].push_back(to);
  }
}

void degree_count(vector < vector <int> > &v, vector <int> &degree){
  degree.resize(v.size());
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      degree.at(v[i][j]) += 1;
    }
  }
}

void topological_order(vector < vector <int> > &v, vector <int> degree){
  queue <int> q;
  for(int i = 0; i < degree.size(); i++)
    if(degree[i] == 0)
      q.push(i);

  int count = 0;

  vector <int> topological;

  while(!q.empty()){
    int top = q.front();
    q.pop();
    topological.push_back(top);

    for(int i = 0; i < v[top].size(); i++){
      if(--degree[v[top][i]] == 0)
        q.push(v[top][i]);
    }
    count++;
  }

  if(count != v.size()){
    cout << "No Order:";
    return;
  }

  cout << "Order:";
  for(int i = 0; i < topological.size(); i++){
    if(i != 0)
      cout << "->";

    cout << topological[i];
  }  
  cout << endl;
}

void print(vector < vector <int> > &v){
  cout << "\n==== Adj List ====\n";
  for(int i = 0; i < v.size(); i++){
    cout << i;
    for(int j = 0; j < v[i].size(); j++){
      cout << " -> " << v[i][j];
    }
    cout << endl;
  }
}

void print(vector <int> &vec){
  for(int i = 0; i < vec.size(); i++)
    cout << "In-degree[" << i << "]:" << vec.at(i) << endl;
}

int main(){
  vector < vector <int> > adj_list;
  vector <int> degree;
  create(adj_list);
  degree_count(adj_list, degree);
  print(degree);
  topological_order(adj_list, degree);
  return 0;
}