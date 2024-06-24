#include<stdio.h>
int MAX[3] ={10,7,4};
typedef struct
{
int a[3];
}node;
int visited[11][8][4]={0};
node pouring(node x,int i,int j);
void draw(node x, node y, FILE*file);
void highlight(node x,FILE*file);
void dsf(node x,FILE*file);
int main(){
  node origin;
scanf("%d %d %d", &origin.a[0], &origin.a[1], &origin.a[2]);
FILE*flie= fopen("dothi.dot","w");
if(!file)
{
   return 1;
}
fprintf(file, "digraph dothi\n");
fprintf(file, "{\n");
dfs(origin,file);
fprintf(file, "}\n");
fclose(file);
return 0;
}
void dfs(node x, FILE*file)
{
  visited[x.a[0]][x.a[1]][x.a[2]]=1;
for(int i=0;i<3;i++)
{
   for(int j=0;j<3;j++)
   {
      if(i!=j)
      {
        node tmp=pouring(x,i,j);
        if(visited[tmp.a[0]][tmp.a[1]][tmp.a[2]]==0)
         {
            draw(x,tmp,file);
            if(tmp.a[1]==2||tmp.a[2]==2)
             {
               highlight(tmp, file);
             }
              dfs (tmp,file);
         }
      }
   }
 }
}
void highlight(node x,FILE*file)
{
  fprintf(file,"\"%d,%d,%d\"[fillcolor=\"red\",style=filled],\n",x.a[0],x.a[1],x.a[2]);
}
node pouring(node x,int i, int j)
{
   node tmp;
   for(int i=0;i<3;i++)
   {
     tmp.a[i]=x.a[i];
   }
   if(x.a[i]+x.a[j]>MAX[j])
   {
    tmp.a[j]=MAX[j];
    tmp.a[i]=x.a[i]+x.a[j]-MAX[j];
   }else
   {
    tmp.a[j]=x.a[j]+x.a[i];
    tmp.a[i]=0;
   }
  return tmp;
}
void draw(node x, node y, FILE*file)
{
  fprintf(file,"\"%d,%d,%d\" -> \"%d,%d,%d\";\n",x.a[0],x.a[1],x.a[2],y.a[0],y.a[1],y.a[2]);
}
