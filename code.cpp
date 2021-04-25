#include <iostream> 
#include <string>
#include<bits/stdc++.h>
using namespace std; 
#include<bits/stdc++.h> 
#include<string.h>
using namespace std; 
string divide(string num1)
{int carry= 0;
for(int i=0;i<num1.length();i++)
    {
    num1[i]= (num1[i]-'0') + carry + '0';
    if((num1[i]-'0')%2==1)
	carry= 10;
    else carry= 0;
    num1[i]= ((num1[i]-'0')/2)+'0';
    }
   return num1;
}
string multiply(string num1, string num2) 
{   int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0||stod(num1)==0||stod(num2)==0) 
    return "0"; 
	string result="0"; 
   unsigned sz = result.size();

  result.resize(sz+len1+len2-1,'0');
	    int i_n1 = 0;  
    int i_n2 = 0;  
      
    for (int i=len1-1; i>=0; i--) 
    {   int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;  
        for (int j=len2-1; j>=0; j--) 
        {   int n2 = num2[j] - '0'; 
            int sum = n1*n2 + (result[i_n1 + i_n2]-'0') + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = (sum % 10)+'0'; 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] = (result[i_n1 + i_n2] -'0')+ carry+'0'; 
        i_n1++; 
    } 
    int i = result.length() - 1; 
    while (i>=0 && result[i] == '0') 
    i--; 
   
    if (i == -1) 
      return "0"; 
   
   reverse(result.begin(), result.end()); 
    return result; 
} 

bool isSmaller(string str1, string str2) 
{ 
    int n1 = str1.length(), n2 = str2.length();   
    if (n1 <= n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 

string findDiff(string str1, string str2) 
{ 
    if (isSmaller(str1, str2)) //  |str2|>|str1|
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    for (int i=0; i<n2; i++) 
    { 
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
  
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
 reverse(str.begin(), str.end()); 
 return str; 
} 

void factorial(int n) 
{ 
    string res="1"; 
    for (int x=2; x<=n; x++) 
        res=multiply(to_string(x), res); 
 
       res.erase(0, res.find_first_not_of('0')); 
        cout << res<<endl; 
} 

string power(string base, string exp)  
{   string temp;  
    if(stod(exp,NULL) == 0)  
        return "1";
  
    temp = power(base, divide(exp)); 
	string ans=multiply(temp,temp); 
    if ((exp.at(exp.size()-1)-'0') % 2 == 0)  
        return ans;  
    else
            return multiply(base,ans);
}    

string gcd(string a,string b)
{if ((stoi(a))==0)
	return b;
if ((stoi(b))==0)
	return a;
if(a==b)
return a;
int a1=a[a.length()-1]-'0';
int b1=b[b.length()-1]-'0';
if(a1%2==0)
a=divide(a);
if(b1%2==0)
b=divide(b);

if((a1%2==0)&&(b1%2==0))
return multiply("2",gcd(a,b));

else if ((a1%2==0) ||(b1%2==0))
return gcd(a,b);

string p=findDiff(a,b);
if(isSmaller(a,b))
		return gcd(a,p);
	else
		return gcd(b,p);
}

int main()
{
	int count;
	cin>>count;
	while(count--)
	 {	
	 		int q;
			std::cin>>q;
			switch(q)
			{
				case 1 :{string a,b;
				std::cin>>a>>b;
				string ans=power(a,b);
				ans.erase(0, ans.find_first_not_of('0')); 
				cout<<ans<<endl;
				}
				break;
				case 2 :{string a,b;
				std::cin>>a>>b;
				cout<<gcd(a,b)<<endl;
				}break;
				case 3 : {int a;
				std::cin>>a;
				factorial(a);
				}
				break;
				default : cout<<"Wrong input";
			}
		}
return 0;
}
