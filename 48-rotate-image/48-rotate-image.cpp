class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        int i=0;
        int j=n-1;
        while(i<j){
            for(int k=0;k<n;k++){
                swap(m[k][i],m[k][j]);
            }
            i++;
            j--;
        }
    }
};