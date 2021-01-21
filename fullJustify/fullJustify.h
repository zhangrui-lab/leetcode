//
// Created by 张锐 on 2021/1/20.
//

#ifndef ALGORITHM_FULLJUSTIFY_H
#define ALGORITHM_FULLJUSTIFY_H

/*
 * 68. 文本左右对齐
 *  给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。你应该使用“贪心算法”来放置
 *  给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。要求尽可能均匀分配单词间的空格
 *  数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 说明:
 *  单词是指由非空格字符组成的字符序列。
 *  每个单词的长度大于 0，小于等于 maxWidth。
 *  输入单词数组 words 至少包含一个单词。
 */

#include <vector>
#include <string>

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth) {
    std::vector<std::string> ans;
    if (words.empty())
        return ans;
    // 合并 [start, end) 的字符为长为 maxWidth 的左右对齐的字符串
    auto align = [&](int start, int end, int len) {
        std::string tmp;
        int wordCount = end - start, extraSpace = maxWidth - len;
        if (wordCount == 1)
            return words[start] + std::string(maxWidth - words[start].size(), ' ');
        int aveSpace = extraSpace / (wordCount - 1), modeSpace = extraSpace % (wordCount - 1);
        for (int i = start; i < end; ++i) {
            int sn;
            if (end == words.size()) {  // 最后一行应为左对齐，而不是左右两端对齐
                sn = i == end - 1 ? extraSpace - (wordCount - 1) : 1;
            } else {
                sn = i == end - 1 ? 0 : aveSpace + (modeSpace > 0 ? 1 : 0);
            }
            tmp += words[i] + std::string(sn, ' ');
            if (modeSpace > 0) modeSpace--;
        }
        return tmp;
    };
    int start = 0, len = words[0].size();
    for (int i = 1; i < words.size(); ++i) {
        if (words[i].size() > maxWidth)
            return std::vector<std::string>();
        if (len + words[i].size() < maxWidth) {
            len += words[i].size() + 1;
        } else {
            ans.push_back(align(start, i, len - (i - start - 1)));
            len = words[i].size();
            start = i;
        }
    }
    ans.push_back(align(start, words.size(), len - (words.size() - start - 1)));
    return ans;
}

#endif //ALGORITHM_FULLJUSTIFY_H
