/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/alien-alphabet/submissions/code/1322976470
 * Title: hw9_2.cpp
 * Abstract: that displays the alphabetical order of characters for an alien language
 * Author: Antonio Felix
 * ID: 9121
 * Date: 4/20/2020
 */

#include<bits/stdc++.h> 
using namespace std; 

/*
Help with creating the graph class and some functions
https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
*/
class Graph{
  int num_v;
  list <int> *adj;

  void topological_sortUtil(int v, bool visited[], stack <int> &s);
  bool is_cycleUtil(int v, bool visited[], bool *rs);

  public:
    Graph(int num_v);
    void add_edges(int from, int to);
    void topological_sort(vector <char> &e);
    void print_graph(list <int> *adj);
    bool is_cycle();
    vector <int> degree_counter(vector <char> &e);
};

Graph::Graph(int num_v){
  this->num_v = num_v;
  adj = new list <int> [num_v];
}
void Graph::add_edges(int from, int to){
  adj[from].push_back(to);
}

void Graph::topological_sortUtil(int v, bool *visited, stack<int> &s){
  visited[v] = true;

  list <int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      topological_sortUtil(*i, visited, s);
  s.push(v);
}

vector <int> Graph::degree_counter(vector <char> &e){
  vector <int> degree;
  degree.resize(e.size(), 0);

  list <int> :: iterator it;
  for(int i = 0; i < e.size(); i++){
    for(it = adj[i].begin(); it != adj[i].end(); ++it){
      int temp = *it;
      degree[temp] += 1;
    }
  } 
  return degree; 
}

void Graph::topological_sort(vector <char> &e){
  queue <int> q;
  vector <int> degree = degree_counter(e);
  for(int i = 0; i < degree.size(); i++)
    if(degree[i] == 0)
      q.push(i);
  
  int count = 0;

  vector <int> topolgical;

  while(!q.empty()){
    int top = q.front();
    q.pop();
    topolgical.push_back(top);

    list <int> :: iterator it;
    for(it = adj[top].begin(); it != adj[top].end(); ++it){
      int temp = *it;
      if(--degree[temp] == 0)
        q.push(temp);
    }
    
    count++;
  }

  if(count != num_v){
    cout << "Invalid input.";
    return;
  }

  for(int i = 0; i < topolgical.size(); i++){
    if(i != 0)
      cout << "->";
    cout << e[i];
  }
}

int min(int x, int y){
  return (x < y) ? x : y;
}

int index(char val, vector <char> e){
  for(int i = 0; i < e.size(); i++)
    if(val == e[i])
      return i;
  return 0;
}

void print_order(vector <string> words, vector <char> &e){
  Graph g(e.size());

  for(int i = 0; i < words.size() - 1; i++){
    string temp = words[i], temp1 = words[i + 1];
    int n_size = min(temp.length(), temp1.length());
    for(int j = 0; j < n_size; j++){
      if(temp[j] != temp1[j]){
        int val1 = index(temp[j], e);
        int val2 = index(temp1[j], e);
        g.add_edges(val1, val2);
        break;
      }
    }
  }

  g.topological_sort(e);
}

bool find(vector <char> e, char val){
  for(int i = 0; i < e.size(); i++)
    if(e[i] == val)
      return true;
  return false;
}

void alphabet(vector <string> v, vector <char> &e){
  for(int i = 0; i < v.size(); i++)
    if(e.empty())
      e.push_back(v[i][0]);
    else
      if(!find(e, v[i][0]))
        e.push_back(v[i][0]);
  
  for(int i = 0; i < v.size(); i++)
    for(int j = 0; j < v[i].length(); j++)
      if(!find(e, v[i][j]))
        e.push_back(v[i][j]);
  return;
}


vector <char> alpha(vector <string> v){
  vector <char> e;
  
  alphabet(v, e);

  return e;
}

int main(){
  vector <string> words;
  int size;
  string temp;
  cin >> size;
  for(int i = 0; i < size; i++){
    cin >> temp;
    words.push_back(temp);
  }

  vector <char> e = alpha(words);

  print_order(words, e);

  return 0;
}