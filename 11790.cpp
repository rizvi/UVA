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
const long long int mx=5000;
const long long int mod=1e9+7;
/* global declaration */

int a[mx+5],in[mx+5],de[mx+5],b[mx+5];
int n;

int increasing(int k)
{
    int &ret=in[k];
    if(ret!=-1) return ret;
    int i;
    ret=0;
    for(i=k+1; i<=n; i++)
    {
        if(a[i]>a[k]) ret=max(ret,increasing(i));
    }
    ret+=b[k];
    return ret;
}

int decreasing(int k)
{
    int &ret=de[k];
    if(ret!=-1) return ret;
    int i;
    ret=0;
    for(i=k+1; i<=n; i++)
    {
        if(a[i]<a[k]) ret=max(ret,decreasing(i));
    }
    ret+=b[k];
    return ret;
}

int main()
{
    int i,longest_in,longest_de,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        for(i=1; i<=n; i++) scanf("%d",&b[i]);
        setneg(in);
        setneg(de);
        longest_in=0;
        longest_de=0;
        for(i=1;i<=n;i++)
        {
            longest_in=max(longest_in,increasing(i));
            longest_de=max(longest_de,decreasing(i));
        }
        if(longest_in>=longest_de) printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc++,longest_in,longest_de);
        if(longest_in<longest_de) printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc++,longest_de,longest_in);
    }
    return 0;
}