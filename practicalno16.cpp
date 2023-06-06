/*. Department maintains a student information. The file contains roll number, name, 
Division and address. Allow user to add, delete information of student. Display 
Information of particular Students. If record of student does not exist an appropriate 
Message is displayed. Use sequential file to maintain the data.*/










#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void insert()
{
	string rn,name,div,add;
	cout<<"\nADDING STUDENT DATA\n";
	fstream f("db.txt",ios::app);
	cout<<"\nENTER STUDENT ROLL NO:\n";
	cin>>rn;
	cout<<"\nENTER STUDENT NAME:\n";
	cin>>name;
	cout<<"\nENTER STUDENT DIV:\n";
	cin>>div;
	cout<<"\nENTER STUDENT ADRESS:\n";
	cin>>add;
	f<<setw(20)<<rn<<setw(20)<<name<<setw(20)<<div<<setw(20)<<add<<endl;
	f.close();
}
void search()
{
	fstream f("db.txt");
	string line,rn;
	cout<<"\nENTER ROLL NO TO SEARCH\n";
	cin>>rn;
	bool found=false;
	while(getline(f,line))
	{
		if(line.find(rn)!=string::npos)
		{
			cout<<"\nSTUDENT DETAILS\n";
			cout<<line<<endl;
			found=true;
			break;
		}
	}
	if(!found)
	{
		cout<<"\nSTUDENT DOESNT EXISTS\n";
	}
	f.close();
}
void del()
{
	fstream f("db.txt");
	string line,rn,filedata;
	cout<<"\nENTER ROLL NO TO DELETE\n";
	cin>>rn;
	
	while(getline(f,line))
	{
		if(line.find(rn)==string::npos)
		{
			filedata+=line;
			filedata+="\n";
			
		}
	}
    fstream f1("db.txt",ios::out);
    f1<<filedata<<endl;
    f1.close();
    cout<<"\nDELETED\n";
}
void display()
{
	fstream f("db.txt");
	string line;
	cout<<"\nPRINTING STUDENT DATA.......\n";
	while(getline(f,line))
	{
		cout<<line<<endl;
	}
	cout<<"\nPRINTING COMPLETED\n";
	f.close();
}
int main()
{
	fstream f("db.txt",ios::out);
	f<<setw(20)<<"ROLL NO"<<setw(20)<<"NAME"<<setw(20)<<"DIV"<<setw(20)<<"ADRESS"<<endl;
	f.close();
	int ch;
	do 
	{
		cout<<"\n1.INPUT\n2.SEARCH\n3.DELETE\n4.DISPLAY\n5.EXIT\nENTER YOUR CHIOCE:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
		    case 2:
				search();
				break;
			case 3:
				del();
				break;
		    case 4:
				display();
				break;
			case 5:
				cout<<"\nPROCCESS ENDED\n";
				break;
		}
		
	}while(ch!=5);
	fstream f1("db.txt",ios::trunc);
	f1.close();
	return 0;
}