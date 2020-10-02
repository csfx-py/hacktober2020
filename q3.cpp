#include<iostream>
#include<stack>

using namespace std;

int main() {
	stack<int> stack,temp;
	int n,i,a;
	cout<<"Enter size of stack : ";
	cin>>n;
	cout<<"Enter elements \n";
	for(i=0;i<n;i++) {
		cin>>a;
		stack.push(a);
	}
	while(!stack.empty()){
		a=stack.top();
		stack.pop();
		while(!temp.empty() && temp.top()>a){
			stack.push(temp.top());
			temp.pop();
		}
		temp.push(a);
	}
	for(i=0;i<n;i++){
		stack.push(temp.top());
		temp.pop();
	}
	cout<<"Stack after sorting\n";
	for(i=0;i<n;i++){
		cout<<stack.top()<<" ";
		stack.pop();
	}
	return 0;
}
