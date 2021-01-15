#include <iostream>
#include <vector>
#include "countAndSay/countAndSay.h"
#include "combinationSum/combinationSum.h"
using namespace std;

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    auto resu = combinationSum1(candidates, target);
    for (int i = 0; i < resu.size(); ++i) {
        for (int j = 0; j < resu[i].size(); ++j) {
            printf("%d ", resu[i][j]);
        }
        printf("\n");
    }
}