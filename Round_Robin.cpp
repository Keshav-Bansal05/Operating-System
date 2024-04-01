#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
void sort(int*at,int*bt,int*p,int np){
    for(int i=0;i<np;i++){
        for(int j=0;j<np-i-1;j++){
            if(at[j]>at[j+1]){
                swap(bt[j],bt[j+1]);
                swap(at[j],at[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }
}
int main(){
    cout<<"Enter the no of process"<<endl;
    int np;
    cin>>np;
    int *p=new int[np];
    int *at=new int[np];
    int *wt=new int[np];
    int *bt=new int[np];
    int *tat=new int[np];
    int *temp=new int[np];
    cout<<"Enter the arrival time and BurstTime"<<endl;
    for(int i=0;i<np;i++){
        cin>>at[i]>>bt[i];
        p[i]=i;
    }

    sort(at,bt,p,np);
    for(int i=0;i<np;i++){
        temp[i]=bt[i];
    }
    int avg_wt=0;
    cout<<"Enter the Time Quantum"<<endl;
    int t;
    cin>>t;
    queue<int>q;
    q.push(p[0]);
    int total=1;
    unordered_map<int,int>map;
    map[p[0]]=1;

    int ct=at[0];//For initializing if 1st process enter at 1 then ct will start from 1

    while(!q.empty()){
        int i=q.front();
            q.pop();

        if(ct<at[i]){
            ct+=at[i]-ct;
        }
        if(bt[i]>t){
            ct+=t;
            bt[i]-=t;
        }
        else{
            ct+=bt[i];
            bt[i]=0;
            tat[i]=ct-at[i];
            wt[i]=tat[i]-temp[i];
            avg_wt+=wt[i];
            // q.pop();
        } 
        if(total!=np){
            for(int k=total;k<np;k++){
            if(ct>=at[p[k]] && map.count(p[k])<=0){
                map[p[k]]=1;
                q.push(p[k]);
                total++;
            } 
        }
        }
        if(bt[i]!=0)
            q.push(i);
    }
    cout<<"Process      Arrival        Burst       Waiting         TAT"<<endl;

    for(int i=0;i<np;i++){
        cout<<p[i]<<"    "<<at[i]<<"    "<<temp[i]<<"     "<<wt[i]<<"    " <<tat[i]<<endl;
    }
    cout<<(double)avg_wt/np;
}

