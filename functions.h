#include <iostream>
#include <fstream>
#include<string.h>
#include <ctime>
using namespace std;

#ifndef FUNCTIONS_H    
#define FUNCTIONS_H


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
	int bg;
	do
	{
	
	cout<<"Enter Blood group";
	cout<<"1. O+ve"<<endl;
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




#endif
