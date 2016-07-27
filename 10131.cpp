/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define fast          ios::sync_with_stdio(0)
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
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
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
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
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1000;
const long long int mod=1e9+7;
/* global declaration */

struct node
{
    int weight,iq,index;
};

bool operator<(node A, node B)
{
    return A.iq>=B.iq;
}

node a[mx+5];

int parent[mx+5],dp[mx+5];

int lis(int x, int n)
{
    int i,cnt=1;
    if(dp[x]!=-1) return dp[x];
    for(i=x+1;i<=n;i++)
    {
        if(a[i].weight>a[x].weight)
        {
            if(lis(i,n)+1>cnt)
            {
                cnt=lis(i,n)+1;
                parent[x]=i;
            }
        }
    }
    dp[x]=cnt;
    return cnt;
}

int main()
{
    int i=1,n,ans,idx;
    while(scanf("%d %d",&a[i].weight,&a[i].iq)!=EOF)
    {
        a[i].index=i;
        i++;
    }
    setneg(dp);
    setneg(parent);
    n=i-1;
    sort(a+1,a+n+1);
    ans=0;
    idx=0;
    for(i=1;i<=n;i++)
    {
        if(lis(i,n)>ans)
        {
            ans=lis(i,n);
            idx=i;
        }
    }
    pr1(ans);
    while(parent[idx]!=-1)
    {
        printf("%d\n",a[idx].index);
        idx=parent[idx];
    }
    printf("%d\n",a[idx].index);
    return 0;
}
