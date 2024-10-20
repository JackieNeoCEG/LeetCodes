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
            return parseAndOr(expression.substr(2, n - 3), true);
        } else if (expression[0] == '|') {
            return parseAndOr(expression.substr(2, n - 3), false);
        }
        return false;
    }
    
    bool parseAndOr(string expression, bool isAnd) {
        int n = expression.size();
        int start = 0, balance = 0;
        bool result = isAnd;
        
        for (int i = 0; i < n; i++) {
            if (expression[i] == '(') balance++;
            if (expression[i] == ')') balance--;
            
            if ((expression[i] == ',' && balance == 0) || i == n - 1) {
                string subExpr = expression.substr(start, i - start + (i == n - 1));
                bool subResult = parseBoolExpr(subExpr);

                // Update the result based on the operation type
                if (isAnd) {
                    result = result && subResult;
                    // Short-circuit for AND: if any sub-result is false, return false
                    if (!result) return false;
                } else {
                    result = result || subResult;
                    // Short-circuit for OR: if any sub-result is true, return true
                    if (result) return true;
                }
                start = i + 1;
            }
        }
        return result;
    }
    
//     bool parseOr(string expression) {
//         int n = expression.size();
//         bool result = false;
//         int start = 0, balance = 0;
        
//         for (int i = 0; i < n; ++i) {
//             if (expression[i] == '(') balance++;
//             if (expression[i] == ')') balance--;
            
//             if ((expression[i] == ',' && balance == 0) || i == n - 1) {
//                 string subExpr = expression.substr(start, i - start + (i == n - 1));
//                 result = result || parseBoolExpr(subExpr);
//                 start = i + 1;

//                 // Short-circuit if any part is true
//                 if (result) return true;
//             }
//         }
//         return result;
//     }

};