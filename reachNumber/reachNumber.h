//
// Created by 张锐 on 2021/3/12.
//

#ifndef ALGORITHM_REACHNUMBER_H
#define ALGORITHM_REACHNUMBER_H

/*
 * 754. 到达终点数字
 *  在一根无限长的数轴上，你站在0的位置。终点在target的位置。
 *  每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。
 *  返回到达终点需要的最小移动次数。
 *
 * 思路概述：
 *  给点给一个target，不管值是正值还是负值，需要的步数是同样的，所以我们统一考虑为正值，统一取绝对值。
 *  向右走是加，向左走是减，那我们可以先不停的向右走，那么走的格数就是1+2+3+a... 当无法得到给定的target值时，代表我们其中是有几步是需要向左走的，那么向左走一步，会导致结果减小2对应的步数。比如第二格我们向左，本来是加2，现在是减2，一来一去少了2*2=4格。
 *  所以我们可以不断累加，直到遇到sum值-target是偶数的情况，当前走的步数就是结果
 */

int reachNumber(int target) {
    int sum = 0;
    int i = 0;
    int a = std::abs(target);
    while (sum < a || (sum - a) % 2 != 0) {
        sum += i;
        i++;
    }
    return i - 1;//因为在判断结果前都要让i+1，所以这里返回的是i-1
}

#endif //ALGORITHM_REACHNUMBER_H
