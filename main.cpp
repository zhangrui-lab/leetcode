#include <iostream>
#include <vector>
#include "countAndSay/countAndSay.h"
#include "combinationSum/combinationSum.h"
#include "combinationSum2/combinationSum2.h"
#include "firstMissingPositive/firstMissingPositive.h"
using namespace std;

int main() {
    vector<int> candidates = {1,1};
    cout << firstMissingPositive2(candidates);
}

