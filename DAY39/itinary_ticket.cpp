#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printTravel(unordered_map<string, string> tickets){
    unordered_set<string> s;
    string start;
    for(pair<string,string> p:tickets){
        s.insert(p.second);
    }
    for(pair<string,string> p:tickets){
        if(s.find(p.first) == s.end()){  //not found
            start = p.first;
        }
    }
    cout<<"start: "<<start;
    for(int i=0;i<tickets.size();i++){
        cout<<" -> "<<tickets[start];
        start = tickets[start];
    }

}



int main(){

    unordered_map<string, string> tickets;
    tickets["Chennai"]="Bengaluru"; 
    tickets["Mumbai"]="Delhi"; 
    tickets["Goa"]="Chennai"; 
    tickets["Delhi"]="Goa"; 

    printTravel(tickets);

    return 0;
}