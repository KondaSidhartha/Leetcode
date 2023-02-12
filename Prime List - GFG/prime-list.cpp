//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++


class Solution

{

public:

    Node *primeList(Node *head)

    {

        int a[10009] ={0};

        vector<int>v;

        for (int i = 2; i <= 10008; i++)

        {

            if (a[i] == 0)

            {

                 v.push_back(i);

                for (int j = i; j <= 10008; j += i) a[j] = 1;

            }

        }

        Node *f = head;

        while (f != NULL)

        {

            auto r = lower_bound(v.begin(),v.end(),f->val);

            if(f->val==1) f->val=2;

            else{

            if((*r)!=f->val){

               int j=(f->val)-(*(--r));

               int k=(*(++r))-(f->val);

                if(j>k)  f->val=*r;

                else  f->val=*(--r);

            }}

            f=f->next;

        }

   return head; }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends