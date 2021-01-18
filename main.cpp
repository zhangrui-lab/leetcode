#include <iostream>
#include <vector>

#include "solveNQueens/solveNQueens.h"
#include "totalNQueens/totalNQueens.h"
#include "maximumSubarray/maximumSubarray.h"

using namespace std;

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
//    auto resu = solveNQueens2(4);
//    for (int i = 0; i < resu.size(); ++i) {
//        for (int j = 0; j < resu[i].size(); ++j) {
//            printf("%s ", resu[i][j].c_str());
//        }
//        printf("\n");
//    }
}
