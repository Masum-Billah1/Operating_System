#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sjf.txt", "r", stdin);
    freopen("sjfout.txt", "w", stdout);
    int n,i,j;
    //cout <<"Enter the number of process : ";
    cin >> n;
    int a[n],b[n],waiting_time[n],mainsum=0,sum=0,avgsum=0,temp;
    float avg;
    
    for(i=0;i<n;i++){
    	//cout <<"Enter the burst time for process "<<i+1<<": ";
    	cin >> a[i];
    	mainsum+=a[i];
	}
    
	map<int,int>mp;
	for(i=0;i<n;i++){
		mp[a[i]]=i+1;
	}	
    vector<int>process;
    for(auto it:mp){
        process.push_back(it.second);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(i==0)
            waiting_time[i] = 0;
        else {
            waiting_time[i] = waiting_time[i-1]+a[i-1];
            avgsum+=waiting_time[i];
        }      
    }
    
    //Printing Gantt chart
    for(i=0;i<mainsum*2+3*n+1;i++)
    	cout <<'_';
    cout << endl;
    
    cout<<"| ";
    for(i=0;i<n;i++){
        temp = a[i];
        while(temp--){
        	cout << 'p'<<process[i];
		}
		cout<<" | ";
    }
    
    cout << endl;
    for(i=0;i<mainsum*2+3*n+1;i++)
    	cout <<'-';
    cout << endl;
   	cout << 0;
   	
	for(i=0;i<n;i++){
		sum+=a[i];
		cout <<' ';
		for(j=0;j<2*a[i];j++)
			cout <<' ';
		printf("%2d",sum);
	} 
	
	
	cout <<"\n\nWaiting time : "<<endl;
	for(i=0;i<n;i++){
		printf("p[%d] = %d\n",i+1,waiting_time[i]);
	}	
	
	cout <<"\n\nResponse time : "<<endl;
	for(i=0;i<n;i++){
		printf("p[%d] = %d\n",i+1,waiting_time[i]);
	}
    
    avg = avgsum*1.0/n;
    cout << "\n\navarage wating time is : " << avg <<endl;
}