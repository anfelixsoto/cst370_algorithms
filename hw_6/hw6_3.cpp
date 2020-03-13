/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/connect-components/submissions/code/1321660014
 * Title: hw6_3.cpp
 * Abstract: That connects several connected components of a graph with minimum number of edges to create a single connected component of the graph
 * Author: Antonio Felix
 * ID: 9121
 * Date: 3/7/2020
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

void create(vector < vector <int> > &v);
void print(vector < vector <int> > &v);
vector <int> bfs(vector < vector <int> > &v);
void disconnected_nodes(vector < vector <int> > &v, vector <int> mark);
bool connected_checker(vector < vector <int> > &v, int source, int key);
void print_answer(vector <int> &v);

int main(){
  vector < vector <int> > adj_list;
  vector <int> mark;
  create(adj_list);
  mark = bfs(adj_list);
  disconnected_nodes(adj_list, mark);

  return 0;
}

void create(vector < vector <int> > &v){
  int nodes, edges, from, to;
  cin >> nodes >> edges;
  v.resize(nodes);

  for(int i = 0; i < edges; i++){
    cin >> from >> to;
    v[from].push_back(to);
  }
}

vector <int> bfs(vector < vector <int> > &v){
  queue <int> q;
  int count = 0;
  vector <int> mark(v.size(), 0);

  mark[0] = ++count;
  q.push(0);
  while(!q.empty()){
    int curr = q.front();
    q.pop();

    for (int i = 0; i < v[curr].size(); i++) {
      int neighbor = v[curr][i];
      if(mark[neighbor] == 0) {
				mark[neighbor] = ++count;
        q.push(neighbor);
      }    
    }
  }

  return mark;
}

void disconnected_nodes(vector < vector <int> > &v, vector <int> mark){
  vector <int> disconnected;
  disconnected.push_back(0);
  
  for(int i = 0; i < mark.size(); i++){
    if(mark.at(i) == 0){
      int source = disconnected.size() - 1;
      if(!connected_checker(v, disconnected.at(source), i)){
        disconnected.push_back(i);
        v[source].push_back(i);
      }
    }
  }
  
  if(disconnected.size() == 1){
    cout << "No new edge:\n";
  }else{
    print_answer(disconnected);
  }
  
  return;
}

bool connected_checker(vector < vector <int> > &v, int source, int key){
  for(int i = 0; i < v[source].size(); i++){
    if(v[source][i] == key){
      return true;
    }
  }
  return false;
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

void print_answer(vector <int> &v){
  for(int i = 0; i < v.size() - 1; i++){
    cout << "Edge: " << v.at(i) << "-" << v.at(i + 1) << endl;
  }
  return;
}