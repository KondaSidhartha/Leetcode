//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* dfs(vector<int>& preorder,int prestart,int preend, vector<int>& postorder,int poststart,int postend)
    {
        if(prestart>preend)
        {
            return NULL;
        }
        if(poststart>postend)
        {
            return NULL;
        }
        Node* root=new Node(preorder[prestart]);
        if(prestart==preend)
        {
            return root;
        }
        int postindex=poststart;
        while(postorder[postindex]!=preorder[prestart+1])
        {
            postindex++;
        }
        int len= postindex-poststart+1;
        root->left=dfs(preorder,prestart+1,prestart+len,postorder,poststart,postindex);
        root->right=dfs(preorder,prestart+len+1,preend,postorder,postindex+1,postend-1);
        return root;

    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        vector<int> preorder;
        vector<int> postorder;
        for(int i=0;i<size;i++){
            preorder.push_back(pre[i]);
            postorder.push_back(preMirror[i]);
        }
        reverse(postorder.begin(),postorder.end());
        return dfs(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends