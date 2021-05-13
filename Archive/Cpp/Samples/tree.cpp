// PROBLEM: Given a n-ary tree,
//   return nodes in a breadth first traversal.

#include <iostream>
#include <list>
#include <queue>

using namespace std;


// Definition of the tree node using generics.
template<class T>
struct node
{
  T data;
  list<struct node*> children;

  node(T x) : data(x) { }
};


// Get the list of all the nodes (breadth first).
template<class T>
list<T> BreadthFirstTraversal(node<T>* head)
{
  list<T> result;
  if (head == NULL)
    return result;

  queue<node<T>*> q;
  q.push(head);

  while(!q.empty())
  {
    node<T>* n = q.front();
    q.pop();
    result.push_back(n->data);
    for(auto& child : n->children)
      q.push(child);
  }

  return result;
}


// Main program that creates a tree, prints it.
int main()
{
  // Construct the tree.
  node<string> *n10 = new node<string>("childC3");
  node<string> *n9  = new node<string>("childC2");
  node<string> *n8  = new node<string>("childC1");
  node<string> *n7  = new node<string>("childB1");
  node<string> *n6  = new node<string>("childA2");
  node<string> *n5  = new node<string>("childA1");
  node<string> *n4  = new node<string>("childC");
  node<string> *n3  = new node<string>("childB");
  node<string> *n2  = new node<string>("childA");
  node<string> *n1  = new node<string>("root");

  n4->children.push_back(n8);
  n4->children.push_back(n9);
  n4->children.push_back(n10);
  n3->children.push_back(n7);
  n2->children.push_back(n5);
  n2->children.push_back(n6);
  n1->children.push_back(n2);
  n1->children.push_back(n3);
  n1->children.push_back(n4);


  // Print all the elements in breadth first manner.
  for(auto& item: BreadthFirstTraversal(n1))
    cout<<item<<endl;


  // Destruct the tree.
  delete n1;
  delete n2;
  delete n3;
  delete n4;
  delete n5;
  delete n6;
  delete n7;
  delete n8;
  delete n9;
  delete n10;
}
