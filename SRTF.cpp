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
    int*at=new int[np];
    int*bt=new int[np];
    int*wt=new int[np];
    int*tat=new int[np];
    int*p=new int[np];

    int *temp=new int[np];
    int avg_wt=0;
    cout<<"Enter the ArrivalTime and BurstTime"<<endl;
    for(int i=0;i<np;i++){
        p[i]=i+1;
        cin>>at[i]>>bt[i];
    }

    sort(at,bt,p,np);
    int ct=at[0];
    for(int i=0;i<np;i++){
        temp[i]=bt[i];
    }

    for(int i=0;i<np;i++){
        bool f=false;
        if(ct<at[i]){
            ct+=at[i]-ct;
        }
        while(bt[i]!=0){
            int pos=i;
            for(int j=i+1;j<np;j++){
                if(ct>=at[j]){
                    if(bt[pos]>bt[j]){
                        pos=j;
                        f=true;
                    }
                }
                else
                break;
            }
            ct++;
            bt[pos]--;
            if(f){
                swap(bt[i],bt[pos]);
                swap(at[i],at[pos]);
                swap(p[i],p[pos]);
                swap(temp[i],temp[pos]);
                break;
            }
        }
        if(f){
            i--;
            continue;
        }
        tat[i]=ct-at[i];
        wt[i]=tat[i]-temp[i];
        avg_wt+=wt[i];

    }
        cout<<"Process      Arrival        Burst       Waiting         TAT"<<endl;

    for(int i=0;i<np;i++){
        cout<<p[i]<<"    "<<at[i]<<"    "<<temp[i]<<"     "<<wt[i]<<"    " <<tat[i]<<endl;
    }
    cout<<(double)avg_wt/np;
}