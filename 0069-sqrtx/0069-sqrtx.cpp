class Solution {
public:
    int mySqrt(int x) {
        int low = 0 ; int high = x ;
        while(low <= high) {
            long long mid = (low + high) / 2;

            if(mid * mid == x) { //exact ans
                return mid;
            }
            else if(mid * mid > x) { //backtrack since overshoot
                high = mid - 1;
            }
            else {low = mid + 1;} //continue iterating
        }
        return high; //returned here for flooring the number
    }
};