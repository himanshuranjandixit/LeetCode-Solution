struct Node {
    // unordered_map<char,Node*>links;
    Node* links[26] ={NULL};
    int size=0;
    int minindx=-1;
    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setminindx(int len, int indx){
        if(minindx== -1 || len<size ){
            size = len;
            minindx=indx;
        }
    }
};
class Trie {
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word, int len,int indx){
        Node* node = root;
        node->setminindx(len,indx);
        for(int i=word.size()-1;i>=0;i--){
            if(!node->contains(word[i])){
                node->put(word[i], new Node());
            }
            node= node->get(word[i]);
            node->setminindx(len,indx);
        }
    }
    int query(string word){
        Node* node = root;
        int ans = node->minindx;
        for(int i=word.size()-1;i>=0;i--){
            if(!node->contains(word[i])){
                return ans;
            }
            node = node->get(word[i]);
            ans = node->minindx;
        }
        return ans;
    }
    private:
    void deleteNode(Node* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                deleteNode(node->links[i]);
            }
        }
        delete node;
    }

public:
    ~Trie() {
        deleteNode(root);
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        for(int i=0;i<wordsContainer.size();i++){
            trie.insert(wordsContainer[i],(int)wordsContainer[i].size(),i);
        }
        vector<int>ans;
        for(auto it :wordsQuery){
            ans.push_back(trie.query(it));
        }
        return ans;
        
    }
};