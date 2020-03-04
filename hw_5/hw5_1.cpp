/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/palindrome-check-10/submissions/code/1321343704
 * Title: hw5_1.cpp
 * Abstract: Checks if an input string is a palindrome or not. In the problem, a palindrome means an alphanumeric string which reads the same front to back. For the problem, you should ignore case and remove all non-alphanumeric characters in the input string.  
 * Author: Antonio Felix
 * ID: 9121
 * Date: 2/28/2020
 */

#include <iostream>
#include <string>
using namespace std;

string remove_whitespace(string word);
void upper(string &s);
bool palindrome(string word, int start, int end);

int main(){
  string str;
  getline(cin, str);

  upper(str);

  string new_string = remove_whitespace(str);

  if(palindrome(new_string, 0, new_string.length() - 1))
    cout << "TRUE";
  else
    cout << "FALSE";

  return 0;
}

string remove_whitespace(string word){
  string temp;
  for(int i = 0; i < word.length(); i++){
    if(word[i] != ' ' && word[i] != ',' && word[i] != '!' && word[i] != '.' && word[i] != '?' && word[i] != '\''){
      temp += word[i];
    }
  }
  return temp;
}

void upper(string &s){
  for(unsigned int l = 0; l < s.length(); l++){
    s[l] = toupper(s[l]);
  }
}

bool palindrome(string word, int start, int end){
  if(word[end] == '\0')
    return true;
  else if(word[start] == word[end])
    return palindrome(word, start + 1, end - 1);
  return false;
}

bool palidrome(string word){
   if(word.length() == 0){
    return false;
  }
  
  int start = 0, end = word.length() - 1;
  while (start < end){
    if(word[start++] != word[end--])
      return false; 
  }

  return true;
}