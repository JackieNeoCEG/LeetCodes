class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> result;
        string currentCombination;
        
        backtrack(digits, 0, currentCombination, digitToLetters, result);
        return result;

    }
    
    void backtrack(const string& digits, int index, string& currentCombination, 
                   unordered_map<char, string>& digitToLetters, vector<string>& result) {

        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        char digit = digits[index];
        string possibleLetters = digitToLetters[digit];
        
        for (char letter : possibleLetters) {
            currentCombination.push_back(letter);  // Add the letter to the current combination
            backtrack(digits, index + 1, currentCombination, digitToLetters, result);  // Move to the next digit
            currentCombination.pop_back();  // Backtrack: remove the last letter and try the next one
        }
    }
};