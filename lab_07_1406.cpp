#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lab7_input.txt","r",stdin);
    int state_num,sym_num,fin_num,i,j,k;
    cout<<"Enter number of states, symbols and final states: ";
    cin>>state_num>>sym_num>>fin_num;
    char states[state_num],symbols[sym_num],finals[fin_num],transition[state_num][sym_num];
    cout<<"Enter the states: ";
    for(i=0;i<state_num;i++){
        cin>>states[i];
    }
    getchar();
    cout<<"Enter the symbols: ";
    for(i=0;i<sym_num;i++){
        cin>>symbols[i];
    }
    getchar();
    cout<<"Enter the final states: ";
    for(i=0;i<fin_num;i++){
        cin>>finals[i];
    }
    getchar();
    for(i=0;i<state_num;i++){
        cout<<"\nEnter transitions for state-"<<states[i]<<endl;
        for(j=0;j<sym_num;j++){
            cout<<"For symbol-"<<symbols[i]<<": ";
            cin>>transition[i][j];
            getchar();
        }
    }
    cout<<"\n\t";
    for(i=0;i<sym_num;i++){
        cout<<symbols[i]<<"\t";
    }
    cout<<endl;
    for(i=0;i<state_num;i++){
        cout<<states[i]<<"\t";
        for(j=0;j<sym_num;j++){
            cout<<transition[i][j]<<"\t";
        }
        cout<<endl;
    }
    char table[state_num][state_num];
    for(i=0;i<fin_num;i++){
        for(j=0;j<state_num;j++){
            for(k=0;k<fin_num;k++){
                if(states[j]==finals[k]){
                    break;
                }
            }
            if(k==fin_num){
                table[i][j]='x';
                table[j][i]='x';
            }
        }
    }

}