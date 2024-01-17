class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap;

        // Count the frequency of each element
        for (int num : arr) {
            freqMap[num]++;
        }
        
        // Create another unordered_map to store the frequency of frequency counts
        unordered_map<int, int> freqFreq;

        // Count the frequency of frequency counts
        for (const auto& pair : freqMap) {
            freqFreq[pair.second]++;
        }
        
        return freqMap.size() == freqFreq.size();
        
    }
};