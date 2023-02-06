#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int>mp;
    vector<int>v;
    int i;
    mp["Masum"] = 18;
    mp["Ankar"] = 9;
    mp["Srity"] = 47;
    mp["Aminul"] = 29;
    mp["Zahid"] = 44;
    cout << mp.size()<<endl;
    for(auto it:mp){
        cout <<it.first<<' '<<it.second<<endl;
        v.push_back(it.second);
    }
    for(i=0;i<v.size();i++)
        cout << v[i]<<' ';
    cout << endl;

}