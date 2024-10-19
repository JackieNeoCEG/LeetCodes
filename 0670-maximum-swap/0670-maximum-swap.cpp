#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Store the last occurrence of each digit in the number
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) {
            last[numStr[i] - '0'] = i;
        }
        
        // Try to find the first place to make a swap
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > numStr[i] - '0'; d--) {
                
                if (i < last[d]) {
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        
        return num;

    }
};