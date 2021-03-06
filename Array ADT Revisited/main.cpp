#include<stdio.h>
#include<stdlib.h>

// ARRAY STRUCTURE WITH POINTER, SIZE AND LENGTH
struct Array{
    int *ptr;
    int Size = 20;
    int length = 0;
};

// dISPLAY UPTO LENGTH
void display(struct Array *arr){
    for(int i=0;i<arr->length;i++){
        printf("%d\t",arr->ptr[i]);
    }
    printf("\n");
}

// ADDS TO LAST OF ARRAY
void Append(struct Array *arr, int data){
    arr->ptr[arr->length] = data;
    arr->length++;
}

// INSERT TO INDEX IN ARRAY
void Insert_Index(struct Array *arr, int index, int data){
    if(index >= 0 && index <arr->length){
        for(int i=arr->length;i>index;i--){
            arr->ptr[i] = arr->ptr[i-1];
        }
        arr->ptr[index] = data;
        arr->length++;
    }
}

// DELETE FROM INDEX
void Delete(struct Array *arr, int index){
    if(index >= 0 && index < arr->length){
            for(int i=index;i<arr->length-1;i++){
            arr->ptr[i] = arr->ptr[i+1];
        }
    }
    arr->length--;
}

// LINEARLY SEARCH ELEMENT
int linear_search(struct Array *arr, int data){
    for(int i=0;i<arr->length;i++){
        if(arr->ptr[i] == data){
            return i;
        }
    }
    return -1;
}

// BINARY SEARCH FOR ELEMENT
int binary_search(struct Array *arr, int low, int high, int key){
    int mid = (low+high)/2;
    if(arr->ptr[mid] == key){
        return mid;
    }
    else if(key > arr->ptr[mid]){
        return binary_search(arr,mid+1,high,key);
    }
    else if(key < arr->ptr[mid]){
        return binary_search(arr,low,mid-1,key);
    }
    else{
        return -1;
    }
}

// RECURSIVE SUM OF ALL ELEMENTS
int Sum(struct Array *arr, int n){
    if(n < 0){
        return 0;
    }
    return Sum(arr,n-1)+arr->ptr[n];
}

// REVERSE ARRAY USING ONE ANOTHER ARRAY
void Reverse(struct Array *arr){
    int *b = (int *)malloc(arr->length * sizeof(int));
    int i,j;
    for(i=arr->length-1,j=0;i>=0,j<arr->length;i--,j++){
        b[j] = arr->ptr[i];
    }
    for(i=0,j=0;i<arr->length;i++,j++){
        arr->ptr[i] = b[j];
    }
    display(arr);
}

// SWAP TWO ELEMENTS USING POINTERS
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// REVERSE WITHOUT USING A SECOND ARRAY
void Reverse2(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<=j){
        Swap(&arr->ptr[i],&arr->ptr[j]);
        i++;
        j--;
    }
    display(arr);
}

// LEFT SHIFT ELEMENTS -> 1 2 3 4 5 0
void left_shift(struct Array *arr){
    int i;
    for(i=0;i<arr->length-1;i++){
        arr->ptr[i] = arr->ptr[i+1];
    }
    arr->ptr[i] = 0;
    display(arr);
}

// RIGHT SHIFT ELEMENTS -> 0 1 2 3 4
void right_shift(struct Array *arr){
    int i;
    for(i=arr->length-1;i>0;i--){
        arr->ptr[i] = arr->ptr[i-1];
    }
    arr->ptr[i] = 0;
    display(arr);
}

// BUBBLE SORT WITH POINTER
void Bubble_Sort(struct Array *arr){
    int n = arr->length;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-1;j++){
            if(arr->ptr[j]>arr->ptr[j+1]){
                Swap(&arr->ptr[j],&arr->ptr[j+1]);
            }
        }
    }
    display(arr);
}

// INSERT INTO THE SORTED ARRAY
void Insert_Sorted(struct Array *arr,int data){
    int i = arr->length-1;
    while(i>=0 && data < arr->ptr[i]){
        arr->ptr[i+1] = arr->ptr[i];
        i--;
    }
    arr->ptr[i+1] = data;
    arr->length++;
}

// REARRANGING ELEMENTS i.e. -1 -2 0 1 2 3 ..
void Rearrange(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->ptr[i]<0){i++;}
        while(arr->ptr[j]>0){j--;}
        if(i<j){
            Swap(&arr->ptr[i],&arr->ptr[j]);
        }
    }
    display(arr);
}

int main(){
    struct Array a;
    a.ptr = (int *)malloc(20*sizeof(int));
    Append(&a,20);
    Append(&a,200);
    Append(&a,400);
    Append(&a,600);
    Append(&a,9000);
    Append(&a,-3);
    Append(&a,-45);
    Insert_Index(&a,1,400);
    display(&a);
    Delete(&a,1);
    display(&a);
    printf("%d",binary_search(&a,0,a.length-1,20));
    printf("\n%d\n",Sum(&a,a.length-1));
    Reverse(&a);
    Reverse2(&a);
    left_shift(&a);
    right_shift(&a);
    Insert_Index(&a,2,5000);
    //Bubble_Sort(&a);
    //Insert_Sorted(&a,300);
    display(&a);
    Rearrange(&a);
return 0;
}
