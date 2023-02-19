#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("srtf.txt", "r", stdin);
    freopen("srtfout.txt", "w" ,stdout);
    //Input number
    int n,i,j,sum=0,mini,index,cnt=1;
    cin >> n;
    string str,res="|";
    int arrival_time[n],burst_time[n],res_time[n],turn_time[n],wait_time[n];
    float avgwt;

    for(i=0;i<n;i++)
        cin >> arrival_time[i] >> burst_time[i];

    for(i=0;i<n;i++)
        sum+=burst_time[i];

    for(i=0;i<sum;i++){
        mini = 9999;
        for(j=0;j<n;j++){
            if(arrival_time[j]<=i && burst_time[j]<mini && burst_time[j]!=0){
                mini = burst_time[j];
                index = j;
            }
        }
        burst_time[index]--;
        str+=('0'+index+1);
    }

    //Gant chart
    cout << "Gant chart : "<<endl;
    vector<int>gant_value;
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

    for(i=0;i<n;i++){
        res_time[i]=-1;
        turn_time[i]=-1;
    }
        

    for(i=0;i<str.size();i++){
        int temporary;
        temporary = str[i]-'1';
        if(res_time[temporary]==-1)
            res_time[temporary]=i;
    }

    cout <<"\n\nResponse time : \n";
    for(i=0;i<n;i++)
        printf("[%d] = %2d\n",i+1,res_time[i]);
    cout << endl;

    for(i=str.size()-1;i>=0;i--){
        int temporary;
        temporary = str[i]-'1';
        if(turn_time[temporary]==-1){
            turn_time[temporary]=i+1-arrival_time[temporary];
        }
    }

    cout <<"\n\nTurn around time : \n";
    for(i=0;i<n;i++)
        printf("[%d] = %2d\n",i+1,turn_time[i]);
    cout << endl;

    sum = 0;
    for(i=0;i<n;i++){
        wait_time[i] = turn_time[i]-burst_time[i];
        sum+=turn_time[i];
    }

    cout <<"\n\nWaiting time : \n";
    for(i=0;i<n;i++)
        printf("[%d] = %2d\n",i+1,wait_time[i]);
    cout << endl;

    avgwt = sum*1.0/n;

    cout <<"\nAvarage Waiting time : "<<avgwt<<endl;
}
