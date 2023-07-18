//Note: I beleive that there could be a better implementation, especially when it comes to updating the priority queue. I intend to update this code in the future.

#include <bits/stdc++.h>
using namespace std;

//For comparing the elements in the priority queue used for the implementation of Prim's algorithm
class Compare
 {
     public:
     bool operator()(pair<int,int> a, pair<int,int> b)
     {
         return a.second>b.second;
     }
 };
 
class Graph
{
    int n;
    vector<vector<pair<int,int>>> gp;
    public:
    Graph(int n)
    {
        this->n=n;
        gp.resize(n);
    }
    void addedge(int a, int b, int c)
    {
        gp[a].push_back(make_pair(b,c));
	gp[a].push_back(make_pair(b,c));
    }
    vector<pair<int,int>> adj(int v)
    {
        return gp[v];
    }
};

//Returns the minimum weight to connect all nodes in the graph
int prims(int n, vector<vector<int>> edges, int start)
{
    Graph g(n);
    for(vector<int> i:edges)
    {
        g.addedge(i[0]-1,i[1]-1,i[2]);
    }
    int sum=0;
    vector<bool> tmark(n, false);
    vector<int> vw(n,INT_MAX);
    priority_queue <pair<int,int>,vector<pair<int,int>>,Compare> pq;
    vw[start-1]=0;
    pq.push(make_pair(start-1,0));
    while(!pq.empty())
    {
        pair<int,int> a=pq.top();
        pq.pop();
        tmark[a.first]=true;
        sum=sum+a.second;
        for(auto j:g.adj(a.first))
        {
            int k=j.first;
            int l=j.second;
            if(!tmark[j.first])
            {
                if(vw[k]==INT_MAX)
                {
                    vw[k]=l;
                    pq.push(make_pair(k,l));
                }
                else if(vw[k]<=l)
                {
                    continue;
                }
                else
                {
                    vw[k]=l;
                    priority_queue <pair<int,int>,vector<pair<int,int>>,Compare> pqu;
                    while(!pq.empty())
                    {
                        pair<int,int> b=pq.top();
                        pq.pop();
                        if(b.first==k)
                        {
                            b.second=l;
                        }
                        pqu.push(b);
                    }
                    pq=pqu;
                }
            }
            
        }
    }
    return sum;
}
