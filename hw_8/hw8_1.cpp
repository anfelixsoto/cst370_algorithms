/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/binary-tree-4/submissions/code/1322478624
 * Title: hw8_2.cpp
 * Abstract: that provides a few functions for a binary tree.
 * Author: Antonio Felix
 * ID: 9121
 * Date: 4/5/2020
 */

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node {
	// Data part for a node. 
  int data;
  Node* left;
  Node* right;

    // Constructor for a new node.
  Node(int d){
    data = d;
    left = nullptr;
    right = nullptr;
  }
};

void inorder(Node* root) {
  if (root != nullptr){
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void preorder(Node* root){
  if(root != nullptr){
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node* root){
  if(root != nullptr){
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}

/*
https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
BST functions
*/
int is_BST(Node* node, int min, int max){
  if(node == NULL)
    return 1;
  
  if(node->data < min || node->data > max)
    return 0;

  return
    is_BST(node->left, min, node->data - 1) &&
    is_BST(node->right, node->data + 1, max);
}

int is_bst(Node* node){
  return(is_BST(node, INT_MIN, INT_MAX));
}

/*
https://www.geeksforgeeks.org/level-order-tree-traversal/
*/
void level_order(Node *root){
  string temp;

  if(root == nullptr)
    return;
  
  queue <Node *> q;
  q.push(root);

  while(!q.empty()){
    Node *node = q.front();
    cout << node->data << " ";
    q.pop();

    if(node->left != nullptr)
      q.push(node->left);

    if(node->right != nullptr)
      q.push(node->right);
  }
  
}

int height(Node* root)
{
	if(root == NULL)
		return 0;

	else
	{
		int lb = height(root->left);
		int rb = height(root->right);
		return max(lb,rb) + 1;
	}
}

void delete_last_node(vector <Node*> &v, Node* last_node){
  for(int i = 0; i < v.size(); i++){
      Node* root = v[i];
      if(root->left != nullptr && root->left->data == last_node->data){
      delete last_node;
      root->left = nullptr;
      return;
    }else if(root->right != nullptr && root->right->data == last_node->data){
      delete last_node;
      root->right = nullptr;
      return;
    }
  }
}

void create_tree(vector <Node*> &v, Node* node){
  for(int i = 0; i < v.size(); i++){
    if(v[i]->left == nullptr){
      v[i]->left = node;
      return;
    }else if(v[i]->right == nullptr){
      v[i]->right = node;
      return;
    }
  }
  return;
}

void create(vector <Node*> &l, vector <string> operation, Node* root){
  int num, data, node_val = 0;
  string type, temp;
  cin >> num;
  stack <Node*> s;
  s.push(root);
  for(int i = 0; i < num; i++){
    cin >> type;
    if(type == "append"){
      cin >> data;
      temp += to_string(node_val);
      Node* temp = new Node(data);
      create_tree(l, temp);
      s.push(temp);
      l.push_back(temp);
      node_val++;
    }else if(type == "isBST"){
      if(is_bst(root))
        cout << "true\n";
      else
        cout << "false\n";
    }else if(type == "preOrder"){
      preorder(root);
      cout << endl;
    }else if(type == "height"){
      if(s.empty())
        cout << "-1\n";
      else
        cout << height(root) - 1 << endl;
      
    }else if(type == "levelOrder"){
      level_order(root);
      cout << endl;
    }else if(type == "deleteLastNode"){
      Node * last_node = s.top();
      s.pop();
      delete_last_node(l, last_node);
    }else if(type == "postOrder"){
      postorder(root);
      cout << endl;
    }else if(type == "inOrder"){
      inorder(root);
      cout << endl;
    }
  }
}

void print(vector <Node*> &v){
  for(int i = 0; i < v.size(); i++){
    if(v[i]->left != nullptr)
      cout << v[i]->left->data << " ";
    else
      cout << "nullptr ";

    cout << v[i]->data << " ";

    if(v[i]->right != nullptr)
      cout << v[i]->right->data << "\n";
    else
      cout << "nullptr\n";
  }
  cout << endl;
}

int main() {
  int node_val = 0, num, data;
  string temp = "n";
  vector <string> operations;
  vector <Node*> nodes;

  cin >> data;
  Node* root = new Node(data);
  nodes.push_back(root);

  create(nodes, operations, root);

  return 0;
}