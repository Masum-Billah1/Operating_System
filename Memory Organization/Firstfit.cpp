#include<bits/stdc++.h>
using namespace std;
int main(){
	int process_number,i,j,k;
	freopen("memory.txt","r",stdin);
	cin >> process_number;
	int process[process_number],result[process_number];
	
	for(i=0;i<process_number;i++){
		cin >> process[i];
		result[i] = -1;
	}
			
	int block_number;
	cin >> block_number;
	int block[block_number],unalocate[block_number];
	
	for(i=0;i<block_number;i++){
		cin >> block[i];
		unalocate[i] = block[i];
	}
	
	for(i=0;i<process_number;i++)
		cout << process[i]<<' ';
	cout << endl;
	
	for(i=0;i<block_number;i++)
		cout << block[i]<<' ';
	cout << endl;
	
	for(i=0;i<process_number;i++){
		for(j=0;j<block_number;j++){
			if(unalocate[j] >= process[i]){
				result[i] = j+1;
				unalocate[j] -= process[i];
				break;
			}
		}
	}
	
	for(i=0;i<process_number;i++)
		cout << result[i]<<' ';
	cout << endl;
}
