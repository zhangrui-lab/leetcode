//
// Created by Administrator on 2021/9/3.
//

#ifndef ALGORITHM_GETHINT_H
#define ALGORITHM_GETHINT_H

/**
 * 299. 猜数字游戏
 *  你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：
 *      你写出一个秘密数字，并请朋友猜这个数字是多少。
 *      朋友每猜测一次，你就会给他一个提示，告诉他的猜测数字中有多少位属于数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位属于数字猜对了但是位置不对（称为“Cows”, 奶牛）。
 *      朋友根据提示继续猜，直到猜出秘密数字。
 *      请写出一个根据秘密数字和朋友的猜测数返回提示的函数，返回字符串的格式为 xAyB ，x 和 y 都是数字，A 表示公牛，用 B 表示奶牛。
 *      xA 表示有 x 位数字出现在秘密数字中，且位置都与秘密数字一致。yB 表示有 y 位数字出现在秘密数字中，但位置与秘密数字不一致。 请注意秘密数字和朋友的猜测数都可能含有重复数字，每位数字只能统计一次。
 */

#include <set>
#include <string>

using namespace std;

string getHint(string secret, string guess) {
    vector<int> stand(10, 0);
    int Rnums = 0, RRnums = 0;
    for (int i = 0; i < secret.size(); i++) {
        stand[secret[i] - '0']++;                      // 统计每个数字出现的次数
    }

    for (int i = 0; i < guess.size(); i++) {
        if (guess[i] == secret[i]) {
            RRnums++;                               // 步骤二
        }
        if (stand[guess[i] - '0'] > 0) {                  // 如果这个数字出现了，则已有数量减一
            Rnums++;                                // 步骤一
            stand[guess[i] - '0']--;
        }
    }
    Rnums = Rnums - RRnums;
    string res = to_string(RRnums) + "A" + to_string(Rnums) + "B";
    return res;
}

#endif //ALGORITHM_GETHINT_H
