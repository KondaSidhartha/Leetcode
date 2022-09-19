class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files;
        vector<vector<string>> ans;
        
        
        for(auto file:paths){
            stringstream ss(file);
            string root;
            string s;
            getline(ss,root,' ');
            while(getline(ss,s,' ')){
                string fileloc=root+'/'+s.substr(0,s.find('('));
                string filecontent=s.substr(s.find('(')+1,s.find(')')-s.find('(')-1);
                files[filecontent].push_back(fileloc);
            }
        }
        for(auto file:files){
            if(file.second.size()>1){
                ans.push_back(file.second);
            }
        }
        return ans;
    }
};