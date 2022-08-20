class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> v;
        int i=0;
        while(i<n){
            int low=intervals[i][0];
            int high=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]<=high){
                high=max(high,intervals[j][1]);
                j++;
            }
            i=j;
            v.push_back({low,high});
        }
        return v;
    }
};