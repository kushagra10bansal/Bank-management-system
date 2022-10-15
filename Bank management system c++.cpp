
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string.h>

using namespace std;

int verifypass(string s){
	string pass;
	cin>>pass;
	if (pass.compare(s) == 0) {
		return 1;
	}
	else 
	{ 
		return 0;
	}
}

void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

class DebitCard {
	int cardno;
	int cvv;
	
	public:
	DebitCard() {
		cardno = -1;
		cvv = -1;
	}
	
	void adddebcard() {
		cout<<"Enter Debit card number: ";
		cin>>cardno;
		cout<<"Enter cvv: ";
		cin>>cvv;
	}
	
	friend ostream & operator<<(ostream &out, const DebitCard &d1);
	
};

ostream & operator<<(ostream &out, const DebitCard &d1) {
	
	if (d1.cardno == -1)
	{
		out<<"No Debit Card";
	}
	else
	{
		out<<d1.cardno;
	}
	return out;
}

class account
{
	
	int acno;
	char name[50];
	int deposit;
	char type;
	DebitCard d1;
	
public:
	
	void create_account();
	void show_account();
	void modify();
	void dep(int);
	void draw(int);
	void report();
	int retacno();
	int retdeposit();
	char rettype();
	void getDebitCard();
	
};

void account::create_account()
{
	
	system("CLS");
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
	
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	
	type=toupper(type);
	
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";
}

void account::show_account() 
{
	
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
	cout<<"\n\t\t\tDebit Card number : ";
	cout<<d1;
	
}


void account::modify()
{
	
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	
	type=toupper(type);
	
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() 
{
	
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<" "<<deposit<<"\t";
	cout<<d1;
	cout<<endl;
	
}

int account::retacno() 
{
	return acno;
}

int account::retdeposit() 
{
	return deposit;
}

char account::rettype()
{
	return type;
}

void account::getDebitCard()
{
	d1.adddebcard();
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void addDebCard(int);

int main()
{
	system("CLS");
	char ch;
	int num;
	int choice;
	string pass = "Password";
	
	cout<<"Enter password to continue: ";
	
	if (verifypass(pass) == 0) {
		cout<<"Wrong Password\nTry Again? (Press 0 to exit:)\n";
		cin>>choice;
		if (choice==1){
			delay(100000000);
			main();
			return 0;
		}
		else{
			system("CLS");
		 	cout<<"This Project was made by Dhruv, Kushagra and Sarthak\n";
		 	for (int i=0; i<100; i++){
		 		cout<<".";
		 		delay(10000000);
			}
			return 0;
		}
	}
	else{
		cout<<"Entering System\n";
		
		delay(100000000);
		
	}
	do
	{
	system("cls");
    system("color 2");
	cout<<"\n\n\t\t\tBANK RECORD SYSTEM";
    cout<<"\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME "
		<<"TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";

		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t8. ADD DEBIT CARD	";
		cout<<"\n\t\t\t\t9. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-9): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account();
			break;
			
		case '2':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
			
		case '3':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
			
		case '4':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
			
		case '5':
			display_all();
			break;
			
		case '6':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
			
		 case '7':
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		
		case '8':
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			addDebCard(num);
			break;
			
		case '9':
		 	system("CLS");
		 	cout<<"This Project was made by Dhruv, Kushagra and Sarthak\n";
		 	
		 	for (int i=0; i<100; i++){
		 		cout<<".";
		 		delay(10000000);
			}
			
			break;
			
		 default :cout<<"\a";
		 
		}
		cin.ignore();
		cin.get();
		
    }
	while(ch!='9');
	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	cout<<"\n\t\t\tBALANCE DETAILS\n";
	
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}



void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); 
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		    
		  }
	}
	
	
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}



void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("account.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	
    inFile.close();
	outFile.close();
	
	remove("account.dat");
	rename("Temp.dat","account.dat");
	
	cout<<"\n\nRecord Deleted ..";
}


void display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance    Debit Card\n";
	cout<<"====================================================\n";
	
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	
    File.open("account.dat", ios::binary|ios::in|ios::out);
    
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		
		if(ac.retacno()==n)
		{
			ac.show_account();
			
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSIT AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				
				ac.dep(amt);
			}
			
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficient balance";
				else
					ac.draw(amt);
		      }
		      
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
    
    if(found==false) cout<<"\n\n\t\t\tRecord Not Found ";
}

void addDebCard(int n) {
	bool found=false;
	account ac;
	fstream File;
	
    File.open("account.dat", ios::binary|ios::in|ios::out);
    
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		
		if(ac.retacno()==n)
		{
			ac.getDebitCard();     
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\tDebit Card Added";
			found=true;
	       }
         }
    File.close();
    
    if(found==false) cout<<"\n\n\t\t\tRecord Not Found ";
}

