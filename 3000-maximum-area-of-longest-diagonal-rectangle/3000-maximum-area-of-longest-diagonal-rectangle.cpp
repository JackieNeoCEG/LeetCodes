class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
                double maxDiagonal = 0.0;
        int maxArea = 0;

        for (const auto& rect : dimensions) {
            int length = rect[0];
            int width = rect[1];
            
            double diagonal = std::sqrt(length * length + width * width);

            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && length * width > maxArea)) {
                maxDiagonal = diagonal;
                maxArea = length * width;
            }
        }

        return maxArea;
    }
};