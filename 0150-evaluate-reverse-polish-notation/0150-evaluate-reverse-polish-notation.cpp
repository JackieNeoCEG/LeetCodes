class Solution {
public:
    int resolve(int a, int b, char op) {
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else if(op == '*') return a * b;
        return a / b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;
        
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i].size() == 1 && tokens[i][0] < 48) {
                int integer2 = Stack.top();
                Stack.pop();
                int integer1 = Stack.top();
                Stack.pop();
                
                string Operator = tokens[i];
                int resolvedAns = resolve(integer1, integer2 , Operator[0]);
                Stack.push(resolvedAns);
            } else { 
                //stoi: string to int
                Stack.push(stoi(tokens[i]));
            }
        }
        return Stack.top();
    }
};