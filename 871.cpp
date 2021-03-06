/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb(a)       push_back(a)
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          printf("\n")

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)
#define tc4(x)      printf("Case #%d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
template <class T> inline T _sqrt(T a)
{
    return (T)sqrt((double)a);
}
template <class T, class X> inline T _pow(T a, X b)
{
    T res=1;
    for(int i=1; i<=b; i++)
        res*=a;
    return res;
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef pair<double, double>pdd;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<double>vd;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const long long int mx=100000;
/* global declaration */

string str[30];
bool visited[30][30];
int m,n;

void reset(void)
{
    int i,j;
    for(i=0; i<30; i++)
    {
        for(j=0; j<30; j++)
        {
            visited[i][j]=false;
        }
    }
}

int dfs(int x, int y)
{
    int i,nx,ny,a;
    visited[x][y]=true;
    a=1;
    for(i=0; i<8; i++)
    {
        nx=x+dx8[i];
        ny=y+dy8[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny] && str[nx][ny]=='1')
        {
            a+=dfs(nx,ny);
        }
    }
    return a;
}

int main()
{
    int i,t,j,blob,ans;
    string in;
    cin>>t;
    getchar();
    getchar();
    while(t--)
    {
        i=0;
        reset();
        while(getline(cin,in))
        {
            if(in.empty())
                break;
            str[i++]=in;
        }
        m=i;
        n=str[0].size();
        ans=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(!visited[i][j] && str[i][j]=='1')
                {
                    blob=dfs(i,j);
                    if(blob>ans)
                        ans=blob;
                }
            }
        }
        pr1(ans);
        if(t)
            nl;
    }
    return 0;
}
