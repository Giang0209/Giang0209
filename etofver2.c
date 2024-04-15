
// day la chuong trinh nhap vao cac cap canh va cho ra prufercode cua no



#include<stdio.h>
#include<string.h>

#define MAX 10000


/* void Nhap(int *n, int A[][2], int B[]){   // nhap vao so dinh va thong tin canh ,bac cua dinh
    scanf("%d",n);               // nhap vao dia chi n chu k phai nhap vao noi dung con tro n tro den (*n)
    int i;                       // phai khai bao i ngoai vong lap
    for ( i = 0; i < *n-1; i++)  // phai truy nhap den noi dung bien n chua khong phai toi n( n mang dia chi)
    {
        scanf("%d %d",&A[i][0],&A[i][1]);
        
        B[A[i][0]]++;   // A[i][0] se tra ve stt dinh  => bac cua no la B[stt]++
        B[A[i][1]]++;
    }
    
}

 void Bac(int *n, int A[][2], int B[]){   // duyet tat ca cac canh va tang bac cua 2 dinh chua trong moi canh do
    int i;
    for ( i = 0; i < *n-2; i++)
    {
        B[A[i][0]]++;   // A[i][0] se tra ve stt dinh  => bac cua no la B[stt]++
        B[A[i][1]]++;
    }
    

}*/
int main(){
    int i,j,x,num1,num2;

      int v;  // chua so dinh cua tree
//    int e;  // chua so luong canh
    int A[MAX][2]={0};  // chua thong tin ve canh
    int D[MAX]={0};      //  chua bac cua dinh deg
    //Nhap(&v,A,D);        // truyen vao kieu con tro thi phai la mot dia chi
    
    int F[MAX]={0};
    int a=0;
    
    FILE *f;
   f = fopen("/home/long/Dropbox/DiscreteMaths/discreteMaths/roirac/1.prufer/input.txt","r");
 
   if(f == NULL)
   {
      printf("Error!");   
      return 1;             
   }
 //   scanf("%d %d",&num1,&num2);

   //fprintf(fptr,"%d %d",num1,num2);


 /*   while (!feof)
    {
        fscanf("%d %d",&)
    }
    */

   fscanf(f,"%d\n",&v);
   for (i=0;i<v-1;i++){
       fscanf(f,"%d %d\n",&A[i][0],&A[i][1]);
        
        D[A[i][0]]++;   // A[i][0] se tra ve stt dinh  => bac cua no la B[stt]++
        D[A[i][1]]++;

   }

   
   fclose(f);

 //  e=v-1;
/*    scanf("%d",&v);  
    e=v-1;

    
    for ( i = 0; i < v-1; i++)
    {
        scanf("%d %d",&A[i][0],&A[i][1]);
        
        D[A[i][0]]++;   // A[i][0] se tra ve stt dinh  => bac cua no la B[stt]++
        D[A[i][1]]++;
    }
*/
    for ( i = 0; i < v-2; i++){     // chi chay toi v-2 vi ma chi co n-2 phan tu 
        int min=MAX;   // bien luu tru ten dinh co bac nho  nhat hien tai
        
        for ( j = 0; j<v-1; j++){     //duyet qua tat ca cac canh
            if (D[   A[j][0]   ]==1&&A[j][0]!=0&&D[A[j][1]]!=0){   // neu bac cua mot canh bang 1 // chu y la bug neu cach do phai khac canh 0 thi moi dc xoa :)) fix cmn 2 ngay
                if (min > A[j][0]){   // bien min de so sanh xem dinh nao co bac nho nhat
                    min=A[j][0];     // min  se dc gan bang ten dinh 
                    x=j;  // bien x de dua chi so phan tu nho nhat ra ngoai
                }
            }
            if (D[   A[j][1]   ]==1&&A[j][1]!=0&&D[A[j][0]]!=0){ // chu y cai dinh lien ket voi no phai co bac khac 0 nua thi moi dc xoa do minh chay lai tu dau
                if (min > A[j][1]){
                    min=A[j][1];
                    x=j;  
                }
            }
            
            
        }   // het vong lap se cho ra min la ten dinh nho nhat va x la chi so canh chua no

        D[   A[x][0]]--;
        D[   A[x][1]]--; // xoa canh thi bac cua 2 dinh cua no se giam

        if (D[A[x][0]]==0)  
            F[i]=A[x][1];
            
        
        else 
            F[i]=A[x][0];
            
        


    }


    // muon debug doan nao thi dat dauu cham do truoc ham do

    for ( a = 0; a < v-2; a++)
    {
        printf("%d ",F[a]);
    }
    



    return 0;


}
