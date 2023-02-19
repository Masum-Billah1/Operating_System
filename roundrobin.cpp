#include<bits/stdc++.h>
using namespace std;
vector<int>gant_value;
int turn_time[100],burst_time[100],sum=0;
void gantchart(string str){
	int i,j,cnt=1;
	string res = "|";
    cout << "Gant chart : "<<endl;
    gant_value.push_back(0);
    for(i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1])
            cnt++;
        else{
            gant_value.push_back(gant_value[gant_value.size()-1]+cnt);
            for(j=0;j<cnt/2;j++)
                res+=' ';
            res+='p';
            res+=str[i];
            for(j=0;j<cnt/2;j++)
                res+=' ';
            res+='|';
            cnt = 1;
        }
    }
    gant_value.push_back(gant_value[gant_value.size()-1]+cnt);
    for(j=0;j<cnt/2;j++)
        res+=' ';
    res+='p';
    res+=str[i];
    for(j=0;j<cnt/2;j++)
        res+=' ';
    res+='|';
    
    for(i=0;i<res.size();i++)
        cout <<'-';
    cout << endl;
    cout << res << endl;
    for(i=0;i<res.size();i++)
        cout <<'-';
    cout << endl;
    
    int in = 1;
    cout <<0;
    for(i=1;i<res.size()-1;i++){
        if(res[i+1]=='|'){
            printf("%2d",gant_value[in]);
            in++;
        }
        else if(res[i]!='|')
            cout <<' ';
    }
}


void response_time(int n,string str){
	int res_time[n],i;
	for(i=0;i<n;i++)
		res_time[i] = -1;
	
	for(i=0;i<str.size();i++){
		int temp;
		temp = str[i]-'1';
		if(res_time[temp] == -1)
			res_time[temp] = i;
	}
	cout <<"\n\nRespose time : \n";
	for(i=0;i<n;i++)
		printf("p[%d] = %2d\n",i+1,res_time[i]);
	cout << endl;
}

void turnaround_time(int n,string str){
	int i;
	for(i=0;i<n;i++){
		turn_time[i] = -1;
	}
	for(i=str.size()-1;i>=0;i--){
		int temp;
		temp = str[i]-'1';
		if(turn_time[temp]==-1){
			turn_time[temp] = i+1;
		}
	}
	
	cout <<"\n\nTurn arround time : \n";
	for(i=0;i<n;i++)
        printf("p[%d] = %2d\n",i+1,turn_time[i]);
    cout << endl;
}

void waiting_time(int n,string str){
	int i,wait_time[n];
	for(i=0;i<n;i++){
        wait_time[i] = turn_time[i]-burst_time[i];
        sum+=wait_time[i];
    }
    cout <<"\n\nWaiting time : \n";
    for(i=0;i<n;i++)
        printf("[%d] = %2d\n",i+1,wait_time[i]);
    cout << endl;
	
	float avgwt = sum*1.0/n ;
	cout <<"\nAvarage Waiting time : "<<setprecision(3)<<avgwt<<endl;
}

int main(){
	freopen("roundrobin.txt", "r", stdin);
	freopen("roundrobinout.txt", "w", stdout);
	string str;
	int burst_number,i,j,quantum_number,sum=0,t=0,cnt=1;
	int temp_burst[burst_number];
	cin >> burst_number;
	
	for(i=0;i<burst_number;i++){
		cin >> burst_time[i];
		temp_burst[i] = burst_time[i];
		sum+=burst_time[i];
	}
	cin >> quantum_number;
	
	while(sum){
		int mn;
		mn = min(temp_burst[t],quantum_number);
		temp_burst[t]-=mn;
		sum-=mn;
		while(mn--){
			str+=(t+'1');
		}
		t++;
		t%=burst_number;
	}
		
	gantchart(str);
	response_time(burst_number,str);
	turnaround_time(burst_number,str);
	waiting_time(burst_number,str);
}
