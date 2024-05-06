/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
private:
    string stack;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, visited, word, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool
    dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int i, int j)
    {
        if (stack == word)
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return false;
        }
        if (board[i][j] != word[stack.size()])
        {
            return false;
        }
        if (visited[i][j] == 1)
        {
            return false;
        }
        visited[i][j] = 1;
        stack.push_back(board[i][j]);
        bool up = dfs(board, visited, word, i + 1, j);
        bool down = dfs(board, visited, word, i - 1, j);
        bool left = dfs(board, visited, word, i, j - 1);
        bool right = dfs(board, visited, word, i, j + 1);
        visited[i][j] = 0;
        stack.pop_back();
        return up || down || left || right;
    }
};
// @lc code=end
