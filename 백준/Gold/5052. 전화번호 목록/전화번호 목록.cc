#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode
{
    TrieNode* children[10];
    bool is_end;

    TrieNode()
    {
        for (int i = 0; i < 10; i++)
            children[i] = nullptr;
        is_end = false;
    }
};

bool insert(TrieNode* root, const string& number)
{
    TrieNode* cur = root;
    for (char ch : number)
    {
        int idx = ch - '0';
        if (cur->children[idx] == nullptr)
            cur->children[idx] = new TrieNode();

        cur = cur->children[idx];
        if (cur->is_end)
            return false;
    }

    for (int i = 0; i < 10; i++)
    {
        if (cur->children[i] != nullptr)
            return false;
    }

    cur->is_end = true;
    return true;
}

void freeTrie(TrieNode* root)
{
    for (int i = 0; i < 10; i++)
    {
        if (root->children[i] != nullptr)
            freeTrie(root->children[i]);
    }
    delete root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    while (T--)
    {
        int N; cin >> N;
        TrieNode* root = new TrieNode();
        bool is_consistent = true;

        vector<string> numbers(N);
        for (int i = 0; i < N; i++)
            cin >> numbers[i];

        for (int i = 0; i < N && is_consistent; i++)
        {
            if (!insert(root, numbers[i]))
                is_consistent = false;
        }

        cout << (is_consistent ? "YES\n" : "NO\n");

        freeTrie(root);
    }

    return 0;
}
