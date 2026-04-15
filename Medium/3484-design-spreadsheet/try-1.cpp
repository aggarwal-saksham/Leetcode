/*
 * Problem #3484: Design Spreadsheet
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/15/2025, 8:51:01 PM
 * Link: https://leetcode.com/problems/design-spreadsheet/
 */


    class Spreadsheet {
public:
    vector<vector<int>> mt;

    Spreadsheet(int rows) {
        mt.resize(rows, vector<int>(28, 0)); 
    }

    int parseRow(const string& cell) {
        int row = 0;
        for (int i = 1; i < cell.size(); ++i) {
            row = row * 10 + (cell[i] - '0');  
        }
        return row;
    }

    void setCell(string cell, int value) {
        if (cell.empty() || cell[0] < 'A' || cell[0] > 'Z') return;
        int col = cell[0] - 'A';
        int row = parseRow(cell);

        if (row >= mt.size()) {
            mt.resize(row + 1, vector<int>(28, 0));
        }

        if (col < mt[row].size()) {
            mt[row][col] = value;
        }
    }

    void resetCell(string cell) {
        if (cell.empty() || cell[0] < 'A' || cell[0] > 'Z') return;
        int col = cell[0] - 'A';
        int row = parseRow(cell);

        if (row >= mt.size()) {
            mt.resize(row + 1, vector<int>(28, 0));
        }

        if (col < mt[row].size()) {
            mt[row][col] = 0;
        }
    }

    int getValue(string formula) {
        if (formula.empty() || formula[0] != '=') return 0;

        formula = formula.substr(1);
        int plus = formula.find('+');
        if (plus == string::npos) return 0;

        string left = formula.substr(0, plus);
        string right = formula.substr(plus + 1);
        int ans = 0;

        if (isdigit(left[0])) ans += atoi(left.c_str());
        else {
            int col = left[0] - 'A';
            int row = parseRow(left);

            if (row < mt.size() && col < mt[row].size()) {
                ans += mt[row][col];
            }
        }

        if (isdigit(right[0])) ans += atoi(right.c_str());
        else {
            int col = right[0] - 'A';
            int row = parseRow(right);

            if (row < mt.size() && col < mt[row].size()) {
                ans += mt[row][col];
            }
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
