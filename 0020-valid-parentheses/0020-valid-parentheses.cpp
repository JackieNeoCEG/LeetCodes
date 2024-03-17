class Solution {
public:
    bool isValid(string s) {
        stack<char> stack; 
        for (char c : s) { 
            if (c == '(' || c == '{' || c == '[') {     //if opening bracket
                stack.push(c);
            } else {                                    // if closing bracket
                if (stack.empty() ||
                    (c == ')' && stack.top() != '(') || 
                    (c == '}' && stack.top() != '{') ||
                    (c == ']' && stack.top() != '[')) {
                    return false; 
                }
                stack.pop();
            }
        }
        return stack.empty();                              // Returning an empty stack means true, 
                                                           // non-empty stack means false :mindblown:
    }
};