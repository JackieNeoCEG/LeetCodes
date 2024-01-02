class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sort in ascending so comparision is easier
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, contentChildren = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                contentChildren++;
                i++; //iterate through greed factors first
            }
            j++; 
        }
        return contentChildren;
    }
};