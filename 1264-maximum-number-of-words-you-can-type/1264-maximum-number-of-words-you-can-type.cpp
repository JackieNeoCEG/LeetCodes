class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    std::istringstream iss(text);
    string word;
    int count = 0;

    // iterate through each word 
    while (iss >> word) {
        bool broken = false;

        for (char cw : word) {
            for (char cbl : brokenLetters) {
                if (cw == cbl) {
                    broken = true;  
                    break;         
                }
            }
            if (broken) {
                break;
            } 
        }
        if (!broken) {
            count++;
        }

    }
    
    return count;
    }

};