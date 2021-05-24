#include <iostream>
#include <fstream>
#include<string.h>
#include <ctime>
#include "functions.h"
using namespace std;
static int val;






//Class Patient
class Patient {
public:
    
    char fName[100];     //patient first Name
    char lName[100];	 //patient last name
    int Age;			 //patient age
    int Department;		//department
 	int id;				//Auto incremental Id
 	int is_in;			//in the hospital or discharged
 	int blood_group;	//blood group id
 	char date_time[100];//Admit date time
    char discharge_date[100];//discharge date time
    Patient()				//constructor
    {
    	this->is_in=1;
    	strcpy(this->lName," ");
    	
    	this->Age=0;
    	strcpy(this->discharge_date," ");
    	
	}
	
    int input();
    int output_data(int);
    int searchData(int);
    int editData();
    int setfName();
    int setlName();
    int deleteData(int);
    int deleteDData(int);
    int setBloodgroup();
    int setAge();
    int setAll();
    int patientLeaves();
    
    
}obj,Emp_1,object,it;



 
 

 void Edit( )
 {
 	int op;
 	do{
 	cout<<endl<<" Enter option "<<endl;
 	cout<<"1. First Name"<<endl;
 	cout<<"2. Last Name"<<endl;
 	cout<<"3. Blood group"<<endl;
 	cout<<"4. Age"<<endl;
 	cout<<"5. All"<<endl;
 	cout<<"6. Exit"<<endl;
 		
 	cin>>op;
 		switch(op)
 	{
 		case 1:
		Emp_1.setfName();
		break;
		
		case 2:
		Emp_1.setlName();
		break;
		
		case 3:
		Emp_1.setBloodgroup();
		break;
		
		case 4:
		Emp_1.setAge();
		break;	
		
		case 5:
		Emp_1.setAll();
		break;
		
		
	}
 }while(op!=6);
 
}
 	
	
 	
 void Display()
 {
 	cout<<endl;
 	cout<<endl<<"Patient ID: "<<Emp_1.id;
   cout<<endl<<"Patient Name: "<<Emp_1.fName<<" "<<Emp_1.lName;
   
   cout<<endl<<"Patient Age: "<<Emp_1.Age;
   cout<<endl<<"Patients Blood Group: ";
  	bg_finder(Emp_1.blood_group);
  	  cout<<endl<<"Purpose of Visit: ";
  	p_finder(Emp_1.Department);
	
  
   cout<<endl<<"Date and Time of Arrival: "<<Emp_1.date_time;

   
   cout<<"Present Status: ";
   if(Emp_1.is_in){
   	cout<<"In the Hospital";
   }
   else
   {
   	cout<<"Discharged";
   cout<<endl<<"Date and Time of Discharge: "<<Emp_1.discharge_date;
   }
   	
   cout<<endl;
   cout<<"_____________________________________";
   cout<<endl;
 }
 
 void searchId(int option)
 {
 	int flag=0;
 	int i;
		cout<<"Enter Id :";
		cin>>i;
	if(option ==1 || option ==3)
	{
	
			
   ifstream file2;
   file2.open("Active_patients.dat",ios::in);
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
}


	if(option ==2 || option ==3)
	{
	
			
   ifstream file2;
   file2.open("Discharged_patients.dat",ios::in);
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
}

   if(flag==0)
   {
   	cout<<"Incorrect Patient Id: "<<i;
   }

 	
 }
 
 void searchfName(int option)
 {
 	int flag=0;
 	char i[100];
 	char temp[100];
		cout<<"Enter Patients Name :";
		cin>>i;
		
		
	 cout<<"         Patients Details";
		
   ifstream file2;
   if(option == 1 ||option==3)
   {
   
   file2.open("Active_patients.dat",ios::in);
   file2.seekg(0);
  
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	strcpy(temp,upper_case(i));
   	strcpy(Emp_1.fName,upper_case(Emp_1.fName));
   	if(strcmp(temp,Emp_1.fName)==0)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   file2.close();
	}
	
	
	if(option == 2 ||option ==3)
   {
   	
   
   file2.open("Discharged_patients.dat",ios::in);
   file2.seekg(0);
   
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	strcpy(temp,upper_case(i));
   	strcpy(Emp_1.fName,upper_case(Emp_1.fName));
   	if(strcmp(temp,Emp_1.fName)==0)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   file2.close();
	}
	
	
   if(flag==0)
   {
   	cout<<"Sorry No patient with first name "<<i<<endl;
   }
 	
 }
 
 
 void searchlName(int option)
 {
 	int flag=0;
 	char i[100];
 	char temp[100];
		cout<<"Enter Patients Last Name :";
		cin>>i;
		
		
	 cout<<"         Patients Details";
		
   ifstream file2;
   if(option == 1 ||option==3)
   {
   
   file2.open("Active_patients.dat",ios::in);
   file2.seekg(0);
  
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   		strcpy(temp,upper_case(i));
   	strcpy(Emp_1.lName,upper_case(Emp_1.lName));
   	
   	if(strcmp(temp,Emp_1.lName)==0)
	{
		
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   file2.close();
	}
	
	
	if(option == 2 ||option ==3)
   {
   	
   
   file2.open("Discharged_patients.dat",ios::in);
   file2.seekg(0);
   
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   		strcpy(temp,upper_case(i));
   	strcpy(Emp_1.lName,upper_case(Emp_1.lName));
   	if(strcmp(temp,Emp_1.lName)==0)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   file2.close();
	}
	
	
   if(flag==0)
   {
   	cout<<"Sorry No patient with Last name "<<i<<endl;
   }
 	
 }


void searchBg(int option)
 {
 int flag=0;
 	int i;
	i=blood();
		
   ifstream file2;
   if(option == 1 ||option==3)
   {
   
   file2.open("Active_patients.dat",ios::in);
   file2.seekg(0);
  
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	
   	if(i==Emp_1.blood_group)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   file2.close();
	}
	
	
	if(option == 2 ||option ==3)
   {
   
   file2.open("Discharged_patients.dat",ios::in);
   file2.seekg(0);
   
   cout<<endl;
   file2.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file2.eof())
   {
   	
   	if(i==Emp_1.blood_group)
	{
		flag=1;
		Display();
		   	
	}
	file2.read((char*)&Emp_1,sizeof(Emp_1));	
   }
   file2.close();
	}
	
	
   if(flag==0)
   {
   	cout<<"Sorry No patient with Blood Group "<<i<<endl;
   }
 	
 }
  
 int findId()
{
	
	ifstream file2;
	
   file2.open("Active_patients.dat",ios::in);
   file2.seekg(0);
   file2.read((char*)&Emp_1,sizeof(Emp_1));
    while(!file2.eof())
   {
   	val=Emp_1.id;
   	file2.read((char*)&Emp_1,sizeof(Emp_1));
   		
   }
   file2.close();
   
   int val1=val;
   
     file2.open("Discharged_patients.dat",ios::in);
   file2.seekg(0);
   file2.read((char*)&Emp_1,sizeof(Emp_1));
    while(!file2.eof())
   {
   	val=Emp_1.id;
   	file2.read((char*)&Emp_1,sizeof(Emp_1));
   		
   }
   file2.close();
   int val2=val;
   
   
   val=(val1>val2) ?  val1 :  val2;
   

   return val;
}



