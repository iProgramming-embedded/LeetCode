给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode * head ,*p, *q, *pre;
	int carry = 0;
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	
	head = l1;
	p = head;
	
	while(l1 && l2){
		pre = p;
		p->val = l1->val + l2->val +carry;
		carry = 0;
		if(p->val > 9){
			p->val -= 10;
			carry = 1;
		}
		l1 = l1->next;
		l2 = l2->next;
		p = p->next;
	}
	if(!l1 && !l2){
		if(carry){
			q = (struct ListNode *)malloc(sizeof(struct ListNode));
			q->val = carry;
			q->next =NULL;
			pre->next = q;
		}
	}
	else if(l2){
		deeltail(pre, 12, carry);
	}
	else{
		deeltail(pre,l1,carry);
	}
	return head;
}

void deeltail(struct ListNode * pre,struct ListNode * r, int carry)
{
	struct ListNode *q;
	pre->next = r;
	q = pre->next;
	while(q){
		q->val += carry;
		if(q->val>9){
			q->val -= 10;
			carry =1;
		}else{
			carry = 0;
		}
		pre = q.
		q = q->next;
	}if(carry){
		q = (struct ListNode *)malloc(sizeof(struct ListNode));
		q->val = carry;
		q->next = NULL;
		pre->next = q;
	}
}