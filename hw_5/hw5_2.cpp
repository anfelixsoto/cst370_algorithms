/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/bfs-hops/submissions/code/1321466331
 * Title: hw5_2.cpp
 * Abstract: That displays the city names in the range of hop(s) from a starting city.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 3/3/2020
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

void create_graph(vector < vector<int> > &g, map <int, string> &m);
int start_point(map <int, string> &m, string city);
void bfs(vector < vector <int> > &g, map <int, string> &m, int source);
void print_list(vector <vector <int> > &g, map <int, string> &m);
void print_set(set <string> &s);

int main(){
  string city_name;
  vector < vector<int> > matrix;
  map <int, string> city_holder;

  create_graph(matrix, city_holder);

  cin >> city_name;
  int source = start_point(city_holder, city_name);

  bfs(matrix, city_holder, source);

}

void create_graph(vector < vector<int> > &g, map <int, string> &m){
  int vertices, edges;
  string city_name, start, end;
  map <string, int> temp;

  cin >> vertices;
  g.resize(vertices);

  for(int i = 0; i < vertices; i++){
    cin >> city_name;
    m[i] = city_name;
    temp[city_name] = i;
  }

  cin >> edges;
  for(int i = 0; i < edges; i++){
    cin >> start >> end;
    g[temp[start]].push_back(temp[end]);
  }
}

int start_point(map <int, string> &m, string city){
  for(int i = 0; i < m.size(); i++){
    if(m[i] == city){
      return i;
    }
  }
  return 0;
}

void bfs(vector < vector <int> > &g, map <int, string> &m, int source){
  int hops, count = 0;
  cin >> hops;
  
  queue <int> q;
  set <string> s;
  vector <int> mark(g.size(), 0);
  map <int, int> levels;
  mark[source] = ++count;
  s.insert(m[source]);
  q.push(source);
  levels[source] = 0;
  int hop_count = 0;

  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(int i = 0; i < g[curr].size(); i++){
      int neighbor = g[curr][i];
      if(mark[neighbor] == 0){
        mark[neighbor] = ++count;
        levels[neighbor] = levels[curr] + 1;
        q.push(neighbor);
      }
    }
  }

  for(auto it = levels.begin(); it != levels.end(); it++){
    if(it->second <= hops){
      s.insert(m[it->first]);
    }
  }

  print_set(s);

  return;
}

void print_set(set <string> &s){
  for(set <string>::iterator it = s.begin(); it != s.end(); it++){
    cout << *it << endl;
  }
}

void print_list(vector <vector <int> > &g, map <int, string> &m){
  for(int i = 0; i < g.size(); i++){
    cout << m[i];
    for(int j = 0; j < g[i].size(); j++){
      cout << " -> " << m[g[i][j]];
    }
    cout << endl;
  }
}