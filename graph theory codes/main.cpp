#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//// spaning tree
struct edge // using struct for record adges
{
    int from,to,w;
    edge(int from,int to,int w):from(from),to(to),w(w){}
    //// sort priority queue acoording to weight
    bool operator< (const edge & e) const
    {
        return w<e.w;
    }
};
// consts used in both algorithms prim and Kruskal’s algorithm
const int maxsize=100;
vector <pair<int,int> >adjlist[maxsize]; // list of graph
vector<edge>edges; // save spanong tree
//////////////////////////////////// prim algorithms /////////////////////////////////
int primmst()
{
    int vis[maxsize]={0};  // note visited nodes

   int mincost=0;  //sum of edges in spaning tree
    priority_queue<edge>q;  // track edges by smallest weight
   q.push(edge(0,1,0));
   while(!q.empty())
   {
       edge e =q.top();
       q.pop();
       if(vis[e.to])continue;
       vis[e.to]=1; // mark node
       e.w*=-1; // weigh turn to + val as q will sort to smallest weight
       mincost+=e.w;
       edges.push_back(e);
     for(int j=0;j<adjlist[e.to].size();++j)
     {
         if(vis[adjlist[e.to][j].first])continue;
         q.push(edge(e.to,adjlist[e.to][j].first,adjlist[e.to][j].second*-1)); // push new node to be added
     }

   }
   return mincost;
}
// kruskal algorithm mst
// union find struct
struct unionfind  // creat ds to track nodes parent and unit it in log(n)
{
    int setsize[maxsize]={0},parent[maxsize]={0};

    unionfind(int n)
    {
        for(int i=1;i<=n;++i)parent[i]=i;  // every node spearted
        for(int i=1;i<=n;++i)setsize[i]=1;
    }
    int findset(int x)
    {
        if(x==parent[x])return x;
        return parent[x]=findset(parent[x]);
    }
    bool same(int a,int b)
    {
        return (findset(a)==findset(b));
    }
    void unite(int a,int b)
    {
        a=findset(a);
        b=findset(b);
        if(a<b)swap(a,b);
        setsize[a]+=setsize[b];
        parent[b]=a;
    }
};
// we will use struct edge same as prim
int kruskalmst(int n)
{
    int mincost=0;
    priority_queue<edge>q;
    unionfind a(n);
    for(int i=1;i<=n;++i)  // put edges in q
    {
        for(int j=0;j<adjlist[i].size();++j)q.push(edge(i,adjlist[i][j].first,adjlist[i][j].second*-1));
    }
    // looping foreach edge sorting from smallest weigh and added to new set (spaning tree)
    while(!q.empty())
    {
        edge e=q.top();
        q.pop();
        if(!a.same(e.from,e.to))
        {a.unite(e.from,e.to);
         mincost+=e.w*-1;
         edges.push_back(edge(e.from,e.to,e.w));
        }
    }
    return mincost;

}
///////////////////////////////////////////////// end of spaning tree////////////////////



/////////////////////dfs // bfs & topological sort && some application ////////////////////////////////////
const int nodes;
vector<int>graph[nodes];
bool vis[nodes];
vector<int>topological_sort; // for topological sort
void dfs(int node)
{
    vis[node]=1;
    for(int j=0;j<graph[node].size();++j)
    {
        if(vis[graph[node][j]])continue;
        dfs(graph[node][j]);

    }
    topological_sort.push_back(node);  // topolojical sort
}


///////// detect cycle
bool dfscycle(int node,int par)
{
    vis[node]=1;
    for(int j=0;j<graph[node].size();++j)
    {
        if(graph[node][j]==par)continue;
        if(vis[graph[node][j]])return true;
        dfs(graph[node][j]);

    }
    return false;
}
                 ////////////connected components test and number ///////////////////////////
int connectedcomponents(int n)
{
    int cnt=0;
    for(int i=1;i<n;++i)
    {
        if(!vis[i])
        {
            dfs(i);
            ++cnt;
        }
    }
    return cnt;
}
//////////////Bipartiteness check ////////////////

