class Solution {
public:
    int strStr(string haystack, string needle) {
        int it=haystack.find(needle);
        if(it!=string::npos) return it;
        return -1;
        
    }
}; 