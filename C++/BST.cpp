/*
 *
 * Author: Mark renzo Santiago
 * University of California, Merced 2017
 * 
 * This implementation of BST was written for the CSE 100: Algorithms Class at UC Merced. 
 * 
 * Description:
 * Binary Search Tree Implementation with the following operations:
 * Insert, Delete, In order Transversal, Post order Transversal, Pre Order Transversal
 *
 * Credit:
 * Sudo code source: cplusplusprgramming tutorials and Text book
 */

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// Representation of an element in the tree
struct Node {
  int val;   
  Node *left;   
  Node *right;  
  Node *parent; 
} *root;

class BST {
  
  public:
    BST();  
   ~BST(); 

    // All basic operations
    void Insert(int key);
    void Delete(int key);
    void destroy_tree();

    // Utility functions to delete a node from a tree
    void find(int item, Node **par, Node **loc);
    void case_a(Node *par, Node *loc);
    void case_b(Node *par, Node *loc);
    void case_c(Node *par, Node *loc);
    
    // Transversal operations
    void InOrder(Node *curr); 
    void PreOrder(Node *curr); 
    void PostOrder(Node *curr); 

  
  private:
    void destroy_tree(Node *leaf); 
    void Insert(int key, Node *leaf);
};

// Parses the key from a string to an int
int parseCommand(string c) {

    int key;
    stringstream convert_stm(c.substr(1, c.size()-1));

    if(!(convert_stm >> key)) {
            key = -1;
    }

    return key;
}

// Main driver function that initializes and begins the program
int main(int argc,char **argv) {

    // Create our BST and all variables
    BST Tree;
    string c;
    int key;

    while (1) {
        cin >> c;

        switch(c[0]) {
            // I command calls insert
            case 'i':
                key = parseCommand(c);
                Tree.Insert(key);
                break;
            
            // D command calls Delete
            case 'd':
                key = parseCommand(c);
                Tree.Delete(key);
                break;

            // E command exits the program
            case 'e':
                exit(1);
                break;

            // all transversals will be processed in the default case
            default:
                if (c == "opre") {
                    Tree.PreOrder(root);
                } else if (c == "opost") {
                    Tree.PostOrder(root);
                } else if (c == "oin") {
                    Tree.InOrder(root);
                } else {
                    break;
                }
                break;
        }

    }

  return 1;
}

// CONSTRUCTOR
BST::BST() {
  root = NULL;
}


// DESTRUCTOR
BST::~BST() {
  destroy_tree();

}


/**********************************************/
// Recursively deletes all nodes within a tree to free up memory

void BST::destroy_tree(Node *leaf) {

  if(leaf!=NULL) {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void BST::destroy_tree() {
  destroy_tree(root);
}

/**********************************************/
// Inserts a key into the binary tree by checking to see if the tree is empty or not

void BST::Insert(int key) {

    // If the tree is NOT empty, call the private Insert function to perform the necessary comparisons
    if(root != NULL)
        Insert(key, root);

    // If the tree is empty, we will create a new root node and insert that to the tree
    else {
        root = new Node;
        root->val = key;
        root->left = NULL;
        root->right = NULL;
    }

}

// Private function of Insert that compares the key value to a current node in the tree. This function is called if a root node cannot be found

void BST::Insert(int key, Node *leaf) {

  if (key < leaf->val) {

      if (leaf->left != NULL)
        Insert(key, leaf->left);

      else {
        leaf->left = new Node;
        leaf->left->val = key;
        leaf->left->left = NULL;    
        leaf->left->right = NULL;   
      }  

  }

  else if(key >= leaf->val) {

    if(leaf->right != NULL)
      Insert(key, leaf->right);

    else {
      leaf->right = new Node;
      leaf->right->val = key;
      leaf->right->left = NULL;  
      leaf->right->right = NULL; 
    }

  }

}
/**********************************************/

/*
 * Finds Element in the Tree. Used as a utility function to delete a node
 */
void BST::find(int item, Node **par, Node **loc) {
    Node *ptr, *ptrsave;
    if (root == NULL) {
        *loc = NULL;
        *par = NULL;
        return;
    }

    if (item == root->val) {
        *loc = root;
        *par = NULL;
        return;
    }

    if (item < root->val)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;

    while (ptr != NULL) {

      if (item == ptr->val) {
          *loc = ptr;
          *par = ptrsave;
          return;
      }

      ptrsave = ptr;

      if (item < ptr->val)
          ptr = ptr->left;
      else
          ptr = ptr->right;
    }

    *loc = NULL;
    *par = ptrsave;
}

/**********************************************/


/*
 * Case A
 */
void BST::case_a(Node *par, Node *loc ) {
    if (par == NULL) {

        root = NULL;

    } else {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}
 
/*
 * Case B
 */
void BST::case_b(Node *par, Node *loc) {
    Node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL) {
        root = child;
    } else {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
      }
}
 
/*
 * Case C
 */
void BST::case_c(Node *par, Node *loc) {
    Node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;

    while (ptr->left != NULL) {
        ptrsave = ptr;
        ptr = ptr->left;
    }

    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL) {
        root = suc;
    } else {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

// Deletes a node 

void BST::Delete(int key) {
 
    Node *parent, *location;

    if (root == NULL)
      return;

    find(key, &parent, &location);
    if (location == NULL)
      return;

    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);

    free(location);
}

/**********************************************/

/* 
Performs the pre order transversal through the tree:

Root -> Left -> Right
*/

void BST::PreOrder(Node *ptr) {
     if (root == NULL) {
        return;
    }

    if (ptr != NULL) {

        cout << ptr->val << endl;
        PreOrder(ptr->left);
        PreOrder(ptr->right);
    }
}

/* 
Performs the post order transversal through the tree:

Left -> Right -> Root
*/

void BST::PostOrder(Node *ptr) {
    if (root == NULL) {
        return;
    }
    if (ptr != NULL) {
        PostOrder(ptr->left);
        PostOrder(ptr->right);
        cout << ptr->val << endl;
    }
}

/* 
Performs the in order transversal through the tree:

Left -> Root -> Right
*/

void BST::InOrder(Node *ptr) {
    if (root == NULL) {
        return;
    }

    if (ptr != NULL) {
        InOrder(ptr->left);
        cout << ptr->val << endl;
        InOrder(ptr->right);
    }
}

