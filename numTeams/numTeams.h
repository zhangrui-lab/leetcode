
//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_NUMTEAMS_H
#define ALGORITHM_NUMTEAMS_H

/*
 * 1395. 统计作战单位数
 *  n 名士兵站成一排。每个士兵都有一个 独一无二 的评分 rating 。每 3 个士兵可以组成一个作战单位，分组规则如下：
 *  从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]
 *  作战单位需满足： rating[i] < rating[j] < rating[k] 或者 rating[i] > rating[j] > rating[k] ，其中  0 <= i < j < k < n
 *  请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。
 *
 * 1. DFS
 * 2. 枚举所有可能的三元组
 * 3. 枚举中间点
 *  我们也可以枚举三元组 (i, j, k) 中的 j，它是三元组的中间点。
 *  出现在位置 j 左侧且比 j 评分低的士兵数量 iless
 *  出现在位置 j 左侧且比 j 评分高的士兵数量 imore
 *  出现在位置 j 右侧且比 j 评分低的士兵数量 kless
 *  出现在位置 j 右侧且比 j 评分高的士兵数量 kmore
 *  任意iless,k,任意kmore可以构成单调递增序列, 任意imore,k,任意kless可以构成单调递减序列;
 * 4. 离散化树状数组
 *
 */

#include <vector>

void numTeams(int index, std::vector<int> &rating, std::vector<int> &curr, int &num) {
    if (curr.size() == 3) {
        num += (int) (curr[0] < curr[1] && curr[1] < curr[2] || curr[0] > curr[1] && curr[1] > curr[2]);
        return;
    }
    if (rating.size() < 3 || index == rating.size())
        return;
    curr.push_back(rating[index]);
    numTeams(index + 1, rating, curr, num);
    curr.pop_back();
    numTeams(index + 1, rating, curr, num);
}

int numTeams(std::vector<int> &rating) {
    std::vector<int> curr;
    int num = 0;
    numTeams(0, rating, curr, num);
    return num;
}

int numTeams1(std::vector<int> &rating) {
    int num = 0;
    for (int i = 0, n = rating.size(); i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                num += (int) (rating[i] < rating[j] && rating[j] < rating[k] ||
                              rating[i] > rating[j] && rating[j] > rating[k]);
    return num;
}

int numTeams2(std::vector<int> &rating) {
    int num = 0;
    for (int j = 0, n = rating.size(); j < n; ++j) {
        int iLess = 0, iMore = 0, kLess = 0, kMore = 0;
        for (int i = 0; i < n; ++i) {
            if (i < j) {
                if (rating[i] < rating[j]) iLess++;
                if (rating[i] > rating[j]) iMore++;
            }
            if (j < i) {
                if (rating[j] > rating[i]) kLess++;
                if (rating[j] < rating[i]) kMore++;
            }
        }
        num += iLess * kMore + iMore * kLess;
    }
    return num;
}


class Solution {
public:
    static constexpr int MAX_N = 200 + 5;

    int c[MAX_N];
    std::vector<int> disc;
    std::vector<int> iLess, iMore, kLess, kMore;

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int p, int v) {
        while (p < MAX_N) {
            c[p] += v;
            p += lowbit(p);
        }
    }

    int get(int p) {
        int r = 0;
        while (p > 0) {
            r += c[p];
            p -= lowbit(p);
        }
        return r;
    }

    int numTeams(std::vector<int> &rating) {
        disc = rating;
        disc.push_back(-1);
        sort(disc.begin(), disc.end());
        auto getId = [&](int target) {
            return lower_bound(disc.begin(), disc.end(), target) - disc.begin();
        };

        iLess.resize(rating.size());
        iMore.resize(rating.size());
        kLess.resize(rating.size());
        kMore.resize(rating.size());

        for (int i = 0; i < rating.size(); ++i) {
            auto id = getId(rating[i]);
            iLess[i] = get(id);
            iMore[i] = get(201) - get(id);
            add(id, 1);
        }

        memset(c, 0, sizeof c);
        for (int i = rating.size() - 1; i >= 0; --i) {
            auto id = getId(rating[i]);
            kLess[i] = get(id);
            kMore[i] = get(201) - get(id);
            add(id, 1);
        }

        int ans = 0;
        for (unsigned i = 0; i < rating.size(); ++i) {
            ans += iLess[i] * kMore[i] + iMore[i] * kLess[i];
        }

        return ans;
    }
};


#endif //ALGORITHM_NUMTEAMS_H
