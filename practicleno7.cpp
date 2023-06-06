/*Beginning with an empty binary search tree, Construct binary search tree 
operations to be performed is 1.  Insert new node 2. Change a tree so that the roles 
of the left and right pointers are swapped at every node 3. Display*/



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

Node* swapNodes(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapNodes(root->left);
    swapNodes(root->right);
    return root;
}


void displayTree(Node* root){
    if (root == NULL){
        return;
    }
    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);

}

int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "1. Insert new node\n";
        cout << "2. Swap left and right pointers at every node\n";
        cout << "3. Display the tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                root = swapNodes(root);
                cout << "Left and right pointers swapped!\n";
                break;
            case 3:
                cout << "Binary Search Tree: ";
                displayTree(root);
                cout << "\n";
                break;
            case 4:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}