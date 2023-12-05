class Solution {
public:
    bool isOneMutationAway(const std::string& gene1, const std::string& gene2) {
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
        int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        if (bank.size() == 1) {
            if (endGene == bank[0])
                return 1;
        }

        int minMutationCount = -1;  // Initialize with an invalid value

        if (std::find(bank.begin(), bank.end(), endGene) != bank.end()) {
            // Initialize a set to keep track of visited genes
            set<string> visited;

            // Use a queue for BFS
            queue<pair<string, int>> q;
            q.push({startGene, 0});  // Start with the initial gene and mutation count

            while (!q.empty()) {
                auto current = q.front();
                q.pop();

                string currentGene = current.first;
                int currentMutationCount = current.second;

                // Check if the current gene is the target gene
                if (currentGene == endGene) {
                    // Update minMutationCount if it's not set or if the current count is smaller
                    if (minMutationCount == -1 || currentMutationCount < minMutationCount) {
                        minMutationCount = currentMutationCount;
                    }
                    continue;  // No need to explore further, we found a valid mutation sequence
                }

                // Check each gene in the bank
                for (const auto& candidateGene : bank) {
                    // Check if the candidate gene is one mutation away from the current gene
                    if (isOneMutationAway(currentGene, candidateGene) && visited.find(candidateGene) == visited.end()) {
                        // Mark the candidate gene as visited
                        visited.insert(candidateGene);
                        // Add the candidate gene to the queue with an incremented mutation count
                        q.push({candidateGene, currentMutationCount + 1});
                    }
                }
            }
        }

        return minMutationCount;
    }
};