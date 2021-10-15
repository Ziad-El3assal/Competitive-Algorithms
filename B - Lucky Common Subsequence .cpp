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
int an, bn, cn;
string a, b, c;
vector<vector<vector<int>>> mem;
vector<int> prefix;
int getborder(int i, char ch)
{
    while (i > 0 && ch != c[i])
        i = prefix[i - 1];
    if (ch == c[i])
    {
        i++;
    }
    return i;
}
int solve(int i, int j, int br)
{
    if (br == cn)
        return -OO;
    if (i == an || j == bn)
        return 0;
    if (mem[i][j][br] != -1)
        return mem[i][j][br];
    int ret = 0;
    if (a[i] == b[j])
        ret = max(ret, solve(i + 1, j + 1, getborder(br, a[i])) + 1);
    ret = max(ret, solve(i + 1, j, br));
    ret = max(ret, solve(i, j + 1, br));
    return mem[i][j][br] = ret;
}
void printsol(int i, int j, int br)
{
    if (br == cn)
        return;
    if (i == an || j == bn)
        return;
    int opt = solve(i, j, br);
    if (a[i] == b[j] && opt == solve(i + 1, j + 1, getborder(br, a[i])) + 1)
    {
        cout << a[i];
        printsol(i + 1, j + 1, getborder(br, a[i]));
    }
    else if (opt == solve(i, j + 1, br))
    {
        printsol(i, j + 1, br);
    }
    else
    {
        printsol(i + 1, j, br);
    }
}
int main(void)
{
    FIO
            //freopen("input.txt","r",stdin);
            //freopen("output.txt","w",stdout);
            cin >>
        a >> b >> c;
    an = a.size();
    bn = b.size();
    cn = c.size();
    prefix = vector<int>(cn);
    prefix[0] = 0;
    mem = vector<vector<vector<int>>>(an, vector<vector<int>>(bn, vector<int>(cn + 1, -1)));
    for (int i = 1; i < cn; i++)
    {
        prefix[i] = getborder(prefix[i - 1], c[i]);
    }
    //cout<<solve(0,0,0)<<endl;
    if (solve(0, 0, 0))
    {
        printsol(0, 0, 0);
        cout << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
