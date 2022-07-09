class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        backtracking(candidates, target, ans, 0, 0, current);
        return ans;
    }
    
    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& ans, int sum, int start, vector<int>& current)
    {
        if(sum == target)
        {
            ans.push_back(current);
            return;
        }
        
        if(sum > target)
        {
            return;
        }
        
        for(int i = start; i < candidates.size(); i++)
        {
            if(i>start && candidates[i]==candidates[i-1])continue;
            int s = sum + candidates[i];
            current.push_back(candidates[i]);
            backtracking(candidates, target, ans, s, i+1, current);
            current.pop_back();
        }
    }
};