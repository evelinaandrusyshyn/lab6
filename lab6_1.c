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
            a[i][j]=rand()%50;
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
            *(*(a+i)+j)=rand()%50;
}
void Matrix(int** a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
int sumIndex(int** a,int rows,int cols){
    int sum=0;
    for(int i=1;i<rows;i+=2){
        int mn=a[i][0];
        for(int j=1;j<cols;j++)if(a[i][j]<mn)mn=a[i][j];
        sum+=mn;
    }
    return sum;
}
int sumPointer(int** a,int rows,int cols){
    int sum=0;
    for(int i=1;i<rows;i+=2){
        int mn=*(*(a+i));
        for(int j=1;j<cols;j++)
            if(*(*(a+i)+j)<mn)mn=*(*(a+i)+j);
        sum+=mn;
    }
    return sum;
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
    cout<<"\nОберіть спосіб обчислення суми мінімальних (1-індекси,2-вказівники): ";
    int c;cin>>c;
    int result=(c==1?sumIndex(a,rows,cols):sumPointer(a,rows,cols));
    cout<<"Сума мінімальних елементів у непарних рядках = "<<result<<"\n";
    if(t==1)freeNew(a,rows);
    else freeMalloc(a,rows);
    return 0;
}
