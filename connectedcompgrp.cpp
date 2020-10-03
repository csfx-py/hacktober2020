#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int>adj(10);

void dfs(int i,vector<int>&vis,vector<int>&adj){
vis[i]=1;
stack<int>s;
s.push(i);
while(!s.empty()){

int t= s.top();
s.pop();
for(int it=t;it<adj[t].size();it++ )
{

    if(!vis[it]){

        vis[it]=1;

        s.push(adj[it]);
    }
}





}


    
}




int main(){

int v;
cin>>v;
int c=0;
int s,k;

vector<int>vis(v,0);
    for(int i=0;i<v;i++){

        cin>>s>>k;

        adj[s].push_back(k);
    }

    for(int i=1;i<=v;i++){

        if(vis[i]==0){
            dfs(i,vis,adj);
            c++;
        }
    }

cout<<c<<"\n";
return 0;

}