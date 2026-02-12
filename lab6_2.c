#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** New(int rows,int cols){
    int** a=new int*[rows];
    for(int i=0;i<rows;i++)a[i]=new int[cols];
    return a;
}
int** Malloc(int rows,int cols){
    int** a=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++)a[i]=(int*)malloc(cols*sizeof(int));
    return a;
}
int** Calloc(int rows,int cols){
    int** a=(int**)calloc(rows,sizeof(int*));
    for(int i=0;i<rows;i++)a[i]=(int*)calloc(cols,sizeof(int));
    return a;
}
void inputIndex(int** a,int rows,int cols){
    cout<<"Введіть елементи:\n";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>>a[i][j];
}
void randomIndex(int** a,int rows,int cols){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            a[i][j]=11+rand()%54;
}
void inputPointer(int** a,int rows,int cols){
    cout<<"Введіть елементи:\n";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>>*(*(a+i)+j);
}
void randomPointer(int** a,int rows,int cols){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            *(*(a+i)+j)=11+rand()%54;
}
void Matrix(int** a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
void EvenIndex(int** a,int rows,int cols){
    cout<<"Парні елементи: ";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(a[i][j]%2==0)cout<<a[i][j]<<" ";
    cout<<"\n";
}
void EvenPointer(int** a,int rows,int cols){
    cout<<"Парні елементи: ";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(*(*(a+i)+j)%2==0)cout<<*(*(a+i)+j)<<" ";
    cout<<"\n";
}
void Not6Index(int** a,int rows,int cols){
    cout<<"Елементи, що НЕ кратні 6: ";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(a[i][j]%6!=0)cout<<a[i][j]<<" ";
    cout<<"\n";
}
void Not6Pointer(int** a,int rows,int cols){
    cout<<"Елементи, що НЕ кратні 6: ";
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(*(*(a+i)+j)%6!=0)cout<<*(*(a+i)+j)<<" ";
    cout<<"\n";
}
void freeNew(int** a,int rows){
    for(int i=0;i<rows;i++)delete[] a[i];
    delete[] a;
}
void freeMalloc(int** a,int rows){
    for(int i=0;i<rows;i++)free(a[i]);
    free(a);
}
int main(){
    srand(time(0));
    int rows,cols;
    cout<<"Введіть кількість рядків і стовпців: ";
    cin>>rows>>cols;
    cout<<"Оберіть спосіб створення масиву (1-new,2-malloc,3-calloc): ";
    int t;cin>>t;
    int** a;
    if(t==1)a=New(rows,cols);
    else if(t==2)a=Malloc(rows,cols);
    else a=Calloc(rows,cols);
    cout<<"Спосіб формування масиву (1-ввід,2-random): ";
    int f;cin>>f;
    if(f==1){
        cout<<"Оберіть спосіб доступу (1-індекси,2-вказівники): ";
        int d;cin>>d;
        if(d==1)inputIndex(a,rows,cols);
        else inputPointer(a,rows,cols);
    }else{
        cout<<"Оберіть спосіб доступу (1-індекси,2-вказівники): ";
        int d;cin>>d;
        if(d==1)randomIndex(a,rows,cols);
        else randomPointer(a,rows,cols);
    }
    cout<<"\nПочатковий масив:\n";
    Matrix(a,rows,cols);
    cout<<"\nОберіть дію:\n1 - знайти всі парні\n2 - знайти всі, крім кратних 6\nВаш вибір: ";
    int act;cin>>act;
    cout<<"Оберіть спосіб пошуку (1-індекси,2-вказівники): ";
    int acc;cin>>acc;
    if(act==1){
        if(acc==1)EvenIndex(a,rows,cols);
        else EvenPointer(a,rows,cols);
    }else{
        if(acc==1)Not6Index(a,rows,cols);
        else Not6Pointer(a,rows,cols);
    }

    if(t==1)freeNew(a,rows);
    else freeMalloc(a,rows);

    return 0;
}
