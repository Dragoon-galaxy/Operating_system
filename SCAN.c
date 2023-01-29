#include <stdio.h>
int main(){
    int i=0,j=0,choice;
    int size;
    int counter=0;
    printf("Enter the size of request queue:");
    scanf("%d",&size);
    int request_queue[size+1],r_w_head,ans[size+1],num;
    printf("Enter the request queue below:\n");
    for ( i = 0; i < size ; i++) {
        scanf("%d",&num);
        request_queue[i]=num;
    } 
    printf("Enter the current position of R/W head:");
    scanf("%d",&r_w_head);
    printf("Enter 0-to move towards larger value and 1-to move towards lower value:");
    scanf("%d",&choice);
    if (choice==0) {
        request_queue[size]=199;
        for ( i = 0; i < size+1; i++)
        {
            for ( j = 0; j < size-i-1; j++)
            {
                if(request_queue[j]>request_queue[j+1]){
                    int t = request_queue[j];
                    request_queue[j]=request_queue[j+1];
                    request_queue[j+1]=t;
                }
            }
            
        }
        for (i = 0; i < size+1; i++) {
        if(request_queue[i]>r_w_head){
            ans[counter]=request_queue[i];
            counter++;
        }
        }
        for ( i = 0; i < size+1; i++) {
            for ( j = 0; j < size-i-1; j++)
            {
                if(request_queue[j]<request_queue[j+1]){
                    int t = request_queue[j];
                    request_queue[j]=request_queue[j+1];
                    request_queue[j+1]=t;
                }
            }
        }
        for ( i = 0; i < size+1; i++){
        if (request_queue[i]<r_w_head) {
            ans[counter]=request_queue[i];
            counter++;
        }
        }
        int sop=(199-r_w_head)+(199-ans[size]);
        printf("Total number of seek operations:%d\n",sop);
        printf("Seek Sequence is:");
     for ( i = 0; i < size+1; i++){
        printf("%d ",ans[i]);
        }        
    }
    if (choice==1){
        request_queue[size]=0;
        for ( i = 0; i < size+1; i++)
        {
            for ( j = 0; j < size-i-1; j++)
            {
                if(request_queue[j]<request_queue[j+1]){
                    int t = request_queue[j];
                    request_queue[j]=request_queue[j+1];
                    request_queue[j+1]=t;
                }
            }
        }
        for (i = 0; i < size+1; i++){
        if(request_queue[i]<r_w_head){
            ans[counter]=request_queue[i];
            counter++;
        }
        }
        for ( i = 0; i < size+1; i++){
            for ( j = 0; j < size-i-1; j++)
            {
                if(request_queue[j]>request_queue[j+1]){
                    int t = request_queue[j];
                    request_queue[j]=request_queue[j+1];
                    request_queue[j+1]=t;
                }
            }
        }
        for ( i = 0; i < size+1; i++){
        if (request_queue[i]>r_w_head)
        {
            ans[counter]=request_queue[i];
            counter++;
        }   
        }
        int sop=(r_w_head)+(ans[size]);
        printf("Total number of seek operations:%d\n",sop);

         printf("Seek Sequence is:");
     for ( i = 0; i < size+1; i++) {
        printf("\n%d",ans[i]);
        }
    }
    return 0;
}

