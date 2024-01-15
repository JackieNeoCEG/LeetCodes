class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;

        for (const auto& match : matches) {
            mp[match[0]];
            mp[match[1]]++;
        }

        vector<vector<int>>ans(2);
        
        for(const auto& a : mp){
            if(a.second == 0) {
                ans[0].push_back(a.first);
            }
            if(a.second == 1) {
                ans[1].push_back(a.first);
            }
        }
        return ans;
    }
};