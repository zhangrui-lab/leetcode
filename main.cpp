#include <iostream>
#include <vector>
#include "countAndSay/countAndSay.h"
#include "combinationSum/combinationSum.h"
#include "combinationSum2/combinationSum2.h"
#include "firstMissingPositive/firstMissingPositive.h"
using namespace std;

int main() {
    vector<int> candidates = {3,4,-1,1,4,9,-5};
    cout << firstMissingPositive1(candidates);
}

