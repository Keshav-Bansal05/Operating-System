#include<iostream>
using namespace std;
void sort(int*at,int*bt,int*p,int np){
    for(int i=0;i<np;i++){
        for(int j=0;j<np-i-1;j++){
            if(bt[j]>bt[j+1]){
                swap(bt[j],bt[j+1]);
                swap(at[j],at[j+1]);
                swap(p[j],p[j+1]);
            }
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

    cout<<"Enter the arrival time and BurstTime"<<endl;
    for(int i=0;i<np;i++){
        cin>>at[i]>>bt[i];
        p[i]=i+1;
    }

    sort(at,bt,p,np);
    int ct=at[0];//For initializing if 1st process enter at 1 then ct will start from 1
    int avg_wt=0;
    
    for(int i=0;i<np;i++){
        if(ct<at[i]){
            ct+=at[i]-ct;
        }
        ct+=bt[i];
        tat[i]=ct-at[i];
        wt[i]=tat[i]-bt[i];
        avg_wt+=wt[i];
    }
    
    cout<<"Process      Arrival        Burst       Waiting         TAT"<<endl;

    for(int i=0;i<np;i++){
        cout<<p[i]<<"    "<<at[i]<<"    "<<bt[i]<<"     "<<wt[i]<<"    " <<tat[i]<<endl;
    }
    cout<<(double)avg_wt/np;
}