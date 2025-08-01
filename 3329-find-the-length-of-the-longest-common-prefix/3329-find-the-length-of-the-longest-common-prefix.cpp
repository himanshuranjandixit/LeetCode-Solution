struct Node {
    public:
    Node* link[10];
    bool flag =false;
    bool contains(int num){
        return (link[num]!=NULL);
    }
    void put(int num, Node* node){
        link[num] =node;
    }
    Node*  get(int num){
        return link[num];
    }
};
class Trie {
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        string s = to_string(num);
        for(int i=0;i<s.size();i++){
            if(!node->contains(s[i]-'0')){
                node->put(s[i]-'0',new Node());
            }
            node = node->get(s[i]-'0');
        }
    }
    int query(int num){
        int cnt =0;
        Node* node =root;
        string s = to_string(num);
        for(int i=0;i<s.size();i++){
            if(!node->contains(s[i]-'0')){
                break;
            }
            else{
                node = node->get(s[i]-'0');
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(auto it : arr1){
            trie.insert(it);
        }
        int ans=0;
        for(auto it:arr2){
            ans=max(ans,trie.query(it));
        }
        return ans;
        
    }
};