int Patient::setfName()
{
	char first[100];
	cout<<"Enter First Name:";
	cin>>first;
	strcpy(this->fName,first);
	
	
	
}

int Patient::setlName()
{
	char last[100];
	cout<<"Enter Last Name:";
	cin>>last;
	
	strcpy(this->lName,last);
	
	
}

int Patient::setBloodgroup()
{
	int blood_group;
	blood_group=blood();
	this->blood_group=blood_group;
	
}

int Patient::setAge()
{
	int Age;
	cout<<"Enter Age :";
	cin>>Age;;
	this->Age=Age;
	
}


int fileTransfer()
{

	int i;
	
	ofstream file2;
	file2.open("Discharged_patients.dat",ios::app);
	fstream file;
	file.open("Active_patients.dat",ios::in);
	file.read((char*)&Emp_1,sizeof(Emp_1));
	while(!file.eof())
	{
		if(Emp_1.is_in==0)
		{
			
			i=Emp_1.id;
			file2.write((char*)&Emp_1,sizeof(Emp_1));
			
		}
		
		file.read((char*)&Emp_1,sizeof(Emp_1));
	}
	file2.close();
	file.close();
	Emp_1.deleteData(i);
	return 0;
}

 int Patient:: patientLeaves()
 {
 	int i,flag=0,flage=0;;
 	cout<<"Enter id :";
	cin>>i;
	
	fstream f;
	f.open("Active_patients.dat",ios::in | ios::app);
	
	while(f.read((char*)&Emp_1,sizeof(Emp_1)))
	{
	
	if(i==Emp_1.id)
	{
		flage=1;
		if(Emp_1.is_in==0)
		{
			
			cout<<" Patient already Discharged"<<endl;
			flag=1;
		}
		else
		{
		time_t now = time(0);	
		strcpy(Emp_1.discharge_date,ctime(&now) );
		Emp_1.is_in=0;
		f.write((char*)&Emp_1,sizeof(Emp_1));
		
		}
		break;
		
	}
	
	}
	f.close();
	if(flag==0 &&flage==1)
	{
	
	Emp_1.deleteData(i);
	cout<<"Patient with ID "<< i <<"  Discharges"<<endl;
	fileTransfer();
	}
	else if(flage==0)
	{
		cout<<endl<<" Incorrect Patient Id";
		
	}
	
	
	
	
	
 	
 }
 

