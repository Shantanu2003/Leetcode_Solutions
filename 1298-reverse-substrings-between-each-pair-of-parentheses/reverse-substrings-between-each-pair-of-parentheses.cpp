// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<string>s;
//         string res = "";
//         string res1 = "";

//         for(char c: s){
//           if(c == '('){
//             s.push(res);
//             res = "";
//          }
//           else if(c == ')'){
//             reverse(res1.begin(),res1.end());
//             string top2 = s.pop();
//             res1 = top2+top1;
//             res = "";
//           }

//           else{
//             res += c;
//             res1 += c;
//           }

//         }
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openParenthesesIndices;
        vector<int> pair(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openParenthesesIndices.push(i);
            }
            if (s[i] == ')') {
                int j = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        for (int currIndex = 0, direction = 1; currIndex < n;
             currIndex += direction) {
            if (s[currIndex] == '(' || s[currIndex] == ')') {
                currIndex = pair[currIndex];
                direction = -direction;
            } else {
                result += s[currIndex];
            }
        }
        return result;
    }
};
