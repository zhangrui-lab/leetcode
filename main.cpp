#include <iostream>
#include <vector>
#include "uniquePaths/uniquePaths.h"
#include "uniquePathsWithObstacles/uniquePathsWithObstacles.h"
#include "minPathSum/minPathSum.h"

using namespace std;

int main() {
    /*
     * 0 0
     * 1 1
     * 0 0
     */
    //6906900
    vector<vector<int>> nums = {
            {1,3,1},{1,5,1},{4,2,1}
    };
    cout << minPathSum(nums);


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
