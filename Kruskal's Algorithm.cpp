#include <bits/stdc++.h>
using namespace std;

 class UF
 {
     int n;
     vector<int> usize;
     vector<int> parent;
     public:
     UF(int n)
     {
         this->n=n;
         usize.resize(n);
         parent.resize(n);
         for(int i=0;i<n;i++)
         {
             usize[i]=1;
             parent[i]=i;
         }
     }
     int find(int a)
     {
         while(parent[a]!=a)
         {
             a=parent[a];
         }
         return a;
     }
     void unite(int x, int y)
     {
         int p=find(x);
         int q=find(y);
         if(p!=q)
         {
         if(usize[p]>=usize[q])
         {
             parent[q]=p;
             usize[p]+=usize[q];
         }
         else
         {
             parent[p]=q;
             usize[q]+=usize[p];
         }
         }
     }
 };
 
 class Edge
 {
     public:
     int x,y,w;
     Edge(int x, int y, int w)
     {
         this->x=x;
         this->y=y;
         this->w=w;
     }
 };
 
 class Graph
 {
     int n;
     vector<Edge> ed;
     public:
     Graph(int n)
     {
         this->n=n;
     }
     void addedge(Edge &e)
     {
         ed.push_back(e);
     }
     vector<Edge> edgeslist()
     {
         return ed;
     }
 };
 
 bool cmp(Edge a, Edge b)
 {
     if(a.w==b.w)
     return a.x+a.y+a.w<=b.x+b.y+b.w;
     else
     return a.w<b.w;
 }

//Returns an integer that represents the total weight of the subtree formed
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{
    vector<Edge> mst;
    Graph gp(g_nodes);
    int q=g_weight.size();
    for(int i=0;i<q;i++)
    {
        Edge edg(g_from[i],g_to[i],g_weight[i]);
        gp.addedge(edg);
    }
    vector<Edge> l=gp.edgeslist();
    sort(l.begin(), l.end(), cmp);
    UF u(g_nodes);
    for(int j=0; j<q; j++)
    {
        if(u.find(l[j].x-1)!=u.find(l[j].y-1))
        {
            mst.push_back(l[j]);
            u.unite(l[j].x-1,l[j].y-1);
        }
    }
    int sum=0;
    for(auto k:mst)
    {
        sum+=k.w;
    }
    return sum;
}
