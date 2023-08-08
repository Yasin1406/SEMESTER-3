#include<bits/stdc++.h>
using namespace std;
void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2);
void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
double determinant(vector<vector<double>> &mat1);
int main(){
    int m1,m2,n1,n2;
    vector<vector<double>> mat1,mat2,mat3;
    cout<<"Enter the dimension of the 1st matrix: ";
    cin>>m1>>n1;
    // cout<<"Enter the dimension of the 2nd matrix: ";
    // cin>>m2>>n2;
    int i,j;
    mat1.resize(m1,vector<double>(n1));
    //mat2.resize(m2,vector<double>(n2));
    
    
    printf("Enter matrix-1:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            cin>>mat1[i][j];
        }
    }
    // printf("Enter matrix-2:\n");
    // for(i=0;i<m2;i++){
    //     for(j=0;j<n2;j++){
    //         cin>>mat2[i][j];
    //     }
    // }

    // addition(mat1,mat2,mat3);
    // subtraction(mat1,mat2,mat3);
    // transpose(mat1,mat2);
    // cout<<"After subtracition:\n";
    // for(i=0;i<m1;i++){
    //     for(j=0;j<n1;j++){
    //         cout<<mat3[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // multiplication(mat1,mat2,mat3);
    // cout<<"After multiplication:"<<endl;
    // for(i=0;i<mat3.size();i++){
    //     for(j=0;j<mat3[i].size();j++){
    //         cout<<mat3[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"determinant: "<<determinant(mat1)<<endl;
    return 0;

}
void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3){
    mat3.resize(mat1.size(),vector<double>(mat1[0].size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3){
    mat3.resize(mat1.size(),vector<double>(mat1[0].size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            mat3[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
}
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2){
    mat2.resize(mat1[0].size(),vector<double>(mat1.size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            mat2[j][i]=mat1[i][j];
        }
    }
}

void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3){
    if(mat1[0].size()!=mat2.size()){
        cout<<"Dimension doesn't match for multiplication!"<<endl;
        return;
    }
    mat3.resize(mat1.size(),vector<double> (mat2[0].size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat2[0].size();j++){
            for(int k=0;k<mat2.size();k++){
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
}

double determinant(vector<vector<double>> &mat1){
       double det,prod;
       int i,j,k,l;
        for(i=0;i<mat1.size();i++){
            prod=1;
            k=i;
            for(j=0;j<mat1.size();j++){
                prod*=mat1[j][k%(mat1.size())];
                k++;
            }
            det+=prod;
        }
        cout<<endl;
        for(i=mat1.size()-1;i>=0;i--){
            prod=1;
            k=i;
            for(j=0;j<mat1.size();j++){
                if(k<0){
                    k=mat1.size()-1;
                }
                prod*=mat1[j][k%(mat1.size())];
                k--;
            }
            det-=prod;
        }
        return det;
}
