//
// Created by 张锐 on 2021/3/18.
//

#ifndef ALGORITHM_SMALLESTK_H
#define ALGORITHM_SMALLESTK_H

/*
 * 面试题 17.14. 最小K个数
 *  设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
 * eg:
 *  输入： arr = [1,3,5,7,2,4,6,8], k = 4
 *  输出： [1,2,3,4]
 *
 * 提示：
 *  0 <= len(arr) <= 100000
 *  0 <= k <= min(100000, len(arr))
 *
 * 1. 排序输入序列并输出其前k个数
 * 2. partition 随机化算法
 *  基于快速划分的k选取： 减治策略，任选一轴点进行划分， 考查轴点秩r与k的相对大小进行处理。
 *  每经过一步主迭代，都会构造出一个轴点A[i]，然后lo和hi将彼此靠拢，查找范围将收缩至A[i]的某一侧。当轴点的秩i恰为k时，算法随即终止。如此，A[k]即是待查找的目标元素。
 *   if k == r:
 *      return r;
 *  else k < r:
 *      [lo, r) 中进行 k选取
 *   else k > r:
 *      [r+1, hi) 中进行 k-r 选取
 * 复杂度： 尽管内循环仅需O(hi - lo + 1)时间，但很遗憾，外循环的次数却无法有效控制。与快速排序算法一样，最坏情况下外循环需执行O(n)次，总体运行时间为O(n^2)。
 *
 * 3. 基于堆的算法
 */

#include <vector>
#include <queue>

std::vector<int> smallestK(std::vector<int> &arr, int k) {
    std::sort(arr.begin(), arr.end());
    arr.resize(k);
    return arr;
}

std::vector<int> smallestK2(std::vector<int> &arr, int k) {
    if (k == 0)
        return {};
    auto partition = [](std::vector<int> &arr, int lo, int hi) {
        std::swap(arr[hi - 1], arr[lo + rand() % (hi - lo)]);
        int pivot = arr[hi - 1], j = lo - 1;
        for (int i = lo; i < hi - 1; ++i)
            if (arr[i] <= pivot)
                std::swap(arr[i], arr[++j]);
        std::swap(arr[hi - 1], arr[++j]);
        return j;
    };
    int lo = 0, hi = arr.size();
    while (true) {
        int r = partition(arr, lo, hi);
        if (r == k) {
            arr.resize(k);
            return arr;
        }
        if (k < r) {
            hi = r;
        }
        if (r < k) {
            lo = r + 1;
        }
    }
}

std::vector<int> smallestK3(std::vector<int> &arr, int k) {
    if (k == 0)
        return {};
    std::priority_queue<int> queue;
    for (int i = 0; i < k; ++i)
        queue.push(arr[i]);
    for (int i = k; i < arr.size(); ++i) {
        if (arr[i] < queue.top()) {
            queue.pop();
            queue.push(arr[i]);
        }
    }
    std::vector<int> ans;
    while (!queue.empty()) {
        ans.push_back(queue.top());
        queue.pop();
    }
    return ans;
}

#endif //ALGORITHM_SMALLESTK_H

