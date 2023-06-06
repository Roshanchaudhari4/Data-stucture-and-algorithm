/*Construct an  expression  tree  from  the  given  prefix  expression  eg.  +--a*bc/def 
and
Traverse it using post order traversal (non recursive) and then delete the entire 
tree.*/



#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* constructExpressionTree(string prefixExpression) {
    stack<TreeNode*> stk;
    
    for (int i = prefixExpression.length() - 1; i >= 0; i--) {
        char ch = prefixExpression[i];
        
        TreeNode* newNode = new TreeNode;
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        
        if (isalnum(ch)) {
            stk.push(newNode);
        }
       
        else {
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();
            stk.push(newNode);
        }
    }
    
    return stk.top();
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    
    stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* lastVisited = NULL;
    
    while (!stk.empty() || current != NULL) {
        if (current != NULL) {
            stk.push(current);
            current = current->left;
        }
        else {
            TreeNode* topNode = stk.top();
            
            if (topNode->right != NULL && topNode->right != lastVisited) {
                current = topNode->right;
            }
            else {
               
                cout << topNode->data << " ";
                stk.pop();
                lastVisited = topNode;
            }
        }
    }
}

void deleteTree(TreeNode* root) {
    if (root == NULL)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    string prefixExpression = "+--a*bc/def";
    TreeNode* root = constructExpressionTree(prefixExpression);

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    deleteTree(root);

    return 0;
}