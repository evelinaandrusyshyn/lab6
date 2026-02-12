#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int** New(int n){
    int** a=new int*[n];
    for(int i=0;i<n;i++)a[i]=new int[n];
    return a;
}
int** Malloc(int n){
    int** a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)a[i]=(int*)malloc(n*sizeof(int));
    return a;
}
int** Calloc(int n){
    int** a=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)a[i]=(int*)calloc(n,sizeof(int));
    return a;
}
void inputIndex(int** a,int n){
    cout<<"Введіть елементи:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
}
void randomIndex(int** a,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=11+rand()%54;
}
void inputPointer(int** a,int n){
    cout<<"Введіть елементи:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>*(*(a+i)+j);
}
void randomPointer(int** a,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            *(*(a+i)+j)=11+rand()%54;
}
void Matrix(int** a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
int sumIndex(int** a,int n){
    int s=0;
    for(int i=0;i<n;i++){
        int L=i;
        int R=n-1-i;
        for(int j=L;j<=R;j++)s+=a[i][j];
    }
    return s;
}
int sumPointer(int** a,int n){
    int s=0;
    for(int i=0;i<n;i++){
        int L=i;
        int R=n-1-i;
        for(int j=L;j<=R;j++)s+=*(*(a+i)+j);
    }
    return s;
}
void normalizeIndex(int** a,int n){
    for(int i=0;i<n;i++){
        int L=i;
        int R=n-1-i;
        for(int j=0;j<n;j++)
            if(j<L || j>R)
                a[i][j]=0;
    }
}
void normalizePointer(int** a,int n){
    for(int i=0;i<n;i++){
        int L=i;
        int R=n-1-i;
        for(int j=0;j<n;j++)
            if(j<L || j>R)
                *(*(a+i)+j)=0;
    }
}
void freeNew(int** a,int n){
    for(int i=0;i<n;i++)delete[] a[i];
    delete[] a;
}
void freeMalloc(int** a,int n){
    for(int i=0;i<n;i++)free(a[i]);
    free(a);
}
int main(){
    srand(time(0));
    int n;
    cout<<"Введіть розмір квадратної матриці: ";
    cin>>n;
    cout<<"Оберіть спосіб створення (1-new,2-malloc,3-calloc): ";
    int t;cin>>t;
    int** a;
    if(t==1)a=New(n);
    else if(t==2)a=Malloc(n);
    else a=Calloc(n);
    cout<<"Спосіб формування (1-ввід,2-random): ";
    int f;cin>>f;
    cout<<"Оберіть доступ (1-індекси,2-вказівники): ";
    int d;cin>>d;
    if(f==1){
        if(d==1)inputIndex(a,n);
        else inputPointer(a,n);
    }else{
        if(d==1)randomIndex(a,n);
        else randomPointer(a,n);
    }
    cout<<"\nПочаткова матриця:\n";
    Matrix(a,n);
    cout<<"\nОберіть метод обчислення суми (1-індекси,2-вказівники): ";
    int m;cin>>m;
    int S=(m==1?sumIndex(a,n):sumPointer(a,n));
    cout<<"Сума елементів у зафарбованій області = "<<S<<"\n";
    cout<<"\nВиконати нормування (обнулити елементи поза областю)? 1-так, 2-ні: ";
    int q;cin>>q;
    if(q==1){
        if(d==1)normalizeIndex(a,n);
        else normalizePointer(a,n);
        cout<<"\nМатриця після нормування:\n";
        Matrix(a,n);
    }
    if(t==1)freeNew(a,n);
    else freeMalloc(a,n);
    return 0;
}
