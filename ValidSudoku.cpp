#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9], col[9], box[3][3];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.') continue; 

                if (row[i].count(num) || col[j].count(num) || box[i / 3][j / 3].count(num)) {
                    return false;
                }

                row[i].insert(num);
                col[j].insert(num);
                box[i / 3][j / 3].insert(num);
            }
        }
        return true;
    }
};
