//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
   int i=0;
    Node *treeFromString(string s){
        Node* root= NULL;
        if(i==s.length())return root;
       if(isdigit(s[i])){
           int num=0;
           while(isdigit(s[i])){
               num=num*10 + s[i]-48;
               i++;
               root=new Node(num);
           }
          
       }
       if(s[i]=='('){
              i++;
              root->left=treeFromString(s);
          }
       if(s[i]=='('){
           i++;
          root->right=treeFromString(s);
      }
      i++;
      return root; 
       
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends