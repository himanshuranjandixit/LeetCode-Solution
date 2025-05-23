class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;
private:
    void dfs(string word, vector<string>& seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
        int step = mpp[word];
        for(int i=0;i<word.size();i++){
            char org = word[i];
            for(char ch = 'a'; ch<='z' ; ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1 == step){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=org;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // queue<vector<string>>q; //{{startword,step},string}
        // unordered_set<string>st(wordList.begin(),wordList.end());
        // st.erase(beginWord);
        // vector<string>v;
        // v.push_back(beginWord);
        // q.push(v);
        // int lvl=1;
        // int minlvl=INT_MAX;
        // unordered_set<string>temp;
        // vector<vector<string>>ans;
        // while(!q.empty()){
        //     vector<string>vec=q.front();
        //     string word =vec.back();
        //     q.pop();
        //     if(vec.size()>lvl){
        //         for(auto const& wrd :temp){
        //             st.erase(wrd);
        //         }
        //         temp.clear();
        //         lvl=vec.size();
        //         if(lvl>minlvl) break;
        //     }
        //     if(word==endWord && vec.size()<=minlvl){
        //         ans.push_back(vec);
        //         minlvl=vec.size();
        //         continue;
        //     }
        //     for(int i=0;i<word.size();i++){
        //         char org = word[i];
        //         for(char ch ='a'; ch<='z';ch++){
        //             word[i]=ch;
        //             if(st.find(word)!=st.end()){
        //                 vector<string>neww=vec;
        //                 neww.push_back(word);
        //                 q.push(neww);
        //                 temp.insert(word);
        //             }
        //         }
        //         word[i]=org;
        //     }
        // }
        // return ans;

        b =beginWord;
        mpp[beginWord]=1;
        queue<string>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push(beginWord);
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int step =mpp[word];
            if(word==endWord) break;
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char ch = 'a'; ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        mpp[word]=step+1;
                        st.erase(word);
                        q.push(word);
                    }
                }
                word[i]=org;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);


        }
        return ans;


    }
};
