#include<bits/stdc++.h>
using namespace std;
#define getbit(x,i) ((x&(1<<i))!=0)
#define setbit(x,i) (x|(1<<i))
#define clearbit(x,i) (x&(~(1<<i)))
#define powerof2(x) (x&(x-1)) // if there is power of 2 then it will be 0
#define bpop(x) __builtin_popcount(x)
int main(){
    int x=5; // 101
    cout<<getbit(x,2)<<endl; // 1
    cout<<setbit(x,1)<<endl; // 111 -> 7
    cout<<clearbit(x,2)<<endl; // 001 -> 1
    cout<<powerof2(x)<<endl; // 1 (not a power of 2)
    cout<<bpop(x)<<endl; // 2 (number of set bits)
    return 0;
}