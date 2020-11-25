#include<iostream>
#include<unistd.h>
using namespace std;
const int DefaultSize = 10;
template <class KeyType>
class StackADT
{
	public:
		StackADT(int MaxStackSize = DefaultSize);
	    //Create an empty stack whose maximum size is MaxStackSize

    	bool IsFull();
		//if number of elements in the stack is equal to the maximum size of the stack, return TRUE (1); otherwise, return FALSE (0)

		void push (const KeyType& item);
    	//if IsFull(), then StackFull(); else insert item into the top of the stack.

    	bool IsEmpty();
    	//if number of elements in the stack is equal to 0, return TRUE (1) else return FALSE (0).

    	KeyType pop();
    	//if IsEmpty(), then StackEmpty(); else remove and return the topmost element of the stack

		void TOS();
		//To display TOS element

		void StackEmpty() {cout << "\nStack is empty" << endl;};
		//Stack empty display message

    	void StackFull() {cout << "\nStack is full" << endl;};
		//Stack full display message 

    		void Output();
		//To display the contents of stack
	private:
		int top;
		KeyType *Stack;
		int MaxSize;
};
//Constructor to initialise stack size
template <class KeyType>
StackADT<KeyType>::StackADT (int MaxStackSize) : MaxSize (MaxStackSize)
{
	Stack = new KeyType[MaxSize];
	top = -1;
}
//To check whether the stack is full
template <class KeyType>
inline bool StackADT<KeyType>::IsFull()
{
if(top==MaxSize-1)
 return true;
 return false;
}
//To check whether stack is empty
template <class KeyType>
inline bool StackADT<KeyType>::IsEmpty()
{
 if(top==-1)
  return true;
  return false;
}
//To push item x
template <class KeyType>
void StackADT<KeyType>::push (const KeyType& x)
{
if(IsFull()){StackFull();}
else{top++;
Stack[top]=x;
}
}
//To pop top item from stack
template <class KeyType>
KeyType StackADT<KeyType>::pop ()
{
 if(IsEmpty())
 {StackEmpty();}
 else{
     KeyType x=Stack[top];
     Stack[top]=0;
     top--; return x;
 }
}

//To display element pointed to by Top of Stack (TOS)
template <class KeyType>
void StackADT<KeyType>::TOS()
{
	cout<<Stack[top];
}

//To display the contents of stack
template <class KeyType>
void StackADT<KeyType>::Output()
{
 if(IsEmpty())
  StackEmpty();
  else{
  cout<<"stack:"<<endl;
  for(int i=top;i>=0;i--)
   cout<<Stack[i]<<endl<<"___"<<endl;
}
}
//Function main()
int main()
{
	StackADT <int> s;
	int ch,flag=0;
	while(1)
	{
		cout<<"\n\nSTACK OP MENU";
		cout<<"\n 1. Push \n 2. Pop \n 3. Display TOS \n 4. Display Stack \n 5. Exit\n";
		cout<<"\nEnter your choice\t: ";
		cin  >> ch;
		switch(ch)
		{
			case 1: //To insert an element into the stack
				cout<<"\nEnter the element to be inserted\t: ";
				cin>>ch;
				s.push(ch);
				break;
			case 2: //To delete the top element from the stack
				if(!s.IsEmpty())
                                {
					ch=s.pop();
					cout<<"Element popped is\t: "<<ch<<endl;
                                }
                                else
                                        cout<<"\nStack underflow.. empty to pop\n";
                                break;
			case 3://To display the element pointed out by TOS	
				if(!s.IsEmpty())
				{
					cout<<"The Top of Stack element is\t: ";
					s.TOS();
				}
				else
					cout<<"\nStack underflow.. empty to pop\n";	
				break;
			case 4: //To display the contents of stack
				if(!s.IsEmpty())
                                	s.Output();                                
                                else
                                        cout<<"\nStack underflow.. empty to pop\n";
				break;
			case 5: //To exit
				cout<<"Bye Bye..";
				_exit(0);
			default:
				cout<<"Only options 1 to 5 are valid. Reenter a valid option";
				break;
		} //End of switch
	}//End of While
	return 0;
}//End of main()


