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
    int A[10];
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

int Sum(struct Array *arr){
    int i;
    int sum = arr->A[0];
    for(i=1;i<arr->length;i++){
        sum += arr->A[i];
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

int Average(struct Array *arr){
    int i;
    int total = 0;
    for(i=0;i<arr->length; i++){
        total += arr->A[i];
    }
    return total/arr->length;
}

int main(int argc, const char * argv[]) {
  
    struct Array arr = {{2,3,4,5,6}, 10, 5};
   
    printf("%d\n", Average(&arr));
    Display(arr);
    
    return 0;
}


