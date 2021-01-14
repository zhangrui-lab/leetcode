#include <iostream>
#include <vector>
#include "reverseKGroup/reverseKGroup.h"
#include "removeDuplicatesFromSortedArray/removeDuplicatesFromSortedArray.h"
#include "removeElement/removeElement.h"
#include "divideTwoIntegers/divideTwoIntegers.h"
#include "substringWithConcatenationOfAllWords/substringWithConcatenationOfAllWords.h"
#include "nextPermutation/nextPermutation.h"

using namespace std;

int main() {

    //nums = [1,2,3]3
    //输出：[1,3,2]
    vector<int> nums = {1,3,2};
    nextPermutation2(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
    }

//    string   s = "word good good good best word";
// "barfoothefoobarman"
//["foo","bar"]
//    string   s = "barfoothefoobarman";
//    vector<string> words = {"foo","bar"};
//    auto p = findSubstring1(s, words);
//    for (int i = 0; i < p.size(); ++i) {
//        cout << p[i] << " ";


//    string haystack = "a";
//    string needle = "a";
//    cout << strStr(haystack, needle);


//    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
//    int n = removeElement1(nums, 0);
//    for (int i = 0; i < n; ++i) {
//        cout << nums[i] << " ";
//    }

    //给你这个链表：1->2->3->4->5
    //当 k = 2 时，应当返回: 2->1->4->3->5
    //当 k = 3 时，应当返回: 3->2->1->4->5
//    ListNode* node1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
//    ListNode* node1 = new ListNode(1, new ListNode(2));
//    node1 = reverseKGroup1(node1, 2);
//    while (node1) {
//        cout << node1->val << " ";
//        node1 = node1->next;
//    }
}