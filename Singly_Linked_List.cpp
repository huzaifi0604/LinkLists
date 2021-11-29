// Muhammad huzaifa
// 20I-0604
// Lab # 05
// Task # 01

#include<iostream>
using namespace std;

class pateint
{
	public:
	char name;			// Pateint class as node class having name as data and np as next pointer
	pateint *n_p;
};

class appointment
{
	public:
	
	pateint *first_pat;		//Declaring head pointer
	
	appointment(){			// List constructor
	first_pat=NULL;}
	
	void append(char pname){
		pateint *curr_pat;		// A curtrent pointer for traversing and adding
		curr_pat=first_pat;
		if(curr_pat==NULL)
		{
			curr_pat=new pateint;
			curr_pat->name=pname;
			curr_pat->n_p=NULL;		// Appending if head == NULL
			first_pat=curr_pat;
		}
		else
		{
			while(curr_pat->n_p!=NULL){
				curr_pat=curr_pat->n_p;
			}
			curr_pat->n_p=new pateint;
			curr_pat->n_p->name=pname;		// Appending if head is not equal to null
			curr_pat->n_p->n_p=NULL;
		}
	}
	void insertatmiddle(int index,char pname)
		{
			pateint *curr;
			curr=first_pat;
			int curr_index=1;			// Inserting a specific char at specific place
			while(curr && curr_index!=index){		
			curr=curr->n_p;	
			curr_index+=1;
			
			}
			pateint *temp=new pateint;
			temp->name=pname;
			temp->n_p=curr->n_p;
			curr->n_p=temp;
		}
		void remove(char pname)
		{
			pateint *prev=NULL;
			pateint *curr=first_pat;
			int index=1;
			while(curr && curr->name!=pname)
			{
				prev=curr;
				curr=curr->n_p;
				index+=1;
			}					// Removing a given char from the list
			if(curr)
			{
				if(prev)
				{
					prev->n_p=curr->n_p;
					delete curr;
				}
				else
				{
					first_pat=curr;
					delete curr;
				}
			
			}
		}
		void replace(char one,char two)
		{
			pateint *curr=first_pat;
			while(curr!=NULL)
			{
				if(curr->name==one)
				{				//Replacing two characters with one another
					curr->name=two;
				}
				curr=curr->n_p;
			}
		}
		bool isempty()
		{
			if(first_pat==NULL)
			return true;
			else
			return false;				// Checking for the empty list
		}
		pateint *split(int index)
		{
			pateint *curr=first_pat;
			for(int i=0;i!=index-1;i++)
			{
				curr=curr->n_p;			// Spliting lists into given index
			}
			pateint* temp=curr->n_p;
			curr->n_p=NULL;
			return temp;
		}
		
		void clear()
		{
			if(first_pat)
			{
				pateint *curr=first_pat;
				while(curr!=NULL)
				{
					pateint *temp=curr;			// Function for clearing link list
					curr=curr->n_p;
					delete temp;
				}
				first_pat=NULL;
			}
		}
		
		void display()
		{
			pateint* i=first_pat;
			while(i){
				cout<<"Pateint name: "<<i->name<<endl;			// Diaplaying function
				i=i->n_p;
			}
		}
		~appointment()
		{
			if(first_pat)
			{
				pateint *curr=first_pat;
				while(curr!=NULL)			// A destructor
				{
					pateint *temp=curr;
					curr=curr->n_p;
					delete temp;
				}
				first_pat=NULL;
			}
		}
};
int main()
{
	// Checking for Functions
	appointment a1;
	a1.append('I');
	a1.append('s');
	a1.append('m');			// Calling append function
	a1.append('a');
	cout<<"---------------------Appending Characters------------------------"<<endl<<endl;
	a1.display();
	a1.insertatmiddle(2,'l');
	a1.insertatmiddle(3,'z');
	cout<<"---------------------Inserting Characters at middle------------------------"<<endl<<endl;
	a1.display();
	a1.remove('l');
	cout<<"---------------------Removing Characters------------------------"<<endl<<endl;
	a1.display();
	cout<<"---------------------Replacing Characters------------------------"<<endl<<endl;
	a1.replace('m','h');
	a1.display();
	cout<<endl;
	cout<<a1.isempty();		// Checking for empty list
	appointment a2;
	cout<<"---------------------Splitting Characters into half------------------------"<<endl<<endl;
	a2.first_pat=a1.split(2);
	cout<<endl;
	a1.display();
	cout<<endl;
	a2.display();
	//a1.clear();
	return 0;
}	