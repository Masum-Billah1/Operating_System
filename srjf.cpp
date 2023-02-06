#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	int n,i,time=0,sum=0,index,contain;
	string str;
	char ch;
    cin >> n;
    int arrival_time[n],burst_time[n],waiting_time[n];
    
    for(i=0;i<n;i++)
    	cin >> arrival_time[i] >> burst_time[i];
    	
    for(i=0;i<n;i++)
    	sum+=burst_time[i];	
    
    while(sum--){
    	for(i=0;i<n;i++){
    		if(burst_time[i]>0){
    			contain = burst_time[i];
    			index = i;
			}		
		}
		cout <<"burst time : ";
		for(i=0;i<n;i++)
			cout << arrival_time[i]<<' ';
		cout << endl;
    	for(i=0;i<n;i++){
    		if(time>=arrival_time[i] && burst_time[i]<contain && burst_time[i]>0){
    			contain = burst_time[i];
    			index = i;
			}
		}
		cout << "contain : "<<contain<<endl;
		ch = index+49;
		str+=ch;
		burst_time[index]--;
		time++;
	} 
	cout << str << endl;
}
