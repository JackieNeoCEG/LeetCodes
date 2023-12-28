class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            // Handle division by zero
            return INT_MAX;
        }

        if (dividend == INT_MIN && divisor == -1) {
            // Handle overflow case where the result is greater than INT_MAX
            return INT_MAX;
        }

        long long ldividend = labs((long long)dividend);
        long long ldivisor = labs((long long)divisor);
        int result = 0;

        // Handle the case where dividend is INT_MIN
        if (dividend == INT_MIN) {
            if (divisor == 1) {
                // This is a special case where incrementing INT_MIN by 1 causes overflow
                return INT_MIN;
            }
            ldividend -= ldivisor;  // Adjust for the decrement
            result++;
        }

        while (ldividend >= ldivisor) { //loops the divisor subtraction
            long long temp = ldivisor;
            long long multiple = 1;
            while (ldividend >= (temp << 1) && (temp << 1) > 0) { //doubles till ldividend is smaller 
                temp <<= 1; //bitshift trick to multiply by 2
                multiple <<= 1;
            }
            ldividend -= temp;
            result += (int)multiple;
        }

        //bitwise XOR, same signs return positive, diff signs return negative
        return ((dividend > 0) ^ (divisor > 0)) ? -result : result;
    }
};