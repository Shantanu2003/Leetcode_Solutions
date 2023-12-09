#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    bool helper(const std::string& gene1, const std::string& gene2) {
        int mutationCount = 0;
        for (size_t i = 0; i < gene1.size(); ++i) {
            if (gene1[i] != gene2[i]) {
                ++mutationCount;
                if (mutationCount > 1) {
                    return false;  
                }
            }
        }
        return mutationCount == 1;  
    }

    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        if (beginWord == endWord) {
            return 0; // Words are the same, no transformation needed
        }

        int minCount = 0;
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

        // Use a queue for BFS
        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});  
        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            std::string currentGene = current.first;
            int currentMutationCount = current.second;

            if (currentGene == endWord) {
                return currentMutationCount;  
            }

            // Use a temporary set to avoid modifying the set during iteration
            std::unordered_set<std::string> tempSet;
            for (const auto& word : wordSet) {
                if (helper(currentGene, word)) {
                    tempSet.insert(word);
                }
            }

            // Remove words from wordSet after iteration
            for (const auto& word : tempSet) {
                wordSet.erase(word);
                q.push({word, currentMutationCount + 1});
            }
        }

        return 0;  // If no transformation sequence is found
    }
};
