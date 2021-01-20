#include <iostream>
#include <vector>
#include "uniquePaths/uniquePaths.h"
#include "uniquePathsWithObstacles/uniquePathsWithObstacles.h"
#include "minPathSum/minPathSum.h"
#include "plusOne/plusOne.h"
#include "addBinary/addBinary.h"
#include "fullJustify/fullJustify.h"
#include "mySqrt/mySqrt.h"
#include "climbStairs/climbStairs.h"

using namespace std;

int main() {

    cout << climbStairs2(20);

//    vector<string> strs = {"This", "is", "an", "example", "of", "text", "justification."};
//    int num = 25;
//    auto ans = fullJustify(strs, num);
//    for (int i = 0; i < ans.size(); ++i) {
//        printf("%s|", ans[i].c_str());
//    }

//    vector<vector<int>> nums = {
//            {1,3,1},{1,5,1},{4,2,1}
//    };
//    cout << minPathSum(nums);


//    ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
//    ListNode* node = new ListNode(0, new ListNode(1, new ListNode(2)));
//    node = rotateRight(nullptr, 0);
//    while (node) {
//        cout << node->val << "->";
//        node = node->next;
//    }

//    auto resu =  generateMatrix(3);
//    for (int i = 0; i < resu.size(); ++i) {
//        for (int j = 0; j < resu{i}.size(); ++j) {
//            printf("%d ", resu{i}{j});
//        }
//        printf("\n");
//    }
}
