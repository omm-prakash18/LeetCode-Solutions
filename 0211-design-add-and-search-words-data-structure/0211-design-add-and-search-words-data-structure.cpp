class TrieNode {

public:

    TrieNode* children[26];

    bool isEndOfWord;



    TrieNode() {

        isEndOfWord = false;

        for (int i = 0; i < 26; ++i) {

            children[i] = nullptr;

        }

    }

};


class WordDictionary {
private:
    TrieNode* root;

    
    bool searchHelper(const string& word, int i, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
       
        if (i == word.size()) {
            return node->isEndOfWord;
        }
        
        char c = word[i];
        if (c == '.') {
           
            for (int j = 0; j < 26; j++) {
                if (node->children[j] != nullptr && searchHelper(word, i + 1, node->children[j])) {
                    return true;
                }
            }
            return false;
        } else {
           
            int index = c - 'a';
            return searchHelper(word, i + 1, node->children[index]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a'; 
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index]; 
        }
        curr->isEndOfWord = true; 
    }
    
    bool search(string word) {
        
        return searchHelper(word, 0, root);
    }
};