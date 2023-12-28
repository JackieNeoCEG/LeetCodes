class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0; int end = s.size() - 1;
        while (start <= end) {
            //Skip non-alphanumeric characters from start
           if(!isalnum(s[start])) {
                start++; 
                continue; //skip to next iter
            }
            //Skip non-alphanumeric characters from end
           if(!isalnum(s[end])) {
                end--;
                continue; //skip to next iter
            }
            //checks if both are same
           if(tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
            } else 
            return false;
        }
        return true;
    }
};