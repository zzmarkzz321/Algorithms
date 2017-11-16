/*

Author: Mark renzo Santiago

Basic implementation for Hoffman Codes

resoureces: http://math.ubbcluj.ro/~tradu/TI/huffmancode.pdf for pseudo code and text book for further explanation

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Create the node structure to represent a node for all encodings and dummy nodes
struct Node {
    Node * leftChild;
    Node * rightChild;
    double freq;
    char c;
    string code;
};


// Retrieves the minimum frequency value to combine. Rather than create a datastructure for the meanheap node, we will extract the min nodes through comparison
Node extractMin(vector<Node>& nodeArray) {

    double temp = (double) 9999999;
    vector<Node>::iterator i1, pos;

    for(i1 = nodeArray.begin(); i1!=nodeArray.end(); i1++) {
        if(temp>(*i1).freq) {
            pos = i1;
            temp = (*i1).freq;
        }
    }

    Node tempNode = (*pos);
    nodeArray.erase(pos);

    return tempNode;

}


// Performs the huffman operation                   
Node huffmanCode(vector<Node>& nodeArray) {

    while(!nodeArray.empty()) {       

        Node * rootNode = new Node;   
        Node * leftNode = new Node;
        Node * rightNode = new Node;

        *leftNode = extractMin(nodeArray);
        *rightNode = extractMin(nodeArray);
     
        rootNode->leftChild = leftNode;
        rootNode->rightChild = rightNode;
        rootNode->freq = leftNode->freq+rightNode->freq;
        nodeArray.push_back(*rootNode);

        if(nodeArray.size() == 1) 
            break;
    }

    return nodeArray[0];

}

// Creates the encoding for each character
void encode(Node * temproot, string s, string arr[]) {
    Node * root = new Node;
    root = temproot;
  
    root->code = s;
   
    if(root->leftChild == NULL && root->rightChild == NULL) {
        int temp = (root->c) - 65;
        arr[temp] = (root->code);
    }
   
    else {
 
        root->leftChild->code = s.append("0");
        s.erase(s.end()-1);
 
        root->rightChild->code = s.append("1");
        s.erase(s.end()-1);

        encode(root->leftChild, s.append("0"), arr);
        s.erase(s.end()-1);
      
        encode(root->rightChild, s.append("1"), arr);        
        s.erase(s.end()-1);
    }
   
}


int main() {

    char character;
    int charFrequency;

    // initialize our vector of Nodes to hold our "tree"
    // the arr will hold each letter
    string arr[6];
    vector<Node> nodeArray;

    for (int i = 0; i < 6; i++) {
        cin >> charFrequency;
        character = 'A' + i;

        Node node;
        node.freq = charFrequency;
        node.c = character;
        node.leftChild = NULL;
        node.rightChild = NULL;

        nodeArray.push_back(node);
    }


    Node root = huffmanCode(nodeArray);

    encode(&root, "", arr);

    for (int i = 0; i<6; i++) {
        cout << (char)(i + 65) << ":" << arr[i] << endl;
    }

    return 0;
}
