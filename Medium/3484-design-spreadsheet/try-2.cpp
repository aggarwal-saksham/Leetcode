/*
 * Problem #3484: Design Spreadsheet
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 3/19/2025, 9:17:25 AM
 * Link: https://leetcode.com/problems/design-spreadsheet/
 */

class Spreadsheet {
public:
    vector<vector<int>> mt;

     Spreadsheet(int rows) {
        mt.resize(rows + 1, vector<int>(28, 0));
    }

    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        mt[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        mt[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        int plus = formula.find('+');
        string left = formula.substr(0, plus);
        string right = formula.substr(plus + 1);
        int ans = 0;

        if(isdigit(left[0])) ans += stoi(left);
        else {
            int col = left[0] - 'A';
            int row = stoi(left.substr(1));
            ans += mt[row][col];
        }

        if(isdigit(right[0])) ans += stoi(right);
        else {
            int col = right[0] - 'A';
            int row = stoi(right.substr(1));
            ans += mt[row][col];
        }

        return ans;
    }

};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
