#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* left;	// left pointer for left child
  Node* right;	// right pointer for right child
  Node(int v) : data(v), left(nullptr), right(nullptr) {}	// Constructor of Node, pass val into data, set left and right to nullptr
};

class BinaryTree {
public:
  BinaryTree() : root(nullptr) {}
  void insert(int v) {
    root = insertR(root, v);
  }
  void remove(int v) {
    root = removeR(root, v);
  }
  bool search(int v) {
    cout << "Searching for " << v << "..." << endl;
    return searchR(root, v);
  }
  void inOrder() {	// Left - Root (Node) - Right
    inOrderR(root);
    cout << endl;
  }
  void preOrder() {	// Root (Node) - Left - Right
    preOrderR(root);
    cout << endl;
  }
  void postOrder() {	// Left - Right - Root (Node)
    postOrderR(root);
    cout << endl;
  }
  void findMin() {
    findMinNode(root);
    cout << endl;
  }
  // Wrappers for the getHeight(Recursive) function and countLeaves(Recursive) function
  // -----------------------------
  int findHeight() {
    return getHeightR(root);
  }
  int leavesCount() {
    return countLeavesR(root);
  }
  // -----------------------------

private:
  Node* root;

  Node* insertR(Node* curr, int v) {
    if (curr == nullptr)
      return new Node(v);
    if (v < curr->data)
      curr->left = insertR(curr->left, v);
    else if (v > curr->data)
      curr->right = insertR(curr->right, v);
    return curr;
  }

  bool searchR(Node* curr, int v) {
    if (curr == nullptr)
      return false;
    if (curr->data == v)
      return true;
    if (v < curr->data)
      return searchR(curr->left, v);
    else
      return searchR(curr->right, v);
  }

  void inOrderR(Node* curr) { // Left - Root (Node) - Right
    if (curr != nullptr) {
      inOrderR(curr->left);		// LEFT
      cout << curr->data << " ";	// ROOT
      inOrderR(curr->right);		// RIGHT
    }
  }

  void preOrderR(Node* curr) { // Root (Node) - Left - Right
    if (curr != nullptr) {
      cout << curr->data << " ";	// ROOT
      preOrderR(curr->left);		// LEFT
      preOrderR(curr->right);		// RIGHT
    }
  }

  void postOrderR(Node* curr) { // Left - Right - Root (Node)
    if (curr != nullptr) {
      postOrderR(curr->left);		// LEFT
      postOrderR(curr->right);	// RIGHT
      cout << curr->data << " ";	// ROOT
    }
  }

  Node* findMinNode(Node* node) {
    Node* curr = node;
    while (curr->left != nullptr)
      curr = curr->left;
    return curr;
  }

  Node* removeR(Node* curr, int v) {
    if (curr == nullptr)
      return curr;
    if (v < curr->data)
      curr->left = removeR(curr->left, v);
    else if (v > curr->data)
      curr->right = removeR(curr->right, v);
    else {	// found the node
      if (curr->left == nullptr) {	// doesn't have a left child
        Node* temp = curr->right;
        delete curr;
        return temp;
      }
      else if (curr->right == nullptr) {	// doesn't have a right child
        Node* temp = curr->left;
        delete curr;
        return temp;
      }
      Node* temp = findMinNode(curr->right);	// 2 child, remove the node with the smallest value in the right subtree
      curr->data = temp->data;
      curr->right = removeR(curr->right, temp->data);
    }
    return curr;
  }

  // The actual recursive functions for getHeight and countLeaves
  // -----------------------------------------------------------------
  int getHeightR(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return 1 + max(getHeightR(node->left), getHeightR(node->right));
  }

  int countLeavesR(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
      return 1;
    }
    return countLeavesR(node->left) + countLeavesR(node->right);
  }
  // -----------------------------------------------------------------
};

int main() {
  int treeHeight, treeLeaves;

  BinaryTree tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(2);
  tree.insert(4);
  tree.insert(7);
  tree.insert(6);
  tree.insert(8);
  cout << "In-Order: ";
  tree.inOrder();
  cout << "Pre-Order: ";
  tree.preOrder();
  cout << "Post-Order: ";
  tree.postOrder();

  cout << endl;

  // Testing the getHeight and countLeaves functions to get the height and number of leaves of the binary tree
  // -----------------------------------------------------
  treeHeight = tree.findHeight();
  cout << "Height of Binary Search Tree: ";
  cout << treeHeight << endl;

  treeLeaves = tree.leavesCount();
  cout << "Number of leaves in Binary Search Tree: ";
  cout << treeLeaves << endl;
  // -----------------------------------------------------

  return 0;
}
