#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertNode(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index])
        { // Child is already present
            child = root->children[index];
        }
        else
        { // Child is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertNode(child, word.substr(1));
    }
    // TC = O(l), l = length of word
    void insertWord(string word)
    {
        insertNode(root, word);
    }
    bool searchNode(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index])
        { // Child is present
            child = root->children[index];
        }
        else
        { // Child is absent
            return false;
        }
        return searchNode(child, word.substr(1));
    }
    // TC = O(l)
    bool searchWord(string word)
    {
        return searchNode(root, word);
    }
    void deleteNode(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index])
        { // Child is present
            child = root->children[index];
        }
        else
        { // Child is absent
            cout << "Word not present" << endl;
            return;
        }
        deleteNode(child, word.substr(1));
    }
    // TC = O(l)
    void deleteWord(string word)
    {
        deleteNode(root, word);
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertWord("PREM");
    t->insertWord("GAURAV");
    cout << t->searchWord("SIMRAN") << " " << t->searchWord("PREM") << " " << t->searchWord("GAURAV") << endl;
    t->deleteWord("GAURAV");
    t->deleteWord("GAURAV");
    t->deleteWord("SHAURYA");
    cout << t->searchWord("SIMRAN") << " " << t->searchWord("PREM") << " " << t->searchWord("GAURAV") << endl;
    t->insertWord("GAURAV");
    cout << t->searchWord("GAURAV") << endl;
}