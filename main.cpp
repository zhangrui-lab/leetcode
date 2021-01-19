#include <iostream>
#include <vector>

#include "spiralMatrix/spiralMatrix.h"
#include "canJump/canJump.h"
#include "mergeIntervals/mergeIntervals.h"
#include "insertInterval/insertInterval.h"
#include "lengthOfLastWord/lengthOfLastWord.h"
#include "generateMatrix/generateMatrix.h"
#include "permutationSequence/permutationSequence.h"
#include "rotateRight/rotateRight.h"

using namespace std;

int main() {
//    ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* node = new ListNode(0, new ListNode(1, new ListNode(2)));
    node = rotateRight(nullptr, 0);
    while (node) {
        cout << node->val << "->";
        node = node->next;
    }

//    auto resu =  generateMatrix(3);
//    for (int i = 0; i < resu.size(); ++i) {
//        for (int j = 0; j < resu[i].size(); ++j) {
//            printf("%d ", resu[i][j]);
//        }
//        printf("\n");
//    }
}
