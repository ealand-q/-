#include <stdio.h>
#include <stdlib.h>
#define NULL 0
typedef struct _Node {
	float coef;    // 系数    
	int expo;       // 指数    
	struct _Node* next; // 下一个节点指针
} Node;
// 创建空链表
Node* createList()
{
	Node* head = (Node*)malloc(sizeof(Node)); // 创建头结点    
	head->next = NULL;// 初始为空链表    
	return head;
}
// 显示表达式
void display(Node* head)
{
	// 判断是否为空链表    
	if (head->next == NULL)
	{
		printf("0\n");
		return;
	}
	Node* cur = head->next;
	while (cur != NULL)
	{
		if (cur != head->next && cur->coef > 0)
		{
			printf("+"); // 不是第一个元素，且系数为正数则输出加号        
		}
		if (cur->coef != 1 || cur->expo == 0)
		{
			printf("%.1f", cur->coef);   // 如果系数不为 1，或指数为 0，则输出系数        
		}
		if (cur->expo != 0)
		{
			printf("x"); // 指数大于 0，则输出 x        
		}
		if (cur->expo != 1 && cur->expo != 0)
		{
			printf("^%d", cur->expo); // 指数大于 1，则输出指数        
		}
		cur = cur->next;
	}
	printf("\n");
}
// 添加节点
void addNode(Node* head, float coefficient, int exponent)
{
	// 找到插入位置，确保链表按指数降序排列   
	Node* cur = head;
	while (cur->next != NULL && cur->next->expo > exponent)
	{
		cur = cur->next;
	}
	if (cur->next != NULL && cur->next->expo == exponent)
	{
		cur->next->coef += coefficient; // 同一项，则系数相加    
	}
	else
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->coef = coefficient;
		node->expo = exponent;
		node->next = cur->next;
		cur->next = node;
	}
}
// 释放链表所占用的内存
void destroyList(Node* head)
{
	Node* cur = head;
	while (cur != NULL)
	{
		Node* temp = cur->next;
		free(cur);
		cur = temp;
	}
}
// 合并两个多项式
Node* merge(Node* list1, Node* list2)
{
	Node* mergedList = createList();
	Node* cur1 = list1->next;
	Node* cur2 = list2->next;    // 双指针遍历链表，将较小的加入新链表    
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->expo > cur2->expo)
		{
			addNode(mergedList, cur1->coef, cur1->expo);
			cur1 = cur1->next;
		}
		else if (cur1->expo < cur2->expo)
		{
			addNode(mergedList, cur2->coef, cur2->expo);
			cur2 = cur2->next;
		}
		else
		{
			if (cur1->coef + cur2->coef != 0)
			{
				addNode(mergedList, cur1->coef + cur2->coef, cur1->expo);
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			else
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
	}
	// 将剩余的节点加入新链表    
	while (cur1 != NULL)
	{
		addNode(mergedList, cur1->coef, cur1->expo);
		cur1 = cur1->next;
	}
	while (cur2 != NULL)
	{
		addNode(mergedList, cur2->coef, cur2->expo);
		cur2 = cur2->next;
	}
	return mergedList;
}
int main()
{
	Node* list1 = createList();
	addNode(list1, 3, 3);
	addNode(list1, 3, 2);
	addNode(list1, -1, 7);
	addNode(list1, 5, 3);
	display(list1);
	Node* list2 = createList();
	addNode(list2, 2, 4);
	addNode(list2, 8, 3);
	addNode(list2, 4, 6);
	display(list2);
	Node* mergedList = merge(list1, list2);
	display(mergedList);
	destroyList(list1);
	destroyList(list2);
	destroyList(mergedList);
	return 0;
}
