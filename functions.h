#include <iostream>
#include <fstream>
#include<string.h>
#include <ctime>
#include<sstream> 
using namespace std;

#ifndef FUNCTIONS_H    
#define FUNCTIONS_H




int getFields()
{
	int field;
	cout<<"Enter Field";
	char fields[10][100]={ "\n1. Id\n", "2. First Name\n", "3. Last Name\n","4. Age\n","5. Status \n",
							"6. Blood Group\n","7. State\n","8. City\n","9. Mobile Number\n","10. Address\n"			};
	for(int i=0;i<10;i++)
	{
		cout<<fields[i];
	}
	
	cin>>field;
	return field;
}

int typeSearch()
{
	int field;
	cout<<"Enter Type";
	char fields[10][100]={ "\n1. At Begining\n", "2.Contains\n", "3.At End\n","4.Equals\n"	};
	for(int i=0;i<4;i++)
	{
		cout<<fields[i];
	}
	
	cin>>field;
	return field;
}



string return_bg(int i)
{
	string str;
	char blo[15][15] ={"A+ve","A-ve","AB+ve","AB-ve","B+ve","B-ve","O+ve","O-ve"};
	for(int j=0;blo[i-1][j]!='\0';j++)
	{
		str+=blo[i-1][j];
	}
	
	return str;
}

void bg_finder(int i)
{
	string str;
char blo[15][15] ={"A+ve","A-ve","AB+ve","AB-ve","B+ve","B-ve","O+ve","O-ve"};

cout<<blo[i-1];
 
}





 void p_finder(int i)
{
	
char blo[15][100] ={"Accident","General Checkup","Minor illness","Others","Serious illness"};
cout<<blo[i-1];
 
}



string toString(char *s)
{
	string str;
	int size=0;
	for(int i=0;s[i]!='\0';i++)
	{
		size++;
	}
	for(int i=0;i<size;i++)
	{
		str=str+s[i];
	}
	//cout<<str;
	return str;
}

char* upper_case(char *s)//converts character array to upper case
{
	
    for(int i=0;s[i]!='\0';i++)
    {
        s[i]=toupper(s[i]);
    }
   
    return s;
}

string upper_case(string s)//converts character array to upper case
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
	cout<<endl<<"1. A+ve"<<endl;
	cout<<"2. A-ve"<<endl;
	cout<<"3. AB+ve"<<endl;
	cout<<"4. AB-ve"<<endl;
	cout<<"5. B+ve"<<endl;
	cout<<"6. B-ve"<<endl;
	cout<<"7. O+ve"<<endl;
	cout<<"8. O-ve"<<endl;
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
	
	
	cout<<endl<<"1. Accident"<<endl;
	cout<<"2. General checkup"<<endl;
	cout<<"3. Minor illness"<<endl;
	cout<<"4. Others"<<endl;
	cout<<"5. Serious illness"<<endl;
	
	cin>>bg;
}while(bg>5);
	return bg;
	
}




#endif
