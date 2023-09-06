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
     * Solution 1: Breadth-First Search
     * @brief In this problem, breadth-first search should be used, but there is no
     *        graph or tree structure. Therefore, the step should be as follows:
     * 1. create graph;
     * 2. breadth-first search
     */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1. construct hash set
        unordered_set<string> wordSet;
        for (auto& str: wordList) {
            wordSet.insert(str);
        }
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        // 2. BFS
        int result = 1;
        queue<string> level;
        level.push(beginWord);
        unordered_set<string> visitedSet;
        visitedSet.insert(beginWord);
        queue<string> tmpLevel;
        while (!level.empty()) {
            string word = level.front();
            level.pop();
            if (word == endWord) {
                return result;
            }
            visitedSet.insert(word);
            oneLetterDistance(word, wordSet, tmpLevel, visitedSet);
            
            if (level.empty()) {
                result += 1;
                level = tmpLevel;
                tmpLevel = queue<string>();
            }
        }
        return 0;
    }

    /**
     * Solution 2: Bidirectional BFS
     * 
     */
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (auto& str: wordList) {
            wordSet.insert(str);
        }
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        int result = 1;
        unordered_set<string> beginLevel;
        beginLevel.insert(beginWord);
        unordered_set<string> endLevel;
        endLevel.insert(endWord);
        unordered_set<string> visitedSet;
        unordered_set<string> tmpLevel, swapLevel;
        while (!beginLevel.empty() && !endLevel.empty()) {
            if (beginLevel.size() > endLevel.size()) {
                swapLevel = beginLevel;
                beginLevel = endLevel;
                endLevel = swapLevel;
            }
            for (auto word: beginLevel) {
                visitedSet.insert(word);
                if (oneLetterDistance(word, wordSet, tmpLevel, visitedSet, endLevel)) {
                    return result + 1;
                }
            }
            beginLevel = tmpLevel;
            tmpLevel.clear();
            result += 1;
        }
        return 0;
    }
private:
    bool oneLetterDistance(string word, unordered_set<string>&wordSet, 
                           unordered_set<string>& nextLevel, unordered_set<string>& visited,
                           unordered_set<string>& endLevel) {
        int wordLen = word.length();
        string tmpWord = word;
        for (int i = 0; i < wordLen; i++) {
            char oriCh = word[i];
            for (int c = 'a'; c <= 'z'; c++) {
                if (c == oriCh) {
                    continue;
                }
                tmpWord[i] = c;
                if (endLevel.find(tmpWord) != endLevel.end()) {
                    return true;
                }
                if (wordSet.find(tmpWord) != wordSet.end() && visited.find(tmpWord) == visited.end()) {
                    nextLevel.insert(tmpWord);
                }
            }
            tmpWord[i] = oriCh;
        }
        return false;
    }

    void oneLetterDistance(string word, unordered_set<string>& wordSet, 
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
                if (wordSet.find(tmpWord) != wordSet.end() && visited.find(tmpWord) == visited.end()) {
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
    cout << "Min ladder length: " << obj.ladderLength2(beginWord, endWord, wordList) << endl;

    // case 2
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << "Min ladder length: " << obj.ladderLength(beginWord, endWord, wordList) << endl;
    cout << "Min ladder length: " << obj.ladderLength2(beginWord, endWord, wordList) << endl;

    return 0;
}