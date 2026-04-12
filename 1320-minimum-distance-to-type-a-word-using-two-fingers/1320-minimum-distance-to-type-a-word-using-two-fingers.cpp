class Solution {
public:
    unordered_map<char, vector<int>> mpp;
    unordered_map<string, int> t;
    int solve(string& word, int indx, const pair<int, int>& fing1,
              const pair<int, int>& fing2, bool isfing2) {
        if (indx == word.size())
            return 0;
        string temp = to_string(indx) + '|' + to_string(fing1.first) + '|' +
                      to_string(fing1.second) + '|' + to_string(fing2.first) +
                      '|' + to_string(fing2.second) + to_string(isfing2);
        if (t.find(temp) != t.end())
            return t[temp];
        int dist1 = INT_MAX;
        int dist2 = INT_MAX;
        char ch = word[indx];
        int r = mpp[ch][0];
        int c = mpp[ch][1];
        if (isfing2) {
            dist1 = abs(fing1.first - r) + abs(fing1.second - c);
            dist2 = abs(fing2.first - r) + abs(fing2.second - c);
            return t[temp] = min(dist1 + solve(word, indx + 1, make_pair(r, c),
                                               fing2, isfing2),
                                 dist2 + solve(word, indx + 1, fing1,
                                               make_pair(r, c), isfing2));
        } else {
            dist1 = abs(fing1.first - r) + abs(fing1.second - c);
            return t[temp] =
                       min(dist1 + solve(word, indx + 1, make_pair(r, c), fing2,
                                         isfing2),
                           solve(word, indx + 1, fing1, make_pair(r, c), true));
        }
    }
    int minimumDistance(string word) {
        char ch = 'A';
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                mpp[ch] = {i, j};
                ch++;
            }
        }
        pair<int, int> fing1 = {mpp[word[0]][0], mpp[word[0]][1]};
        pair<int, int> fing2 = {-1, -1};
        bool isfing2 = false;
        return solve(word, 1, fing1, fing2, isfing2);
    }
};