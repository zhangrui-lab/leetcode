#include <iostream>
#include <vector>

#include "spiralMatrix/spiralMatrix.h"
#include "canJump/canJump.h"
#include "mergeIntervals/mergeIntervals.h"

using namespace std;

int main() {
    // [1,3],[2,6],[8,10],[15,18]
    vector<vector<int>> nums = {
            {1,3},
            {2,6},
            {8,10},
            {15,18},
    };
    auto resu =  mergeIntervals1(nums);
    for (int i = 0; i < resu.size(); ++i) {
        for (int j = 0; j < resu[i].size(); ++j) {
            printf("%d ", resu[i][j]);
        }
        printf("\n");
    }
}
