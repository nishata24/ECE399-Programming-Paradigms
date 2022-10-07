//
//  IS_Project1.c
//  ECE-399 Programming Paradigms
//  Professor Sable
//  Created by Nishat Ahmed on 6/13/22.
//

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

//swap function to reorder elements in selection sort algorithm
void swap(void *x, void *y, int size){
    char buffer [size];
    memcpy(buffer, x, size);
    memcpy(x, y, size);
    memcpy(y, buffer, size);
}

//function to compare integers in array
int IntCmp(void *int1, void *int2){
    int *ip1 = int1;
    int *ip2 = int2;
    if(*ip1 < *ip2){
        return 1;
    }
    else{
        return 0;
    }
}

//function to compare strings in array
int StrCmp(void *str1, void *str2){
    char *cp1 = *(char**)str1;
    char *cp2 = *(char**)str2;
    if((strcmp(cp1, cp2))<0){
        return 1;
    }
    else{
        return 0;
    }
}

//struct named student that contains names and GPAs of students
struct student{
    char *name;
    double gpa;
};

//function to compare GPAs (doubles) in array of structs
int DoubleCmp(void *d1, void *d2){
    struct student *dp1 = d1;
    struct student *dp2 = d2;
    if(dp1->gpa < dp2->gpa){
        return 1;
    }
    else{
        return 0;
    }
}

//function to compare names (strings) in array of structs
int StructStrCmp(void *s1, void *s2){
    struct student *c1 = s1;
    struct student *c2 = s2;
    if((strcmp(c1->name, c2->name))<0){
        return 1;
    }
    else{
        return 0;
    }
}

//function for sorting generic data types using selection sort algorithm
void selection_sort(void *array, int elems, int elem_size, int(*cmpfn)(void*, void*)){
    for(int i=0; i<elems-1; i++){
        void *elemAddr = (char*)array + i*elem_size; //obtain address of current element
        void *min = elemAddr; //pointer to minimum element
        for(int j = i+1; j<elems; j++){
            void *v1 = (char*)array + j*elem_size;
            if(cmpfn(v1, min)){
                min = v1; //update pointer to minimum element
            }
        }
        swap(min, elemAddr, elem_size);
    }
}

int main(){
    //test selection sort algorithm on array of integers
    int array1[] = {12, 25, 3, 10, 75, 59, 96, 80, 44, 7};
    selection_sort(array1, 10, sizeof(int), (int(*)(void*, void*))IntCmp);
    for(int i=0; i<10; i++){
        printf("%d ", array1[i]);
    }
    printf("\n");
    
    //test selection sort algorithm on array of strings
    char *array2[] = {"golf", "soccer", "football", "hockey", "basketball", "volleyball", "baseball", "tennis", "cricket", "badminton"};
    selection_sort(array2, 10, sizeof(char*), (int(*)(void*, void*))StrCmp);
    for(int i=0; i<10; i++){
        printf("%s ", array2[i]);
    }
    printf("\n");
    
    //test selection sort algorithm on array of structs
    struct student array3[6];
    
    array3[0].name = "Brandon";
    array3[0].gpa = 2.3;
    
    array3[1].name = "Amy";
    array3[1].gpa = 3.5;
    
    array3[2].name = "Kelvin";
    array3[2].gpa = 2.88;
    
    array3[3].name = "James";
    array3[3].gpa = 1.67;
    
    array3[4].name = "Nate";
    array3[4].gpa = 3.45;
    
    array3[5].name = "Mason";
    array3[5].gpa = 1.8;
    
    selection_sort(array3, 6, sizeof(struct student), (int(*)(void*, void*))StructStrCmp);
    for(int i=0; i<6; i++){
        printf("%s ", array3[i].name);
        printf("%f", array3[i].gpa);
        printf("\n");
    }
    
    selection_sort(array3, 6, sizeof(struct student), (int(*)(void*, void*))DoubleCmp);
    for(int i=0; i<6; i++){
        printf("%f ", array3[i].gpa);
        printf("%s ", array3[i].name);
        printf("\n");
    }
    return 0;
}
