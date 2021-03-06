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
const long long int mx=1120;
const long long int mod=1e9+7;
/* global declaration */

bool x[mx+5];
vi primes;
int dp[200][15][1120+5];

void sieve(void)
{
    int i,j,k;
    k=sqrt(mx);
    for(i=3;i<=k;i+=2)
    {
        if(!x[i])
        {
            for(j=i+i;j<=mx;j+=i) x[j]=true;
        }
    }
    primes.pb(2);
    for(i=3;i<=mx;i+=2)
    {
        if(!x[i]) primes.pb(i);
    }
    return;
}

int coin_change(int i, int amount, int taken)
{
    if(taken==0) return amount==0;
    if(amount==0) return 0;
    if(i<0) return 0;
    if(taken*primes[i]<amount) return 0;

    int &ret=dp[i][taken][amount];
    int res=0;
    if(ret!=-1) return ret;

    if(amount-primes[i]>=0) res+=coin_change(i-1,amount-primes[i],taken-1);
    res+=coin_change(i-1,amount,taken);

    ret=res;
    return ret;
}

int main()
{
    int n,k;
    sieve();
    setneg(dp);
    while(scanf("%d %d",&n,&k))
    {
        if(!n && !k) break;
        printf("%d\n",coin_change(primes.size()-1,n,k));
    }
    return 0;
}
