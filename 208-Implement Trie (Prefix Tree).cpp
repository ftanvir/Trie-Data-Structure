class TrieNode {
    public:
    TrieNode* arr[26];
    bool flag;

    TrieNode() {
        flag = false;
        for(int i=0;i<26; i++) {
            arr[i] = nullptr;
        }
    }
};

class Trie {
private:
TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto ch: word) {
            int idx = ch-'a';
            if(node->arr[idx]==nullptr) {
                node->arr[idx] = new TrieNode();
            }
            node = node->arr[idx];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        TrieNode* node  = root;
        for(auto ch:word) {
            int idx = ch-'a';
            if(node->arr[idx]==nullptr) {
                return false;
            }
            node = node->arr[idx];
        }

        return (node!=nullptr and node->flag==true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* node  = root;
        for(auto ch:prefix) {
            int idx = ch-'a';
            if(node->arr[idx]==nullptr) {
                return false;
            }
            node = node->arr[idx];
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