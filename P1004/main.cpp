#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int answer = 0;
string ballon = "";

struct Trie {
    Trie() {
        this->count = 0;
        this->value = "";
        for (int i = 0; i < 26; ++i) this->child[i] = NULL;
    }

    int count;
    string value;
    Trie *child[26];
};

int getIndex(char c) {
    return c - 97;
}

void insert(Trie *root, int step, const string &word) {

    // 找到插入位置
    if (step == word.size()) {
        root->count++;
        root->value = word;
        return;
    }
    if (!root->child[getIndex(word[step])]) {
        root->child[getIndex(word[step])] = new Trie();

    }
    insert(root->child[getIndex(word[step])], step + 1, word);
}

void findMax(Trie *root) {
    if (root->count > answer) {
        answer = root->count;
        ballon = root->value;
    }
    root->count = 0;
    for (int i = 0; i < 26; ++i) {
        if (root->child[i]) {
            findMax(root->child[i]);
        }
    }
}

bool find(Trie *root, int step, const string &word) {

    if (step == word.size() && root->count > 0) {
        return true;
    }
    if (root->child[word[step] - 97]) {
        return find(root->child[word[step] - 97], step + 1, word);
    } else {
        return false;
    }
}

int main() {
    ifstream fin("a.in");
    ofstream fout("a.out");
    int n;
    Trie root = {};
    string word;

    fin >> n;
    while (n) {
        answer = 0;
        ballon = "";
        for (int i = 0; i < n; ++i) {
            fin >> word;
            insert(&root, 0, word);
        }
        fout << find(&root, 0, "orange") << endl;
        findMax(&root);

        fout << ballon << endl;
        fin >> n;
    }
    return 0;
}