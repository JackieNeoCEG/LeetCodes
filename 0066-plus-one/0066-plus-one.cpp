class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Increment the least significant digit
    if (digits[n - 1] != 9) {
        digits[n - 1]++;
    } else {
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                break; // No need to continue if there's no carry
            }
        }
    }

    // Check for a carry in the most significant digit
    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
    }
};