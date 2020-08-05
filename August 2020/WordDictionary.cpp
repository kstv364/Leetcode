/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class WordDictionary {

    bool end;
    WordDictionary *children[26];
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        end = false;
        for (int i = 0; i < 26; i++)    this->children[i] = nullptr;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *root = this;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!root->children[index])
                root->children[index] = new WordDictionary();
            root = root->children[index];
        }
        root->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

    bool searchUtil(WordDictionary * root, string &s, int l) {
        if (!root) return false;
        int index = s[l] - 'a';
        // if this is the last index
        if (l == s.size() - 1) {
            // if this is not wild carad
            if (s[l] != '.')   return root->children[index] and root->children[index]->end;

            //else if this is wild card
            for (int i = 0; i < 26; i++)
                if (root->children[i] and root->children[i]->end) return true;
            return false;
        }

        // if current character is wild card
        if (s[l] == '.') {
            for (int i = 0; i < 26; i++)
                if (root->children[i] and searchUtil(root->children[i], s, l + 1))   return true;
            return false;
        }

        if (root->children[index])   return searchUtil(root->children[index], s, l + 1);
        return false;
    }

    bool search(string word) {
        WordDictionary *root = this;
        return searchUtil(root, word, 0);
    }
};

