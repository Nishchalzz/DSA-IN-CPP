#include<iostream>
#include<string>
using namespace std;

class Pa{
public:
    static int car;
};

int Pa::car = 0;
void countfunc(){
    static int count =0;
    count++;
    cout<<count<<endl;
}
int main(){
   Pa a,b,c;
   cout<<a.car++<<endl;
   cout<<b.car++<<endl;
   cout<<c.car++<<endl;
   countfunc();
   countfunc();
   countfunc();
 
    return 0;
}