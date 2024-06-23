

#include<iostream>
using namespace std;

  typedef struct node     // Node chua thong tin mot truong hop sinh
{
    int tt;    // chua thu tu sinh
    int fa;    // bien luu chu chi so phan tu cha
    int A[3];  // mang luu chu trang thai cua node
}Node;

  Node G[300];    // mang luu tru cac node co the co
  int i=0;          // bien luu tru gia tri hien thoi cua chi so
  
void In(Node B){    
    cout<<B.A[0]<<" "<<B.A[1]<<" " <<B.A[2]<<" tt "<< B.tt<<" fa "<< B.fa <<endl;
}
// sau day la ham lap ra mot node
void Lap(Node B,int a){             // chu y thu tu neu de ham nay sep sau ham sinh thi se bi bao loi vi compiler bien dich tuyen tinh
            i++;
            G[i].A[0]=B.A[0];
            G[i].A[1]=B.A[1];
            G[i].A[2]=B.A[2];

            G[i].fa=a;
            G[i].tt=i;
}
int Dung(Node B){               // kiem tra dieu kien dung
    if (B.A[1]==2||B.A[2]==2) return 1;
    return 0;
}
int KtG(Node &B, Node &C){    //ham kiem tra giong khong
    if (
        (B.A[0]==C.A[0])&&              // vcl dau la == chu khong phai la = dcmn
        (B.A[1]==C.A[1])&&
        (B.A[2]==C.A[2])
    )
    return 1;                   // tra lai 1 neu giong
    else
    return 0;
}
int KtT(Node &B){   // ham kiem tra Ton tai
     for (int i = 0; i < B.tt; i++)
     {
        if (KtG(G[i],B)) return 1;    // tra lai 1 neu da ton tai
     }
     return 0;
     

}
void Do01(Node B){         // ham thuc hien do can 0 cho  can 1  ,goii sinh node neu node do chua ton tai
    int x=B.tt;
    
    if (   (B.A[0]+B.A[1])     >7){
        
        B.A[0]=B.A[0]+B.A[1]-7;

        B.A[1]=7;


    }
    else {
        B.A[1]=B.A[0]+B.A[1];

        B.A[0]=0;
    };
     if (!KtT(B))  Lap(B,x) ;

     
}
void Do21(Node B){
     int x=B.tt;
    if (   (B.A[2]+B.A[1])     >7){
        
        B.A[2]=B.A[2]+B.A[1]-7;

        B.A[1]=7;


    }
    else {
        B.A[1]=B.A[2]+B.A[1];

        B.A[2]=0;
    };
     if (!KtT(B))  Lap(B,x) ;
}
void Do20(Node B){
     int x=B.tt;
    if (   (B.A[0]+B.A[2])     >10){
        
        B.A[2]=B.A[0]+B.A[2]-10;

        B.A[0]=10;


    }
    else {
        B.A[0]=B.A[0]+B.A[2];

        B.A[2]=0;
    }
     if (!KtT(B))  Lap(B,x) ;
}
void Do10(Node B){
    int x;
    x=B.tt;
    if (   (B.A[1]+B.A[0])     >10){
        
        B.A[1]=B.A[0]+B.A[1]-10;

        B.A[0]=10;


    }
    else {
        B.A[0]=B.A[0]+B.A[1];

        B.A[1]=0;
    }

    if (!KtT(B))  Lap(B,x) ;              //neu khong ton tai thi lap G
}
void Do12(Node B){
     int x=B.tt;
    if (   (B.A[2]+B.A[1])     >4){
        
        B.A[1]=B.A[2]+B.A[1]-4;

        B.A[2]=4;


    }
    else {
        B.A[2]=B.A[2]+B.A[1];

        B.A[1]=0;
    };
     if (!KtT(B))  Lap(B,x) ;
}
void Do02(Node B){
     int x=B.tt;
    if (   (B.A[0]+B.A[2])     >4){
        
        B.A[0]=B.A[0]+B.A[2]-4;

        B.A[2]=4;


    }
    else {
        B.A[2]=B.A[0]+B.A[2];

        B.A[0]=0;
    };
     if (!KtT(B))  Lap(B,x) ;
}

void Sinh(Node B){          // ham sinh node kiem tra dieu kien ban dau xem can thu ? co day khong, va thuc hien Do

    if (B.A[0]!=10){
        if (B.A[1]!=0) Do10(B);
        if (B.A[2]!=0) Do20(B);
    }
    if (B.A[1]!=7){
        if (B.A[0]!=0)Do01(B);
        if (B.A[2]!=0)Do21(B);
    }
    if (B.A[2]!=4){
        if (B.A[1]!=0) Do12(B);
        if (B.A[0]!=0) Do02(B);
    }
}
    
main(){

    G[0].A[0]=0;
    G[0].A[1]=7;
    G[0].A[2]=4;
    G[0].tt=0;
    G[0].fa=0;

    i=0;

 
Sinh(G[0]);

for (int t = 0; t <= i; t++) {   // sinh tuyen tinh . i co the tang sau moi lan sinh . neu toi uu co the sinh lai sau moi lan  i thay doi  de co the bao quat nhung trong truong hop nay cungn da ra ket qua va thay k co bao phai la thuat toan toi uu :))
        Sinh(G[i]);
        if (Dung(G[i])) break;   // sinh den khi gap dieu kien dung , neu xoa dong nay di se sinh tat ca truong hop co the theo tuyen tinh
}

for (int h = 0; h <= i; h++)
{
    In(G[h]);
}

// sau khi in t truy lan luot tu node cuoi len tren dua theo fa cua no 
// vidu   5 6 0 tt 10 fa 9     day la node co bo la tt 9
//        5 2 4 tt 11 fa 10     day la node co bo la tt 10




}
