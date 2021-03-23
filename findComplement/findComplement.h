//
// Created by 张锐 on 2021/3/23.
//

#ifndef ALGORITHM_FINDCOMPLEMENT_H
#define ALGORITHM_FINDCOMPLEMENT_H

/*
 * 476. 数字的补数
 *  给你一个正整数 num ，输出它的补数。补数是对该数的二进制表示取反。
 * eg:
 *  输入：num = 5
 *  输出：2
 *  解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
 *
 * 1. 暴力解乏，将所有0转换为1
 * 2. 异或操作: 101 ^ 111: 010; 1110 0101 ^ 1111 1111: 0001 1010
 * 3. 题目的意思就是将正整数n二进制表示中最高位1之后（包括最高位1）全部取反。假设最高位1为第i位，求解过程可以分两步进行：
 *  第一步：将n全部位取反，得到n';
 *  第二步：找到正整数的二进制表示最高位1，即第i位;
 *  第三步：取n'第i位之后所有位，丢弃i之前的高位;
 *  举例，当n = 14时。n的二进制表示为:            0000 0000 0000 0000 0000 0000 0000 1110;
 *      第一步：将n全部取反得到n'，n'二进制表示为   1111 1111 1111 1111 1111 1111 1111 0001;
 *      第二步：找到n的最高位1，这里i = 3(从右往左，假设下标从0开始);
 *      第三步：取n'第i位即第3位之后所有位(0-2位)，丢弃3-31位，得到001，即1;结束。
 *  将n全部位取反，比较常见，可以利用补码，补码 = 反码+1，因此反码=补码-1。所以n' = -n-1;
 *  找到最高位1,我们可以将最高位1往右填充填满整个后续位，然后将得到的结果+1就可以得到最高位1再往高一位的1，再右移就行了，填充的办法如下：
 */

int findComplement(int num) {
    int ans = 0, last = 0;
    for (int i = 0; i < 32; ++i)
        last = num & 1 << i ? i : last;
    for (int i = 0; i <= last; ++i)
        if (!(num & 1 << i))
            ans |= 1 << i;
    return ans;
}

int findComplement2(int num) {
    int ans = 1;
    while (ans < num) {
        ans <<= 1;
        ans += 1;
    }
    return ans ^ num;
}

int findComplement3(int num) {
    int temp = (-num - 1);
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16);
    num = (num + 1) >> 1;
    return (num - 1) & temp;
}

#endif //ALGORITHM_FINDCOMPLEMENT_H
