#include <iostream>
#include <fstream>
#include<string.h>
#include <ctime>
using namespace std;

#ifndef FUNCTIONS_H    
#define FUNCTIONS_H


 void bg_finder(int i)
{
	
char blo[15][15] ={"O+ve","O-ve","A+ve","A-ve","B+ve","B-ve","AB+ve","AB-ve"};
cout<<blo[i-1];
 
}



 void p_finder(int i)
{
	
char blo[15][100] ={"General Checkup","Serious illness","Accident","Minor illness","Others"};
cout<<blo[i-1];
 
}

char* upper_case(char *s)//converts character array to upper case
{
	
    for(int i=0;s[i]!='\0';i++)
    {
        s[i]=toupper(s[i]);
    }
   
    return s;
}


int blood()  //getter
{
	int flag=0;
	int bg;
	do
	{
		if(flag==1)
		{
			cout<<"Improper Blood group selection";
		}
	flag=1;
	cout<<"Enter Blood group";
	cout<<endl<<"1. O+ve"<<endl;
	cout<<"2. O-ve"<<endl;
	cout<<"3. A+ve"<<endl;
	cout<<"4. A-ve"<<endl;
	cout<<"5. B+ve"<<endl;
	cout<<"6. B-ve"<<endl;
	cout<<"7. AB+ve"<<endl;
	cout<<"8. AB-ve"<<endl;
	cin>>bg;
}while(bg>8);
	return bg;
	
}


int dept()  //getter
{
	int flag=0;
	int bg;
	do
	{
		if(flag==1)
		{
			cout<<"Improper Purpose selection";
		}
	flag=1;
	cout<<"Purpose of Visit ";
	cout<<endl<<"1. General checkup"<<endl;
	cout<<"2. Serious illness"<<endl;
	cout<<"3. Accident"<<endl;
	cout<<"4. Minor illness"<<endl;
	cout<<"5. Others"<<endl;
	
	cin>>bg;
}while(bg>5);
	return bg;
	
}




#endif
