#include <iostream>
#include <vector>
#include "countAndSay/countAndSay.h"
#include "combinationSum/combinationSum.h"
#include "combinationSum2/combinationSum2.h"
#include "firstMissingPositive/firstMissingPositive.h"
#include "trappingRainWater/trappingRainWater.h"
#include "permutations/permutations.h"
using namespace std;

int main() {
    vector<int> candidates = {1,2,3};
    auto resu = permute2(candidates);
    for (int i = 0; i < resu.size(); ++i) {
        for (int j = 0; j < resu[i].size(); ++j) {
            printf("%d ", resu[i][j]);
        }
        printf("\n");
    }
}

