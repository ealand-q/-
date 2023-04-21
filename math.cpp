#include <stdio.h>
#include <stdlib.h>
#define NULL 0
typedef struct _Node {
	float coef;    // ϵ��    
	int expo;       // ָ��    
	struct _Node* next; // ��һ���ڵ�ָ��
} Node;
// ����������
Node* createList()
{
	Node* head = (Node*)malloc(sizeof(Node)); // ����ͷ���    
	head->next = NULL;// ��ʼΪ������    
	return head;
}
// ��ʾ���ʽ
void display(Node* head)
{
	// �ж��Ƿ�Ϊ������    
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
			printf("+"); // ���ǵ�һ��Ԫ�أ���ϵ��Ϊ����������Ӻ�        
		}
		if (cur->coef != 1 || cur->expo == 0)
		{
			printf("%.1f", cur->coef);   // ���ϵ����Ϊ 1����ָ��Ϊ 0�������ϵ��        
		}
		if (cur->expo != 0)
		{
			printf("x"); // ָ������ 0������� x        
		}
		if (cur->expo != 1 && cur->expo != 0)
		{
			printf("^%d", cur->expo); // ָ������ 1�������ָ��        
		}
		cur = cur->next;
	}
	printf("\n");
}
// ��ӽڵ�
void addNode(Node* head, float coefficient, int exponent)
{
	// �ҵ�����λ�ã�ȷ������ָ����������   
	Node* cur = head;
	while (cur->next != NULL && cur->next->expo > exponent)
	{
		cur = cur->next;
	}
	if (cur->next != NULL && cur->next->expo == exponent)
	{
		cur->next->coef += coefficient; // ͬһ���ϵ�����    
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
// �ͷ�������ռ�õ��ڴ�
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
// �ϲ���������ʽ
Node* merge(Node* list1, Node* list2)
{
	Node* mergedList = createList();
	Node* cur1 = list1->next;
	Node* cur2 = list2->next;    // ˫ָ�������������С�ļ���������    
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
	// ��ʣ��Ľڵ����������    
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
