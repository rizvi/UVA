#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<utility>
using namespace std;
int main()
{
    vector<int>v[200];
    queue<int>q;
    int i,j,node,node1,node2,edge,level[200],visited[200],color[200],t,x,n,count;
    bool res;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&node,&edge);
        for(i=0;i<200;i++)
        {
            v[i].clear();
            visited[i]=color[i]=0;
            level[i]=-1;
        }
        for(i=0;i<edge;i++)
        {
            scanf("%d %d",&node1,&node2);
            v[node1].push_back(node2);
            v[node2].push_back(node1);
            //printf(" %d %d\n",i,edge);
        }
        res=false;
        count=0;
        for(i=0;i<node;i++)
        {
            if(level[i]==-1)
            {
                level[i]=0;
                visited[i]=1;
                color[i]=1;
                q.push(i);
                while(!q.empty())
                {
                    x=q.front();
                    for(j=0;j<v[x].size();j++)
                    {
                        n=v[x][j];
                        if(visited[n]==0)
                        {
                            visited[n]=1;
                            level[n]=level[x]+1;
                            q.push(n);
                            if(color[x]==1)
                            {
                                color[n]=2;
                            }
                            else
                            {
                                color[n]=1;
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
        for(i=0;i<node;i++)
        {
            if(level[i]%2==0){
                //printf("%d %d\n",i,level[i]);
                count++;
            }
            for(j=0;j<v[i].size();j++)
            {
                x=v[i][j];
                if(color[i]==color[x])
                {
                    res=true;
                    break;
                }
            }
            if(res)
                break;
        }
        if(res==false)
        {
            printf("%d\n",count);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
