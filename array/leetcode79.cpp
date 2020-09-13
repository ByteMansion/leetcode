/**
 * @brief   Leetcode 79: Word Search
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 */

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // create an array to 
        int row = board.size();
        int col = board[0].size();

        vector<pair<int, int>> startPos;
        char startChar = word[0];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == startChar) {
                    startPos.push_back(make_pair(i, j));
                }
            }
        }
        if(startPos.size() == 0) {
            return false;
        }

        return existHelp(board, word, startPos);
    }
private:
    bool existHelp(vector<vector<char>>& board, string word, vector<pair<int, int>> start) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < start.size(); i++) {
            bool is_found = findWord(board, visited, word, 0, start[i].first, start[i].second);
            if(is_found) {
                return true;
            }
        }
        return false;
    }
    bool findWord(vector<vector<char>>& board, vector<vector<bool>> visited, string word, int idx, int row, int col) {
        if(idx >= word.size()) {
            return true;
        }
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        if(board[row][col] != word[idx]) {
            return false;
        } else if(visited[row][col]) {
            return false;
        }
        visited[row][col] = true;
        return findWord(board, visited, word, idx+1, row-1, col) ||
               findWord(board, visited, word, idx+1, row+1, col) ||
               findWord(board, visited, word, idx+1, row, col-1) ||
               findWord(board, visited, word, idx+1, row, col+1);
    }
};
int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution obj;
    // case 1
    string word = "ABCCED";
    cout << word << ":" << obj.exist(board, word) << endl;

    // case 2
    word = "SEE";
    cout << word << ":" << obj.exist(board, word) << endl;

    // case 3
    word = "ABCB";
    cout << word << ":" << obj.exist(board, word) << endl;

    return 0;
}
