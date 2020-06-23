#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct edges                               // describe edges of graph which nodes connect between them and its weight
{
    int from,to,weight;
    friend bool operator< (edges e1,edges e2)   //operator to sort the edges according to weight in decreasing order
    {
        return e1.weight>e2.weight;
    }
};
const int Max=100000;                  // max number of nodes in graph
vector<pair<int,int> >adjList[Max];    // graph representation
vector<edges>spanningTree;             // the spanning tree from given graph
/*   structure that used to keep track nodes connected in one sit with findSet function and also,
      join 2 sets with joinSet function the find and join operate in O(log(n)) time because the trick in join which
        choose the shortest set and make its parent the bigger set parent also it connect each the node to the parent
        directly which make the tree with linear length make sure the tree length is always is log(n)
*/
struct UnionFind
{
    vector<int>sets;        //  keep track connected sets
    vector<int>setSize;     //  keep track sets size

     UnionFind(int N)       // constructor to initlize the union find structure
    {
       sets.reserve(N+1);
       setSize.reserve(N+1);
       for(int i=1;i<=N;++i)sets[i]=i;            // first time each node sperated
       for(int i=1;i<=N;++i)setSize[i]=1;         // all sets length = 1
    }

    int findSet(int node)                     // find the parent of node
    {
      while(node!=sets[node])node=sets[node];
      return node;

    }

    void joinSet(int set1,int set2)          // connect 2 sets
    {
         set1=findSet(set1);
         set2=findSet(set2);
         if(setSize[set1]<setSize[set2])
         swap(set1,set2);
         sets[set2]=set1;                       // always connect to parent which make it linear length
         setSize[set1]+=setSize[set2];
   }
   bool sameSet(int set1,int set2)             // test if 2 nodes in same set
   {

     if(findSet(set1)==findSet(set2))return 1;
       return 0;
   }

};
////////////////////////// Kruskal algorithm to find minimum spanning tree from a graph//////////////////////////

int MSTKruskal(int N)
{
    int minCost=0;               // count minimum cost of tree weights
    priority_queue<edges>q;      // keep track edges from smallest to bigger weights
    UnionFind tree(N);           // initalize union find structure
    /* loop in graph and add the edges to q  */
    for(int i=1;i<=N;++i)
    {
        for(int j=0;j<adjList[i].size();++j)
        {
            edges edge;
            edge.from=i;edge.to=adjList[i][j].first;edge.weight=adjList[i][j].second;
            q.push(edge);
        }
    }
    /* loop in edges if the edge will connect 2 nodes already in same set cancel it.
    if it don`t join the node to the set   */
    while(!q.empty())
    {
        edges edge = q.top();
        q.pop();
        if(tree.sameSet(edge.from,edge.to))continue;
        tree.joinSet(edge.from,edge.to);
        minCost+=edge.weight;
        spanningTree.push_back(edge);   // add the chosen edge to the spanning tree
    }
    return minCost;

}

int main()
{
    /* enter the graph */
    int edgesNum,N;
    cin>>N>>edgesNum;
    for(int i=0;i<edgesNum;++i)
    {
        int node1,node2,weight;
        cin>>node1>>node2>>weight;
        adjList[node1].push_back(make_pair(node2,weight));
        adjList[node2].push_back(make_pair(node1,weight));
    }


    cout<<MSTKruskal(N)<<"\n";   // call with graph size
    /* showing the construction of the result spanning tree */

    for(int i=0;i<spanningTree.size();++i)
    {
        cout<<spanningTree[i].from<<" "<<spanningTree[i].to<<" "<<spanningTree[i].weight<<"\n";
    }




    return 0;
}
