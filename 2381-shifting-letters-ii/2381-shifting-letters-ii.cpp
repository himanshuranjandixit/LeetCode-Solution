class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v(s.size()+1,0);
        for (int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                v[shifts[i][0]]-=1;
                if(shifts[i][1]<s.size()) v[shifts[i][1]+1]+=1;
            }
            else {
                v[shifts[i][0]]+=1;
                if(shifts[i][1]<s.size()) v[shifts[i][1]+1]-=1;

            }
        }
        for(int i=1;i<s.size();i++){
            v[i]+=v[i-1];
        }
        for(int i=0;i<s.size();i++){
            int shiftAmount = (v[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shiftAmount) % 26; 
        }
        return s;
        
    }
};