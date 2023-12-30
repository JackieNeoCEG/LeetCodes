class Solution {
public:
    string intToRoman(int num) {
        //Using ordered map, sorted in descending order using greater<int>
        map<int, string, greater<int>> numMap = {
            {1000, "M"},{900, "CM"},{500, "D"},{400, "CD"},
            {100, "C"},{90, "XC"},{50, "L"},{40, "XL"},
            {10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"}
        };

        string result;
        
        //iterates over the whole map to reduce num to 0
        for (const auto& [value, symbol] : numMap) {
            while (num >= value) { //finds largest val to minus
                result += symbol; //concatenates the string
                num -= value; 
            }
        }

        return result;
    }
};