#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("fifo.txt","r",stdin);
	int page_number,frame_size,i;
	cin >> page_number >> frame_size;
	int page[page_number];
	
	queue<int>q;
	set<int> s;
	
	int page_fault = 0;
	
	for(i=0;i<page_number;i++){
		cin >> page[i];
		if(q.size() < frame_size){
			if(s.find(page[i])==s.end()){
				s.insert(page[i]);
				q.push(page[i]);
				page_fault++;
			}
		}
		else{
			if(s.find(page[i])==s.end()){
				int er = q.front();
				s.erase(er);
				q.pop();
				s.insert(page[i]);
				q.push(page[i]);
				page_fault++;
			}
		}
	}
	cout <<"Number of page fault : "<<page_fault<<endl;
}