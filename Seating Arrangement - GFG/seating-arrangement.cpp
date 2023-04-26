//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& arr) {
    for(int i = 0; i < m && n > 0; ++i) {
        if(i == 0 && m >= 2 && arr[i] == 0 && arr[i + 1] == 0) {
            arr[0] = 1;
            --n;
        }
        else if(i == m - 2 && arr[m - 2] == 0 && arr[m - 1] == 0) {
            --n;
            arr[m - 1] = 1;
        }
        else if(arr[i] == 0 && arr[i - 1] == 0 && arr[i + 1] == 0) {
            arr[i] = 1;
            --n;
        }
    }
    
    return n == 0;
}
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends