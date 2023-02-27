#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("banker.txt","r",stdin);
	int n,i,j,sum=0;
	string str;
	cin >> n;
	int allocation[n][3],maximum[n][3],need[n][3],available[3];
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin >> allocation[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin >> maximum[i][j];
			need[i][j] = maximum[i][j] - allocation[i][j];
			sum+=need[i][j];
		}
	}
	for(i=0;i<3;i++){
		cin >> available[i];
	}
	cout <<"Need : "<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cout << need[i][j]<<' ';
		}
		cout << endl;
	}
	int index = 0;
	while(sum){
		if(need[index][0] == -1){
			index++;
			continue;
		}
		if(need[index][0]<=available[0] && need[index][1]<=available[1] && need[index][2]<=available[2]){
			available[0]+=allocation[index][0];
			available[1]+=allocation[index][1];
			available[2]+=allocation[index][2];
			str+=(index+'0');
			sum-=(need[index][0]+need[index][1]+need[index][2]);
			need[index][0] = -1;
		}
		index++;
		index%=n;
	}
	
	cout << "\n\nSafe sequence : " << endl;	
	
	for(i=0;i<str.size();i++){
		cout <<"p"<<str[i];
		if(i!=str.size()-1)
			cout <<" -> ";
	}	
}
