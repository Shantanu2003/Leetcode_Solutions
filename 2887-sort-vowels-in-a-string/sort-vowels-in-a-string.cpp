class Solution {
public:
    string sortVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string vowelChars;

    for (char ch : s) {
        if (vowels.count(ch)) {
            vowelChars.push_back(ch);
        }
    }

    sort(vowelChars.begin(), vowelChars.end());

    string result;
    int vowelIndex = 0;

    for (char ch : s) {
        if (vowels.count(ch)) {
            result.push_back(vowelChars[vowelIndex]);
            vowelIndex++;
        } else {
            result.push_back(ch);
        }
    }

    return result;
    }
};