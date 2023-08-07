#include<bits/stdc++.h>
using namespace std;
int m1,n1,m2,n2;
vector<vector<double>> mat1;
vector<vector<double>> mat2;
vector<vector<double>> mat_mul;
vector<vector<double>> mat_add;
vector<vector<double>> mat_sub;
void addition();
void subtract();
void multiplication();
int main(){
    printf("Enter the dimension of the 1st matrix: ");
    scanf("%d %d",&m1,&n1);
    printf("Enter the dimension of the 1st matrix: ");
    scanf("%d %d",&m2,&n2);
    int i,j;
    mat1.resize(m1,vector<double>(n1));
    mat2.resize(m2,vector<double>(n2));
    if(n1==m2){
        mat_mul.resize(m1,vector<double>(n2));
    }
    if(m1==m2&&n1==n2){
        mat_add.resize(m1,vector<double>(n1));
        mat_sub.resize(m2,vector<double>(n2));
    }
    printf("Enter matrix-1:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter matrix-2:\n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

}
void addition(){
    if(!(m1==m2&&n1==n2)){
        printf("Invalid dimensions for addition\n");
        return;
    }
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            mat_add[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
void subtraction(){
    if(!(m1==m2&&n1==n2)){
        printf("Invalid dimensions for subtraction\n");
        return;
    }
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            mat_sub[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
}