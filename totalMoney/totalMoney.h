//
// Created by 张锐 on 2021/3/11.
//

#ifndef ALGORITHM_TOTALMONEY_H
#define ALGORITHM_TOTALMONEY_H

/*
 * 1716. 计算力扣银行的钱
 *  Hercy 想要为购买第一辆车存钱。他每天都往力扣银行里存钱。
 *  最开始，他在周一的时候存入 1 块钱。从周二到周日，他每天都比前一天多存入 1 块钱。在接下来每一个周一，他都会比前一个周一多存入 1 块钱。
 *  给你 n ，请你返回在第 n 天结束的时候他在力扣银行总共存了多少块钱。
 * eg:
 *  输入：n = 4
 *  输出：10
 *  解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
 *
 *  输入：n = 10
 *  输出：37
 *  解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
 */

int totalMoney(int n) {
    int res = 0;
    int week = 1;
    int day = 0;
    for (int i = 0; i < n; i++) {
        day++;
        if (day == week + 7) {
            week++;
            day = week;
        }
        res += day;
    }
    return res;
}

#endif //ALGORITHM_TOTALMONEY_H