void dfs_Bipartiteness(int i,int color)
{
    vis[i]=color;
    for(int j=0;j<graph[i].size();++j)
    {
        if(vis[graph[i][j]]==color){exit((cout<<-1<<endl,0));}  // not partite
        if(!vis[v[i][j]])dfs(v[i][j],1-color);     // colores is 0 and one 1-0=1 , 1-1=0
    }
}
vector<int>c[2];  // what nodes has color 0 and 1
for(int i=1;i<nodes;++i)c[vis[i]].push_back(i);
///////////// bfs///////////////////////
queue<int>q;
int dist[nodes];
int par[nodes];  // track path
vector<int>path;
void bfs(int node,int d)  //// d if we want specific destintion in shortest path
{
    q.push(node);
    dis[node]=0;  ////// shortest path
    vis[node]=1;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        if(s==d)break;  // enf traversal when reach our destintion
        for(int j=0;j<graph[s].size();++j)
        {
            if(vis[graph[s][j]])continue;
            vis[graph[s][j]]=1;
            dis[graph[s][j]]=dis[s]+1; ///////// shortest path
            par[graph[s][j]]==s; // save node par to use in track path
            q.push(graph[s][j]);
        }
    }
   while(d!=0)
   {
       path.push_back(d);   /////// note path is reversed
       d=par[d];
   }

}
 ////////////////////// single shortest path /////////////////////
 ///////////// bellman forward ////////////////
 vector<pair<int,int> >v[nodes];
 int shortestpath[nodes];
 void bellman(int node,int n)
 {
     for(int i=1;i<n;++i)
        shortestpath[i]=1e9;
     shortestpath[node]=0;
     for(int i=1;i<=n-1;++i)
     {
         bool r=0; ////// if no change happen in one loop just break
         for(int j=1;j<=n;++j)
         {
             for(int k=0;k<v[j].size();++k)
             {
                 if (shortestpath[a]+v[a][j].second < shortestpath[b.first])
             {    shortestpath[b.first] = shortestpath[a]+b.second;
                   r=1;
                }
             }
         }
         if(!r)break;
     }
 }
 ///////// spfa efficent version from bellman algo //////////////////
void spfa(int node,int n)
{
    queue<int>q;
    for (int i = 1; i <= n; i++) shortestpath[i] = 1e9;
     shortestpath[x] = 0;
     q.push(x);
     while (!q.empty())
        { int a = q.front();
         q.pop(); vis[a] = 0;
          for (int j=0;j<v[a].size();++j)
            { if (shortestpath[a]+v[a][j].second < shortestpath[b.first])
             { shortestpath[b.first] = shortestpath[a]+b.second;
                if (!vis[v[a][j].first])
                    {q.push(v[a][j].first);
                      z[b.first] = 1;
                }
            }
            }
          }

}
//////////////// negative cycle detect
 bool bellman(int node,int n)
 {
     for(int i=1;i<=n;++i)
        shortestpath[i]=1e9;
     shortestpath[node]=0;
     for(int i=1;i<=n;++i)
     {
         bool r=0;

         for(int j=1;j<=n;++j)
         {
             for(int k=0;k<v[j].size();++k)
             {
                 if (shortestpath[a]+v[a][j].second < shortestpath[b.first])
             {    shortestpath[b.first] = shortestpath[a]+b.second;
                   r=1;
                   if(i==n)return true;
                }
             }
         }
         if(!r)break;

     }
     return false;
 }
 /////////////// dijkestra ////////////////////
 priority_queue<pair<int,int> >q;
 void dijkestra(int node,int n)
 {
     for(int i=1;i<=n;++i)
        shortestpath[i]=1e9;
     shortestpath[node]=0;
     q.push(make_pair(0,node));
     while(!q.empty())
     {
         int a=q.top().second;
         q.pop();
         if(vis[a])continue;
         vis[a]=1;
         for(int j=0;j<v[a].size();++j)
         {
             if(shortestpath[a]+v[a][j].second<shortestpath[v[a][j].first])
             {
                 shortestpath[v[a][j].first]=shortestpath[a]+v[a][j].second;
                 q.push(-shortestpath[v[a][j].first],v[a][j].first);
             }

         }
     }
 }
 /////////////// all shortest path  Floyd Algorithm /////////////////////////////////
 int allshortestpath[nodes][nodes];
 int v[nodes][nodes]; // adjaceny matrix
 void floyd(int n)
 {
     for(int i=1;i<=n;++i)
     {
         for(int j=1;j<=n;++j)
         {
             if(i==j)allshortestpath[i][j]=0;
             else if(v[i][j])allshortestpath=v[i][j];
             else allshortestpath[i][j]=1e9;
         }
     }
     for(int k=1;k<=n;++k)
     {
         for(int i=1;i<=n;++i)
         {
             for(int j=1;j<=n;++j)
                allshortestpath[i][j]=min(allshortestpath[i][j],allshortestpath[i][k]+allshortestpath[k][j]);
         }
     }
 }
