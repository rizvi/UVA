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
const long long int mx=10000;
/* global declaration */

struct graph
{
    LL u,v,w;
};

bool operator<(struct graph A, struct graph B)
{
    return A.w<B.w;
}

LL parent[mx+5];
vector<graph>G;

LL find_set(LL a)
{
    if(a==parent[a])
        return a;
    return parent[a]=find_set(parent[a]);
}

LL MST(LL n, LL a)
{
    LL u,v,i,x,total;
    for(i=1;i<=n;i++)
        parent[i]=i;
    sort(G.begin(),G.end());

    x=total=0;
    for(i=0;i<G.size() && G[i].w<a;i++)
    {
        u=find_set(G[i].u);
        v=find_set(G[i].v);
        if(u!=v)
        {
            parent[u]=v;
            x++;
            total+=G[i].w;
            if(x==n-1)
                break;
        }
    }
    return total;
}

int main()
{
    LL i,n,m,a,t,sum,count,u;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&m,&a);
        G.clear();
        while(m--)
        {
            graph get;
            scanf("%lld %lld %lld",&get.u,&get.v,&get.w);
            G.pb(get);
        }
        sum=MST(n,a);
        count=0;
        for(i=1;i<=n;i++)
        {
            u=find_set(i);
            if(u==i)
                count++;
        }
        printf("Case #%d: ",tc++);
        printf("%lld %lld\n",(count*a)+sum,count);
    }
    return 0;
}
