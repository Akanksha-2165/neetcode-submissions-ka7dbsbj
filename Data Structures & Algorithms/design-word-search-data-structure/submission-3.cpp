class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* node = root;

        for(char ch : word) {

            int idx = ch - 'a';

            if(node->children[idx] == NULL)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool dfs(string word, int i, TrieNode* node) {

        if(i == word.size())
            return node->isEnd;

        char ch = word[i];

        if(ch == '.') {

            for(int k=0;k<26;k++) {

                if(node->children[k] &&
                   dfs(word, i+1, node->children[k]))
                    return true;
            }

            return false;
        }

        int idx = ch - 'a';

        if(node->children[idx] == NULL)
            return false;

        return dfs(word, i+1, node->children[idx]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};