#include<stdio.h>
#include<string.h>
 char words[5757][6]={0};
int visited[5757]={0};
int matranke[5757][5757]={0};
int khac(char *x, char *y);
void explore(int i);
int main()
{
  //Doc file
char temp[6];
FILE*file=fopen("sgb-words.txt","r");
if(!file)
{
return 1;
}
for(int i=0;i<5757;i++){
fscanf(file,"%s",temp);
strcpy(words[i], temp);
}

fclose(file);

//tao ma tran ke
for(int i=0;i<5757;i++){
for(int j=i+1;j<5757;j++)
{
if(khac(words[i],words[j])==1)
{
matranke[i][j]=1;
matranke[j][i]=1;
}
}
}
//Su dung dfs dem so tp lien thong
int count=0;
for(int i=0;i<5757;i++)
{
if(visited[i]==0){
count++;
explore(i);
}
}
printf("so thanh phan lien thong %d",count);
return 0;
}
void explore(int i){
  visited[i]=1;
for(int j=0;j<5757;j++)
{
if(matranke[i][j]==1&& i!=j)
{
if(visited[j]==0)
{
explore(j);
}
}
}
}

int khac(char *x, char *y)
{
  int total=0;
for(int i=0;i<5;i++)
{
if(x[i]!=y[i])
{
total++;
}
}
return total;
}
