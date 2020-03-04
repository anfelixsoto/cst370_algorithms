/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/equal-groups/submissions/code/1320753140
 * Title: hw3_2.cpp
 * Abstract: Partitions n positive integers into two disjoint sets with the same sum. Of course, the problem does not always have a solution
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/12/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
using namespace std;

vector <int> add(int size);
string decimal_to_binary(int decimal);
vector <string> binary_subset(vector <int> vec);
string partition_subset(vector <int> element_holder, vector <string> binary_holder);
void print(string answer, vector <int> vec);

int main(){
  int num_elements;
  cin >> num_elements;
  vector <int> elements = add(num_elements);
  sort(elements.begin(), elements.end());
  vector <string> binary_rep = binary_subset(elements);
  print(partition_subset(elements, binary_rep), elements);
  
}

vector <int> add(int size){
  int element;
  vector <int> vec;
  for(int i = 0; i < size; i++){
    cin >> element;
    vec.push_back(element);
  }
  return vec;
}

/*
  This function gives me all the subsets and returns them in a vector that holds strings.
*/
vector <string> binary_subset(vector <int> vec){
  vector <string> subset_vec;
  int count = pow(2, vec.size());
  for(int i = 1; i < count; i++){
    string binary_rep = bitset<10>(i).to_string();
    subset_vec.push_back(binary_rep.substr(binary_rep.length() - vec.size()));
  }
  return subset_vec;
}

/*
  This checks all the possible subsets and if they are equal to each other. Once they are equal to each other that subset is returned.
*/
string partition_subset(vector <int> element_holder, vector <string> binary_holder){
  string temp;
  int sum = 0, sum1 = 0;
  for(int i = binary_holder.size() - 1; i > 0; i--){
    temp = binary_holder.at(i);
    sum = 0;
    sum1 = 0;
    for(int i = 0; i < temp.length(); i++){
      if(temp[i] == '1'){
        sum1 += element_holder.at(i);
      }else{
        sum += element_holder.at(i);
      }
    }

    if(sum == sum1){
      return temp;
    }
  }
  return "0";
}

void print(string answer, vector <int> vec){
  cout << "Equal Set: ";
  if(answer == "0"){
    cout << answer;
  }else{
    for(int i = 0; i < answer.length(); i++){
      if(answer[i] == '1'){
        cout << vec.at(i) << " ";
      }
    }
  }
}