class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;
        int len=part.size();
        while(i<s.size()){
            if(s.substr(i,len)==part){
                s.erase(i,len);
                i=0;
                continue;
            }
            i++;

        }
        return s;
        
    }
};