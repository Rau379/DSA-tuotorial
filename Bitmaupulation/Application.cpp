#include<bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for(int i=10; i>=0; i--)
    {
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}
int main()
{
    // checking for even and odd
    // for(int i=0; i<8; i++)
    // {
    //     printBinary(i);
    //     if(i&1)
    //     {
    //         cout<<"ODD"<<endl;
    //     }
    //     else{
    //         cout<<"Even"<<endl;
    //     }
    // }


    // divide and multiply
//     int n=5;
//     // rightshift divide by 2
//     cout<<(n>>1) <<endl;
//    // lwftshift multiply by 2
//    cout<<(n<<1) <<endl;

// Uppercase to lowercase and Vice- versa
// for(char c='A'; c<='E'; c++)
// {
//     cout<<c<<endl;
//     printBinary(int(c));
// }
// for(char c='a'; c<='e'; c++)
// {
//     cout<<c<<endl;
//     printBinary(int(c));
// }
//    char A= 'A' ;
//    char a= A | (1<<5);
//    cout<<a <<endl;
//    cout<<char( a &(~(1<<5))) <<endl;
//    printBinary(int('_'));

//    // another way
//    cout<<char(1<<5) <<endl;
//    //lowercase
//    cout<<char('C' | ' ')<<endl;
//    //uppercase
//    cout<<char('c' &'_')<<endl;



// clear LSB i.e least siginificant bits
printBinary(59);
int a=59;
int i=4;
int b= (a &(~((1<<(i+1))-1)));
printBinary(b);
// clear MSB
// i=3;
// int c=( a & ((1 <<(i+1))-1))<<endl;
// printBinary(c);

// chcking power of 2
int n= 15;
//cout<<(n &(n-1));
if(n & (n-1))
{
    cout<<"Not power of 2"<<endl;
}
else{
    cout<<"Power of 2"<<endl;
}
}