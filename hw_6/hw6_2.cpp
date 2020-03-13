/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/knapsack-8/submissions/code/1321589009
 * Title: hw6_2.cpp
 * Abstract: That solves the Knapsack problem. Your program should read the weight and value of each item from a user and determine the best subset
 * Author: Antonio Felix
 * ID: 9121
 * Date: 3/7/2020
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

struct item_obj{
  int weight;
  int value;
};

struct knapsack{
  vector <int> items_holder;
  int capcity = 0;
  int value = 0;
};

void create(map <int, item_obj> &m, int size);
void subset_finder(vector <string> &vec, int size);
void knapsack_finder(map <int, item_obj> &m ,map <string, knapsack> &k, vector <string> &v);
void answer(map <string, knapsack> &k, int max_cap);

int main(){
  int amount_items, max_weight;
  map <int, item_obj> items;
  map <string, knapsack> knapsack_holder;
  vector <string> subset_holder;

  cin >> amount_items >> max_weight;

  create(items, amount_items);
  subset_finder(subset_holder, amount_items);
  knapsack_finder(items, knapsack_holder, subset_holder);

  answer(knapsack_holder, max_weight);

  return 0;
}

void create(map <int, item_obj> &m, int size){
  int weight, value;
  for(int i = 0; i < size; i++){
    item_obj new_obj;
    cin >> weight >> value;
    new_obj.weight = weight;
    new_obj.value = value;
    m[i + 1] = new_obj;
  }
}

void subset_finder(vector <string> &vec, int size){
  int count = pow(2, size);
  vector <string> temp;
  for(int i = 0; i < size; i++){
    int temper = i + 1;
    temp.push_back(to_string(temper));
  }

  for(int i = 0; i < count; i++){
    string t;
    for(int j = vec.size() - 1; j >= 0; j--){
      if(i == 0){
        break;
      }else if((i & (1 << j)) > 0){
        t += temp.at(j);
      }
    }
    vec.push_back(t);
  }
}

void knapsack_finder(map <int, item_obj> &m ,map <string, knapsack> &k, vector <string> &v){
  string temp;
  for(int i = 0; i < v.size(); i++){
    temp = v.at(i);
    knapsack new_knapsack;
    for(int j = 0; j < temp.length(); j++){
      int n = temp[j] - '0';
      new_knapsack.items_holder.push_back(n);
      new_knapsack.capcity += m[n].weight;
      new_knapsack.value += m[n].value;
    }
    sort(new_knapsack.items_holder.begin(), new_knapsack.items_holder.end());
    k[temp] = new_knapsack;
  }
}

void answer(map <string, knapsack> &k, int max_cap){
  map <string, knapsack>:: iterator i;
  int max_weight = 0;
  int max_value = 0;

  for(auto it = k.begin(); it != k.end(); it++){
    if(it->second.capcity >= max_weight && it->second.capcity <= max_cap){
      if(it->second.value >= max_value){
        max_weight = it->second.capcity;
        max_value = it->second.value;
        i = it;
      }
    }
  }

  cout << "Items:";
  for(auto i2 = i->second.items_holder.begin(); i2 != i->second.items_holder.end(); i2++){
      cout << *i2 << " ";
  }

  if(i->second.capcity > 0 && i->second.value > 0){
    cout << "\nCapacity:" << i->second.capcity;
    cout <<"\nValue:" << i->second.value;
  }else{
    cout << "\nCapacity:";
    cout <<"\nValue:";
  }
  cout << endl;
}