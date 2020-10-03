#include<iostream>
using namespace std;

struct node{
int data;
node *next;
node *prev;
};
node *head= NULL;
node *tail= NULL;

node* getnewnode(int data){
node *newnode= new node();
newnode->data= data;
newnode->prev=NULL;
newnode->next= NULL;
return newnode;
}

class doubly{
public:

void InsertAthead(int data);
void inssertAttail(int data);
void print();
void reversse();
};




void doubly :: InsertAthead(int data){
    node *newnode= getnewnode(data);
if (head==NULL){
    newnode->next= head;
return;
}
head->prev= newnode;
newnode->next= head;
head= newnode;
}

void doubly:: inssertAttail(int data){
    node *newnode= getnewnode(data);

tail->next= newnode;
newnode->prev=tail;
tail= newnode;
}
void doubly ::print(){
node *temp= head;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<endl;
}

void doubly ::reversse(){
node*temp= tail;
while(temp!=NULL){

    cout<<temp->data<<"->";
    temp=temp->prev;
}
cout<<endl;
}

int main(){
doubly d;
d.InsertAthead(1);
d.InsertAthead(3);
d.InsertAthead(4);
//d.inssertAttail(2);
//d.inssertAttail(8);
d.print();
d.print();
//d.reversse();
//d.reversse();
return 0;
}
