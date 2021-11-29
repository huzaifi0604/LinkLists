/* Muhammad Huzaifa
  20I0604
  Lab # 04
  Task # 01*/
  
#include<iostream>
using namespace std;

const int size=20;

class lists
{
	private:
	int *array;
	int last;				// Declaring Private members
	int current;
	public:
	lists(){
		last=0;
		current=0;
		array=new int[size];
		for(int i=0;i<size;i++)			// Constructor
		{
			array[i]=0;
		}
	}
	// Function for inserting an element
	void insert(int input)
	{
		array[last]=input;			// Inserting element at end
		last++;
	}
	void display()					// Printing array
	{
		cout<<"\nArray: ";
		for(int i=0;i<last;i++)
		{
			cout<<array[i]<<" ";
		}
	}
	void insertatstart(int input)				// Inserting element at start
	{
		for(int i=last;i>=0;i--)
		{
			array[i+1]=array[i];
		}
		array[0]=input;
		last++;
		display();
	}
	void insertatposition(int num,int position)		// Inserting element at certain position
	{
		for(int i=last;i>=position;i--)
		{
			array[i+1]=array[i];
		}
		array[position]=num;
		last++;
		display();
	}
	void remove(int num)					// Removing an element
	{
		int index=0;
		for(int i=0;i<last;i++)
		{
			if(array[i]==num)
			{
				index=i;
				break;
			}
		}
		for(int i=index;i<last;i++)
		{
			array[i]=array[i+1];
		}
		last--;
		display();
	}
	bool isempty()						// Checking for empty list
	{
		if(last==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void replace(int num,int position)			// Replacing certain elements
	{
		int index=-1;
		for(int i=0;i<last;i++)
		{
			if(array[i]==num)
			{
				index=i;
				break;
			}
		}
		if(index!=-1)
		{
			array[index]=position;
		}
		else
		{
			cout<<"Data not Found"<<endl;
		}
		display();
	}
	void clearlist()					// Clearing whole list
	{
		last=0;
		display();
		cout<<"array has been cleared\n";
	}
	void sort()						// Sorting whole array
	{
		int temp;
		for(int i=0;i<last-1;i++)
		{
			for(int j=0;j<last-i-1;j++)
			{
				if(array[j]>array[j+1])
				{
					temp=array[j+1];
					array[j+1]=array[j];
					array[j]=temp;
				}
			}
		}
		cout<<"\nSorted Array\n";
		display();
	}
	int search(int input)					// Searching certain elements from th array
	{
		bool found=false;
		int index=0;
		for(int i=0;i<last;i++)
		{
			if(input==array[i])
			{
				index=i;
				found=true;
				break;
			}
		}
		if(found==false)
			{
				return -1;
			}
			else
			{
				return index;
			}
	}
	bool duplicate()				// Checking for duplicate elementrs in array
	{
		for(int i=0;i<last;i++)
		{
			for(int j=0;j<last;j++)
			{
				if(array[i]==array[j] && i!=j)
				{
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	int index;
	lists obj1;
	cout<<"Inserting elements at the end"<<endl;
	obj1.insert(1);
	obj1.insert(2);				// Inserting elements at end
	obj1.insert(3);
	obj1.display();
	cout<<"\n\nInserting element at start";
	cout<<endl;
	obj1.insertatstart(5);			// Inserting at start
	obj1.insertatstart(11);
	cout<<"\n\nInserting elements at certain position"<<endl;
	obj1.insertatposition(6,2);					// Inserting at position
	cout<<"\n\nRemoving an element"<<endl;
	obj1.remove(3);							//Removing element
	cout<<"\n\nReplacing an element"<<endl;
	obj1.replace(2,7);						// Replacing element
	cout<<"\n\nSorting whole array"<<endl;
	obj1.sort();							// Sorted array
	cout<<"\nS\nearching element from the array"<<endl;
	index=obj1.search(7);						// Searched element
	cout<<"\n\nElement found at index: "<<index<<endl;
	cout<<"\n\nReplacing an element"<<endl;
	obj1.replace(7,6);
	cout<<"\n\nChecking for duplicates after replacing elements"<<endl;
	cout<<endl<<obj1.duplicate()<<endl;					// duplicate elements
	cout<<"\n\nClearing the list"<<endl;
	obj1.clearlist();							// Clearing array
	cout<<"\n\nChecking for Empty list"<<endl;
	cout<<endl<<obj1.isempty()<<endl;					// Checking empty array
	return 0;
}
