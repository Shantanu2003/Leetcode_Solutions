class Solution {
public:
struct ComparePairs {
    bool operator()(const pair<char, int>& p1, const pair<char, int>& p2) {
        if(p1.first == p2.first)
        return p1.first> p2.first;

        return p1.second < p2.second; 
    }
};
    string frequencySort(string s) {
        unordered_map<char,int>frequency;
        string res= "";
        for(char c :s){
            frequency[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, ComparePairs> pq;
        for(auto i: frequency){
            pq.push(make_pair(i.first,i.second));
        }
        while(!pq.empty()){
            auto pairs = pq.top();
            res.append(pairs.second, pairs.first);
            pq.pop();
        }
        return res;
    }
};