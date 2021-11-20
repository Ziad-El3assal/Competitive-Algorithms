#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define pb push_back
#define sbe(x) sort(x.rbegin(), x.rend())
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int OO = 0x3f3f3f3f, MOD = 1e9 + 7;
const long double EPS = 1e-8;
const ll loo = 0x3f3f3f3f3f3f3f3f;
class Trie
{
private:
    struct node
    {
        bool leaf;
        node *child[10];
    };
    node *root;

public:
    Trie()
    {
        root = create();
    }
    node *create()
    {
        node *nd = new node();
        for (int i = 0; i < 10; i++)
            nd->child[i] = NULL;
        nd->leaf = 1;
        return nd;
    }
    void add(string str)
    {
        node *nd = root;
        for (int i = 0; i < str.size(); i++)
        {
            if (nd->child[str[i] - '0'] == NULL)
            {
                nd->leaf = 0;
                nd->child[str[i] - '0'] = create();
            }
            nd = nd->child[str[i] - '0'];
        }
    }
    bool find(string s)
    {
        node *nd = root;
        for (int i = 0; i < s.size(); i++)
        {
            /*if(nd->child[s[i]-'0']==NULL)
                    return 0;*/
            nd = nd->child[s[i] - '0'];
        }
        return nd->leaf;
    }
};
int main(void)
{
    FIO int t;
    cin >> t;
    while (t--)
    {
        Trie trie = Trie();
        int q;
        cin >> q;
        string array[q]={};
        for (int i = 0; i < q; i++)
        {
            cin >> array[i];
            trie.add(array[i]);
        }
        bool ans = 1;
        for (int i = 0; i < q && ans; i++)
        {
            if (trie.find(array[i]) == 0)
            {
                ans = 0;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
