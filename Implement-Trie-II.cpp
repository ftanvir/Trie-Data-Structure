class TrieNode {
public:
    TrieNode* children[26];
    int cntEndWith=0;
    int cntPrefix = 0;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        cntEndWith = 0;
        cntPrefix = 0;
    }

    bool containsKey(char ch) {
        return (children[ch-'a']!=nullptr);
    }

    void put(char ch, TrieNode* node) {
        children[ch-'a'] = node;
    }

    TrieNode* get(char ch) {
        return children[ch-'a'];
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
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
        // TODO: Implement the insert function
        TrieNode* node = root;
        for(int i=0; i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();

    }
    
    int countWordsWithPrefix(string prefix) {
        // TODO: Implement the countWordsWithPrefix function
        TrieNode* node = root;

        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->cntPrefix;

    }
    
    int countWordsEqualTo(string word) {
        // TODO: Implement the countWordsEqualTo function
        TrieNode* node = root;

        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->cntEndWith;
    }
    
    void erase(string word) {
        // TODO: Implement the erase function
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->cntPrefix--;
            } else {
                return;
            }
        }
        node->cntEndWith--;
    }
};