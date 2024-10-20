class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Edge case: if no digits, return empty vector

        vector<string> digitToLetters = {
            "",    // 0 (not used)
            "",    // 1 (not used)
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        // Initialise
        vector<string> result = {""};

        for (char digit : digits) {
            string letters = digitToLetters[digit - '0'];
            vector<string> newResult;

            for (string combination : result) {
                for (char letter : letters) {
                    newResult.push_back(combination + letter);
                }
            }

            result = newResult;
        }

        return result;

    }
};