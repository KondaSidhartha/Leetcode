class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        std::map<int,int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
        	int diff=k-nums[i];
        	if (map[diff]>0)
        	{
        		ans++;
        		map[diff]--;
        	}
        	else{
        		map[nums[i]]++;
        	}
        }
        return ans;
    }
};