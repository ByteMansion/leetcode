/**
 * @file leetcode126.cpp
 * @brief Leetcode 126 Word Ladder II
 * 
 */
#include "utils.hpp"
#include <stack>
#include <unordered_set>

class Solution {
public:
    /**
     * Solution 1: Recursive method
     * @result Exceed time limit
     */
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> results = vector<vector<string>>(0, vector<string>());
        unordered_set<string> wordSet;
        for (auto& str: wordList) {
            wordSet.insert(str);
        }
        // there is no endWord
        if (wordSet.find(endWord) == wordSet.end()) {
            return results;
        }
        
        unordered_set<string> visitedSet;
        vector<string> result;
        result.push_back(beginWord);
        findPath(beginWord, endWord, wordSet, visitedSet, result, results);
        return results;
    }
private:
    void findPath(string word, string endWord, unordered_set<string> wordSet, unordered_set<string>& visitedSet, vector<string>& result, vector<vector<string>>& results) {
        if (word == endWord) {
            if (result.size() < minLen) {
                results.clear();
                minLen = result.size();
                results.push_back(result);
            } else if (result.size() == minLen) {
                results.push_back(result);
            }
            return;
        }
        if (result.size() > minLen) {
            return;
        }
        if (visitedSet.size() == wordSet.size()) {
            return;
        }

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            for (int j = 'a'; j <= 'z'; j++) {
                if (j == ch) {
                    continue;
                }
                word[i] = j;
                if (wordSet.find(word) == wordSet.end()) {
                    continue;
                }
                if (visitedSet.find(word) == visitedSet.end()) {
                    result.push_back(word);
                    visitedSet.insert(word);
                    findPath(word, endWord, wordSet, visitedSet, result, results);
                    result.pop_back();
                    visitedSet.erase(word);
                }
            }
            word[i] = ch;
        }
    }
    int minLen = INT32_MAX;
};

int main() {
    Solution obj;
    vector<string> wordList;
    string beginWord, endWord;

    // case 1
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    print_2d_array(obj.findLadders(beginWord, endWord, wordList));

    // case 2
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log"};
    print_2d_array(obj.findLadders(beginWord, endWord, wordList));

    // case 3
    beginWord = "qa";
    endWord = "sq";
    wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    print_2d_array(obj.findLadders(beginWord, endWord, wordList));

    return 0;
}