#include<bits/stdc++.h>
using namespace std;

//continuously input until enter pressed
int main()
{
	char c;
	string myString;
	while((c=getchar())!='\n')			// 1st way
   		{
        	myString+=c;
    	}
    cout<<myString<<endl;
    
	char str[100];
	scanf(" %[^\n]", str);				// 2nd way
	cout<<str<<endl;
	return 0;
}
