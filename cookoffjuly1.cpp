#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main() {
	// your code goes here
	
	long long  T;
	cin>>T;
	long long n;
	if(T>200){
	    return 0;
	}
	while(T-->0)
	
	{
	    cin>>n;
	    string s;
	   cin>>s;
	    map<char,int>mp;
	    
	    for(int i=0;i<n;i++){
	        
	        mp[s[i]]++;
	    }
	    int flag1=0,flag2=0;
	    
	    for(auto it=mp.begin();it!=mp.end();it++){
	        
	   // cout<<it->first<<" "<<it->second<<"\n";
	    
	        if(it->second%2==0){
	            
	            flag1+=1;
	        }
	        else if(it->second%2!=0){
	            flag2+=1;
	        }
	    }
	    
	    if(flag2==0){
	        
	        cout<<"YES"<<"\n";
	    }
	    else if(flag2!=0){
	        cout<<"NO"<<"\n";
	    }
	    
	}
	return 0;
}
