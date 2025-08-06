#include<iostream>
using namespace std;


class TrieNode{
    public:
        int data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(int data){
            this -> data = data;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                // poora word traverse kar liya toh last node ko terminal node mark kar do
                root -> isTerminal = true;
                return;
            }
            // assuming words will be in capital letters
            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root -> children[index] != NULL){
                child = root ->children[index];
            }
            else{
                // absent case
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            // recursion

            insertUtil(child, word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                return root -> isTerminal;
            }
            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root ->children[index] != NULL){
                child = root -> children[index];
            }
            else{
                // absent
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root, word);
        }
};

int main(){
    Trie *t = new Trie();

    t->insertWord("abcd");
    cout << "Present or not" << t->searchWord("abcd") << endl;

    return 0;
}