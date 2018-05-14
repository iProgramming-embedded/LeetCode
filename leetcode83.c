/*题号：83  删除排序链表中的重复元素

给定一个排序链表，删除所有重复元素，使得每个元素只出现一次

示例：

输入：1->1->2

输出：1->2



解题思路：定义一个中间层，将节点中的数据与中间层比较，如果值相同，将值赋给中间层，节点使用当前中间层的指针，反之直接访问下一个*/

struct ListNode{  
int val;  
struct ListNode *next;  
}  
struct ListNode *deleteDuplictes(struct ListNode *head)  
{  
if(NULL==head){  
return NULL;  
}          //安全检查，如果头节点为NULL  
if(NULL==head->next)  
{  
return head;  
}        //如果下一节点为NULL，则返回头节点  
struct ListNode *p=head;  
struct ListNode *pre=NULL;  
while(NULL!=p)  
{  
if(pre!=NULL&&pre->val==p->val){          //括号中的条件设置很关键  （pre!=NULL）不可以放在右边，会导致“空指针内的成员访问，而链表中结点的使用比其他数据结构严格，一定要保证使用的结点不能为NULL，为NULL做出相应处理”）  
pre->next=p->next;  
p=pre->next;  
}  
}  
} 