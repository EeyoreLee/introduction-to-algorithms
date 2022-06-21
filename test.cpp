#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n = 5;
    int row = 2;
    int col = 3;
    string s = "...";
    s[1] = "Q";
    vector<string> board(n, string(n, '.'));
    board[row] = "..Q..";
    for (auto c: board){
        cout<< c <<endl;
    }
    return 0;
}