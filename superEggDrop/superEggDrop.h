//
// Created by 张锐 on 2021/3/23.
//

#ifndef ALGORITHM_SUPEREGGDROP_H
#define ALGORITHM_SUPEREGGDROP_H

/*
 * 887. 鸡蛋掉落
 *  给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
 *  已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。
 *  每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。
 *  请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
 * eg:
 *  输入：k = 1, n = 2
 *  输出：2
 * 解释：
 *  鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
 *  否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
 *  如果它没碎，那么肯定能得出 f = 2 。
 *  因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
 *
 *  输入：k = 2, n = 6
 *  输出：3
 *
 *  输入：k = 3, n = 14
 *  输出：4
 *
 * 1. 蛮力策略求多少层会摔碎: 1层一层往上迭代。直至鸡蛋摔碎
 * 2. 二分策略求多少层会摔碎: 前k-1个鸡蛋对楼层进行二分，第k个鸡蛋在[lower, high)中进行迭代
 * 3. 分组策略求多少层会摔碎: 将楼层分为 n/k 组，每组在最高处进行一次尝试。当只剩最后一个鸡蛋时，从低向高尝试。
 *
 * todo
 */

#include <unordered_map>
#include <vector>

class Solution {
    std::unordered_map<int, int> memo;

    int dp(int k, int n) {
        if (memo.find(n * 100 + k) == memo.end()) {
            int ans;
            if (n == 0) {
                ans = 0;
            } else if (k == 1) {
                ans = n;
            } else {
                int lo = 1, hi = n;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(k - 1, x - 1);
                    int t2 = dp(k, n - x);

                    if (t1 < t2) {
                        lo = x;
                    } else if (t1 > t2) {
                        hi = x;
                    } else {
                        lo = hi = x;
                    }
                }

                ans = 1 + std::min(std::max(dp(k - 1, lo - 1), dp(k, n - lo)),
                                   std::max(dp(k - 1, hi - 1), dp(k, n - hi)));
            }

            memo[n * 100 + k] = ans;
        }

        return memo[n * 100 + k];
    }

public:
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};

class Solution1 {
public:
    int superEggDrop(int k, int n) {
        if (n == 1) {
            return 1;
        }
        std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1));
        for (int i = 1; i <= k; ++i) {
            f[1][i] = 1;
        }
        int ans = -1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
            }
            if (f[i][k] >= n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};


#endif //ALGORITHM_SUPEREGGDROP_H
