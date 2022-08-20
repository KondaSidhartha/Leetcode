class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix.size()-1;
        int k=0;
        int l=matrix[0].size()-1;
        if(matrix[0][0]>target || matrix[j][l]<target)return false;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        while(k<=l){
            int mid=k+(l-k)/2;
            if(matrix[j][mid]==target)return true;
            else if(matrix[j][mid]>target){
                l=mid-1;
            }
            else{
                k=mid+1;
            }
        }
        return false;
    }
};