class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        if (n < 3) {
            if (expression == "t") return true; 
            if (expression == "f") return false;
        }
        if (expression[0] == '!') {
            return !parseBoolExpr(expression.substr(2, n - 3));
        } else if (expression[0] == '&') {
            return parseAnd(expression.substr(2, n - 3));
        } else if (expression[0] == '|') {
            return parseOr(expression.substr(2, n - 3));
        }
        return false;
    }
    
    bool parseAnd(string expression) {
        int n = expression.size();
        bool result = true;
        int start = 0, balance = 0;
        
        for (int i = 0; i < n; i++) {
            if (expression[i] == '(') balance++;
            if (expression[i] == ')') balance--;
            
            if ((expression[i] == ',' && balance == 0) || i == n - 1) {
                string subExpr = expression.substr(start, i - start + (i == n - 1));
                result = result && parseBoolExpr(subExpr);
                start = i + 1;

                // Short-circuit if any part is false
                if (!result) return false;
            }
        }
        return result;
    }
    
    bool parseOr(string expression) {
        int n = expression.size();
        bool result = false;
        int start = 0, balance = 0;
        
        for (int i = 0; i < n; ++i) {
            if (expression[i] == '(') balance++;
            if (expression[i] == ')') balance--;
            
            if ((expression[i] == ',' && balance == 0) || i == n - 1) {
                string subExpr = expression.substr(start, i - start + (i == n - 1));
                result = result || parseBoolExpr(subExpr);
                start = i + 1;

                // Short-circuit if any part is true
                if (result) return true;
            }
        }
        return result;
    }

};