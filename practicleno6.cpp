/*Beginning with an empty binary search tree, Construct binary search tree 
operations to be performed is 1.  Insert new node 2.  Find number of nodes in 
longest path from root 3. Display*/





#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int value){
    Node* newNode = new Node();
    if (newNode) {
        newNode->data = value;
        newNode->left = newNode->right =NULL;
    }
    return newNode;
}

Node* insertNode(Node* root,int value){
    if(root == NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = insertNode(root->left,value);
    }else if(value >root->data){
        root->right = insertNode(root->right,value);
    }

    return root;
}

int findLongestPath(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = findLongestPath(root->left);
    int rightHeight = findLongestPath(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void displayTree(Node* root){
    if (root == NULL){
        return;
    }
    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);

}

int main(){
    Node* root = NULL;

    root = insertNode(root,10);
    root = insertNode(root,6);
    root = insertNode(root,15);
    root = insertNode(root,3);
    root = insertNode(root,8);
    root = insertNode(root, 12);
    root = insertNode(root, 18);
    root = insertNode(root, 1);
    root = insertNode(root, 5);


cout << "Binary search tree:";
displayTree(root);
cout << endl;

int longestPath = findLongestPath(root);
cout<<"Number of nodes in the longest path from root:"<<longestPath <<endl;
return 0;
}


   
