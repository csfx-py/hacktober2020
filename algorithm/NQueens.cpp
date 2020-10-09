
#include <bits/stdc++.h>

#include <iostream>

using namespace std;
int N;
int arr[100][100]={{0}};

bool is_attack(int i,int j)
{
    for(int m=0;m<N;m++)
    {
        if(arr[i][m]==1 || arr[m][j]==1)
        {
        return true;
        }
        
    }
    
    for(int m=0;m<N;m++)
    {
        for(int z=0;z<N;z++)
        {
            if(((m+z)==(i+j)) || ((m-z)==(i-j)))
            {
                if(arr[m][z]==1)
                {
                return true;
                }
            }
        }
        
    }
    
    return false;
}

bool solveNQ(int n)
{
    
    if(n==0)
    {
    return false;
    }
    for(int k=0;k<N;k++)
    {
        for(int l=0;l<N;l++)
        {
            if(!(is_attack(k,l)) && arr[k][l]!=1)
            {
                
                arr[k][l]=1;
                
            
            
            if(solveNQ(n-1)==false)
            {
            return false;
            }
            
            arr[k][l]=0;
            }
            
        }
    }
    
    return true;
    
    
}



int main()
{
   cin>>N;
   
   
  solveNQ(N);
     for(int i=0;i<N;i++)
       {
         for(int j=0;j<N;j++)
           {
           cout<<arr[i][j];
           cout<<" ";
           }
         cout<<"\n";
        }
   
   
   
    return 0;
}
