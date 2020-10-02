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
};
int main() {
    Graph<string> g;
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
    g.addmanycities("English","Programming Logic",false);
    g.addmanycities("Maths","Programming Logic",false);
    g.addmanycities("Programming Logic","HTML",false);
    g.addmanycities("Programming Logic","Python",false);
    g.addmanycities("Programming Logic","Java",false);
    g.addmanycities("Programming Logic","JS",false);
    g.addmanycities("Python","Web Dev",false);
    g.addmanycities("CSS","JS",false);
    g.addmanycities("JS","Web Dev",false);
    g.addmanycities("Java","Web Dev",false);
    g.addmanycities("Python","Web Dev",false);

 // g.print();  
 //g.dfs("amritsar");
 g.dfstopological();
}
