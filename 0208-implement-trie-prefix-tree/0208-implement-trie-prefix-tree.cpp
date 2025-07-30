struct Node {
    Node *link[26];
    bool flag = false;
    bool contains(char ch){
        return (link[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        link[ch-'a'] =node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }

};
class Trie {
    Node * root;
public:
    Trie() {
        root=new Node();
        
    }
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(!node->contains(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->flag = true;
        
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(!node->contains(ch)) return false;
            node = node->get(ch);
        }
        return node->flag;
        
    }
    
    bool startsWith(string word) {
         Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])) return false;
            node = node->get(word[i]);
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */