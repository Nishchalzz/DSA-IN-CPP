#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){

    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);

    // cout<<"Size: "<<ll.size()<<endl;
    // cout<<"front: "<<ll.front()<<endl;
    // cout<<"back:  "<<ll.back()<<endl;
    // ll.pop_back();
    // ll.pop_front();

    auto it = ll.begin();
    it++;
    ll.insert(it,ll.begin(), ll.end());
    printList(ll);
    return 0;
}