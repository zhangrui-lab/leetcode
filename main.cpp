#include <iostream>
#include <vector>
#include "countAndSay/countAndSay.h"
#include "combinationSum/combinationSum.h"
#include "combinationSum2/combinationSum2.h"
#include "firstMissingPositive/firstMissingPositive.h"
#include "trappingRainWater/trappingRainWater.h"
#include "permutations/permutations.h"
#include "permuteUnique/permuteUnique.h"
#include "rotateImage/rotateImage.h"
#include "groupAnagrams/groupAnagrams.h"

using namespace std;

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto matrix = groupAnagrams1(strs);

//    vector<vector<int>> matrix = {
//                    { 5, 1, 9,11},
//                    { 2, 4, 8,10},
//                    {13, 3, 6, 7},
//                    {15,14,12,16}
//            };
//    rotateImage2(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            printf("%s ", matrix[i][j].c_str());
        }
        printf("\n");
    }
}
