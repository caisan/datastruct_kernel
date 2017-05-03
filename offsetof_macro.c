#include <stdio.h>
#include <stdlib.h>

#define offsetof(type, member) (size_t)&(((type*)0)->member)

#define container_of(ptr, type, member) ({ \
       const typeof( ((type*)0)->member )  *__mptr = (ptr); \
        (type *)( (char*)__mptr - offsetof(type, member) );})

typedef struct student_info
{
    int id;
    int age;
    char name[32];
}student_info;

int main() 
{
    size_t offset = 0;
    offset = offsetof(student_info, id);
    printf("%ld\n", offset);

    offset = offsetof(student_info, age);
    printf("%ld\n", offset);
    
    offset = offsetof(student_info, name);
    printf("%ld\n", offset);

    student_info *stu = (student_info *)malloc(sizeof(student_info));
    stu->age = 10;
    stu->id = 20;
    student_info *ptr= container_of(&(stu->age), student_info, age);
    student_info *ptr1= container_of(&(stu->id), student_info, id);
    printf("age:%d\n", ptr->age);
    printf("stu address:%p\n", stu);
    printf("ptr address:%p\n", ptr);
    printf("ptr1 address:%p\n", ptr1);
    return 0;
}
