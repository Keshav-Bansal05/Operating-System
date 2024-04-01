#include<iostream>
#include<climits>
using namespace std;
void sort(int*at,int*bt,int*p,int*pi,int np){
    for(int i=0;i<np;i++){
        for(int j=0;j<np-i-1;j++){
            if(pi[j]<pi[j+1]){
                swap(bt[j],bt[j+1]);
                swap(at[j],at[j+1]);
                swap(p[j],p[j+1]);
                swap(pi[j],pi[j+1]);
            }
            if(at[j]>at[j+1]){
                swap(bt[j],bt[j+1]);
                swap(at[j],at[j+1]);
                swap(p[j],p[j+1]);
                swap(pi[j],pi[j+1]);
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
    int*pi=new int[np];
    cout<<"Enter the arrival time and BurstTime and Priority"<<endl;
    for(int i=0;i<np;i++){
        cin>>at[i]>>bt[i]>>pi[i];
        p[i]=i+1;
    }

    int ct=at[0];
    sort(at,bt,p,pi,np);
    int avg_wt=0;
    for(int i=0;i<np;i++){

        int pos=i;
        if(ct<at[i]){
            ct+=at[i]-ct;
        }

        for(int j=i+1;j<np;j++){
            if(ct>at[j]){            
                if(pi[pos]<pi[j]){         
                    pos=j;
                }
            }
            else{
                break;
            }
        }
        swap(bt[i],bt[pos]);
        swap(at[i],at[pos]);
        swap(p[i],p[pos]);
        swap(pi[i],pi[pos]);
        ct+=bt[i];
        tat[i]=ct-at[i];
        wt[i]=tat[i]-bt[i];
        avg_wt+=wt[i];
    }
    
    cout<<"Process    Arrival     Burst   Priority    Waiting         TAT"<<endl;

    for(int i=0;i<np;i++){
        cout<<p[i]<<"        "<<at[i]<<"             "<<bt[i]<<"             "<<pi[i]<<"       "<<wt[i]<<"          " <<tat[i]<<endl;
    }
    cout<<(double)avg_wt/np;
}