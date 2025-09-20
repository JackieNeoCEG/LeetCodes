class Spreadsheet {
public:
    unordered_map<string, int> cell2int;
    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        cell2int[cell] = value;
    }
    
    void resetCell(string cell) {
        cell2int[cell] = 0;
    }
    
    int getValue(string formula) {
        int plusPos = formula.find('+');

        string s1 = formula.substr(1, plusPos - 1);
        string s2 = formula.substr(plusPos + 1);

        int X = (s1[0] >= 'A' && s1[0] <= 'Z') ? cell2int[s1] : stoi(s1);
        int Y = (s2[0] >= 'A' && s2[0] <= 'Z') ? cell2int[s2] : stoi(s2); 

        return X + Y;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */