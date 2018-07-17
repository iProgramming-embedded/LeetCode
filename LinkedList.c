1，单链表
2，链表遍历，增删查改
3，双向链表
4，鱼数笔记操作系统数据结构

1，
#include<stdio.h>
typedef struct node{
  int data;
  struct node *pNext;
}node;
node *create_node(int data)
{
  node *p = (node *)malloc(sizeof(node));
  if(p == NULL){
    printf("malloc error!\n");
    return NULL;
  }
}
void insert_tail(node * ph,node * new)
{
  node *p = ph;
  while(NULL != p->pNext){
    p = p->pNext;
  };
  p->pNext = new;
}
int main()
{
  node * ph =create_tail(1);
  insert_tail(ph,create_tail(2));
  insert_tail(ph,create_tail(3));
  printf("node1 data:%d\n",ph->data);
  printf("dode2 data:%d\n",ph->pNext->data);
  printf("node3 data:%d\n",ph->pNext->pNext->data);
}
//无头节点
void list_for_each1(ndoe *ph)
{
  node * p =ph;
  while(NULL != p->pNext){
    printf("node data:%d\n",p->data);
    p=p->pNext;
  }
  printf("node data:%d\n",p->data);
}
//有头节点
void list_for_each2(node *ph)
{
  node * p = ph;
  while(NULL != p ){
    p = p -> pNext;
    printf("node data:%d\n",p->data);
  } 
}
//增删查改
void delete_node（node *pH, int data）
｛
  node *p = pH;
  node *pPrev = NULL;
  while(NULL != p->pNext){
    pPrev = p;
    p = p->pNext;
    if (p->data == data){
      if(NULL == p->pNext){
        pPrev->pNext = NULL;
        free(p);
      }
      else{
        pPrev->pNext = p->pNext;
        free(p);
      }
      return 0;
    }
  }
  printf("没有要删除的节点\n");
  return -1；
｝
//双向链表
typedef struct node{
  int data;
  struct node *pNext;
  struct node *pPrev;
}node;
node * create_node(int data)
{
  node * p = (node *)malloc(sizeof(node));
  if(NULL == p){
    printf("malloc error\n");
    return NULL;
  }
     p->data = data;
    p->pPrev = NULL;
    p->pNext = NULL;
    
    return p;
}
void insert_tail(node * pH, node * new)
{
    struct node *p = pH;
    while(NULL != p->pNext){
      p = p->pNext;
    }
    
    p->pNext = new;
    new->pPrev = p;
}
void insert_head(node * pH, node * new)
{
  new->pNext = pH->pNext;
  
  if(NULL != pH->pNext)
    pH->pNext->pPrev = new;
    
  pH->pNext = new;
  
  new->pPrev = pH;
}
//正向遍历
struct node * list_for_each(node * pH)
{
  node * p = pH;
  if(NULL == p){
    return NUll;
  }
  while(NULL != p->pNext){
    p = p->pNext;
    printf("data = %d.\n",p->data);
  }
  return p;
}
//逆向遍历
#inlcude<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  node * pPrev;
  node * pNext;
}node;
node * list_for_each(node * pH);
void list_for_reverse(node * pTail)
{
  node * p = pTail;
  
  while(NULL != p->pPrev){
    printf("data = %d.\n",p->data);
    p = p->pPrev;
  }
}
int main()
{
  node * pHeader = create_node(0);
  insert_tail(pHeader,create_node(0));
  insert_tail(pHeader,create_node(1));
  insert_tail(pHeader,create_node(2));
  
  printf("正向遍历：\n");
  node * pTail = list_for_each(pHeader);
  printf("逆向遍历：\n");
  list_for_reverse(pTail);
  return 0;
}
双向链表的删除与实际应用
链表的实际应用

struct list_head{
  struct list_head *next,*prev;
}
#define LIST_HEAD(name){&(name),&(name)}
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)
static inline void INIT_LIST_HEAD(struct list_head *list){
  list->next = list;
  list->prev = list;
}//define的使用
