class Solution {
public:
    bool helper(const std::string& gene1, const std::string& gene2) {
        int mutationCount = 0;
        for (size_t i = 0; i < gene1.size(); ++i) {
            if (gene1[i] != gene2[i]) {
                ++mutationCount;
                if (mutationCount > 1) {
                    return false;  // More than one mutation, not one mutation away
                }
            }
        }
        return mutationCount == 1;  // Exactly one mutation
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    if (beginWord == endWord) {
        return 0; // Words are the same, no transformation needed
    }


    
        int minCount = -1;  

        if (std::find(wordList.begin(), wordList.end(), endWord) != wordList.end()) {

            // Initialize a set to keep track of visited genes
            set<string> visited;

            // Use a queue for BFS
            queue<pair<string, int>> q;
            q.push({beginWord, 0});  // Start with the initial gene and mutation count

            while (!q.empty()) {
                auto current = q.front();
                q.pop();

                string currentGene = current.first;
                int currentMutationCount = current.second;

                // Check if the current gene is the target gene
                if (currentGene == endWord) {
                    // Update minCount if it's not set or if the current count is smaller
                    if (minCount == -1 || currentMutationCount < minCount) {
                        minCount = currentMutationCount;
                    }
                    return minCount +1;  // No need to explore further, we found a valid mutation sequence
                }

                // Check each gene in the wordList
                for (const auto& candidateGene : wordList) {
                    // Check if the candidate gene is one mutation away from the current gene
                    if (helper(currentGene, candidateGene) && visited.find(candidateGene) == visited.end()) {
                        // Mark the candidate gene as visited
                        visited.insert(candidateGene);
                        // Add the candidate gene to the queue with an incremented mutation count
                        q.push({candidateGene, currentMutationCount + 1});
                    }
                }
            }
        }

        return 0;
    }
};