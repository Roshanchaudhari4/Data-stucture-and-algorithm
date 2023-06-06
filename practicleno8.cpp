/*Beginning with an empty binary search tree, Construct binary search tree 
operations to be performed is 1.  Insert new node 2. Search a value 3. Display*/


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

bool searchValue(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return searchValue(root->left, value);
    } else {
        return searchValue(root->right, value);
    }
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
        cout << "2. Search a value\n";
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
                cout << "Enter the value to search: ";
                cin >> value;
                if (searchValue(root, value)) {
                    cout << "Value " << value << " is present in the tree.\n";
                } else {
                    cout << "Value " << value << " is not found in the tree.\n";
                }
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