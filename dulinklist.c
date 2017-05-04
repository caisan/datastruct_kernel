#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#define offsetof(type, member) (size_t)(&((type*)0)->member)

#define container_of(ptr, type, member) ({ \
        const typeof(((type*)0)->member)* __mptr = (ptr);   \
        (type*)((char*)__mptr - offsetof(type, member)) ;})

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)
#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member);
#define list_for_each(pos, head) \
    for (pos=(head)->next; pos!=(head);pos = pos->next)

typedef struct list_head {
    struct list_head *prev;
    struct list_head *next;
}list_head;
static inline void init_list_head(list_head *head)
{
    head->prev = head;
    head->next = head;
}
static inline void __list_add(list_head *new, list_head *prev, list_head *next)
{
    prev->next = new;
    new->prev = prev;
    new->next = next;
    next->prev = new;
}
static inline void list_add(list_head *new, list_head *head)
{
    __list_add(new, head, head->next);
}
static inline void list_add_tail(list_head *new, list_head *head)
{
    __list_add(new, head->prev, head);
}


/*TEST*/
typedef struct info
{
    uint32_t id;
    const char* name;
    const char* locate;
    struct list_head info_node;
}info;

info* get_info(uint32_t id, char* name, char* locate)
{
    info* node = (info*)malloc(sizeof(info));
    if( node == NULL ){
        return NULL;
    }
    node->id = id;
    node->name = name;
    node->locate = locate;
    return node;
}
static void display_info(const list_head *head)
{
    list_head *pos;
    info *node;
    list_for_each(pos, head)
    {
        node = list_entry(pos, info, info_node);
        printf("%u\t, %s\t, %s\t",
                node->id,node->name, node->locate );
    }
}
int main()
{
    info* info_list = (info*)malloc(sizeof(info));
    info* node_t;
    if(info_list== NULL){
        return -1;
    }
    list_head* head = &info_list->info_node;
    init_list_head(head);

    //insert three info
    node_t = get_info(001, "jia","AA");
    list_add_tail(&node_t->info_node, head);

    node_t = get_info(002, "yi","BB");
    list_add_tail(&node_t->info_node, head);
    
    node_t = get_info(003, "bing","CC");
    list_add_tail(&node_t->info_node, head);

    display_info(head);
    return 0;
}
