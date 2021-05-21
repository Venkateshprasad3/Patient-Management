#include <iostream>
#include <fstream>
#include<string.h>
#include <ctime>
using namespace std;
 
 

class Patient {
public:
    
    char Name[100];
    int Age;
 	int id;
 	char blood_group[100];
 	char date_time[100];
    
    int input();
    int output_data();
    int searchData();
    int editData();
}Emp_1,object;
 
 
 void Display()
 {
 	cout<<endl;
 	cout<<endl<<"Patient ID: "<<Emp_1.id;
   cout<<endl<<"Patient Name: "<<Emp_1.Name;
   
   cout<<endl<<"Patient Age: "<<Emp_1.Age;
   cout<<endl<<"Patient Blood Group: "<<Emp_1.blood_group;
   cout<<endl<<"Date and Time of Arrival: "<<Emp_1.date_time;
   cout<<endl;
   cout<<"_____________________________________";
   cout<<endl;
 }
 
 void searchId()
 {
 	int flag=0;
 	int i;
		cout<<"Enter Id :";
		cin>>i;
		
   ifstream file2;
   file2.open("Input.txt",ios::in);
   file2.seekg(0);
   cout<<"         Patients Details";
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	
   	if(Emp_1.id==i)
	{
		Display();
		flag=1;
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   if(flag==0)
   {
   	cout<<"Sorry there is No Patient Id: "<<i;
   }
 	
 }
 
 void searchName()
 {
 	int flag=0;
 	char i[100];
		cout<<"Enter Patients Name :";
		cin>>i;
		
   ifstream file2;
   file2.open("Input.txt",ios::in);
   file2.seekg(0);
   cout<<"         Patients Details";
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	
   	if(strcmp(i,Emp_1.Name)==0)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   if(flag==0)
   {
   	cout<<"Sorry No patiented name "<<i;
   }
 	
 }


void searchBg()
 {
 	int flag=0;
 	char i[100];
		cout<<"Enter Blood group:";
		cin>>i;
		
   ifstream file2;
   file2.open("Input.txt",ios::in);
   file2.seekg(0);
   cout<<"         Patients Details";
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	
   	if(strcmp(i,Emp_1.blood_group)==0)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   if(flag==0)
   {
   	cout<<"Sorry No patient With Blood Group "<<i;
   }
 	
 }
  
 int findId()
{
	static int val;
	ifstream file2;
   file2.open("Input.txt",ios::in);
   file2.seekg(0);
    while(!file2.eof())
   {
   	val=Emp_1.id;
   	file2.read((char*)&Emp_1,sizeof(Emp_1));
   		
   }
   file2.close();
   return val;
   
}

int Patient::input()
{
	
	
	int val=findId();
   
    time_t now = time(0);
   
   
    ofstream file_obj;
 
    
    file_obj.open("Input.txt", ios::app);
 
    // Object of class Patient to input data in file
    Patient obj;
    
   
   
    char str[100],bg[100];
    int age;
    cout<<endl<<"Enter Patients Name:  ";
    cin>>str;
    cout<<endl<<"Enter Patients Age:  ";
    cin>>age;
    cout<<endl<<"Enter Patients Blood Group:(eg:O+,A1B+,B-)  ";
    cin>>bg;
 	strcpy(obj.Name, str);
 	strcpy(obj.blood_group, bg);
 	strcpy(obj.date_time,ctime(&now) );
   
    obj.Age = age;
    obj.id=val+1;
   // obj.date_time=ctime(&now);
   
    
 
    file_obj.write((char*)&obj, sizeof(obj));
 
    
 
    return 0;
}
 

int Patient::output_data()
{
    
    ifstream file2;
   file2.open("Input.txt",ios::in);
   file2.seekg(0);
   cout<<"      Patient Details  ";
   cout<<endl;
   int p_id=0;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
   while(!file2.eof())
   {
   	
   	

   	Display();
	file2.read((char*)&Emp_1,sizeof(Emp_1));
 
   }
cout<<endl<<endl;
   file2.close();
    return 0;
}
 
 
 
 
 
 
int Patient::searchData()
{
	cout<<"Search using -"<<endl;
	int opt;
	cout<<"1.Id :"<<endl;
	cout<<"2.Patient Name :" <<endl;
	cout<<"3.Blood Group :" <<endl;
	
	cin>>opt;
	switch(opt)
	{
		case 1:
			searchId();
			break;
		case 2:
			searchName();
			break;
		case 3:
			searchBg();
			break;
			
	}
	
	
		
		
	
	
	
} 
 
 
 
 int Patient::editData()
{
}
 
 
 
 
// Driver code
int main()
{
	int option;
    cout<<"                          Patient Management System        ";
    do
    {
	
	cout<<endl<<"Enter Option";
    cout<<endl<<"1. Add Patient information";
    cout<<endl<<"2. Display Patient details ";
    cout<<endl<<"3. Search details ";
    cout<<endl<<"4. Update Patient details ";
    cout<<endl<<"5.Exit";
    cin>>option;
 	switch(option)
 	{
 		case 1:
 			object.input();
 			break;
 		case 2:
 			object.output_data();
 			break;
 		case 3:
 			object.searchData();
 			break;
 		case 4:
 			object.editData();
 			break;
 		
		 	
	}
}while(option!=5);
 	
 	
    return 0;
}
