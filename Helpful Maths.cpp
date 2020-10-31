#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>ans;
    string ch;
    cin>>ch;
    for(int i=0; ch[i] != '\0'; i++){
        if(ch[i] != '+'){
            ans.push_back((int)ch[i]-48);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        if(i == ans.size()-1){
            cout<<ans[i];
            return 0;
        }
        cout<<ans[i]<<"+";
    }
    return 0;
}
