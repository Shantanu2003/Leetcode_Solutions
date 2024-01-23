class Solution {
public:
 int maxLengthHelper(const vector<string>& arr, int index, const string& current, unordered_set<char>& charSet) {
    int max_length = current.size();

    for (int i = index; i < arr.size(); ++i) {
        unordered_set<char> tempSet(charSet);

        bool isUnique = true;
        for (char c : arr[i]) {
            if (tempSet.find(c) == tempSet.end()) {
                tempSet.insert(c);
            } else {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            max_length = max(max_length, maxLengthHelper(arr, i + 1, current + arr[i], tempSet));
        }
    }

    return max_length;
}

int maxLength(const vector<string>& arr) {
    unordered_set<char> charSet;
    return maxLengthHelper(arr, 0, "", charSet);
}
};