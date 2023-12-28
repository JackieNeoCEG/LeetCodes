class Solution {
public:
    int maxScore(string s) {
        int zero = 0; int one = 0; int ans = 0;
        for (int i = 0; i < s.size(); i++) { //loop to fix all '1's
            if (s[i] == '1') {one++;}
        }
        for (int i = 0; i < s.size() - 1; i++) { //loop again to update '0's and '1's
            if (s[i] == '0') {zero++;}
            else {one--;}

            if (zero + one > ans) {
                ans = zero + one; //update answers
            }
        }
        return ans;
    }
};