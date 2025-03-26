//START OF THE PROGRAM FOR seminar MANAGEMENT

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//START OF CLASS
class seminar
{
int seat;
char fname[15];
char lname[15];
char address[20];
char phone[15];
char email[20];

public:
void main_menu();		//to dispay the main menu
void add();			//to book a seat
void display(); 		//to display the student record
void rooms();			//to display alloted seats
void edit();			//to edit the student record
int check(int);			//to check seat status
void modify(int);		//to modify the record
void delete_rec(int);		//to delete the record
};
//END OF CLASS

// START OF MENU CLASS
void seminar::main_menu()
{
int choice;
while(choice!=5)
{
  system("cls");
cout<<"\n\t\t\t\t*******************************";
cout<<"\n\t\t\t\t SEMINAR HALL-BOOK MANAGEMENT ";
cout<<"\n\n\t\t\t\t\t* MAIN MENU *";
cout<<"\n\t\t\t\t*******************************";
cout<<"\n\n\n\t\t\t1.Book For Seminar";
cout<<"\n\t\t\t2.Students Records";
cout<<"\n\t\t\t3.Seats Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice:";
cin>>choice;

switch(choice)
{
case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5: break;
default:
{

cout<<"\n\n\t\t\tWrong choice!!";
cout<<"\n\t\t\tPress any key to continue!!";
}
}
}
}
//END OF MENU FUNCTION

//FUNCTION FOR BOOKING OF ROOM
void seminar::add()
{

  system("cls");
int r,flag;
ofstream fout("Record.txt",ios::app);

cout<<"\n Enter Student Details";
cout<<"\n ----------------------";
cout<<"\n\n Seat no:";
cout<<"\n Total no. of Seats - 50";
cout<<"\n Ordinary Seats from 1 - 30";
cout<<"\n Luxuary Seats from 31 - 45";
cout<<"\n Royal Seats from 46 - 50";
cout <<"\n Enter The Seats no. you want to seat in:-"<<endl;
cin>>r;
flag=check(r);

if(flag)
cout<<"\n Sorry!! Seat is already booked";
else if (r>50 || r<1)
{
	cout<<"Invalid Seat Number";
}

else
{
seat=r;
cout<<" Name:";
cin>>fname>>lname;
cout<<" Address:";
cin>>address;
cout<<" Phone No:";
cin>>phone;
cout<<" Email-ID:";
cin>>email;

fout.write((char*)this,sizeof(seminar));
cout<<"\n Seat is booked!!";
}

cout<<"\n Press any key to continue!!";

getch();
fout.close();
}
//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PARTICULAR STUDENT RECORD
void seminar::display()
{

  system("cls");

ifstream fin("Record.txt",ios::in);
int r,flag;
cout<<"\n Enter seat no. for a particular student details :- "<<endl;
cin>>r;

while(!fin.eof())
{
fin.read((char*)this,sizeof(seminar));
if(seat==r)
{
  system("cls");
cout<<"\n Student Details";
cout<<"\n ----------------";
cout<<"\n\n Seat no: "<<seat;
cout<<"\n Name: "<<fname<<" "<<lname;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
cout<<"\n Email-ID: "<<email;

flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Seat no. not found or vacant!!";
cout<<"\n\n Press any key to continue!!";
getch();
fin.close();
}
//END OF DISPLAY FUNCTION


//FUNCTION TO DISPLAY ALL SEATS OCCUPIED
void seminar::rooms()
{
  
  system("cls");
 
ifstream fin("Record.txt",ios::in);
cout<<"\n\t\t\t    List Of Seats Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Seat No.\tName\t\t\t\tAddress\t\t\t\tPhone No.\t\t\t\tEmail\n";
fin.read((char*)this,sizeof(seminar));
while(!fin.eof())
{
cout<<"\n\n "<<seat<<"\t\t"<<fname<<" "<<lname;
cout<<"\t\t\t"<<address<<"\t\t\t\t"<<phone<<"\t\t\t\t"<<email;
fin.read((char*)this,sizeof(seminar));
}
cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();
}

//FUNCTION FOR EDITING RECORDS
void seminar::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Student Record";
cout<<"\n 2.Delete Student Record";
cout<<"\n Enter your choice:";

cin>>choice;
  system("cls");

cout<<"\n Enter Seat no:" ;
cin>>r;

switch(choice)
{

case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;

default: cout<<"\n Wrong Choice!!";
}
cout<<"\n Press any key to continue!!";
getch();
}
int seminar::check(int r)
{
int flag=0;
ifstream fin("Record.txt",ios::in);
while(!fin.eof())
{
  fin.read((char*)this,sizeof(seminar));
if(seat==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}

//FUNCTION TO MODIFY RECORDs
void seminar::modify(int r)
{
long pos,flag=0;
fstream file("Record.txt",ios::in|ios::out);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(seminar));

if(seat==r)
{
cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name:";
cin>>fname>>lname;
cout<<" Address:";
cin>>address;
cout<<" Phone no:";
cin>>phone;
cout<<" Email-ID:";
cin>>email;

file.seekg(pos);
file.write((char*)this,sizeof(seminar));
cout<<"\n Record is modified!!";
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Seat no. not found or vacant!!";
file.close();
}
//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD
void seminar::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.txt",ios::in);
ofstream fout("temp.txt",ios::out);
fin.read((char*)this,sizeof(seminar));
while(!fin.eof())
{
if(seat==r)
{
cout<<"\n Name:"<<fname<<" "<<lname;
cout<<"\n Address:"<<address;
cout<<"\n Phone No:"<<phone;
cout<<"\n Email-ID:"<<email;
cout<<"\n\n Do you want to delete this record(y/n):";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(seminar));
flag=1;
}
else
fout.write((char*)this,sizeof(seminar));
fin.read((char*)this,sizeof(seminar));
}
fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry seat no. not found or vacant!!";
else
{
remove("Record.txt");
rename("temp.txt","Record.txt");
}
}
//END OF DELETE FUNCTION

//START OF MAIN PROGARM
int main()
{

seminar h;
string log="aaaaa";
string pass="aaaaa";
int a=20;
int b=20;
int c;

  system("cls");

again : cout<<"\n\n\n\n\n\t\t\t\t Login ID:";
cin>>log;

cout<<"\n\t\t\t\t Password:";
cin>>pass;

if(log == "oopcj" && pass == "oopcj")
{
 cout<<"\n\n\t\t\t WELCOME YOU SUCCESSFULLY LOGGED IN THE SYSTEM SEMINAR BOOKING!!";
 getch();
system("cls");
}

else
{
    cout<<"\n\n\t\t\t\t Please Try Again!";
    getch();
    system("cls");
    goto again;
}


   system("cls");

cout<<"\n\t\t\t\t\t**************************************";
cout<<"\n\t\t\t\t\t* SEMINAR HALL-BOOK MANAGEMENT PROJECT *";
cout<<"\n\t\t\t\t\t**************************************";
cout<<"\n\n\t\t Made By:";
cout<<"\tRusheil Baath (11), Jatin Garad (05), Vama Shah (06), Ashmi (21)";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue!!";
getch();
h.main_menu();
return 0;
}
//END OF MAIN PROGRAM
