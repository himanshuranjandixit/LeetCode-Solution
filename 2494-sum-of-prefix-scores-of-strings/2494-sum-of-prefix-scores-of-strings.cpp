struct Node{
    public:
    int count =0;
    Node* links[26];
    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* node = root;
        for(int i=0;i<s.size();i++){
            if(!node->contains(s[i])){
                node->put(s[i],new Node());
            }
            node = node->get(s[i]);
            node->count++;
        }  
    }
    int score(string& s){
        Node* node  =root;
        int ans =0;
        for(int i=0;i<s.size();i++){
            if(!node->contains(s[i])) return ans;
            node = node->get(s[i]);
            ans+=node->count;
        }
        return ans;
    }

};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(auto it : words){
            trie->insert(it);
        }
        vector<int>ans;
        for(auto it : words){
            int val = trie->score(it);
            ans.push_back(val);
        }
        return ans;

        
    }
};