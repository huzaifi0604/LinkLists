#include<iostream>
using namespace std;

class employee
{
	public:
	string id;
	string cnic;
	int salary;
	int bonus;
};

class node
{
	public:
	employee data;
	node *next;
	node *prev;
};
class list
{
	public:
	node *head;
	node *tail;
	list()
	{
		head=NULL;
		tail=NULL;
	}
	void insertnode(employee &emp)
	{
		node *newnode=new node;
		newnode->data=emp;
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			newnode->prev=NULL;
		}
		else
		{
			node *current=head;
			while(current->next)
			{
				current=current->next;
			}
			current->next=newnode;
			newnode->prev=current;
			tail=newnode;
		}
		
	}
	void remove(const string empid)
	{
		node *curr=head;
		while(curr && curr->data.id!=empid)
		{
			curr=curr->next;
		}
		if(curr==NULL)
		{
			cout<<"No data Found"<<endl;
		}
		if(curr==head)
		{
			head=curr->next;
			curr->next->prev=head;
			delete curr;
		}
		else if(curr==tail)
		{
			tail=curr->prev;
			curr->prev->next=curr->next;
			curr->next=NULL;
			delete curr;
		}
		else{
		curr->prev->next=curr->next;
		curr->next->prev=curr->prev;
		delete curr;
	}
	}
	void update_salary(int newsal,string empid)
	{
		node *curr=head;
		while(curr && curr->data.id!=empid)
		{
			curr=curr->next;
		}
		if(curr==NULL)
		{
			cout<<"No data Found"<<endl;
		}
		else
		{
			curr->data.salary=newsal;
		}
	}
	
	void update_bonus(int newbonus,string empid)
	{
		node *curr=head;
		while(curr && curr->data.id!=empid)
		{
			curr=curr->next;
		}
		if(curr==NULL)
		{
			cout<<"No data Found"<<endl;
		}
		else
		{
			curr->data.bonus=newbonus;
		}
	}
	void clear()
	{
		node *curr=head;
		node *newone=NULL;
		while(curr)
		{
			newone=curr->next;
			delete curr;
			curr=newone;
		}
		head=NULL;
		tail=NULL;
	}
	bool is_empty()
	{
		if(head==NULL && tail==NULL)
		return true;
		else
		return false;
	}
	void sorting()
	{	
		node *curr=head;
		int index=0;
		while(curr)
		{
			curr=curr->next;
			index+=1;
		}
		cout<<"Size is: "<<index<<endl;
		curr=head;
		for(int i=*head;i< *tail; )
	}
	void display()
	
	{
		node *i=head;
		while(i)
		{
			cout<<"-----------Employee Data----------"<<endl;
			cout<<"ID: "<<i->data.id<<endl;
			cout<<"CNIC: "<<i->data.cnic<<endl;
			cout<<"SALARY: "<<i->data.salary<<endl;
			cout<<"BONUS: "<<i->data.bonus<<endl;
			i=i->next;
		}
		cout<<endl;
	}
};
int main()
{
	list l1;
	employee e1;
	e1.id="ismail";
	e1.cnic="3310243661745";
	e1.salary=20000;
	e1.bonus=5000;
	l1.insertnode(e1);
	l1.display();
	employee e2;
	e2.id="usman";
	e2.cnic="3314683662345";
	e2.salary=10000;
	e2.bonus=5200;
	l1.insertnode(e2);
	l1.display();
	employee e3;
	e3.id="huzaifa";
	e3.cnic="3302684665345";
	e3.salary=15000;
	e3.bonus=5500;
	l1.insertnode(e3);
	l1.display();
	cout<<endl<<endl<<endl;	
	l1.remove("huzaifa");
	l1.display();
	cout<<"\nHuzaifa removed successfully"<<endl;	
	l1.update_salary(10000,"ismail");
	l1.display();
	l1.update_bonus(6000,"usman");
	l1.display();
	if(l1.is_empty()==0)
	{
		cout<<"list is not empty"<<endl;
	}
	else{
		cout<<"List is empty"<<endl;
	}
	cout<<l1.is_empty();
	cout<<endl;
	l1.clear();
	l1.display();
	cout<<endl;
	l1.sorting();
	cout<<endl;
	return 0;
}
