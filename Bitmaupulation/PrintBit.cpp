#include<bits/stdc++.h>
using namespace std;
void printBinary(int num)
{
    for(int i=10; i>=0; i--)
    {
        cout<<((num >> i) & 1);
    }
}

int main()
{
     printBinary(9);
     // to check set bit or unset bit
     cout<<endl;
     int a=9;
     int i=2;
     if((a & (1<<i)) != 0)
     {
        cout<<"Set Bit"<<endl;
     }
     else 
     {
        cout<<"Not set Bit"<<endl;
     }

      // bit set
     
      printBinary(a |(1<<1)); cout<<endl;
      // Invert the BInary Representation of an number
      printBinary(~a); cout<<endl;
      
      // unset the particular bit
      printBinary(a &(~(1<<3))); cout<<endl;
      // toggle the bit
      printBinary(a^ (1<<2));  cout<<endl;
    
    // Count the number of bits
     int cnt=0;
     for(int i =31; i>=0; i--)
     {
        if((a & (1<<i)) !=0)
        {
            cnt++;
        }
     }
     cout<<cnt<<endl;
     // Inbuilt function
     cout<<__builtin_popcount(a)<<endl;

 

}