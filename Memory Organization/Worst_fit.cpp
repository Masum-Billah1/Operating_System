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
	int block[block_number],unallocate[block_number];
	
	for(i=0;i<block_number;i++){
		cin >> block[i];
		unallocate[i] = block[i];
	}
	sort(unallocate,unallocate+block_number);
	reverse(unallocate,unallocate+block_number);
	
	for(i=0;i<process_number;i++)
		cout << process[i]<<' ';
	cout << endl;
	
	for(i=0;i<block_number;i++)
		cout << block[i]<<' ';
	cout << endl;
	
	for(i=0;i<process_number;i++){
		for(j=0;j<block_number;j++){
			if(unallocate[j] >= process[i]){
				for(k=0;k<block_number;k++){
					if(block[k] == unallocate[j]){
						result[i] = k+1;
						unallocate[j] -= process[i];
						break;
					}		
				}
				break;
			}
		}
	}
	
	for(i=0;i<process_number;i++){
		cout <<"process "<<i<<" :"<<"-> block_number : "<<result[i]<<endl;
	}
	cout << endl;
}
