//
// Created by Administrator on 2021/9/6.
//

#ifndef ALGORITHM_SORTITEMS_H
#define ALGORITHM_SORTITEMS_H

/**
 * 1203. 项目管理
 *  有 n 个项目，每个项目或者不属于任何小组，或者属于 m 个小组之一。group[i] 表示第 i 个项目所属的小组，如果第 i 个项目不属于任何小组，则 group[i] 等于 -1。项目和小组都是从零开始编号的。可能存在小组不负责任何项目，即没有任何项目属于这个小组。
 *  请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
 *      同一小组的项目，排序后在列表中彼此相邻。
 *      项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
 *      如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个空列表 。
 * 求解策略:
 *  1. 带分组(同一小组的项目，排序后在列表中彼此相邻)的拓扑排序.
 */

#include <vector>
#include <algorithm>
#include <mem.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        //ans保存最后的答案，blank用于返回空数组
        vector<int> ans, blank;

        //如果某个项目不属于当前任何小组，新建一个小组，并且把它分给这个小组，为了避免冲突，新的小组编号从m开始
        for (int i = 0; i < group.size(); i++)
            if (group[i] == -1) {
                group[i] = m++;
            }

        //分别保存组间依赖关系、项目之间的依赖关系、各个小组负责的项目
        vector<int> topoGroup[m], topoItem[n], groupItem[m];
        //分别保存小组和项目在图中的入度
        int groupDgr[m], itemDgr[n];
        //避免添加多余的有向边，依赖关系只需要一条有向边就可以表示
        unordered_set<int> vis;
        memset(groupDgr, 0, sizeof groupDgr);
        memset(itemDgr, 0, sizeof itemDgr);
        for (int i = 0; i < beforeItems.size(); i++) {
            //将项目添加到对应的组内
            groupItem[group[i]].push_back(i);
            for (int j = 0; j < beforeItems[i].size(); j++) {
                //hashval用于判断是否有重复的邮箱边出现
                int u = beforeItems[i][j], hashval = group[u] * m + group[i];
                topoItem[u].push_back(i);
                itemDgr[i]++;
                //自己不能依赖自己
                if (group[i] == group[u] || vis.find(hashval) != vis.end()) continue;
                vis.insert(hashval);
                topoGroup[group[u]].push_back(group[i]);
                groupDgr[group[i]]++;
            }
        }

        //groupOrder保存了组的顺序
        queue<int> q;
        vector<int> groupOrder;
        for (int i = 0; i < m; i++)
            if (groupDgr[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            groupOrder.push_back(u);
            for (int i = 0; i < topoGroup[u].size(); i++) {
                int v = topoGroup[u][i];
                groupDgr[v]--;
                if (groupDgr[v] == 0) q.push(v);
            }
        }

        //判断组内项目是否满足拓扑排序
        for (int i = 0; i < groupOrder.size(); i++) {
            int t = groupOrder[i];
            for (int j = 0; j < groupItem[t].size(); j++) {
                int u = groupItem[t][j];
                if (itemDgr[u] == 0) q.push(u);
            }

            int cnt = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cnt++;
                ans.push_back(u);
                for (int j = 0; j < topoItem[u].size(); j++) {
                    int v = topoItem[u][j];
                    itemDgr[v]--;
                    if (itemDgr[v] == 0 && group[v] == t) q.push(v);
                }
            }
            if (cnt != groupItem[t].size()) return blank;
        }

        //如果组间关系不能满足拓扑排序，必定有项目不能加入ans内
        if (ans.size() != n) return blank;

        return ans;
    }
};

#endif //ALGORITHM_SORTITEMS_H
