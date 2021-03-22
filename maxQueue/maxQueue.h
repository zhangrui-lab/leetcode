//
// Created by 张锐 on 2021/3/22.
//

#ifndef ALGORITHM_MAXQUEUE_H
#define ALGORITHM_MAXQUEUE_H

/*
 * 剑指 Offer 59 - II. 队列的最大值
 *  请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 *  若队列为空，pop_front 和 max_value 需要返回 -1
 * eg:
 *  输入: ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]  [[],[1],[2],[],[],[]]
 *  输出: [null,null,null,2,1,2]
 */

class MaxQueue {
public:
    MaxQueue() : header(new QueueNode(-1, trailer)), trailer(new QueueNode(-1, header)) {
        header->next = trailer;
    }

    int max_value() {
        return max;
    }

    void push_back(int value) {
        max = header->next == trailer ? value : std::max(max, value);
        new QueueNode(value, trailer->prev, trailer);
    }

    int pop_front() {
        if (header->next == trailer)
            return -1;
        QueueNode *node = header->next;
        header->next = node->next;
        node->next->prev = header;
        // todo update max val
        return node->val;
    }

private:
    class QueueNode {
    public:
        QueueNode *next;
        QueueNode *prev;
        int val;

        QueueNode(int val, QueueNode *prev = nullptr, QueueNode *next = nullptr) : val(val), prev(prev), next(next) {}
    };

    int max = -1;
    QueueNode *header;
    QueueNode *trailer;
};

#endif //ALGORITHM_MAXQUEUE_H
