#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> vec;
    vector<int> vec1={1,2,3,4,5};
    // vector<int> vec2(5,-1);
    // cout<<vec.size()<<"\n";
    // cout<<vec1.size()<<endl;

    // for(int i=0;i<vec2.size();i++){
    //     cout<<vec2[i]<<"  ";
    // }
    cout<<vec1.size()<<endl;
    cout<<vec1.capacity()<<endl<<endl;

    vec1.push_back(1);
    cout<<vec1.size()<<endl;
    cout<<vec1.capacity()<<endl;
    vec1.pop_back();
       cout<<vec1.size()<<endl;
    return 0;
}