///////////////////////// tree /////////////////////////////////////////
//// tree traversal ////////////////////////
int nodesnumber[nodes];
void dfs(int node, int par)
 {
     nodesnumber[node]=1;
     for(int j=0;j<graph[node].size();++j)
        {if(graph[node][j]==par)continue;
         dfs(graph[node][j],node);
         nodesnumber[node]+=nodesnumber[graph[node][j]];
        }

 }


 ///////////// binary trees//////////////////////////////
 ///////// number of pathes from specific node
 int paths[nodes];
 vector<int>graph[nodes]  ////// directed graph
 void dfs (int specificnode )
 {
     for(int j=0;j<graph[specificnode].size_type(),++j)
     {
         dfs(graph[specificnode][j]);
     }
     paths[node]+=1;   //// number of paths from spcific node to all other nodes

 }
////////////////Extending Dijkstra’s algorithm number of shortest paths /////////////

priority_queue<pair<int,int> >q;
int  numberofshortestpaths[nodes];
 void dijkestra(int node,int n)
 {
     for(int i=1;i<=n;++i)
       {
           shortestpath[i]=1e9;
           numberofshortestpaths[i]=0;
       }
     shortestpath[node]=0;

     q.push(make_pair(0,node));
     while(!q.empty())
     {
         int a=q.top().second;
         q.pop();
         if(vis[a])continue;
         vis[a]=1;
         for(int j=0;j<v[a].size();++j)
         {
             if(shortestpath[a]+v[a][j].second<shortestpath[v[a][j].first])
             {
                 shortestpath[v[a][j].first]=shortestpath[a]+v[a][j].second;
                 q.push(-shortestpath[v[a][j].first],v[a][j].first);
                 numberofshortestpaths[v[a][j].first]=1;  // one shortest path
             }
             else if(shortestpath[a]+v[a][j].second==shortestpath[v[a][j].first]) //// dtect number of shortest paths if thear are equal sum of shortest paths from node + number in childrens

             {
                 numberofshortestpaths[v[a][j].first]+=numberofshortestpaths[a];
             }

         }
     }
 }

int main()
{
    /*
    //prim code adjecny list fill and testing
      for(int i=0;i<8;++i)
      {
          int a,b,w;
          cin>>a>>b>>w;
          adjlist[a].push_back(make_pair(b,w));
          adjlist[b].push_back(make_pair(a,w));
      }
      cout<<primmst()<<"\n";
      for(int i=0;i<edges.size();++i)
        cout<<edges[i].from<<"  "<<edges[i].to<<"  "<<edges[i].w<<"\n";
      //// prim end test
      ////// kruskal test
      /* for(int i=0;i<8;++i)
      {
          int a,b,w;
          cin>>a>>b>>w;
          adjlist[a].push_back(make_pair(b,w));
          adjlist[b].push_back(make_pair(a,w));
      }
          cout<<kruskalmst(8)<<"\n";
      for(int i=0;i<edges.size();++i)
        cout<<edges[i].from<<"  "<<edges[i].to<<"  "<<edges[i].w*-1<<"\n";
        /////////////////////////////// end testing */


    return 0;
}
