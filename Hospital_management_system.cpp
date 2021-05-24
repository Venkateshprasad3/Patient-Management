#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string.h>
#include <ctime>
#include "functions.h"

using namespace std;


	//Contact Details
	class Contact
	{
		public:
		long long mobile_number;
		char address[100];
		char mail_id[100];
		char state[100];
		char city[100];
		
	
		Contact()						//Constructor
		{
			mobile_number=0;
			strcpy(address," ");
			strcpy(mail_id," ");
			strcpy(state," ");
			strcpy(city," ");
		}
		
		//Setters
		void setMobileNumber()
		{
			long long mobile;
			cout<<endl<<"Enter Mobile number: ";
			cin>>mobile;
			this->mobile_number=mobile;
		}
	
		void setAddress()
		{
			char address[100];
			cout<<endl<<"Enter Complete Address: ";
			cin.getline(address,100);
			strcpy(this->address,address); 
		}
	
		void setCity()
		{
			char city[100];
			cout<<endl<<"Enter City: ";
		 	cin.getline(city,100);
		 	strcpy(this->city,city);
		 
		}
	
		void setState()
		{
			char state[100];
			cin.ignore();
			cout<<endl<<"Enter State: ";
		 	cin.getline(state,100);
		 	strcpy(this->state,state);
		 
		}
	
	
		void setEmail()
		{
			char mail_id[100];
			cin.ignore();
			cout<<endl<<"Enter Mail Id: ";
		 	cin.getline(mail_id, 100);
		 	strcpy(this->mail_id,mail_id);
		 
		}
	};




	//Class Patient
	class Patient : public Contact 
	{
	public:
    
    	char first_name[100];     //patient first Name
    	char last_name[100];	 //patient last name
    	int age;			 //patient age
    	int department;		//department
 	int id;				//Auto incremental Id
 	int is_in;			//in the hospital or discharged
	int blood_group;	//blood group id
 	char date_time[100];//Admit date time
    	char discharge_date[100];//discharge date time
    
    
    
    	 Patient()				//constructor
	 {
   		is_in=1;
    		strcpy(this->discharge_date," ");
	 }
	
		//Setters		int setfName();
	    int setlName();
	    int setTime();
	    int setDept();
	    int setAge();
	    int setAll();
	    int setBloodgroup();
		
		//New Patient Details
	    int input();
	    
	    //Printer
		int output_data(int);
		int Display();
		
		//Search
	    int searchData(int);
	    
	    //Edit
	    int editData();
	    int Edit();
	    
	    //Delete
	    int deleteData(int);
	    int deleteDData(int);
	    
		//Entries
	    int patientLeaves();
	    int oldPatient();
	    
	    
	}patient_object;


	int findId()    //Auto Increment Id
	{
		int max=0;
		ifstream file2; //file pointer object 
		int val,val1;//val-max in first file val2-max in second file
	    file2.open("Active_patients.dat",ios::in);
	    file2.seekg(0);
	    file2.read((char*)&patient_object,sizeof(patient_object));
	    while(!file2.eof())
	    {
	   		val=patient_object.id;
	   		if(val>max)
	   		{
	   			max=val;
		   	}
	   		file2.read((char*)&patient_object,sizeof(patient_object));
	   		
	    }
	   	file2.close();
	   
	   
	   
	     file2.open("Discharged_patients.dat",ios::in);
	   	 file2.seekg(0);
	     file2.read((char*)&patient_object,sizeof(patient_object));
	     while(!file2.eof())
	     {
	   	 val1=patient_object.id;
	   	
	   	 if(val1>max)
	   	 {
	   		max=val1;
		 }
	   	file2.read((char*)&patient_object,sizeof(patient_object));
	   		
	   }
	   file2.close();
	   return max;
	}
	
	
	
	//New Patient 
	int Patient::input()
	{
			
		int val=findId();
	    time_t now = time(0); 
	    ofstream file_obj;
	  
	    file_obj.open("Active_patients.dat",ios::out |  ios::app);
	
	   
	   
	    char first_name[100];
	    char last_name[100];
	    int blood_group;
	    int age;
	    int department;
	    cout<<endl<<"Enter Patients First Name:  ";
	    cin>>first_name;
	    strcpy(this->first_name,first_name );
	    cout<<endl<<"Enter Patients Last Name:  ";
	    cin>>last_name;
	    strcpy(this->last_name,last_name);
	    setEmail();
	    setMobileNumber();
	    setState();
	    setCity();
	    setAddress();
	       
	    cout<<endl<<"Enter Patients age:  ";
	    cin>>age;
	    blood_group=blood();
	 	department=dept();
	 	this->blood_group=blood_group;
	 	this->department=department;
	 	strcpy(this->date_time,ctime(&now) );
	   
	    this->age = age;
	    this->is_in=1;
	    this->id=val+1;
	    file_obj.write((char*)&patient_object, sizeof(patient_object));
	    
	    return 0;
	}
	
	
	
	 
	 
	//Edit Functions
	 int Patient :: Edit()
	 {
	 	int op;
	 	do{
	 	cout<<endl<<" Enter option "<<endl;
	 	cout<<"1. First Name"<<endl;
	 	cout<<"2. Last Name"<<endl;
	 	cout<<"3. Blood group"<<endl;
	 	cout<<"4. Age"<<endl;
	 	cout<<"5. Contact details"<<endl;
	 	cout<<"6. All"<<endl;
	 	cout<<"7. Exit";
	 		
	 	cin>>op;
	 		switch(op)
	 	{
	 		case 1:
			setfName();
			break;
			
			case 2:
			setlName();
			break;
			
			case 3:
			setBloodgroup();
			break;
			
			case 4:
			setAge();
			break;
				
			case 5:
				setEmail();
			setMobileNumber();
			
			setState();
			setCity();
			setAddress();
			break;
			
				
			case 6:
			setAll();
			break;
			
			
		}
	 }while(op!=7);
	 
	}
	 	
		
	 //Display function	
	 int Patient:: Display()
	 {
	 	cout<<"________________________________________________________________________";
	 	cout<<endl<<"---------------------------------------------------------";
	   	cout<<endl<<"     	  Patient Details\n";
	   	cout<<"---------------------------------------------------------";
	 	cout<<endl<<"\tPatient ID: "<<this->id;
	   	cout<<endl<<"\tPatient Name: "<<this->first_name<<" "<<this->last_name;
	   	cout<<endl<<"\tPatient age: "<<this->age;
	   	cout<<endl<<"\tPatients Blood Group: ";
	  	bg_finder(this->blood_group);
	  	
	  	cout<<endl<<"\tPurpose of Visit: ";
	  	p_finder(this->department);
		
	  
	   cout<<endl<<"\tDate and Time of Arrival: "<<this->date_time;
	
	   
	   cout<<"\tPresent Status: ";
	   
	   if(this->is_in==1){
	   	cout<<"In the Hospital";
	   }
	   else
	   {
	   	cout<<"Discharged";
	   cout<<endl<<"\tDate and Time of Discharge: "<<this->discharge_date;
	   }
	   	cout<<endl<<"---------------------------------------------------------";
	   	cout<<endl<<"       		 Contact Details\n";
	   	cout<<"---------------------------------------------------------";
	    cout<<endl<<"\tMobile Number: "<<this->mobile_number;
	   	cout<<endl<<"\tEmail: "<<this->mail_id;
	   	cout<<endl<<"\tAddress: "<<this->address;
	    cout<<endl<<"\tState : "<<this->state;
	    cout<<endl<<"\tCity : "<<this->city;
	    cout<<endl<<"--------------------------------------------------------";
	   
	   cout<<"\n________________________________________________________________________";
	   	
	   cout<<endl;
	   
	   cout<<endl;
	   return 0;
	 }
	 
	 
	 
	 
	 
	 //Search using Id
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
	   file2.read((char*)&patient_object,sizeof(patient_object));
		while(!file2.eof())
	   {
	   	
	   	if(patient_object.id==i)
		{
			patient_object.Display();
			flag=1;
			   	
		}
		file2.read((char*)&patient_object,sizeof(patient_object));	
	   }
	}
	
	
		if(option ==2 || option ==3)
		{
		
				
	   ifstream file2;
	   file2.open("Discharged_patients.dat",ios::in);
	   file2.seekg(0);
	   cout<<"         Patients Details";
	   cout<<endl;
	   file2.read((char*)&patient_object,sizeof(patient_object));
		while(!file2.eof())
	   {
	   	
	   	if(patient_object.id==i)
		{
			patient_object.Display();
			flag=1;
			   	
		}
		file2.read((char*)&patient_object,sizeof(patient_object));	
	   }
	}
	
	   if(flag==0)
	   {
	   	cout<<"Incorrect Patient Id: "<<i;
	   }
	 	
	 }
	 
	 
	 
	 
	//Search using first name 
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
	   file2.read((char*)&patient_object,sizeof(patient_object));
		while(!file2.eof())
	   {
	   	strcpy(temp,upper_case(i));
	   	strcpy(patient_object.first_name,upper_case(patient_object.first_name));
	   	if(strcmp(temp,patient_object.first_name)==0)
		{
			flag=1;
			patient_object.Display();
			   	
		}
		file2.read((char*)&patient_object,sizeof(patient_object));	
	   }
	   file2.close();
	   }
		
		
		if(option == 2 ||option ==3)
	   	{
	   	
	   
	   	file2.open("Discharged_patients.dat",ios::in);
	   	file2.seekg(0);
	   
	   	cout<<endl;
	   	file2.read((char*)&patient_object,sizeof(patient_object));
		while(!file2.eof())
		{
	   		strcpy(temp,upper_case(i));
	   		strcpy(patient_object.first_name,upper_case(patient_object.first_name));
	   		if(strcmp(temp,patient_object.first_name)==0)
			{
				flag=1;
				patient_object.Display();
			}
			file2.read((char*)&patient_object,sizeof(patient_object));	
	   	}
	   	file2.close();
		}
		
		
	   if(flag==0)
	   {
	   		cout<<"Sorry No patient with first name "<<i<<endl;
	   }
	 	
	}
	 
	int Patient::setTime()
	{ 	
	 	time_t now = time(0);
	 	strcpy(this->date_time,ctime(&now) );	 	
    }
	 
	int Patient::setDept()
	{ 	
	 	int d=dept();
	 	this->department=d; 		
	}
	 
	 
	void searchlName(int option)
	{
	 	int flag=0;
	 	char name[100];
	 	char temp[100];
		cout<<"Enter Patients Last Name :";
		cin>>name;
				
		cout<<"         Patients Details";
			
	   	ifstream file2;
	   	if(option == 1 ||option==3)
	   	{
	  		file2.open("Active_patients.dat",ios::in);
	   		file2.seekg(0);
	  
		    cout<<endl;
	   		file2.read((char*)&patient_object,sizeof(patient_object));
			while(!file2.eof())
	   		{
	   			strcpy(temp,upper_case(name));
	   			strcpy(patient_object.last_name,upper_case(patient_object.last_name));
	   			if(strcmp(temp,patient_object.last_name)==0)
				{	
					flag=1;
					patient_object.Display();
			   	
				}
			file2.read((char*)&patient_object,sizeof(patient_object));	
	   		}
	   		file2.close();
		}
			
		if(option == 2 ||option ==3)
	   	{
	   		file2.open("Discharged_patients.dat",ios::in);
	   		file2.seekg(0); 
	   		cout<<endl;
	   		file2.read((char*)&patient_object,sizeof(patient_object));
			while(!file2.eof())
	   		{
	   			strcpy(temp,upper_case(name));
	   			strcpy(patient_object.last_name,upper_case(patient_object.last_name));
	   			if(strcmp(temp,patient_object.last_name)==0)
				{
				flag=1;
				patient_object.Display();
				}
				file2.read((char*)&patient_object,sizeof(patient_object));	
	   		}
	   		file2.close();
		}
		
	   if(flag==0)
	   {
	   	cout<<"Sorry No patient with Last name "<<name<<endl;
	   }
	 	
	 }
	
	
	void searchBg(int option)
	{
		int flag=0;
	 	int input; //stores input for blood group
		input=blood();
			
	   	ifstream file2;
	   	if(option == 1 ||option==3)
	   	{
	   	file2.open("Active_patients.dat",ios::in);
	   	file2.seekg(0);
	   	cout<<endl;
	   	file2.read((char*)&patient_object,sizeof(patient_object));
		while(!file2.eof())
		{
	   		if(input==patient_object.blood_group)
			{
				flag=1;
				patient_object.Display();
			   	
			}
			file2.read((char*)&patient_object,sizeof(patient_object));	
	   	}
		   	file2.close();
		}
		
		
		if(option == 2 ||option ==3)
	   	{
	   		file2.open("Discharged_patients.dat",ios::in);
	   		file2.seekg(0);
	   		cout<<endl;
	   		file2.read((char*)&patient_object,sizeof(patient_object));
			while(!file2.eof())
	  		{
		   	if(input==patient_object.blood_group)
			{
				flag=1;
				patient_object.Display();		   	
			}
			file2.read((char*)&patient_object,sizeof(patient_object));	
	   		}
	   		file2.close();
		}
		
		
	   if(flag==0)
	   {
	   	cout<<"Sorry No patient with Blood Group "<<input<<endl;
	   }
	 	
	 }
	  
	 
	
	int Patient::setfName()
	{
		char first[100];
		cout<<"Enter First Name:";
		cin>>first;
		strcpy(this->first_name,first);	
	}
	
	int Patient::setlName()
	{
		char last[100];
		cout<<"Enter Last Name:";
		cin>>last;
		strcpy(this->last_name,last);
	}
	
	int Patient::setBloodgroup()
	{
		int blood_group;
		blood_group=blood();
		this->blood_group=blood_group;
		
	}
	
	int Patient::setAge()
	{
		int age;
		cout<<"Enter age :";
		cin>>age;;
		this->age=age;
		
	}
	
	
	int fileTransfer()
	{
	
		int i;
		ofstream file2;
		file2.open("Discharged_patients.dat",ios::app);
		fstream file;
		file.open("Active_patients.dat",ios::in);
		file.read((char*)&patient_object,sizeof(patient_object));
		while(!file.eof())
		{
			if(patient_object.is_in==0)
			{
				
				i=patient_object.id;
				file2.write((char*)&patient_object,sizeof(patient_object));
				
			}
			
			file.read((char*)&patient_object,sizeof(patient_object));
		}
		file2.close();
		file.close();
		patient_object.deleteData(i);
		return 0;
	}
	
	//Exit
	 int Patient:: patientLeaves()
	 {
	 	int i,flag=0,flage=0;;
	 	cout<<"Enter id :";
		cin>>i;
		
		fstream f;
		f.open("Active_patients.dat",ios::in | ios::app);
		
		while(f.read((char*)&patient_object,sizeof(patient_object)))
		{
		
		if(i==patient_object.id)
		{
			flage=1;
			if(patient_object.is_in==0)
			{	
				cout<<" Patient already Discharged"<<endl;
				flag=1;
			}
			else
			{
				time_t now = time(0);	
				strcpy(patient_object.discharge_date,ctime(&now) );
				patient_object.is_in=0;
				f.seekp(1);
				f.write((char*)&patient_object,sizeof(patient_object));
			}
			break;
			
		}
		
		}
		f.close();
		if(flag==0 &&flage==1)
		{
		
			patient_object.deleteData(i);
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
	
	
	
	//Output read
	int Patient::output_data(int option)
	{
		
	   ifstream file2;
	   if(option ==1 || option ==3)
	   {
	   		file2.open("Active_patients.dat",ios::in);
	   		file2.seekg(0);
	   
	   		file2.read((char*)&patient_object,sizeof(patient_object));
	   		while(!file2.eof())
	   		{
	   			patient_object.Display();	
				file2.read((char*)&patient_object,sizeof(patient_object));
	 
		    }
			cout<<endl<<endl;
	   		file2.close();
		}
	
	
	  	if(option ==2 || option ==3)
	   	{
	   		file2.open("Discharged_patients.dat",ios::in);
	   		file2.seekg(0);
	   		file2.read((char*)&patient_object,sizeof(patient_object));
	   		while(!file2.eof())
	   		{
	   			patient_object.Display();
				file2.read((char*)&patient_object,sizeof(patient_object));
	   		}
			cout<<endl<<endl;
	   		file2.close();
		}
	    return 0;
	}
	
	
	 
	//Search logic 
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
		file.read((char*)&patient_object,sizeof(patient_object));
		while(!file.eof())
		{
			if(d==patient_object.id)
			{
			flage=1;
			}
		
			if(d!=patient_object.id || flag==1)
			{	
				file2.write((char*)&patient_object,sizeof(patient_object));
			}
			else
			{
				flag=1;
			}
			file.read((char*)&patient_object,sizeof(patient_object));
		}
	
		file2.close();
		file.close();
	
	   
		if(flage==1)
		{	
			remove("Active_patients.dat");
			rename("new.dat","Active_patients.dat");
	
		}
		else
		{
			cout<<"Incorrect Patient Id";
		}
	}
	
	
	
	
	int Patient::editData()
	{
		int flag=0;
		int input;
		cout<<"Enter id :";
		cin>>input;
		
	    fstream f;
		f.open("Active_patients.dat",ios::in |ios ::app);
	
		while(f.read((char*)&patient_object,sizeof(patient_object)))
		{
			if(input==patient_object.id)
			{
				patient_object.Display();
				f.seekp(1);
				
				patient_object.Edit();
				flag=1;	
				f.write((char*)&patient_object,sizeof(patient_object));
				f.close();
				patient_object.deleteData(input);
				break;
			}
		
		}		
		
	} 
	
	int Patient::oldPatient()
	{
		int i,flag=0;;
		cout<<"Enter Existing Patient Id";
		cin>>i;
		
		fstream f;
		f.open("Discharged_patients.dat",ios::in | ios::out |ios::app);
		while(f.read((char*)&patient_object,sizeof(patient_object)))
		{
			if(i==patient_object.id)
			{
				
				
			flag=1;
			patient_object.setDept();
			patient_object.setTime();
			patient_object.is_in=1;
			f.close();
			break;
			}
					
		}
		if(flag==1)
		{
			fstream f2;
			f.open("Active_patients.dat",ios::app);
			f2.seekg(0);
			
			f2.write((char*)&patient_object,sizeof(patient_object));
			f2.close();
			cout<<"Done";
			
		}
		
		return 0;
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
	  		//  cout<<endl<<"7. Existing Patient";
	    	cout<<endl<<"7. Exit";
	    
	    	cin>>option;
	    	cout<<endl;
	 		switch(option)
	 		{
	 			case 1:
	 				patient_object.input();
	 				break;
	 			case 2:
	 				int opt;
	 				cout<<endl<<"1. Active Patients "<<endl<<"2. Discharged Patients "<<endl<<"3. ALL patients";
	 				cin>>opt;	
	 				system("cls");
					patient_object.output_data(opt);
	 				break;
	 			case 3:
	 				cout<<endl<<"1. Active Patients "<<endl<<"2. Discharged Patients "<<endl<<"3. ALL patients";
	 				cin>>opt;
	 				patient_object.searchData(opt);
	 				break;
	 			case 4:
	 				int d;
	 				cout<<"Delete Id";
					cin>>d;	
	 				patient_object.deleteData(d);
	 	
	 				break;
	 			case 5:
	 				patient_object.editData();
	 				break;
	 			case 6:
	 				patient_object.patientLeaves();
	 				break;
	 			case 7:
	 				//object.oldPatient();
	 				break;
	 			
			}
		}	while(option<7);
	 	
	 	
	    return 0;
	}
