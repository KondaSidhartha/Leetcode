class Solution {
public:
    int minRefuelStops(int target, int sFuel, vector<vector<int>>& stations) {
        stations.push_back({target,0});
        
        priority_queue<int> p;
        int currpos=0;
        int currfuel=sFuel;
        int minstations=0;
        for(auto i : stations){
            int d=i[0]-currpos;
            
            while(!p.empty() && currfuel<d){
                currfuel+=p.top();
                p.pop();
                minstations++;
            }
            
            if(currfuel<d)return -1;
            
            currpos=i[0];
            currfuel-=d;
            
            p.push(i[1]);
        }
        return minstations;
    }
};