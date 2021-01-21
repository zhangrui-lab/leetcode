//
// Created by 张锐 on 2021/1/21.
//

#ifndef ALGORITHM_SORTCOLORS_H
#define ALGORITHM_SORTCOLORS_H

/*
 * 75. 颜色分类
 *  给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 *  此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 *  1. 一次排序界定0和非0, 第二次排序界定1和非1。
 *  2. 一次排序,分别使用i,j界定0,1和2。for p=0 to n: nums[p]=0时, 交换nums[p],nums[i]，扩展i,j并再查看nums[p]是否为1。 nums[p]=1时，交换nums[p],nums[j]并扩展j。 nums[p]=2时，i,j不扩展。
 *  3. 一次排序i定0和非0, j界定2和非2。i从前向后，j从后向前。for p=0 to n: 遇到0时扩展i，遇到2时,交换nums[p],nums[j],并再次查看nums[p]。遇到1时不扩展。
 */

#include <vector>

void sortColors1(std::vector<int> &nums) {
    int n = nums.size(), j = 0;
    for (int i = 0; i < n; ++i)
        if (nums[i] == 0)
            std::swap(nums[j++], nums[i]);
    for (int k = j; k < n; ++k)
        if (nums[k] == 1)
            std::swap(nums[j++], nums[k]);
}

void sortColors2(std::vector<int> &nums) {
    for (int p = 0, i = p, j = p; p < nums.size(); ++p) {
        if (nums[p] == 1) {
            std::swap(nums[j++], nums[p]);
        } else if (nums[p] == 0) {
            std::swap(nums[i++], nums[p]);
            if (nums[p] == 1) {
                std::swap(nums[j++], nums[p]);
            }
            if (j < i)
                j = i;
        }
    }
}

void sortColors3(std::vector<int> &nums) {
    for (int p = 0, i = p, j = nums.size() - 1; p <= j;) {
        if (nums[p] == 0) {
            std::swap(nums[i++], nums[p++]);
        } else if (nums[p] == 2) {
            std::swap(nums[j--], nums[p]);
        } else {
            p++;
        }
    }
}

#endif //ALGORITHM_SORTCOLORS_H
