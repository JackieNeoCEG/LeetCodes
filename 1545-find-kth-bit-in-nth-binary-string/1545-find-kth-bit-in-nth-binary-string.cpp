class Solution {
public:
    char findKthBit(int n, int k) {
        string bin = "0";
        char inverted;

        for (int i = 1; 1 < n && k > bin.length(); i++) {
            bin += "1";
        
            string temp = bin;

            // Invert and reverse??
            for (int j = temp.length() - 2; j >= 0; j--) {
                if (temp[j] == '1') {
                    inverted = '0';
                } else {
                    inverted = '1';
                }
                bin += inverted;
            }
        }
        return bin[k - 1];
    }
};