/**
 * @file leetcode127.cpp
 * @brief Leetcode 127 Word Ladder
 * 
 */
#include "utils.hpp"
#include <unordered_set>
#include <queue>

class Solution {
public:
    /**
     * Solution: Breadth-first traversal
     * @brief In this problem, breadth-first traversal should be used, but there is no
     *        graph or tree structure. Therefore, the step should be as follows:
     * 1. create graph;
     * 2. breadth-first traversal
     */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1. construct hash set
        unordered_set<string> hashSet;
        for (auto& str: wordList) {
            hashSet.insert(str);
        }
        if (hashSet.find(endWord) == hashSet.end()) {
            return 0;
        }
        // 2. BFS
        int result = 1;
        queue<string> level;
        unordered_set<string> visited;
        level.push(beginWord);
        visited.insert(beginWord);
        queue<string> tmpLevel;
        while (!level.empty()) {
            string word = level.front();
            level.pop();
            if (word == endWord) {
                return result;
            }
            visited.insert(word);
            oneLetterDistance(word, hashSet, tmpLevel, visited);
            
            if (level.empty()) {
                result += 1;
                level = tmpLevel;
                tmpLevel = queue<string>();
            }
        }
        return 0;
    }
private:
    void oneLetterDistance(string word, unordered_set<string>& hashSet, 
                           queue<string>& level, unordered_set<string>& visited)
    {
        int wordLen = word.length();
        string tmpWord = word;
        for (int i = 0; i < wordLen; i++) {
            char oriCh = word[i];
            for (int c = 'a'; c <= 'z'; c++) {
                if (c == oriCh) {
                    continue;  // avoid same string
                }
                tmpWord[i] = c;
                if (hashSet.find(tmpWord) != hashSet.end() && visited.find(tmpWord) == visited.end()) {
                    level.push(tmpWord);
                }
            }
            tmpWord[i] = oriCh;
        }
    }
};

int main() {
    Solution obj;
    vector<string> wordList;
    string beginWord, endWord;

    // case 1
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << "Min ladder length: " << obj.ladderLength(beginWord, endWord, wordList) << endl;

    // case 2
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << "Min ladder length: " << obj.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}