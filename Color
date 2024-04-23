#include<iostream>
#include<stdio.h> // thu vien chua file
#include<string.h>
#define MAX 50

using namespace std;

bool Exist(int a, int b,int A[MAX][2], int c){  // nhap vao ten 2 canh a,b , mang A chua danh sach canh , c la so luong canh
    for (int i = 0; i < c; i++)
    {
        if (       (A[i][0]==a&&A[i][1]==b)        ||   (A[i][0]==b&&A[i][1]==a)      ) 
        return true;     // tra ve 1 neu co 
    }

    return false;  // tra ve 0 neu k co canh
}
void Mau(int n, char cl[20]){
    
    switch (n)
    {
    case 1: strcpy(cl,"yellow"); break;
    case 2:strcpy(cl,"red");break;
    case 3: strcpy(cl,"orange");break;
    case 4:strcpy(cl,"pink");break;
    case 5:strcpy(cl,"green");break;
    case 6:strcpy(cl,"salmon");break;
    case 7:strcpy(cl,"brown");break;
    case 8:strcpy(cl,"purple1");break;
    case 9:strcpy(cl,"gold1");break;
    case 10:strcpy(cl,"blue");break;
    case 11:strcpy(cl,"gray");break;

    
       
    };
    
    
}

int main(){
    int n,m;     // n la dinh , m la so luong canh
    int A[MAX][2];         // mang luu danh sach canh
    int mau[MAX]={0};     // mag luu tru mau cua dinh 
    bool stt[MAX]; // gan status tat ca cac mau bang true 
    char cl[20];
    
    FILE *f;
    f=fopen("/home/long/Dropbox/DiscreteMaths/discreteMaths/roirac/2.color/input.txt","r");
    if(f==NULL){
        cout<<"error";
        return 1;
    }
    fscanf(f,"%d %d\n",&n,&m);
    for (int i = 0; i < m; i++)
    {
        fscanf(f,"%d %d\n",&A[i][0],&A[i][1]);
    }
    fclose(f);


     mau[1]=1;
    for (int i = 2; i <= n; i++){
        
        for (int k = 0; k < MAX; k++)
        {
           stt[k]=true;
        }
        
        for (int j = 1; j < i; j++){  // chi chay tu dau toi cai trc i thoi :))
            if (Exist(i,j,A,m)) {
                stt[mau[j]]=false;
            }
        }
        int c=1;
         while (!stt[c]){
             c++;
         };
            // tim mau[c] nho nhat thoa man , c chinh la ten dinh
           
        mau[i]=c;
    }
  



 // test ok
 //if (Exist(1,2,A,m))  cout << "chuancmnl";
 //else cout <<"ngu r";

 cout<<"graph dothi\n{\n";
 
 for (int i = 1; i <= n; i++)
 {
    //cl[20]=NULL;
    Mau(mau[i],cl);
  //strcpy(cl,"snow"); 
    cout<<i<<" [fillcolor=" << cl <<", style=filled];\n ";
 }
 for (int i = 0; i < m; i++)
 {
     cout<< A[i][0] <<" -- "<< A[i][1]<<";"<< endl;
 }
 cout <<"}";
 
 










    return 0;
    
}
