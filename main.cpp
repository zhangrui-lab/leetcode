#include <iostream>
#include <vector>
#include "countAndSay/countAndSay.h"
#include "combinationSum/combinationSum.h"
#include "combinationSum2/combinationSum2.h"
#include "firstMissingPositive/firstMissingPositive.h"
#include "trappingRainWater/trappingRainWater.h"
#include "permutations/permutations.h"
#include "permuteUnique/permuteUnique.h"
using namespace std;

int main() {
    vector<int> candidates = {2,2,1,1};
    auto resu = permuteUnique2(candidates);
    for (int i = 0; i < resu.size(); ++i) {
        for (int j = 0; j < resu[i].size(); ++j) {
            printf("%d ", resu[i][j]);
        }
        printf("\n");
    }
}
