class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstMinCost = INT_MAX;
        int secondMinCost = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            int p = prices[i];
            if (p < firstMinCost) { //to update both
                secondMinCost = firstMinCost;
                firstMinCost = p;
            } else { //update only
                secondMinCost = min(secondMinCost, p);
            }
        }
        //calculates money left, returns original money if negative
        int leftover = money - (firstMinCost + secondMinCost);
        return leftover >= 0 ? leftover : money;        
    }
};