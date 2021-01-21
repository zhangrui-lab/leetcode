//
// Created by 张锐 on 2021/1/18.
//

#ifndef ALGORITHM_TOTALNQUEENS_H
#define ALGORITHM_TOTALNQUEENS_H

/*
 * N皇后 II
 *  n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。给你一个整数n，返回n皇后问题不同的解决方案的数量。
 *
 * 位运算优化之后的N皇后求解。
 */
void totalNQueens(int n, int row, int &nums, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
        nums++;
        return;
    }
    int bits = ~(columns | diagonals1 | diagonals2) & ((1 << n) - 1);
    while (bits > 0) {
        int pick = bits & -bits;
        totalNQueens(n, row + 1, nums, columns | pick, (diagonals1 | pick) << 1, (diagonals2 | pick) >> 1);
        bits &= bits - 1;
    }
}

int totalNQueens(int n) {
    int columns = 0, diagonals1 = 0, diagonals2 = 0, nums = 0;
    totalNQueens(n, 0, nums, columns, diagonals1, diagonals2);
    return nums;
}

#endif //ALGORITHM_TOTALNQUEENS_H
