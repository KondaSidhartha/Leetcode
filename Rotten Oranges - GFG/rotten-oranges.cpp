//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isvalid(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return false;
        return true;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int org=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)org++;
            }
        }
        vector<int> x = {+1, -1, 0, 0};
        vector<int> y = {0, 0, +1, -1};
        if(org==0)return 0;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                auto t=q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int newX = t.first+ x[k];
                    int newY = t.second + y[k];
                    
                    if(isvalid(newX, newY,grid) && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        org--;
                    }
                }
            }
            t++;
        }
        if(org>0)return -1;
        return --t;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends