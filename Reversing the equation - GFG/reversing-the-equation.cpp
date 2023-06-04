//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
             //code here.
            int n=s.length();
            stack<int>num;stack<char>op;
            int number=0;
            for(int i=0;i<n;i++){
                if(isdigit(s[i])){
                    number=number*10+(s[i]-'0');
                }
                else{
                    num.push(number);
                    number=0;
                    op.push(s[i]);
                }
            }
            num.push(number);
            string ans="";
            while(!num.empty() and !op.empty()){
                ans=ans+to_string(num.top());num.pop();
                ans=ans+op.top();op.pop();
            }ans=ans+to_string(num.top());num.pop();
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends