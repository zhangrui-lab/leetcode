#include <iostream>
#include <vector>

#include "solveNQueens/solveNQueens.h"

using namespace std;

int main() {
    auto resu = solveNQueens2(4);
    for (int i = 0; i < resu.size(); ++i) {
        for (int j = 0; j < resu[i].size(); ++j) {
            printf("%s ", resu[i][j].c_str());
        }
        printf("\n");
    }
}
