//
//  main.c
//  Study
//
//  Created by hyobeom han on 2020/07/23.
//  Copyright © 2020 hyobeom han. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//study


struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
};

void Append(struct Array *arr, int x){
  
    if(arr->length<arr->size){
        arr->A[arr->length++] = x;
    }
        };


void Insert(struct Array *arr, int index, int x){
    int i;
    if(index>=0 && index <= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    };
}

int Delete(struct Array *arr, int index){
    int i;
    int x=0;
    if(index>=0 && index < arr->length){
        
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
        
        
    };
    return 0;
};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};

int LinearSearch(struct Array *arr, int key){
    
    int i;
    
    for(i=0;i<arr->length;i++){
        if(arr->A[i] == key){
            swap(&arr->A[i], &arr->A[0]);
            return i;
        };
    }
    
    return -1;
};

int BinarySearch(struct Array *arr, int key){
   
    int l = 0;
    int h = arr->length-1;
    
    while(l<=h){
        int m = (l+h)/2;
    if(key== arr->A[m]){
        return m;
    } else if(key > arr->A[m]){
        l = m+1;
    } else{
        h = m -1;
    }
    }
    return -1;
};


int RBinarySearch(struct Array *arr, int key, int l, int h){
    
    if(l<=h){
        int m = (l+h)/2;
        if(key==arr->A[m]){
            return m;
        } else if(key>arr->A[m]){
            return RBinarySearch(arr, key, m+1, h);
        } else if(key<arr->A[m]){
            return RBinarySearch(arr, key, l, m-1);
        }
    }
    return -1;
};

int Max(struct Array *arr){
    int i;
    int max = arr->A[0];
    for(i=1; i<arr->length; i++){
        if(arr->A[i]> max){
            max = arr->A[i];
        }
    }
    return max;
};

int Min(struct Array *arr){
    int i;
    int min = arr->A[0];
    for(i=1;i<arr->length;i++){
        if(arr->A[i]<min){
            min = arr->A[i];
        }
    }
    return min;
};

int Sum(struct Array arr){
    int i;
    int sum = arr.A[0];
    for(i=1;i<arr.length;i++){
        sum += arr.A[i];
    }
    
    return sum;
}

int Get(struct Array arr, int index){
    if(index>=0 && index <arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length){
        arr->A[index] = x;
    }
}

void Reverse(struct Array *arr){
    int i;
    int tmp[arr->size];
    for(i=0;i<arr->length;i++){
        tmp[arr->length-i-1] = arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i] = tmp[i];
    }
}

void ReverseT(struct Array *arr){
    int i,j;
    int *B;
    B = (int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1, j=0;i>=0;i--,j++){
        B[j] = arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i] = B[i];
    }
    free(B);
}

void ReverseSwap(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}



void LeftRotation(struct Array *arr){
    int i;
    int tmp;
    tmp = arr->A[0];
    for(i=0;i<arr->length-1;i++){
        arr->A[i]= arr->A[i+1];
    }
    arr->A[arr->length-1] = tmp;
}

void LeftShift(struct Array *arr){
    int i;
    for(i=0;i<arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
}

void SortedInsert(struct Array *arr, int x){
    int i = arr->length-1;
    
    if(arr->length == arr->size)
        return;
    
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int IsSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}




float Average(struct Array *arr){
    int i;
    int total = 0;
    for(i=0;i<arr->length; i++){
        total += arr->A[i];
    }
    return (float)total/arr->length;
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        } else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=arr1->length + arr2->length;
    arr3->size = 10;
    
    return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *newArr;
    newArr = (struct Array *)malloc(sizeof(struct Array));
   
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            newArr->A[k++] = arr1->A[i++];
           
        } else if(arr1->A[i] == arr2->A[j]){
            newArr->A[k++] = arr1->A[i++];
            j++;
        } else{
            newArr->A[k++] = arr2->A[j++];
        }
    }
    
    for(;i<arr1->length;i++){
        newArr->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        newArr->A[k++]=arr2->A[j];
    }
    newArr->length=k;
    newArr->size = 10;
    return newArr;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *newArr;
    newArr = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        } else if(arr1->A[i] == arr2->A[j]){
            newArr->A[k++] = arr1->A[i++];
            j++;
        } else{
            j++;
        }
    }
    newArr->length=k;
    newArr->size = 10;
    return newArr;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2){
    int i,k,j;
    i=k=j=0;
    struct Array *newArr;
    newArr = (struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            newArr->A[k++] = arr1->A[i++];
        } else if(arr1->A[i] == arr2->A[j]){
            i++;
            j++;
        } else{
            j++;
        }
    }
    for(;i<arr1->length;i++){
        newArr->A[k++] = arr1->A[i];
    }
    newArr->length=k;
    newArr->size = 10;
    return newArr;
}



int main(int argc, const char * argv[]) {
  
//    struct Array arr1;
//    int ch;
//    int x;
//    int index;
//
//    printf("Enter Size of Array");
//    scanf("%d",&arr1.size);
//    arr1.A = (int *)malloc(arr1.size*sizeof(int));
//    do{
//    printf("\nMenu\n");
//    printf("1. Insert\n");
//    printf("2. Delete\n");
//    printf("3. Search\n");
//    printf("4. Sum\n");
//    printf("5. Display\n");
//    printf("6. Exit\n");
//
//    printf("Enter your choice ");
//    scanf("%d",&ch);
//
//    switch(ch){
//        case 1: printf("Enter an element and index ");
//            scanf("%d%d", &x,&index);
//            Insert(&arr1, index, x);
//            break;
//        case 2: printf("Enter index");
//            scanf("%d", &index);
//            x=Delete(&arr1, index);
//            printf("Deleted element is %d\n", x);
//            break;
//        case 3: printf("Enter an element to search");
//            scanf("%d", &x);
//            index = LinearSearch(&arr1, x);
//            printf("Element index is %d", index);
//            break;
//        case 4: printf("Sum is %d\n", Sum(arr1));
//            break;
//        case 5: Display(arr1);
//
//
//    }
//
//    }while(ch<6);
//
    
    struct Array arr;
    int i;
    arr.A = (int *)malloc(sizeof(struct Array));
    arr.length = 11;
    arr.size = 15;
    
    for(i=0;i<arr.length;i++){
        if(i>5){
            Set(&arr, i, i+7);
        }else{
            Set(&arr, i, i+6);
        }
    }
   
   
    Display(arr);
    
    
    return 0;
}


