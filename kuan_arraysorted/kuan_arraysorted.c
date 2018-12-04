#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int main()
{
    int *prarr,*mark;
    int n=0;
    while(scanf("%d",&n)&&n!=-1){
        prarr=(int *)malloc(sizeof(int)*n);
        mark=(int *)malloc(sizeof(int)*n);
        memset(prarr, 0, sizeof(prarr));
        memset(mark, 1, sizeof(mark));
        for(int in=0;in<n;in++){
            scanf("%d",&prarr[in]);
        }
        for(int i=0;i<n;i++){
            if(!mark[i]) continue;
            for(int j=i+1;j<n;j++){
                if(prarr[i]==prarr[j])
                    mark[j]=0;//重复出现的标为0
            }
        }//for i
        //根据标志位输出
        for(int i=0;i<n;i++){
            if(mark[i]){
                printf("%d ",prarr[i]);
            }
        }
        putchar('\n');//一组结束
    }
    return 0;
}


