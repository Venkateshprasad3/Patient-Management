#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string.h>
#include <bits/stdc++.h>
#include <ctime>
#include <vector>
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
	
		//Setters
		int setfName();
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
		void Display();
		
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
	    
	    
	    //Sort
	    int sortAndDisplay();
	    
	}patient_object;

	vector<Patient> sorted;  // vector to store and sort objects
	
	
	void getData(int option)
	 {
	 	sorted.clear();
	 	ifstream file_object;
	 	if(option==1 || option==3)
		{
		file_object.open("Active_patients.dat",ios::in);
	
		while(file_object.read((char *)&patient_object,sizeof(patient_object)))
		{
			sorted.push_back(patient_object);
		}
		file_object.close();
		}
		if(option==2 || option==3)
		{
		file_object.open("Discharged_patients.dat",ios::in);
		
		while(file_object.read((char *)&patient_object,sizeof(patient_object)))
		{
			sorted.push_back(patient_object);
		}
		file_object.close();
		}
	 }
	
	void displayVector()
	{
		for(int i=0;i<sorted.size();i++)
		{
			sorted[i].Display();
		}
	}
	
	void displayHeader()
	{
		cout<<"id    "<<"Name    "<<"          Age   "<<"  Purpose     "<<" Blood Group     "<<"Status        ";
		cout<<"     Email      "<<"                 State    "<<"      City   ";
		cout<<"       Address     ";
		cout<<"     Mobile Number ";
		cout<<"     Admit Date and Time ";
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"_____________________________________________________________________________________________________________________________________________________________________________________________________";
		cout<<"\n";
		cout<<"\n";
	}
	
	int findId()    //Auto Increment Id
	{
		int max=0;
		ifstream file_object; //file pointer object 
		int val,val1;//val-max in first file val2-max in second file
	    file_object.open("Active_patients.dat",ios::in);
	    file_object.seekg(0);
	    file_object.read((char*)&patient_object,sizeof(patient_object));
	    while(!file_object.eof())
	    {
	   		val=patient_object.id;
	   		if(val>max)
	   		{
	   			max=val;
		   	}
	   		file_object.read((char*)&patient_object,sizeof(patient_object));
	   		
	    }
	   	file_object.close();
	   
	   
	   
	     file_object.open("Discharged_patients.dat",ios::in);
	   	 file_object.seekg(0);
	     file_object.read((char*)&patient_object,sizeof(patient_object));
	     while(!file_object.eof())
	     {
	   	 val1=patient_object.id;
	   	
	   	 if(val1>max)
	   	 {
	   		max=val1;
		 }
	   	file_object.read((char*)&patient_object,sizeof(patient_object));
	   		
	   }
	   file_object.close();
	   return max;
	}
	
	
	//Setters Definition
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
	

	
	int Patient::setAll()
	{
		this->setfName();
		this->setlName();
		this->setAge();
		this->setBloodgroup();
		
	}
	
	//Display function	
	 void Patient:: Display()
	 {
	 	cout<<this->id<<"     "<<this->first_name<<" "<<this->last_name<<"    "<<this->age<<"    ";
	 	p_finder(this->is_in);
	 	cout<<"     ";
		bg_finder(this->blood_group);
		cout<<"           ";
		if(this->is_in==1){cout<< "In the hospital";}
		else cout<<"Discharged";
		cout<<"     "<<this->mail_id;
		cout<<"        "<<this->state;
		cout<<"      "<<this->city;
		cout<<"       "<<this->address;
		cout<<"        "<<this->mobile_number;
		cout<<"     "<<this->date_time;
		cout<<"\n";
		cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
		cout<<" \n";
	 }
	
	
	
	//Searchers
	 //Search using Id
	

	 string global_input;
	 
	 	void inline_fun(int i,int field)
		{
			string blood;
		switch(field)
		{
			case 1:
    			global_input=to_string(sorted[i].id);
				break;   
			case 2:
    			global_input=toString(sorted[i].first_name);
				break;
			case 3:
    			global_input=toString(sorted[i].last_name);
				break;
			case 4:
    			global_input=to_string(sorted[i].age);
				break;
			case 5:
    			global_input=to_string(sorted[i].is_in);
				break; 	
			case 6:
				global_input=return_bg(sorted[i].blood_group);
				
				break;
			case 7:
    			global_input=toString(sorted[i].state);
				break;
			case 8:
    			global_input=toString(sorted[i].city);
				break;
			case 9:
    			global_input=to_string(sorted[i].mobile_number);
				break;
			case 10:
    			global_input=toString(sorted[i].address);
				break;
    	}
    	}
	 
	//Search using first name 
	void AdvanceSearch(int type,int option,int field)
	 {
	 	
	 	int flag=0,i;
	 	string input;
	 	char temp[100];
		cout<<"Enter Search data :";
		cin>>input;
		getData(option);
		displayHeader();
		
		
    			
		int found;
    
    	switch(type)
    	{
    		case 1:
    			for(i=0;i<sorted.size();i++)
    			{
    			inline_fun(i,field);
    			found = upper_case(global_input).find(upper_case(input));
    			if (found != string::npos)
    			{
        			if(found==0)
        			{
        				flag=1;
            			
            			sorted[i].Display();
            		}
    			}
				}									    				
    			break;
    			
    			case 2:
    			for(i=0;i<sorted.size();i++)
    			{
    			inline_fun(i,field);
    			found = upper_case(global_input).find(upper_case(input));
    			if (found != string::npos)
    			{
        			if(found>=0)
        			{
        				flag=1;
            			
            			sorted[i].Display();
            		}
    			}
				}							    				
    			break;
    			
    			
    			
    			case 3:
    			for(i=0;i<sorted.size();i++)
    			{
    			inline_fun(i,field);
    			found = upper_case(global_input).rfind(upper_case(input));
    			if (found != string::npos)
    			{
    				
        			if((found + input.length() )==global_input.length())
        			{
        				flag=1;
            			sorted[i].Display();
            		}
    			}
				}							    				
    			break;
    			
    			
    			case 4:
    			for(i=0;i<sorted.size();i++)
    			{
    			inline_fun(i,field);
    			found = upper_case(global_input).find(upper_case(input));
    			if (found != string::npos)
    			{
        			if((found )==global_input.length())
        			{
        				flag=1;
            			sorted[i].Display();
            		}
    			}
				}							    				
    			break;
				
		}
	  
		
	   if(flag==0)
	   {
	   		cout<<"Sorry ";
	   }
	 	
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
	 	do
	 	{
	 	op=getEditFields();
	 	
	 	switch(op)
	 	{
	 		case 1:
			setfName();
			break;
			
			case 2:
			setlName();
			break;
			
			case 3:
			setAge();
		
			break;
			
			case 4:
			setBloodgroup();
			break;
			
			case 5:
			setState();

			case 6:
			setCity();
			break;
			
				
			case 7:
			setMobileNumber();
			break;
			
			case 8:
			setAddress();
			break;
			
			case 9:
			setEmail();
			break;
			
			case 10:
			setfName();
			setlName();
			setAge();
			setBloodgroup();
			 setEmail();
	    	setMobileNumber();
	    	setState();
	    	setCity();
	    	setAddress();
			break;
			
			
			
			
				
		}
	} while(op != 11 );
	 
	}

		
	 
	 
	 
	 
	 
	
	int fileTransfer()
	{
	
		int i;
		ofstream file_object;
		file_object.open("Discharged_patients.dat",ios::app);
		fstream file;
		file.open("Active_patients.dat",ios::in);
		file.read((char*)&patient_object,sizeof(patient_object));
		while(!file.eof())
		{
			if(patient_object.is_in==0)
			{
				
				i=patient_object.id;
				file_object.write((char*)&patient_object,sizeof(patient_object));
				
			}
			
			file.read((char*)&patient_object,sizeof(patient_object));
		}
		file_object.close();
		file.close();
		patient_object.deleteData(i);
		return 0;
	}
	
	//Exit
	 int Patient:: patientLeaves()
	 {
	 	int input,flag=0,flage=0;;
	 	cout<<"Enter id :";
		cin>>input;
		
		fstream file_object;
		file_object.open("Active_patients.dat",ios::in | ios::app);
		
		while(file_object.read((char*)&patient_object,sizeof(patient_object)))
		{
		
		if(input==patient_object.id)
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
				file_object.seekp(1);
				file_object.write((char*)&patient_object,sizeof(patient_object));
			}
			break;
			
		}
		
		}
		file_object.close();
		if(flag==0 &&flage==1)
		{
		
			patient_object.deleteData(input);
			cout<<"Patient with ID "<< input <<"  Discharges"<<endl;
			fileTransfer();
		}
		else if(flage==0)
		{
			cout<<endl<<" Incorrect Patient Id";
		}
	 }
	 
	

	
	
	
	//Output read
	int Patient::output_data(int option)
	{
		
	   ifstream file_object;
	   if(option ==1 || option ==3)
	   {
	   		file_object.open("Active_patients.dat",ios::in);
	   		file_object.seekg(0);
	   
	   		file_object.read((char*)&patient_object,sizeof(patient_object));
	   		while(!file_object.eof())
	   		{
	   			patient_object.Display();	
				file_object.read((char*)&patient_object,sizeof(patient_object));
	 
		    }
			cout<<endl<<endl;
	   		file_object.close();
		}
	
	
	  	if(option ==2 || option ==3)
	   	{
	   		file_object.open("Discharged_patients.dat",ios::in);
	   		file_object.seekg(0);
	   		file_object.read((char*)&patient_object,sizeof(patient_object));
	   		while(!file_object.eof())
	   		{
	   			patient_object.Display();
				file_object.read((char*)&patient_object,sizeof(patient_object));
	   		}
			cout<<endl<<endl;
	   		file_object.close();
		}
	    return 0;
	}
	
	
	 
	//Search logic 
	int Patient::searchData(int option)
	{
		int input,type,field;
		field=getFields();
		type=typeSearch();
		
		AdvanceSearch(type,option,field);
		
		
	} 
	 
	 
	 
	 
	 
	int Patient::deleteData(int d)
	{
		int option=1;
		getData(option);
		ofstream file_object;
		file_object.open("Active_patients.dat",ios::out);
		for(int i=0;i<sorted.size();i++)
		{
			if(sorted[i].id==d)
			{
			//sorted[i].Display();
			continue;
			}
			else
			{
				
				file_object.write((char *)&sorted[i],sizeof(patient_object));
			}
		}
		file_object.close();
		
//		int flag=0,flage=0;
//	
//		ofstream file_object;
//		file_object.open("new.dat",ios::app);
//		fstream file;
//		file.open("Active_patients.dat",ios::in);
//		file.read((char*)&patient_object,sizeof(patient_object));
//		while(!file.eof())
//		{
//			if(d==patient_object.id)
//			{
//			flage=1;
//			}
//		
//			if(d!=patient_object.id || flag==1)
//			{	
//				file_object.write((char*)&patient_object,sizeof(patient_object));
//			}
//			else
//			{
//				flag=1;
//			}
//			file.read((char*)&patient_object,sizeof(patient_object));
//		}
//	
//		file_object.close();
//		file.close();
//	
//	   
//		if(flage==1)
//		{	
//			remove("Active_patients.dat");
//			rename("new.dat","Active_patients.dat");
//	
//		}
//		else
//		{
//			cout<<"Incorrect Patient Id";
//		}
	}
	
	
	
	
	int Patient::editData()
	{
		int input;
	int pos;
	cout<<"id :";
	cin>>input;
	fstream f;
	
	
	f.open("Active_patients.dat",ios::in | ios::out );
	f.seekg(0);
	pos = f.tellg();
	while(f.read((char *)&patient_object,sizeof(patient_object)))
	{
		
		if(patient_object.id==input)
		{
			cout<<patient_object.id;
			
			f.seekp(pos);
			//patient_object.age=90;
			patient_object.Edit();
			f.write((char *)&patient_object,sizeof(patient_object));	 	
			break;
		}
		pos = f.tellg();
		
		
	}
	f.close();
	} 
	
	int Patient::oldPatient()
	{
		int input,flag=0;
		int dont_re_enter=0;
		cout<<"Enter Existing Patient Id";
		cin>>input;
		ifstream file_obj;
		file_obj.open("Active_patients.dat",ios::in );
		while(file_obj.read((char*)&patient_object,sizeof(patient_object)))
		{
			if(input==patient_object.id)
			{
				dont_re_enter=1;
				
			}
		}
		file_obj.close();
		
		
		
		if(dont_re_enter==0)
		{
		file_obj.open("Discharged_patients.dat",ios::in );
		while(file_obj.read((char*)&patient_object,sizeof(patient_object)))
		{
			if(input==patient_object.id)
			{			
			flag=1;
			patient_object.setDept();
			patient_object.setTime();
			patient_object.is_in=1;
			file_obj.close();
			break;
			}
					
		}
		if(flag==1)
		{
			ofstream file_obj2;
			file_obj2.open("Active_patients.dat",ios::app);
			file_obj2.write((char*)&patient_object,sizeof(patient_object));
			file_obj2.close();
			cout<<"Patient re-entry successul";
			
		}
		else
		{
			cout<<"No such patient id exists";
		}
		}
		else
		{
			cout<<"Already  in the hospital";
		}
		return 0;
	}
	

	
	
	
	
	
	int Patient :: sortAndDisplay()
	{
		
		ifstream file_object;
		file_object.open("Active_patients.dat",ios::in);
		sorted.clear();
		while(file_object.read((char *)&patient_object,sizeof(patient_object)))
		{
			sorted.push_back(patient_object);
		}
		file_object.close();
		
		int order,field;
		cout<<"\nEnter Order to sort: \n";
		cout<<"1. Ascending Order \n";
		cout<<"2. Decending Order \n";
		cin>>order;
		field=getFields();
		
		
		
		
		switch(field)
		{
			case 1:
			if(order==1)
			{
     			sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.id < rhs.id;
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.id > rhs.id;
   				});
			}
			break;
			
			case 2:
			if(order==1)
			{	
     			sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
				    return upper_case(lhs.first_name)<upper_case(rhs.first_name);
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      			return upper_case(lhs.first_name)>upper_case(rhs.first_name);
   				});
			}
			break;
			
			
			
			case 3:
			if(order==1)
			{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return upper_case(lhs.last_name)<upper_case(rhs.last_name);
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      			return upper_case(lhs.last_name)>upper_case(rhs.last_name);
   				});
			}
			break;
			
			case 4:
			if(order==1)
			{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.age < rhs.age;
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.age > rhs.age;
   				});
			}
			break;
			case 5:
			if(order==1)
			{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.is_in < rhs.is_in;
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return rhs.is_in > rhs.is_in;
   				});
			}
			break;
			
			case 6:
			if(order==1)
			{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.blood_group < rhs.blood_group;
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return rhs.blood_group > rhs.blood_group;
   				});
			}
			break;
			
			
			case 7:
				if(order==1)
				{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return strcmp(lhs.state,rhs.state);
   				});
				}
				else
				{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      			return strcmp(rhs.state,lhs.state);
   				});
				}
				
				break;
				
			case 8:
				if(order==1)
				{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return strcmp(lhs.city,rhs.city);
   				});
				}
				else
				{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      			return strcmp(rhs.city,lhs.city);
   				});
				}
				
				break;
				
			
			
			case 9:
			if(order==1)
			{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.mobile_number < rhs.mobile_number;
   				});
			}
			else
			{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return lhs.mobile_number > rhs.mobile_number;
   				});
			}
			break;
			
			
			case 10:
				if(order==1)
				{
	     		sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      				return strcmp(lhs.address,rhs.address);
   				});
				}
				else
				{
				sort(sorted.begin(), sorted.end(), [](const Patient& lhs, const Patient& rhs) 
				{
      			return strcmp(rhs.address,lhs.address);
   				});
				}
				
			break;
		}
				
		displayVector();
	}
	
	
	// Driver code
	int main()
	{
		int option;
	    cout<<"                          Patient Management System        ";
	    
	    do
	    {
			cout<<endl<<"Enter Option";
		    cout<<endl<<"1. Add  New Patient information";
	   		cout<<endl<<"2. Display Patient details ";
	    	cout<<endl<<"3. Advanced Search details ";
	    	cout<<endl<<"4. Delete details ";
	    	cout<<endl<<"5. Edit Data";
	    	cout<<endl<<"6. Patient Exits";
	  	    cout<<endl<<"7. Existing Patient";
	    	cout<<endl<<"8. Sorting";
	    	cout<<endl<<"9. Exit";
	    
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
	 				displayHeader();
					patient_object.output_data(opt);
	 				break;
	 			case 3:
	 				cout<<endl<<"1. Active Patients "<<endl<<"2. Discharged Patients "<<endl<<"3. ALL patients";
	 				cin>>opt;
	 				patient_object.searchData(opt);
	 				break;
	 			case 4:
	 				int d;
	 				cout<<"Enter Patient Id to be deleted";
					cin>>d;	
	 				patient_object.deleteData(d);
	 				cout<<"Patient ID Removed successfully ";
	 	
	 				break;
	 			case 5:
	 				patient_object.editData();
	 				break;
	 			case 6:
	 				patient_object.patientLeaves();
	 				break;
	 			case 7:
	 				patient_object.oldPatient();
	 				break;
	 			case 8:
	 				patient_object.sortAndDisplay();
	 				break;
	 			
			}
		}	while(option<9);
	 	
	 	
	    return 0;
	}
