class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; //all negative numbers are not palindrome
        
        string str = to_string(x);
        string reversedStr = str;
        
        reverse(reversedStr.begin(), reversedStr.end());
        
        if(str != reversedStr) return false;
        else return true;
    }
};