int Patient::setAll()
{
	this->setfName();
	this->setlName();
	this->setAge();
	this->setBloodgroup();
	
	
	
}






int Patient::input()
{
	
	
	int val=findId();
  
    time_t now = time(0);
   
    ofstream file_obj;
 
    
    file_obj.open("Active_patients.dat",ios::app);
 
    // Object of class Patient to input data in file
    
    
   
   
    char str[100];
    char str2[100];
    int bl;
    int age;
    int d;
    cout<<endl<<"Enter Patients Name:  ";
    cin>>str;
    strcpy(obj.fName, str);
    cout<<endl<<"Enter Patients Last Name:  ";
    cin>>str2;
    strcpy(obj.lName, str2);
    
    cout<<endl<<"Enter Patients Age:  ";
    cin>>age;
    bl=blood();
 	d=dept();
 	obj.blood_group=bl;
 	obj.Department=d;
 	strcpy(obj.date_time,ctime(&now) );
   
    obj.Age = age;
    obj.id=val+1;
  
 
    file_obj.write((char*)&obj, sizeof(obj));
   
 
    return 0;
}
 

int Patient::output_data(int option)
{
	
   ifstream file2;
   if(option ==1 || option ==3)
   {
   
   file2.open("Active_patients.dat",ios::in);
   file2.seekg(0);
   
   file2.read((char*)&Emp_1,sizeof(Emp_1));
   while(!file2.eof())
   {
   	
   	

   	Display();
   	
	file2.read((char*)&Emp_1,sizeof(Emp_1));
 
   }
cout<<endl<<endl;
   file2.close();
}


  if(option ==2 || option ==3)
   {
   
   file2.open("Discharged_patients.dat",ios::in);
   file2.seekg(0);
   
   file2.read((char*)&Emp_1,sizeof(Emp_1));
   while(!file2.eof())
   {
   	
   	

   	Display();
   	
	file2.read((char*)&Emp_1,sizeof(Emp_1));
 
   }
cout<<endl<<endl;
   file2.close();
}
    return 0;
}


 
 
 
 
 
 
int Patient::searchData(int option)
{
	cout<<"Search using -"<<endl;
	int opt;
	cout<<"1. Id "<<endl;
	cout<<"2. Patient First Name " <<endl;
	cout<<"3. Patient Last Name " <<endl;
	cout<<"4. Blood Group " <<endl;
	
	cin>>opt;
	switch(opt)
	{
		case 1:
			searchId(option);
			break;
		case 2:
			searchfName(option);
			break;
		case 3:
			searchlName(option);
			break;
		case 4:
			searchBg(option);
			break;
			
	}
	
	
		
		
	
	
	
} 
 
 
 
 
 
