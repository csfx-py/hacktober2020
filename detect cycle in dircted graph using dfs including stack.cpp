
graph-implementadcylist/detect cycle in dircted graph using dfs including stack.cpp
@imhkr
imhkr coding block
  
#include <bits/stdc++.h>
using namespace std;
template<typename T> 
class Graph
{
    public:
    map<T,list<T>> h;
    Graph()
    {

    }
    void addmanycities(T x ,T y,bool bir=true)
    {
        h[x].push_back(y);
        if(bir)
        {
            h[y].push_back(x);
        }
    }
    void print()
    {
        for(auto key:h)
        {
            T k=key.first;
        cout<<k<<"---> ";
        for(auto tt:key.second)
        {
            cout<<tt<<" ";
        }
        cout<<endl;
        }
    }
    void dfs_helper(T node,map<T,bool>&visited)
    {
        visited[node]=true;
        cout<<node<<" "<<endl;
        for(T neigh:h[node])
        {
            if(!visited[neigh])
            {
                dfs_helper(neigh,visited);
            }
        }
    }
    void dfs_helper2(T node,map<T,bool>&visited,list<T> &ordering)
    {
        visited[node]=true;
        for(auto neigh:h[node])
        {
            if(!visited[neigh])
            {
                dfs_helper2(neigh,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfstopological()
    {
        map<T,bool> visited;
        list<T> ordering;
        for(auto i:h)
        {
            T node=i.first;
            if(!visited[node])
            {
                dfs_helper2(node,visited,ordering);
            }
        }
        for(auto i:ordering)
        {
            cout<<i<<"----->";
        }
    }
    void dfs(T src)
    {
        map<T,bool> visited;
        dfs_helper(src,visited);
        cout<<endl;
        int co=1;
        for(auto neigh:h)
        {
            T city=neigh.first;
            if(!visited[city])
            {
                dfs_helper(city,visited);
                co++;
            }
        }
            cout<<"The cities that was left are "<<co<<endl;
        

    }
    void toposort()
    {
        map<T,bool> visited;
        map<T,int> indegree;
        queue<T> q;
        for(auto i:h)
        {
            T node=i.first;
            visited[node]=false;
            indegree[node]=0;
        }
        for(auto i:h)
        {
            T u=i.first;
            for(auto v:h[u])
            {
                indegree[v]++;
            }
        }
        // find all node with zero degree
        {
            for(auto i:h)
            {
                T node=i.first;
                if(indegree[node]==0)
                {
                    q.push(node);
                }
            }
            //start the algo 
            while(!q.empty())
            {
                T node=q.front();
                cout<<node<<"->";
                q.pop();
                // now remove the degree of the neigh bcoz this node is deleted from the queue so the value will dec by -1
                for(auto neigh:h[node])
                {
                    indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
                }
            }
        }
    }
    bool detectcyclebfs(T src)
    {
        map<T,bool>visited;
        queue<T>q;
        map<T,int> parent;
        q.push(src);
        parent[src]=src;
        while(!q.empty())
        {
            int node=q.front();
          //  cout<<node<<" ->";
            q.pop();
            for(auto neigh:h[node])
            {
                if(visited[neigh]==true && parent[node]!=neigh)
                {
                    return true;
                }
                else if(!visited[neigh])
                {
                    visited[neigh]=true;
                    parent[neigh]=node;
                    q.push(neigh);
                }
            }
        }
        return false;
    }
    bool detectcycledfs_helper(T node,map<T,bool>&visited,map<T,bool>&instack)
    {
    visited[node]=true;
    instack[node]=true;
    for(T neigh:h[node])
    {
        if(!visited[neigh] && detectcycledfs_helper(neigh,visited,instack)||instack[neigh])
        {
            return true;
        }
    }
    instack[node]=false;
    return false;
    }
    bool detectcycledfs()
    {
        map<T,bool> visited;
        map<T,bool> instack;
        
        for(auto i:h)
        {
            T node=i.first;
            if(!visited[node])
            {
              bool re= detectcycledfs_helper(node,visited,instack);
              if(re)
              {
                  return true;
              }
            }
    }
    return false;
    }
};
int main() {
  //  Graph<string> g;
    /*g.addmanycities("amritsar","jaipur");
    g.addmanycities("amristar","delhi");
    g.addmanycities("delhi","jaipur");
    g.addmanycities("delhi","mumbai");
    g.addmanycities("mumbai","jaipur");
    g.addmanycities("mumbai","bhopal");
    g.addmanycities("delhi","bhopal");
    g.addmanycities("mumbai","banglore");
    g.addmanycities("delhi","agra");
    g.addmanycities("Andman","nicobar");
    */
    /*
    g.addmanycities("English","Programming Logic",false);
    g.addmanycities("Maths","Programming Logic",false);
    g.addmanycities("Programming Logic","HTML",false);
    g.addmanycities("Programming Logic","Python",false);
    g.addmanycities("Programming Logic","Java",false);
    g.addmanycities("Programming Logic","JS",false);
    g.addmanycities("Python","Web Dev",false);
    g.addmanycities("HTML","CSS",false);  
    g.addmanycities("CSS","JS",false);
   // g.addmanycities("Python","Web Dev",false);
    g.addmanycities("JS","Web Dev",false);
    g.addmanycities("Java","Web Dev",false);
    g.addmanycities("Python","Web Dev",false);
     */
 // g.print();  
 //g.dfs("amritsar");
// g.dfstopological();
    //g.toposort();
    Graph<int>g;
    g.addmanycities(0,2,false);
    g.addmanycities(0,1,false);
    g.addmanycities(2,3,false);
    g.addmanycities(2,4,false);
    g.addmanycities(2,0,false);
    g.addmanycities(4,5,false);
    g.addmanycities(1,5,false);
    if(g.detectcycledfs())
    {
        cout<<"it's cycle"<<endl;
    }
    else
    {
        cout<<"it's not cycle"<<endl;
    }
}
