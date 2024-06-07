#include <iostream>
#include <string>

using namespace std;

class TrieNode {
    
    public:
        TrieNode* arr[26];
        bool flag;

        TrieNode() {
            flag = false;
            for(int i=0; i<26; i++) {
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

        void insert(const string &word) {

            TrieNode* node = root;
            for(auto ch: word) {
                int idx = ch - 'a';

                if(node->arr[idx]==nullptr) {
                    node->arr[idx] = new TrieNode();
                }
                node = node->arr[idx];
            }


            node -> flag = true;

        }

        bool search(const string &word) {

            TrieNode* node = root;

            for(auto ch:word) {
                if(node->arr[ch-'a']==nullptr) {
                    return false;
                }

                node = node->arr[ch-'a'];
            }

            return (node!=nullptr and node->flag == true);

        }

        bool startsWith(const string &prefix) {
            TrieNode* node = root;

            for(auto ch:prefix) {
                if(node->arr[ch-'a']==nullptr) {
                    return false;
                }

                node = node->arr[ch-'a'];
            }

            return true;
        }


};