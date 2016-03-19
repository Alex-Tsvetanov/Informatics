# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

const long long MAX_N = 1024;
const long long MAX_Q = 2e5 + 10;
const long long INF = (1LL << 62);

long long n;
char t[MAX_N];
long long let[32];
char q[32];

long long pos;
long long st[MAX_N];
long long tp[MAX_N];
long long cnt;

void solve ()
{
    long long i, j;
    long long sz = -1;
    pos = 0;
    for (i = 0; i < n; i ++)
    {
        if (t[i] == '(')
        {
            st[pos] = -1;
            tp[pos] = 1;
            pos ++;
            continue;
        }
        if (t[i] != ')')
        {
            st[pos] = let[t[i] - 'a'];
            tp[pos] = 0;
            pos ++;
        }
        if (pos >= 2)
        {
            if (tp[pos - 1] && tp[pos - 2])
            {
                pos --;
                continue;
            }
            if (tp[pos - 1])
            {
                pos --;
                continue;
            }
            if (tp[pos - 2])
            {
                st[pos - 2] = st[pos - 1];
                tp[pos - 2] = 0;
                pos --;
                continue;
            }
            st[pos - 2] = ~(st[pos - 2] & st[pos - 1]);
            tp[pos - 2] = 0;
            pos --;
        }
    }

    while (pos >= 2)
    {
        if (tp[pos - 1])
        {
            pos --;
            continue;
        }
        if (tp[pos - 2])
        {
            st[pos - 2] = st[pos - 1];
            pos --;
            continue;
        }
        st[pos - 2] = ~(st[pos - 2] & st[pos - 1]);
        pos --;
    }

    for (i = 0; i < cnt; i ++)
        if (st[pos - 1] & (1LL << i))
            printf ("1");
        else
            printf ("0");
}

int main ()
{

    long long i, sz = -1, lamp;
    scanf ("%s", t);
    n = strlen (t);
    while (1)
    {
            scanf ("%s", q);
            if (q[0] == '2')
            {
                solve ();
                for (i = 0; i < 30; i ++)
                    let[i] = 0;
                cnt = 0;
                break;
            }
            if (sz == -1)
                sz = strlen (q);
            for (i = 0; i < sz; i ++)
                let[i] += (((long long) (q[i] - '0')) << cnt);
            cnt ++;
            if (cnt == 64)
            {
                solve();
                for (i = 0; i < 30; i ++)
                    let[i] = 0;
                cnt = 0;
            }
    }
    printf ("\n");
    return 0;
}
