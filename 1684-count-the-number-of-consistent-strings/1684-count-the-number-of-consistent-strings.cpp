class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count =0;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            int chk=0;
            for(auto it : word){
                int check=1;
                for(int j=0;j<allowed.size();j++){
                    if(allowed[j]==it) check=0;
                }
                if(check==1) chk=1;
            }
            if(chk==0) count++;
            chk=1;

            
        }
        return count;
        
    }
};