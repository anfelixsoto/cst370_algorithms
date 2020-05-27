/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/max-heap-1-2/submissions/code/1323062416
 * Title: hw9_1.cpp
 * Abstract: heap operations
 * Author: Antonio Felix
 * ID: 9121
 * Date: 4/24/2020
 */

#include <iostream>
#include <vector> 
using namespace std;

void create(vector <int> &v, int size){
  for(int i = 1; i < size; i++)
    cin >> v[i];
  return;
}

bool is_max_heap(vector <int> &v, int index, int size){
  if(index > size/2)
    return true;
  
  if(v[index] >= v[index * 2])
    if(v[index] >= v[index * 2 + 1])
      if(is_max_heap(v, (index * 2), size))
        if(is_max_heap(v, (index * 2 + 1), size))
          return true;
  return false;
}

void heapify(vector <int> &v, int index, int size){
  int curr = index;
  int left_side = index * 2;
  int right_side = index * 2 + 1;

  if(left_side <= size)
    if(v[left_side] > v[curr])
      curr = left_side;
  
  if(right_side <= size)
    if(v[right_side] > v[curr])
      curr = right_side;

  if(curr != index){
    int temp_val = v[index];
    v[index] = v[curr];
    v[curr] = temp_val;
    heapify(v, curr, size);
  }
}

void create_max_heap(vector <int> &v, int size){
  for(int i = size / 2; i >= 1; i--)
    heapify(v, i, size);
}

int display_max(vector <int> &v, int size){
  int max = 0;
  for(int i = 0; i < size; i++)
    if(max < v[i])
      max = v[i];
  return max;
}

void insert_heap(vector <int> &v, int n, int index){
  int p_index = (index)/2;
  if(p_index > 0)
    if(v[index] > v[p_index]){
      int temp_val = v[index];
      v[index] = v[p_index];
      v[p_index] = temp_val;
      insert_heap(v, n, p_index);
    }
}

void insert_node(vector <int> &v, int &size, int data){
  size++;
  v[size - 1] = data;
  insert_heap(v, size, size - 1);
}

void delete_max(vector <int> &v, int &size){
  if(size == 2)
    v[1] = 0;
  else if(size > 2){
    v[1] = v[size - 1];
    v[size - 1] = 0;
    size--;
    heapify(v, 1, size);
  }
}

void delete_node(vector <int> &v, int &size, int data){
  int curr_index = -1;
  for(int i = 0; i < size; i++)
    if(v[i] == data)
      curr_index = i;
  
  if(curr_index == -1)
    return;
  else{
    v[curr_index] = v[size - 1];
    v[size - 1] = 0;
    size--;
    insert_heap(v, size, curr_index);
    heapify(v, curr_index, size);
  }
}

void print(vector <int> &v, int size){
  for(int i = 1; i < size; i++)
    cout << v[i] << " ";
  cout << endl;
}

void update_data(vector <int> &v, int &size, int index, int data){
  if(index < 1 && index >= size)
    return;
  v[index] = data;
  insert_heap(v, size, index);
  heapify(v, index, size);
}

void commands(int size, vector <int> &v, int v_size){
  string temp;
  int data, index;
  for(int i = 0; i < size; i++){
    cin >> temp;
    if(temp == "displayMax"){
      cout << display_max(v, v_size) << endl;
    } else if(temp == "insert"){
      cin >> data;
      insert_node(v, v_size, data);
    } else if(temp == "deleteMax"){
      delete_max(v, v_size);
    } else if(temp == "delete"){
      cin >> data;
      delete_node(v, v_size, data);
    } else if(temp == "display"){
      print(v, v_size);
    }else if(temp == "update"){
      cin >> index >> data;
      update_data(v, v_size, index, data);
    }
  }
}

int main(){
  int num_nodes, num_commands;
  vector <int> nodes;

  cin >> num_nodes;

  int size = num_nodes + 1;
  nodes.resize(size + 1, 0);

  create(nodes, size);

  if(is_max_heap(nodes, 1, size))
    cout << "This is a heap.\n";
  else
    cout << "This is NOT a heap.\n";

  create_max_heap(nodes, size);

  cin >> num_commands;
  commands(num_commands, nodes, size);

  return 0;

}