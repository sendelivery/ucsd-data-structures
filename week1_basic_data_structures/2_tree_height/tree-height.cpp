#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node;

class Node {
  public:
    int label;
    Node *parent;
    vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int tree_height() {
  int n, root;
  cin >> n;
  vector<Node> nodes(n);

  // populate tree, store index of root
  for (int i = 0; i < n; ++i) {
    int parent_index;
    cin >> parent_index;

    if (parent_index >= 0) 
      nodes[i].setParent(&nodes[parent_index]);
    else
      root = i;
    
    nodes[i].label = i;
  }

  //bfs
  queue<Node> q;
  q.push(nodes[root]);
  Node deepest;

  while(!q.empty()) {
    deepest = q.front();
    q.pop();

    for (int i = 0; i < deepest.children.size(); ++i)
      q.push(*deepest.children[i]);
  }

  // traverse back up the tree
  int height = 1;
  while(deepest.parent != NULL) {
    height++;
    deepest = *deepest.parent;
  }

  return height;
}

int main() {
  cout << tree_height() << endl;
}
