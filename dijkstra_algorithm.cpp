#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
    public:
        map<T,list<pair<T,int>>> m;
        Graph()
        {
        }
        void addedge(T u,T v,int dist,bool birid=true)
        {
            m[u].push_back(make_pair(v,dist));
            if(birid)
            {
                m[v].push_back(make_pair(u,dist));
            }
        }
        void printdijsktra()
        {

            for(auto city:m)
            {
                T cityname=city.first;
                cout<<cityname<<"->";
                for(auto citie:city.second)
                {
                    cout<<"( "<<citie.first<<" , "<<citie.second<<" )"<<endl;
                }
            }
        }
        void dijsktrasssp(T src)
        {
            map<T,int>dist;
            for(auto j:m)
            {
                dist[j.first]=INT_MAX;
            }
            set<pair<int,T>> s;
            dist[src]=0;
            s.insert(make_pair(0,src));
            while(!s.empty())
            {
                auto p=*(s.begin());
                T node=p.second;
                int nodedit=p.first;
                s.erase(s.begin());
                for(auto neigh:m[node])
                {
                    if(neigh.second+nodedit<dist[neigh.first])
                    {
                        T dest=neigh.first;
                        auto f=s.find(make_pair(dist[dest],dest));
                        if(f!=s.end())
                        {
                            s.erase(f);
                        }
                        dist[dest]=neigh.second+nodedit;
                        s.insert(make_pair(dist[dest],dest));
                    }
                }
            }
            for(auto d:dist)
            {
                cout<<d.first<<" is located at distance of "<<d.second<<endl;
            }
        }
};
int main() {
    /*Graph<int> g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);
    //g.printdijsktra();
    g.dijsktrasssp(1);
    */
    Graph<string>india;
    india.addedge("Amritsar","Delhi",1);
    india.addedge("Amritsar","Jaipur",4);
    india.addedge("Jaipur","Delhi",2);
    india.addedge("Jaipur","Mumbai",8);
    india.addedge("Bhopal","Agra",2);
    india.addedge("Mumbai","Bhopal",3);
    india.addedge("Agra","Delhi",1);
    india.dijsktrasssp("Amritsar");
    return 0;

}
