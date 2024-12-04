#include<stdio.h>
#include<stdlib.h>
void printContent(int *arr,int *n){
    for(int i=0;i<*n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void insertBeginning(int *arr,int *n){
    int ele;
    printf("Enter element you want to insert : ");
    scanf("%d",&ele);
    for(int i=*n-1;i>=0;i--)
        arr[i+1]=arr[i];
    arr[0]=ele;
    (*n)++;
    printf("Array element after insertion at beginning \n");
    printContent(arr,n);
}
void insertEnd(int *arr,int *n){
    int ele;
    printf("Enter element you want to insert : ");
    scanf("%d",&ele);
    arr[*n]=ele;
    (*n)++;
    printf("Array element after insertion at end \n");
    printContent(arr,n);
}
void insertNthLocation(int *arr,int *n){
    int ele,pos;
    printf("Enter element you want to insert : ");
    scanf("%d",&ele);
    printf("Enter the position of insertion : ");
    scanf("%d",&pos);
    if(pos<0||pos>*n){
        printf("Invalid index \n");
        return;
    }
    for(int i=(*n-1);i>=pos;i--)
        arr[i+1]=arr[i];
    arr[pos]=ele;
    (*n)++;
    printf("Array element after insertion at given location \n");
    printContent(arr,n);
}
void insertAfterData(int *arr,int *n){
    int ele,pos=-1,data;
    printf("Enter element you want to insert : ");
    scanf("%d",&ele);
    printf("Enter the data after which you want to insert : ");
    scanf("%d",&data);
    for(int i=0;i<*n;i++)
        if(arr[i]==data){
            pos=i;
            break;
        }
    if(pos==-1){
        printf("Data not present so can't insert \n");
        return;
    }
    for(int i=*n;i>pos+1;i--)
        arr[i]=arr[i-1];
    arr[pos+1]=ele;
    (*n)++;
    printf("Array element after insertion at given data \n");
    printContent(arr,n);
}
void deleteBeginning(int *arr,int *n){
    for(int i=0;i<*n;i++)
        arr[i]=arr[i+1];
    (*n)--;
    printf("Array element after deletion from beginning \n");
    printContent(arr,n);
}
void deleteEnd(int *arr,int *n){
    (*n)--;
    printf("Array element after deletion from end \n");
    printContent(arr,n);
}
void deletNthlocation(int *arr,int *n){
    int pos;
    printf("Enter the position of element you want to delete : ");
    scanf("%d",&pos);
    if(pos<0||pos>(*n-1)){
        printf("Invalid index \n");
        return;
    }
    for(int i=pos;i<*n;i++)
        arr[i]=arr[i+1];
    (*n)--;
    printf("Array element after deletion from given index \n");
    printContent(arr,n);
}
void deleteData(int *arr,int *n){
    int data,found=0,index=0;
    printf("Enter the data you want to delete : ");
    scanf("%d",&data);
    for(int i=0;i<*n;i++){
        if(arr[i]!=data)
            arr[index++]=arr[i];
        else    found=1;
    }
    if(!found){
        printf("Data not present \n");
        return;
    }
    *n=index;
    printf("Array element after deletion of all same inputted data \n");
    printContent(arr,n);
}
void deleteDataFirst(int *arr,int *n){
    int data,found=0;
    printf("Enter the data you want to delete : ");
    scanf("%d",&data);
    for(int i=0;i<*n;i++){
        if(arr[i]==data){
            found=1;
            for(int j=i;j<*n;j++)
                arr[j]=arr[j+1];
            (*n)--;
            break;
        }
    }
    if(!found){
        printf("Data not present \n");
        return;
    }
    printf("Array element after deletion of data from first occurrence \n");
    printContent(arr,n);
}
void sortAscending(int *arr,int *n){
    int flag=1;
    for(int i=0;i<(*n-1);i++){
        flag=0;
        for(int j=0;j<(*n-i-1);j++)
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        if(!flag) break;
    }
    printf("Array elements after sorting in ascending order \n");
    printContent(arr,n);
}
void sortDescending(int *arr,int *n){
    int flag=1;
    for(int i=0;i<(*n-1);i++){
        flag=0;
        for(int j=0;j<(*n-i-1);j++)
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        if(!flag) break;
    }
    printf("Array elements after sorting in descending order \n");
    printContent(arr,n);
}
void searchData(int *arr,int *n){
    int data,flag=0;
    printf("Enter the data to search : ");
    scanf("%d",&data);
    for(int i=0;i<*n;i++)
        if(arr[i]==data){
            flag=1;
            break;
        }
    if(flag)    printf("Element is present \n");
    else    printf("Element is not present \n");
}
void countNumberOfOccurrences(int *arr,int *n){
    int data,count=0;
    printf("Enter the data to search : ");
    scanf("%d",&data);
    for(int i=0;i<*n;i++)
        if(arr[i]==data)
            count++;
    printf("No of occurrences of data = %d \n",count);
}
void reportIndex(int *arr,int *n){
    int data,index=-1;
    printf("Enter the data to search : ");
    scanf("%d",&data);
    for(int i=0;i<*n;i++)
        if(arr[i]==data){
            index=i;
            break;
        }
    if(index==-1)   printf("Element not present \n");
    else    printf("First index of given element is = %d \n",index);
}
int main(){
    int *arr;
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of array \n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertBeginning(arr,&n);
    insertEnd(arr,&n);
    insertNthLocation(arr,&n);
    insertAfterData(arr,&n);
    deleteBeginning(arr,&n);
    deleteEnd(arr,&n);
    deletNthlocation(arr,&n);
    deleteData(arr,&n);
    deleteDataFirst(arr,&n);
    sortAscending(arr,&n);
    sortDescending(arr,&n);
    searchData(arr,&n);
    countNumberOfOccurrences(arr,&n);
    reportIndex(arr,&n);
    return 0;
}