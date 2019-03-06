#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
class vehicle
{
private:
int vno;
char name[20];
long int cn;
double ca;
public:
void input()
{
 cout<<"Enter Vehicle Registration Number"<<endl;
 cin>>vno;
 fstream abc;
 abc.open("vehicle.dat",ios::in|ios::binary);
 if(!abc)
 {
 cout<<"No Vehicle Challaned Yet"<<endl;
 getch();
 exit(0);
 }
 vehicle s1;
 int f=0;
 while(abc)
 {
 abc.read((char*)&s1,sizeof(s1));
 if(abc.eof())
 break;
 if(s1.getvno()==vno)
 {
 f=1;
 }
 }
 abc.close();
 if(f==1)
 {
 cout<<"Already Challaned"<<endl;
 cout<<"Use Modify To Change Challan Details"<<endl;
 cout<<"Press Any Key to Continue"<<endl;
 getch();
 }
 else if(f==0)
 {
 cout<<"Enter Person's Name"<<endl;
 gets(name);
 cout<<"Challan Number"<<endl;
 cn=s1.cnvalue();
 cout<<cn<<endl;
 cout<<"Enter Challan Amount"<<endl;
 cin>>ca;
 gotoxy(34,12);
 cout<<"Person Challaned"<<endl;
 gotoxy(30,13);
 cout<<"Press Any key to Continue"<<endl;
 getch();
 clrscr();
 gotoxy(23,12);
 cout<<"Press Any Key to generate Challan Receipt"<<endl;
 getch();
 clrscr();
 int i;
 for(i=13;i<=67;i++)
 {
 gotoxy(i,3);
 cout<<"-";
 }
 for(i=13;i<=67;i++)
 {
 gotoxy(i,23);
 cout<<"-";
 }
 for(i=4;i<=22;i++)
 {
 gotoxy(12,i);
 cout<<"|";
 }
 for(i=4;i<=22;i++)
 {
 gotoxy(68,i);
 cout<<"|";
 }
 gotoxy(15,5);
 cout<<"Vehicle"<<endl;
 gotoxy(15,6);
 cout<<"Registration"<<"               :"<<vno<<endl;
 gotoxy(15,7);
 cout<<"Number"<<endl;
 gotoxy(15,9);
 cout<<"Name"<<"                       :"<<name<<endl;
 gotoxy(15,11);
 cout<<"Challan Number"<<"             :"<<cn<<endl;
 gotoxy(15,13);
 cout<<"Challan Amount"<<"             :"<<ca<<endl;
 gotoxy(20,22);
 cout<<"Issued By:DELHI TRAFFIC POLICE DEPARTMENT"<<endl;
 getch();
 }
}
void output()
{
gotoxy(10,2);
cout<<"Vehicle"<<endl;
gotoxy(7,3);
cout<<"Registration"<<endl;
gotoxy(10,4);
cout<<"Number"<<endl;
gotoxy(12,6);
cout<<vno;
gotoxy(27,2);
cout<<"Name"<<endl;
gotoxy(27,6);
cout<<name;
gotoxy(39,2);
cout<<"Challan Number"<<endl;
gotoxy(46,6);
cout<<cn;
gotoxy(59,2);
cout<<"Challan Amount"<<endl;
gotoxy(65,6);
cout<<ca;
}
void modify()
{
int ch,ch2;
char nname[20];
double nca;
cout<<"Name"<<endl;
cout<<"Press 0 to Retain Same"<<endl;
cout<<"Press 1 to Modify"<<endl;
cin>>ch;
if(ch==0)
{
strcpy(nname,name);
}
else if(ch==1)
{
cout<<"Enter New Name"<<endl;
gets(nname);
}
cout<<"Challan Amount"<<endl;
cout<<"Press 0 to Retain Same"<<endl;
cout<<"Press 1 to modify"<<endl;
cin>>ch2;
if(ch2==0)
{
nca=ca;
}
else if(ch2==1)
{
cout<<"Enter New Challan Amount"<<endl;
cin>>nca;
}
strcpy(name,nname);
ca=nca;
cout<<"Record Modified"<<endl;
getch();
}
int getvno()
{
return vno;
}
long int getcn()
{
return cn;
}
void anotherdisplay()
{
clrscr();
int i;
 for(i=13;i<=67;i++)
 {
 gotoxy(i,3);
 cout<<"-";
 }
 for(i=13;i<=67;i++)
 {
 gotoxy(i,17);
 cout<<"-";
 }
 for(i=4;i<=16;i++)
 {
 gotoxy(12,i);
 cout<<"|";
 }
 for(i=4;i<=16;i++)
 {
 gotoxy(68,i);
 cout<<"|";
 }
 gotoxy(15,5);
 cout<<"Vehicle"<<endl;
 gotoxy(15,6);
 cout<<"Registration"<<"               :"<<vno<<endl;
 gotoxy(15,7);
 cout<<"Number"<<endl;
 gotoxy(15,9);
 cout<<"Name"<<"                       :"<<name<<endl;
 gotoxy(15,11);
 cout<<"Challan Number"<<"             :"<<cn<<endl;
 gotoxy(15,13);
 cout<<"Challan Amount"<<"             :"<<ca<<endl;
 gotoxy(28,16);
 cout<<"Press Any Key to See Next"<<endl;
}
long int cnvalue()
{
fstream abc;
abc.open("vehicle.dat",ios::in|ios::binary);
vehicle s1;
int f=0,c=0;
while(abc)
{
abc.read((char*)&s1,sizeof(s1));
if(abc.eof())
break;
++f;
}
abc.close();
c=f+1;
return c;
}
};
void fun1()
{
char ch;
do
{
fstream abc;
abc.open("vehicle.dat",ios::app|ios::binary);
vehicle s1;
s1.input();
abc.write((char*)&s1,sizeof(s1));
abc.close();
clrscr();
gotoxy(30,12);
cout<<"Do You Want to Enter More"<<endl;
cin>>ch;
clrscr();
}
while(ch=='y'||ch=='Y');
}
void fun2()
{
fstream abc;
abc.open("vehicle.dat",ios::in|ios::binary);
if(!abc)
{
cout<<"No Vehicle Challaned Yet"<<endl;
getch();
exit(0);
}
vehicle s1;
int rn;
cout<<"Enter Vehicle Registration Number You Want to Search"<<endl;
cin>>rn;
clrscr();
int f=0;
while(abc)
{
abc.read((char*)&s1,sizeof(s1));
if(abc.eof())
break;
if(s1.getvno()==rn)
{
f=1;
void fun4();
fun4();
s1.output();
getch();
break;
}
}
if(f==0)
{
cout<<"Vehicle Not Challaned Yet"<<endl;
getch();
}
abc.close();
}
void fun3()
{
int i;
for(i=1;i<=80;i++)
{
gotoxy(i,1);
cout<<"*";
}
for(i=1;i<=80;i++)
{
gotoxy(i,24);
cout<<"*";
}
for(i=1;i<=24;i++)
{
gotoxy(1,i);
cout<<"*";
}
for(i=1;i<=24;i++)
{
gotoxy(80,i);
cout<<"*";
}
for(i=1;i<=24;i++)
{
gotoxy(2,i);
cout<<"*";
}
for(i=1;i<=24;i++)
{
gotoxy(3,i);
cout<<"*";
}
for(i=1;i<=24;i++)
{
gotoxy(79,i);
cout<<"*";
}
for(i=1;i<=24;i++)
{
gotoxy(78,i);
cout<<"*";
}
}
void fun4()
{
int i;
for(i=1;i<=80;i++)
{
gotoxy(i,1);
cout<<"/";
}
for(i=1;i<=80;i++)
{
gotoxy(i,24);
cout<<"/";
}
for(i=1;i<=24;i++)
{
gotoxy(1,i);
cout<<"/";
}
for(i=1;i<=24;i++)
{
gotoxy(80,i);
cout<<"/";
}
for(i=1;i<=24;i++)
{
gotoxy(2,i);
cout<<"/";
}
for(i=1;i<=24;i++)
{
gotoxy(3,i);
cout<<"/";
}
for(i=1;i<=24;i++)
{
gotoxy(79,i);
cout<<"/";
}
for(i=1;i<=24;i++)
{
gotoxy(78,i);
cout<<"/";
}
}
void fun5()
{
clrscr();
fstream abc;
abc.open("vehicle.dat",ios::in|ios::out|ios::binary);
if(!abc)
{
cout<<"No Vehicle Challaned Yet"<<endl;
getch();
exit(0);
}
int vno2,f=0;
long pos=0;
cout<<"Enter Vehicle Registration Number You Want To Modify"<<endl;
cin>>vno2;
clrscr();
vehicle s1;
while(abc)
{
 pos=abc.tellg();
 abc.read((char*)&s1,sizeof(s1));
if(s1.getvno()==vno2)
{
f=1;
s1.output();
getch();
clrscr();
cout<<"Press Any Key To Modify"<<endl;
getch();
clrscr();
s1.modify();
abc.seekg(pos);
abc.write((char*)&s1,sizeof(s1));
break;
}
}
if(f==0)
{
cout<<"Vehicle Not Challaned Yet"<<endl;
getch();
}
abc.close();
}
void fun6()
{
fstream abc;
abc.open("vehicle.dat",ios::in|ios::binary);
if(!abc)
{
cout<<"No Vehicle Challaned Yet"<<endl;
getch();
exit(0);
}
vehicle s1;
int f=0;
while(!abc.eof())
{
if(abc.eof())
break;
f++;
abc.read((char*)&s1,sizeof(s1));
s1.anotherdisplay();
getch();
}
if(f==0)
{
cout<<"No Vehicle Challaned Yet"<<endl;
getch();
}
abc.close();
}
void fun7()
{
ifstream abc;
ofstream cde;
abc.open("vehicle.dat",ios::in|ios::binary);
cde.open("challan.dat",ios::out|ios::binary);
if(!abc)
{
cout<<"No Vehicle Challaned Yet"<<endl;
getch();
exit(0);
}
int rno;
cout<<"Enter Vehicle Registration Number you Want To Pay Challan For"<<endl;
cin>>rno;
clrscr();
vehicle s1;
int f=0;
while(!abc.eof())
{
if(abc.eof())
break;
abc.read((char*)&s1,sizeof(s1));
if(s1.getvno()==rno)
{
++f;
s1.output();
getch();
break;
}
}
if(f==0)
{
clrscr();
cout<<"Vehicle Not Challaned Yet"<<endl;
cout<<"Press Any Key To Go Back to Main Menu"<<endl;
getch();
void main();
main();
}
clrscr();
char ch;
gotoxy(20,12);
cout<<"Press >Y< if challan is paid by Guilty Person"<<endl;
cin>>ch;
if(ch=='y'|ch=='Y')
{
abc.seekg(0);
while(!abc.eof())
{
if(abc.eof())
break;
abc.read((char*)&s1,sizeof(s1));
if(s1.getvno()!=rno)
{
cde.write((char*)&s1,sizeof(s1));
}
}
clrscr();
cout<<"Challan Paid Successfully"<<endl;
cout<<"Press any key to continue"<<endl;
getch();
}
else if(ch!='y'|ch!='Y')
{
abc.seekg(0);
while(!abc.eof())
{
if(abc.eof())
break;
abc.read((char*)&s1,sizeof(s1));
cde.write((char*)&s1,sizeof(s1));
}
clrscr();
cout<<"Challan Not Paid"<<endl;
cout<<"Press Any Key To Continue"<<endl;
getch();
}
abc.close();
cde.close();
remove("vehicle.dat");
rename("challan.dat","vehicle.dat");
}
void main()
{
int ch,ch1;
do
{
clrscr();
void fun3();
fun3();
gotoxy(25,10);
cout<<"Welcome to Delhi Traffic Police"<<endl;
gotoxy(32,11);
cout<<"Challan Management"<<endl;
gotoxy(28,12);
cout<<"Press Any Key To Continue"<<endl;
gotoxy(53,12);
getch();
clrscr();
void fun3();
fun3();
gotoxy(25,10);
cout<<"1.New Challan"<<endl;
gotoxy(25,11);
cout<<"2.Display a Challan Detail"<<endl;
gotoxy(25,12);
cout<<"3.Modify Challan Details"<<endl;
gotoxy(25,13);
cout<<"4.Display All Challan Records"<<endl;
gotoxy(25,14);
cout<<"5.Pay Challan"<<endl;
gotoxy(25,15);
cout<<"6.EXIT"<<endl;
gotoxy(25,16);
cin>>ch;
clrscr();
if(ch==1)
{
clrscr();
cout<<"Enter 1 to Continue"<<endl;
cout<<"Enter Any other key to Go Back To Main Menu"<<endl;
cin>>ch1;
clrscr();
if(ch1==1)
{
void fun1();
fun1();
}
else
{
void main();
main();
}
}
else if(ch==2)
{
clrscr();
cout<<"Enter 1 to Continue"<<endl;
cout<<"Enter Any other key to Go Back To Main Menu"<<endl;
cin>>ch1;
clrscr();
if(ch1==1)
{
void fun2();
fun2();
}
else
{
void main();
main();
}
}
else if(ch==3)
{
clrscr();
cout<<"Enter 1 to Continue"<<endl;
cout<<"Enter Any other key to Go Back To Main Menu"<<endl;
cin>>ch1;
clrscr();
if(ch1==1)
{
void fun5();
fun5();
}
else
{
void main();
main();
}
}
else if(ch==4)
{
clrscr();
cout<<"Enter 1 to Continue"<<endl;
cout<<"Enter Any other key to Go Back To Main Menu"<<endl;
cin>>ch1;
clrscr();
if(ch1==1)
{
void fun6();
fun6();
}
else
{
void main();
main();
}
}
else if(ch==5)
{
clrscr();
cout<<"Enter 1 to Continue"<<endl;
cout<<"Enter Any other key to Go Back To Main Menu"<<endl;
cin>>ch1;
clrscr();
if(ch1==1)
{
void fun7();
fun7();
}
else
{
void main();
main();
}
}
else if(ch==6)
{
exit(0);
}
 else
 {
 gotoxy(29,12);
 cout<<"Please Enter Correct Option"<<endl;
 gotoxy(29,13);
 cout<<"Press Any Key To Try Again"<<endl;
 getch();
 }
}
while(ch!=6);
getch();
}
