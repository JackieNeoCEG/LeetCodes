class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //2 vectors to store freq of the 26 characters in the english alphabet
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++; //-'a' trick to zero-index the english alphabet within [0, 25]
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }
        
        //checks if word1 and word2 have the same types of characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Check if the sorted frequency vectors are the same
        return freq1 == freq2;
    }
};