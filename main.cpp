#include <iostream>
#include <vector>

#include "spiralMatrix/spiralMatrix.h"
#include "canJump/canJump.h"

using namespace std;

int main() {
    vector<int> nums = {2,0, 0};
    cout << canJump1(nums);
}
