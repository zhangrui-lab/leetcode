//
// Created by Administrator on 2021/7/26.
//

#ifndef ALGORITHM_COUNTPRIMES_H
#define ALGORITHM_COUNTPRIMES_H

/**
 * 204. 计数质数 (质数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。)
 *  统计所有小于非负整数 n 的质数的数量。
 *
 * 示例 1：
 *  输入：n = 10
 *  输出：4
 *  解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 * 求解策略:
 *  1. 蛮力策略: 判断数x是否为质数, 从2到x的每一个数y, 看x%y是否都不为0.
 *  2. 从2到 根号x 的每一个数y, 看x%y是否都不为0.
 *  3. 埃氏筛: 枚举没有考虑到数与数的关联性，因此难以再继续优化时间复杂度。接下来我们介绍一个常见的算法，该算法由希腊数学家厄拉多塞提出，称为厄拉多塞筛法，简称埃氏筛。
 *     我们考虑这样一个事实：如果 xx 是质数，那么大于 xx 的 xx 的倍数 2x,3x,… 一定不是质数，因此我们可以从这里入手。我们设 isPrime[i] 表示数 ii 是不是质数，如果是质数则为 1，否则为 0。
 *     从小到大遍历每个数，如果这个数为质数，则将其所有的倍数都标记为合数（除了该质数本身），即 0，这样在运行结束的时候我们即能知道质数的个数。
 *     这种方法的正确性是比较显然的：这种方法显然不会将质数标记成合数；另一方面，当从小到大遍历到数 x 时，倘若它是合数，则它一定是某个小于 x 的质数 y 的整数倍，故根据此方法的步骤，我们在遍历
 *     到 y 时，就一定会在此时将 xx 标记为 isPrime[x]=0。因此，这种方法也不会将合数标记为质数。
 *     当然这里还可以继续优化，对于一个质数 x，如果按上文说的我们从 2x 开始标记其实是冗余的，应该直接从  xx 开始标记，因为 2x,3x,… 这些数一定在 x 之前就被其他数的倍数标记过了，例如 2 的所有倍数，3 的所有倍数等。
 * 4. 线性筛
 */

#include <cmath>
#include <vector>

using namespace std;

int isPrimes(int n) {
    int ans = 1;
    for (int i = 2; ans && i < n; ++i) {
        ans &= ((n % i) != 0);
    }
    return ans;
}

int isPrimes2(int n) {
    int ans = 1;
    for (int i = 2, r = (int) sqrt(n); ans && i <= r; ++i) {        // 可以优化掉偶数; i+=2
        ans &= ((n % i) != 0);
    }
    return ans;
}

int countPrimes(int n) {
    int num = 0;
    for (int i = 2; i < n; ++i) {
        num += isPrimes(i);
    }
    return num;
}

int countPrimes3(int n) {
    int ans = 0;
    vector<int> isPrime(n, 1);
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            ans += 1;
            if ((long long) i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
    }
    return ans;
}

int countPrimes4(int n) {
    vector<int> primes;
    vector<int> isPrime(n, 1);
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primes.size();
}

#endif //ALGORITHM_COUNTPRIMES_H
