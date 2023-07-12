#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detection.txt","r",stdin);
	bool isdeadlock = 0;
	int n,i,j,cnt;
	cin >> n;
	int allocation[n][3],request[n][3],available[n],finish[n],work[n];
	
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			cin >> allocation[i][j];
	
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			cin >> request[i][j];
		
	
				
	for(i=0;i<3;i++){
		cin >> available[i];
		work[i] = available[i];
	}
	
	for(i=0;i<n;i++)
		finish[i] = 1;
		
	cnt = n;
	
	while(cnt){
		int temp = cnt;
		for(i=0;i<n;i++){
			if(finish[i]==1 && request[i][0]<=work[0] && request[i][1]<=work[1] && request[i][2]<=work[2]){ 
				work[0]+=allocation[i][0];
				work[1]+=allocation[i][1];
				work[2]+=allocation[i][2];
				finish[i] = 0;
				cnt--;
			}
		}
		if(temp==cnt){
			isdeadlock = 1;
			break;
		}	
	}
	
	if(isdeadlock == 1)
		cout <<"Deadlock is occured"<<endl;
	else
		cout <<"Deadlock is not occured"<<endl;
}