int Patient::deleteData(int d)
{
int flag=0,flage=0;

ofstream file2;
file2.open("new.dat",ios::app);
fstream file;
file.open("Active_patients.dat",ios::in);
file.read((char*)&Emp_1,sizeof(Emp_1));
while(!file.eof())
{
	if(d==Emp_1.id)
	{
		flage=1;
	}
	
	if(d!=Emp_1.id || flag==1)
	{
	
		
		file2.write((char*)&Emp_1,sizeof(Emp_1));
			
	}
	else
	{
		flag=1;
	}
	file.read((char*)&Emp_1,sizeof(Emp_1));
}

file2.close();
file.close();

   
if(flage==1)
{

remove("Active_patients.dat");
rename("new.dat","Active_patients.dat");
;
}
else
{
	cout<<"Incorrect Patient Id";
}
}



int Patient::deleteDData(int d)
{
int flag=0,flage=0;

ofstream file2;
file2.open("new.dat",ios::app);
fstream file;
file.open("Discharged_patients.dat",ios::in);
file.read((char*)&Emp_1,sizeof(Emp_1));
while(!file.eof())
{
	if(d==Emp_1.id)
	{
		flage=1;
	}
	
	if(d!=Emp_1.id || flag==1)
	{
	
		
		file2.write((char*)&Emp_1,sizeof(Emp_1));
			
	}
	else
	{
		flag=1;
	}
	file.read((char*)&Emp_1,sizeof(Emp_1));
}

file2.close();
file.close();

   
if(flage==1)
{

remove("Discharged_patients.dat");
rename("new.dat","Discharged_patients.dat");
;
}
else
{
	cout<<"Incorrect Patient Id";
}
}
 
int Patient::editData()
{
	int flag=0;
	int i,pos;
	cout<<"Enter id :";
	cin>>i;
	
	fstream f;
	f.open("Active_patients.dat",ios::in | ios::out |ios::app);
	
	while(f.read((char*)&Emp_1,sizeof(Emp_1)))
	{
	
	if(i==Emp_1.id)
	{
		flag=1;
		Display();
		Edit();	
		f.write((char*)&Emp_1,sizeof(Emp_1));
		break;
	}
	
	}
	f.close();
	if(flag==1)
	{
		deleteData(i);
	}
	else
	{
	
	cout<<"Incorrect Id";
	//Check Inactive
//	fstream f;
//	f.open("Discharged_patients.dat",ios::in | ios::out |ios::app);
//	
//	while(f.read((char*)&Emp_1,sizeof(Emp_1)))
//	{
//	
//	if(i==Emp_1.id)
//	{
//		flag=1;
//		Display();
//		Edit();
//			
//		f.write((char*)&Emp_1,sizeof(Emp_1));
//		break;
//	}
//	
//	}
//	f.close();
//	if(flag==1)
//	{
//		deleteDData(i);
//	}
//	else
//	{
//		cout<<"Incorrect Id";
//		
//	}
//	
	
}
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
    cout<<endl<<"4. Delete details ";
    cout<<endl<<"5. Edit Data";
    cout<<endl<<"6. Patient Exits";
    cout<<endl<<"7. Exit";
    
    cin>>option;
    cout<<endl;
 	switch(option)
 	{
 		case 1:
 			object.input();
 			break;
 		case 2:
 			int o;
 			cout<<endl<<"1. Active Patients "<<endl<<"2. Discharged Patients "<<endl<<"3. ALL patients";
 			cin>>o;
 			
 			cout<<"           Patients Details ";
			object.output_data(o);
 			break;
 		case 3:
 			cout<<endl<<"1. Active Patients "<<endl<<"2. Discharged Patients "<<endl<<"3. ALL patients";
 			cin>>o;
 			object.searchData(o);
 			break;
 		case 4:
 			int d;
 			cout<<"Delete Id";
			cin>>d;
			
 			object.deleteData(d);
 		//	object.deleteDData(d);
 			
 			break;
 		case 5:
 			object.editData();
 			break;
 		case 6:
 			object.patientLeaves();
 			break;
 			
 		
		 	
	}
}while(option!=7);
 	
 	
    return 0;
}
