#include<iostream>
#include<queue>
#include<string>
using namespace std;

void FirstNonRepeat(string str){
    int freq[26]={0};
    queue<char> q;

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front()-'a']>1){
            q.pop();
        }

        if(freq[q.front()-'a']==1){
            cout<<q.front()<<endl;
        }else{
                cout<<"not there"<<endl;
        }
    }
}

int main(){
    string str = "aabccxb";
    FirstNonRepeat(str);
    return 0;
    
}