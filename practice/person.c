#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 255

typedef struct Person_s {
    char *name;
    int age;
} Person;

// function prototypes
Person * create_person(char *, int);
void destroy_person(Person *);
void introduce(Person *);


int main(void) {
    char name[MAX_SIZE];
    int age;
    
    printf("Enter Name: ");
    scanf("%s", name);
    
    printf("Enter Age: ");
    scanf("%d", &age);
    
    
    

    return 0;
}


Person * create_person(char *name, int age) {
    
    
}

void destroy_person(Person *p) {
    
    
}

void introduce(Person *p) {
    
    
}
