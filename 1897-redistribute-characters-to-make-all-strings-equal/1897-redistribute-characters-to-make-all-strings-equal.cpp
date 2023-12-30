class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        // Count the frequency of each character
        unordered_map<char, int> charCount; //key:char, value:int
        
        
        for (const string& word : words) { //iterating over each word in the vector
            for (char ch : word) { //then iterating over each character in the word
                charCount[ch]++; //increments frequency
            }
        }

        // Check if the count of each character is divisible evenly by the number of words
        for (const auto& pair : charCount) { // iterating over each key-value in charCount
            if (pair.second % n != 0) { //pair.second accesses the value in map
                return false;
            }
        }
        return true;
    }
};