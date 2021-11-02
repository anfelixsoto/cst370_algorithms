/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw10/challenges/closed-hashing/submissions/code/1323170919
 * Title: hw10_2.cpp
 * Abstract: operations of linear probing
 * Author: Antonio Felix
 * ID: 9121
 * Date: 4/27/2020
 */

#include <iostream>
#include <vector>
using namespace std;

struct Key{
  int data;
  string status;

};

void print(vector <Key> &hash){  
  for(int i = 0; i < hash.size(); i++)
    cout << i << " " << hash[i].data << " " << hash[i].status << endl;
}

void hash_hash(vector <Key> &hash){
  for(int i = 0; i < hash.size(); i++){
    Key n_key;
    n_key.data = 0;
    n_key.status = "Empty";
    hash[i] = n_key;
  }
}

bool prime_checker(int num){
  int count = 0;
  for(int i = 2; i < num / 2; i++)
    if(num % i == 0)
      return false;
  
  return true;
}

int resize(int curr){
  if(!prime_checker(curr))
    resize(++curr);
  return curr;
}

bool resize_checker(int size, int counter){
  double cap = double(counter)/ double(size);
  if(cap >= 0.5)
    return false;
  return true;
}

void insert_data(vector <Key> &hash, int data){
  int placement = data % hash.size();
  if(hash[placement].status != "Active"){
    hash[placement].data = data;
    hash[placement].status = "Active";
  }else{
    for(int i = placement; i < hash.size(); i++){
      if(hash[i].status != "Active"){
        hash[i].data = data;
        hash[i].status = "Active";
        break;
      }
    }
  }
}

void rehash_table(vector <Key> &hash){
  int n_size = resize(hash.size() * 2);
  vector <int> data;
  for(int i = 0; i < hash.size(); i++)
    if(hash[i].status == "Active")
      data.push_back(hash[i].data);
  hash.resize(n_size);
  hash_hash(hash);

  for(int i = 0; i < data.size(); i++)
    insert_data(hash, data[i]);
}

void display_status(vector <Key> &hash, int index){
  if(hash[index].status == "Empty")
    cout << "Empty\n";
  else
    cout << hash[index].data << " " << hash[index].status << endl;
}

bool search_data(vector <Key> &hash, int data){
  for(int i = 0; i < hash.size(); i++)
    if(hash[i].data == data && hash[i].status == "Active")
      return true;
  return false;
}

void delete_data(vector <Key> &hash, int data){
  for(int i = 0; i < hash.size(); i++)
    if(hash[i].data == data)
      hash[i].status = "Deleted";
}

void operations(vector <Key> &hash){
  int size, data, counter = 0;
  cin >> size;
  string operation;
  for(int i = 0; i < size; i++){
    cin >> operation;
    if(operation == "insert"){
      cin >> data;
      counter++;
      if(!resize_checker(hash.size(), counter))
        rehash_table(hash);
      insert_data(hash, data);
    }else if(operation == "displayStatus"){
      cin >> data;
      display_status(hash, data);
    }else if(operation == "tableSize"){
      cout << hash.size() << endl;
    }else if(operation == "search"){
      cin >> data;
      cout << data << (search_data(hash, data) ? " Found\n" : " Not found\n");
    }else if(operation == "delete"){
      cin >> data;
      delete_data(hash, data);
      counter--;
    }
  }
}

int main(){
  vector <Key> hash_table;
  int size;
  cin >> size;
  hash_table.resize(size);
  hash_hash(hash_table);
  operations(hash_table);

  return 0;
}
