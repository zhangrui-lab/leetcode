//
// Created by 张锐 on 2021/3/10.
//

#ifndef ALGORITHM_REACHINGPOINTS_H
#define ALGORITHM_REACHINGPOINTS_H

/*
 * 780. 到达终点
 *  从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
 *  给定一个起点 (sx, sy) 和一个终点 (tx, ty)，如果通过一系列的转换可以从起点到达终点，则返回 True ，否则返回 False。
 *
 * 1. DFS
//                                        (1,1)(3,5)
//                          (2,1)                           (1，2)
//                (3,1)               (2,3)             (3,2)
//        (4,1)         (3,4)     (5,3)   (2,5)     (5,2)  (3,5)
//                  (7,4)   (3,7)       (7,5) (2,7)
 * 2. 动态规划/基于备忘录的递归求解
 * 3. 回溯法(简单变体)
 *  每个父点 (x, y) 都有两个子点 (x, x+y) 和 (x+y, y)。由于坐标不能为负，每个子点 (x, y) 只能有一个父点，当 x >= y 时父点为 (x-y, y)；当 y > x 时父点为 (x, y-x)。
 * 4. 回溯法(取模变体)
 *  使用模运算加速求解父点的过程。
 *  当 tx > ty 时，求解父点的运算是 tx - ty，并且它的往上 tx = tx % ty 个父点都是减去 ty。当同时满足 tx > ty 和 ty <= sy 时，可以一次性执行所有的这些操作，直接令 tx %= ty。
 *  否则，如果满足 tx > ty 和 ty <= sy，那么 ty 不再改变，只能不断从 tx 中减去 ty。因此， (tx - sx) % ty == 0 是结果为 true 的充要条件。
 *  上面的分析是针对 tx > ty 的情况，对于 ty > tx 的情况类似。 当 tx == ty 时，无法再求解父点。
 * 5. 辗转相除法
 */

#include <map>
#include <utility>

bool reachingPoints(int sx, int sy, int tx, int ty) {
    if (sx == tx && sy == ty)
        return true;
    if (sx > tx || sy > ty)
        return false;
    return reachingPoints(sx + sy, sy, tx, ty) || reachingPoints(sx, sx + sy, tx, ty);
}

bool reachingPoints1(int sx, int sy, int tx, int ty, std::map<std::pair<int, int>, bool> &memo) {
    bool can;
    if (sx == tx && sy == ty) {
        can = true;
    } else if (sx > tx || sy > ty) {
        can = false;
    } else {
        can = reachingPoints1(sx + sy, sy, tx, ty, memo) || reachingPoints1(sx, sx + sy, tx, ty, memo);
    }
    memo[{sx, sy}] = can;
    return memo[{sx, sy}];
}

bool reachingPoints1(int sx, int sy, int tx, int ty) {
    std::map<std::pair<int, int>, bool> memo;
    return reachingPoints1(sx, sy, tx, ty, memo);
}

bool reachingPoints2(int sx, int sy, int tx, int ty) {
    while (tx >= sx && ty >= sy) {
        if (sx == tx && sy == ty)
            return true;
        if (tx > ty)
            tx -= ty;
        else
            ty -= tx;
    }
    return false;
}

bool reachingPoints3(int sx, int sy, int tx, int ty) {
    while (tx >= sx && ty >= sy) {
        if (tx == ty)
            break;
        if (tx > ty) {
            if (ty > sy) tx %= ty;
            else return (tx - sx) % ty == 0;
        } else {
            if (tx > sx) ty %= tx;
            else return (ty - sy) % tx == 0;
        }
    }
    return (tx == sx && ty == sy);
}

bool reachingPoints4(int sx, int sy, int tx, int ty) {
    if (tx < sx || ty < sy) return false;
    if (tx > ty) {
        if (sy == ty)
            return sx >= (tx % ty) && (tx - sx) % sy == 0;
        return reachingPoints4(sx, sy, tx % ty, ty);
    } else if (tx < ty) {
        if (sx == tx)
            return sy >= (ty % tx) && (ty - sy) % sx == 0;
        return reachingPoints4(sx, sy, tx, ty % tx);
    } else return tx == sx && ty == sy;
}

#endif //ALGORITHM_REACHINGPOINTS_H
