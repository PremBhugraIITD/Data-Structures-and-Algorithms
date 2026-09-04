#include <iostream>
#include <vector>
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
        int index = word[0] - 'a';
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
    void insert(string word)
    {
        insertNode(root, word);
    }
    bool searchNode(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
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
    bool search(string word)
    {
        return searchNode(root, word);
    }
    bool startswithNode(TrieNode *root, string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }
        int index = prefix[0] - 'a';
        TrieNode *child;
        if (root->children[index])
        { // Child is present
            child = root->children[index];
        }
        else
        { // Child is absent
            return false;
        }
        return startswithNode(child, prefix.substr(1));
    }
    bool startsWith(string prefix)
    {
        return startswithNode(root, prefix);
    }
    void printSuggestions(TrieNode *curr, vector<string> &temp, string pre)
    {
        if (curr->isTerminal)
        {
            temp.push_back(pre);
        }
        for (char ch = 'a'; ch < 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                pre.push_back(ch);
                printSuggestions(next, temp, pre);
                pre.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string s)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (auto i : s)
        {
            char lastCharacter = i;
            prefix.push_back(lastCharacter); //'prefix' string gets slowly filled with all the characters in the query string.
            TrieNode *curr = prev->children[lastCharacter - 'a'];
            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefix); // Adds all the words into the 'temp' vector which present inside the trie and start with the word 'prefix'.
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();
    for (auto i : contactList)
    { // Adding every contact to the trie
        t->insert(i);
    }
    return t->getSuggestions(queryStr);
}
int main()
{
    cout << "Enter the number of contacts you want to add:" << endl;
    int n;
    cin >> n;
    vector<string> contacts;
    cout << "Enter the contacts:" << endl;
    while (n--)
    {
        string str;
        cin >> str;
        contacts.push_back(str);
    }
    cout << "Enter the query string:" << endl;
    string q;
    cin >> q;
    vector<vector<string>> results = phoneDirectory(contacts, q);
    string t;
    for (int i = 0; i < results.size(); i++)
    {
        t += q[i];
        cout << t << ": ";
        for (int j = 0; j < results[i].size(); j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}
// TC = O(n*(m^2)), n = No. of contacts, m = Average length of a word
// SC = O(m*n)