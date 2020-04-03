#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string.h>
#include <cmath>
#include <sstream>
using namespace std;
class Karatsuba
{
public:
	int length(string &,string &);
	string add(string,string);
	string mul(string,string);
	string DecToBin(long long int);
	string sub(string,string);
	string MakeShift(string,int);
	long long int BinToDec(string);
};
//Function to convert Decimal to Binary
string Karatsuba::DecToBin(long long int num)
{
	string res= "";
	if (num<=0)
	{
		return "0";
	}
	else
	{
		int i=0;
		while (num>0)
		{

			long long int n= num%2;
			stringstream ss;
			ss<<n;
			res=ss.str()+res;
			num=num/2;
			i++;
		}
		return res;
	}
}
//Function to control the lenght of strings
int Karatsuba::length(string &s1,string &s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	if(len1<len2)
	{
		for (int i=0;i<len2-len1;i++)
			s1= '0'+s1;
		return len2;
	}
	else if(len1>len2)
	{
		for (int i=0;i<len1-len2;i++)
			s2='0'+s2;
	}
	return len1;
}
//Function to add two strings
string Karatsuba::add(string str1, string str2)
{
	string res;
	int len=length(str1,str2);
	int carry=0;
	for(int i=len-1;i>=0;i--)
	{
		int firstBit=str1.at(i)-'0';
		int secondBit=str2.at(i)-'0';
		int sum=(firstBit^secondBit^carry)+'0';
		res=(char)sum+res;
		carry=(firstBit&secondBit)|(secondBit&carry)|(firstBit&carry);
	}
	if (carry)
	{
		res='1'+res;
	}
	return res;
}
string Karatsuba::sub(string lft, string rgt)
{

	int len=length(lft,rgt);
	int d;
	string res;
	for(int i=len-1;i>= 0;i--)
	{
		d=(lft[i]-'0')-(rgt[i]-'0');
		if(d >= 0)
		{
			res=DecToBin(d)+res;
		}
		else
		{
			for(int j =i-1;j>=0;j--)
			{
				lft[j]=((lft[j]-'0')-1)%10+'0';
				if (lft[j]!='1')
				{
					break;
				}
			}
			res=DecToBin(d+2)+res;
		}
	}
	return res;
}
//Function to make shifting
string Karatsuba::MakeShift(string str, int step)
{
	string shift=str;
	for(int i = 0;i<step;i++)
		shift=shift+'0';
	return shift;
}
//Multiplication of strings
string Karatsuba::mul(string x, string y)
{
	int n=length(x,y);
	if(n==1)
        	return((y[0]-'0'==1)&&(x[0]-'0' == 1))?"1":"0";
	int fh=n/2;
	int sh=(n-fh);
	string xl=x.substr(0, fh);
	string xr=x.substr(fh, sh);
	string yl=y.substr(0, fh);
	string yr=y.substr(fh, sh);
	string s1=mul(xl, yl);
	string s2=mul(xr, yr);
	string s3=mul(add(xl,xr),add(yl,yr));
	return add(add(MakeShift(s1,2*(n-n/2)),s2),MakeShift(sub(s3,add(s1,s2)),n-(n/2)));
}
//Function to convert Binary to Decimal
long long int Karatsuba::BinToDec(string res)
{
	long long int v=0;
	for(int i=res.length()-1;i>= 0;i--)
	{
		if (res[i]=='1')
		{
			v+=pow(2,(res.length()-1)-i);
		}
	}
	return v;
}
int main(int argc,char *argv[])
{
    long long int a=0,b=0,res;
    if(argc == 2)
   {
	   ifstream fd;
	   int z = 0;
	   fd.open(argv[1]);
	   if(!fd)
	   {
		cout<<"!!Invalid Filename!!\n-->The entered file either does not exist or has no data in it \n";
		exit(1);

	   }
	   do {
		    b = a;
		    a = z;
	      }while(fd >> z);
	   fd.close();
	    Karatsuba obj;
    	    string x=obj.DecToBin(a);
    	    string y=obj.DecToBin(b);
    	    string karatsuba=obj.mul(x,y);
    	    res=obj.BinToDec(karatsuba);
    	    cout<<"Result of multiplication is:"<<res<<endl;
	}
}
