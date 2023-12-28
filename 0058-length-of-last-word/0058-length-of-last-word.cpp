class Solution {
public:
    int lengthOfLastWord(string s) {
        int z = s.size(); int space = 0; int ans = 0;
        for (int i = 1; i < z; i++) {
            if (s[z - i] == ' ') {
                space++;
            } else {break;}
        }
        for (int i = z - 1 - space; i >= 0; i--) {
            if (s[i] != ' ') {
                ans++;
            } else {break;}
        }
        return ans;
    }

};