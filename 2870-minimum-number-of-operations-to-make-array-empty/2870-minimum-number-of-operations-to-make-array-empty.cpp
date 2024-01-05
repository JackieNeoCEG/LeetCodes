class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>map;
        //calculate frequency of each element in a map
        for(int num: nums){
            map[num]++;
        }

        int count = 0;
        for(auto& a: map){
            int t = a.second; //current freq count
            if(t == 1) {return -1;} //impossible case
            count += t / 3;
            if(t % 3 != 0) {count++;} //increment count if remainder
        }
        return count;
    }
};