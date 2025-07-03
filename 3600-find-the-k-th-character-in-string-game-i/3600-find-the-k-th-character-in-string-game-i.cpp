class Solution {
public:
    void gameStep(string& s){
        int n = s.size();
        for ( int i = 0; i < n; i++) {
            if (s[i] == 'z') {
                s += 'a';
            }
            else{
                char temp = s[i]+1;
                s += temp;
            }

        }
        return;
    }
    char kthCharacter(int k) {
        string s = "a";
        int n = s.size();
        while(n<k) {
            n = n+n;
            gameStep(s);
        }
        char c = s[k-1];
        return c;
        
        
    }
};