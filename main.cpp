#include <iostream>
#include <vector>

#include "spiralMatrix/spiralMatrix.h"

using namespace std;

int main() {
    vector<vector<int>>matrix  = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    auto resu = spiralOrder(matrix);
    for (int i = 0; i < resu.size(); ++i) {
        printf("%d ", resu[i]);
    }
}
