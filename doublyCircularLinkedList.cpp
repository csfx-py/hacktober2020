#include<iostream>
using namespace std;

class node
{
public:
	int value;
	node* next;
	node* prev;
};

class dcll
{
	node* head, *temp1;
	public:
		node* create(int);//create
		void insertAtBeg();//insert at beg
		//delete
		void disp();//display
		dcll()
		{
			head = NULL;
		}
};

node* dcll::create(int value)
{
	node* temp;
	temp = new node;
	temp->value = value;
	if(temp==NULL)
	{
		cout<<endl<<"Memory not allocated!";
		return 0;
	}
	else
	{
		temp->next = NULL;
		temp->prev = NULL;
	}
	return temp;
}

void dcll::insertAtBeg()
{
	node* temp;
	int value;
	cout<<endl<<"Enter the value: ";
	cin>>value;
	temp = create(value);
	if(head == NULL)
	{
		head = temp;
		temp->next = head;
		temp->prev = head;
		temp1 = head;
	}
	else
	{
		temp->prev = temp1;
		temp->next = head;
		temp1->next = temp;
		head->prev = temp;
		temp1 = temp;
	}
}

void dcll::disp()
{
	if(head == NULL)
	{
		cout<<endl<<"List is empty";
		return;
	}
	node* s;
	s = head;
	while(s->next!=head)
	{
		cout<<s->value<<" ";
		s = s->next;
	}
	cout<<s->value<<" ";
	
	
}

int main()
{
	int choice, choice2;
	dcll dcl;
	while(1)
	{
		cout<<endl<<"Welcome";
		cout<<endl<<"Choose one of the following options: ";
		cout<<endl<<"1. Insert at beginning";
		cout<<endl<<"2. Display";
		// cout<<endl<<"2. Insert at position";
		// cout<<endl<<"3. Insert at end";
		// cout<<endl<<"4. Display";
		// cout<<endl<<"5. Update a value";
		// cout<<endl<<"6. Delete a value";
		// cout<<endl<<"7. Reverse the list";
		// cout<<endl<<"8. Search for a value";
		// cout<<endl<<"9. Sort the list";
		cout<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:
				dcl.insertAtBeg();
				break;

			case 2:
				dcl.disp();
			// 	cl.insertAtPos();
			// 	break;

			// case 3:
			// 	cl.insertAtEnd();
			// 	break;

			// case 4:
			// 	cl.display();
			// 	break;

			// case 5:
			// 	cl.update();
			// 	break;

			// case 6:
			// 	cl.del();
			// 	break;

			// case 7:
			// 	cl.reverse();
			// 	break;

			// case 8:
			// 	cl.search();
			// 	break;

			// case 9:
			// 	cl.sort();
			// 	break;
		}
		cout<<endl<<"Do you want to continue? (1 for yes) ";
		cin>>choice2;
		if(choice2 != 1)
			break;
	};
	return 0;
}