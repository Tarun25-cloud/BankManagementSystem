#include <iostream>
#include <stdio.h>
using namespace std;

int flag=0,crt=0;

class customer
{
	static customer *top,*p,*prev;
	int accno;
	char name[32],vip, bias;
	float balance;
	customer *next;
	
	public:
	customer()
	{		
		next=NULL;
	}
	
	void entinfo()
	{
		fflush(stdin);
		cout<<"Enter name of customer:";
		gets(name);
		cout<<endl;
		cout<<"Enter current account balance:";
		cin>>balance;
		cout<<endl;
		cout<<"VIP status (y/n):";
		cin>>vip;
		cout<<endl;
		cout<<"Service bias:";
		cin>>bias;
		cout<<endl;
		accno=crt++;
		cout<<"Account number:"<<accno;
		
		fflush(stdin);
	}
	
	
	void modinfo()
	{
		fflush(stdin);
		cout<<"Enter name of customer:";
		gets(name);
		cout<<endl;
		cout<<"Enter current account balance:";
		cin>>balance;
		cout<<endl;
		cout<<"VIP status (y/n):";
		cin>>vip;
		cout<<endl;
		cout<<"Service bias:";
		cin>>bias;
		cout<<endl;
		fflush(stdin);
	}
	
	
	int accnum()
	{
		return accno;
	}
	
	void disinfo()
	{
		cout<<"Name of customer:";
		puts(name);
		cout<<"Current account balance";
		cout<<balance;
		cout<<"\nVIP status:";
		cout<<vip;
		cout<<"\nAccount number:"<<accno<<endl<<endl;
	}
	
	
	void newcust()
	{
			customer *ptr= new customer;
			ptr->entinfo();
			ptr->next=top;
			top=ptr;
	}

	
	void firstcust()
	{
		
			customer *top = new customer;
			top->accno=1;
			p=top;
			top->entinfo();
			top->next=NULL;
		
	}

	void searchcust(int acn)
	{
		flag=0;
		p=top;
		if (acn==1)
		{
			top->disinfo();
			flag=1;
		}
		while (p != NULL)
		{
			if (acn==p->accno)
			{
				p->disinfo();
				flag=1;
				break;
			}
			else p=p->next;
		}
		if (flag==0) cout<<"No account matches number";
	}
	
	
	void modcust(int acn)
	{
		flag=0;
		p=top;
		if (acn==1)
		{
			top->modinfo();
			flag=1;
		}
		while (p != NULL)
		{
			if (acn==p->accno)
			{
				p->modinfo();
				flag=1;
				break;
			}
			else p=p->next;
		}
		if (flag==0) cout<<"No account matches number";
	}
	
	
	void disall()
	{
		p=top;
		
		while (p!=NULL)
		{
			p->disinfo();
			p=p->next;
		}

	}
	
	void deposit()
	{
		float depo;
		cout<<"Enter amount to be deposited:";
		cin>> depo;
		this->balance+=depo;
		cout<< "New balance="<<this->balance;
	}
	
	void withdraw()
	{
		float with;
		cout<<"Enter amount to be withdrawn:";
		cin>> with;
		if (this->vip == 'y' || this->vip == 'Y' )
		{
			this->balance-= (with*1.05);
		}
		else
		{
			this->balance-= (with*1.1);
		}
		cout<<"New balance="<<this->balance;
	}
	
	void cashch(int acn)
	{
		cout<<"\n1.Deposit\n2.Withdraw\n ";
		int flg;
		cin>>flg;
		if (flg == 1)
		{
			flag=0;
			p=top;

			while (p != NULL)
			{
				if (acn==p->accno)
				{
					p->deposit();
					flag=1;
					break;
				}
				else p=p->next;
			}
			
			if (flag==0) cout<<"No account matches number";
		}
		else if (flg==2)
		{
			flag=0;
			p=top;

			while (p != NULL)
			{
				if (acn==p->accno)
				{
					p->withdraw();
					flag=1;
					break;
				}
				else p=p->next;
			}
			
			if (flag==0) cout<<"No account matches number";
		}
		else cout<<"Incorrect choice";	
	}



};

customer* customer::top=NULL;
customer* customer::p=NULL;
customer* customer::prev=NULL;


int main()
{
	
	int s,ex=0,a;
	customer c;
	
	cout<<"Enter details for admin (wont appear in searches)\n";
	c.firstcust();
	while(ex==0)
	{
	
		cout<<"\n\n\n1.Add a new customer\n2.Display details of a cusomer\n3.Modify a customer\n4.Display all customers\n5.Withdraw or depsit cash \n6.Exit\n";
		fflush(stdin);
		cin>>s;
		switch(s)
		{
			case 1: c.newcust();
					break;
					
			case 2: cout<<"\nEnter account number:";
					cin>>a;
					c.searchcust(a);
					break;
					
			case 3: cout<<"\nEnter account number:";
					cin>>a;
					c.modcust(a);
					break;
					
			case 4: c.disall();
					break;
					
			case 5: cout<<"\nEnter account number:";
					cin>>a;
					c.cashch(a);
					break;		
					
			case 6: ex=1;
					break;
					
			default:cout<<"Invalid";
					break;
					
		}
	}
	return 0;
}

