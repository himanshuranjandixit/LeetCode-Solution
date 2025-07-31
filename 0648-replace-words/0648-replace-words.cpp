class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>s;
        for(auto i : dictionary){
            s.insert(i);
        }
        string ans ="";
        sentence.push_back(' ');
        string temp="";
        for(int i = 0 ; i<sentence.size(); i++){
            if(sentence[i]==' '){
                ans+=temp;
                ans+=(char)(' ') ;
                temp="";
            }
            else{
                temp+=(char)(sentence[i]);
                if(s.count(temp)){
                    ans+=temp;
                    temp="";
                    ans+=(char)(' ');
                    while(sentence[i] != ' '){
                        // ans+=(char)(' ');
                        i++ ;

                    }
                }
            }
        }
        ans.pop_back();
        return ans;

        
    }
};