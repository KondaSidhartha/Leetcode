class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
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
            int s = sum + candidates[i];
            current.push_back(candidates[i]);
            backtracking(candidates, target, ans, s, i, current);
            current.pop_back();
        }
    }
};