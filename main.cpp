#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        vector<int> result(puzzles.size());
        result.clear();                             // 小优化，提高push_back效率
        unordered_map<int, int> wordCount;
        for (const string &word: words) {
            int value = 0;                          // 二进制状态值
            for (const char chr: word)
                value |= (1 << (chr - 'a'));        // puzzle二进制状态压缩
            if (__builtin_popcount(value) <= 7)     // 如果对应二进制表示中1的数量大于7，没有必要加入哈希表中
                ++wordCount[value];                 // 哈希表计数
        }
        for (const string &puzzle: puzzles) {
            int total = 0, value = 0;
            for (int i = 1; i < 7; ++i)
                value |= (1 << (puzzle[i] - 'a'));  // word跳过首位的二进制状态压缩
            int subset = value, toLeft = puzzle[0] - 'a';
            do {
                int s = subset | (1 << toLeft);     // 添加首位
                if (wordCount.count(s))
                    total += wordCount[s];          // 计数
                subset = (subset - 1) & value;      // 二进制组合遍历
            } while (subset != value);
            result.push_back(total);                // 添加对应计数结果
        }
        return result;
    }
};

int main() {
    Solution solution;
    string word[] = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    string puzzle[] = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    vector<string> words(word, word + 7);
    vector<string> puzzles(puzzle, puzzle + 6);
    for (int res: solution.findNumOfValidWords(words, puzzles))
        cout << res << "\t";
    return 0;
}