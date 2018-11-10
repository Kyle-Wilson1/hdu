#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int answer = 0;
string ballon = "";

struct Tire {
    Tire() {
        this->count = 0;
        this->value = "";
        for (int i = 0; i < 26; ++i) this->child[i] = NULL;
    }

    int count;
    string value;
    Tire *child[26];
};

int getIndex(char c) {
    return c - 97;
}

void insert(Tire *root, int step, const string &word) {

    // 找到插入位置
    if (step == word.size()) {
        root->count++;
        root->value = word;
        return;
    }
    if (!root->child[getIndex(word[step])]) {
        root->child[getIndex(word[step])] = new Tire();

    }
    insert(root->child[getIndex(word[step])], step + 1, word);
}

void process(Tire *root) {
    if (root->count > answer) {
        answer = root->count;
        ballon = root->value;
    }
    root->count = 0;
    for (int i = 0; i < 26; ++i) {
        if (root->child[i]) {
            process(root->child[i]);
        }
    }
}

int main() {
    ifstream fin("a.in");
    ofstream fout("a.out");
    int n;
    Tire root = {};
    string word;

    fin >> n;
    while (n) {
        answer = 0;
        ballon = "";
        for (int i = 0; i < n; ++i) {
            fin >> word;
            insert(&root, 0, word);
        }
        process(&root);
        fout << ballon << endl;
        fin >> n;
    }
    return 0;
}