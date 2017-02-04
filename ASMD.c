//只有上帝和我看得懂这个代码
#include <stdio.h>
#include <stdlib.h>
#define MAX 11
#define mal (struct Calentry*)malloc(sizeof(struct Calentry));
void putlist(struct Calentry *);
void insert(struct Calentry **, int, char);
int ASMD(struct Calentry *);
void MD(struct Calentry **); 
struct Calentry *ana_str(const char *);
void AS(struct Calentry **);

struct Calentry
{
	int value;
	char sym;
	struct Calentry * prev;
	struct Calentry * next;

};
void insert(struct Calentry **p, int V, char S)
{
	struct Calentry* head = *p;
	if (head == NULL)
	{
		head = mal;
		head->prev = NULL;
		head->next = NULL;
		head->value = V;
		head->sym = S;
		*p = head;
	}
	else
	{
		struct Calentry *end = *p;
		for (; end->next != NULL; end = end->next);
		struct Calentry * temp = end;
		end = end->next;
		end = mal;
		end->next = NULL;
		end->sym = S;
		end->value = V;
		end->prev = temp;
		temp->next = end;
	}
}
struct Calentry *ana_str(const char *in)
{
	struct Calentry *head = NULL;
	char num[MAX];
	int Cn = 0;
	for (int i = 0; in[i] != '\0'; ++i)
	{
		if (in[i] >= '0'&&in[i] <= '9')
		{
			num[Cn++] = in[i];
		}
		else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
		{
			num[Cn] = '\0';
			insert(&head, atoi(num), in[i]);
			Cn = 0;
		}
	}
	if (Cn == 0)
		exit(1);
	else
	{
		num[Cn] = '\0';
		insert(&head, atoi(num), '0');
	}
	return head;
	//putlist();
}
void MD(struct Calentry **p)
{
	struct Calentry *two, *pre;
	struct Calentry *t = *p;
	int v;
	while (t->next != NULL)
	{
		if (t->sym == '*' || t->sym == '/')
		{
			pre = t->prev;
			two = t->next;
			v = (t->sym == '*') ? (t->value *two->value) : (t->value / two->value);
			if (t == *p)
				*p = two;
			free(t);
			if (pre != NULL)
				pre->next = two;
			two->value = v;
			t = two;
		}

		else if (t->next != NULL)
		{
			t = t->next;
		}
	}
	//putlist();
}

void AS(struct Calentry **p)
{
	struct Calentry *two, *pre;
	struct Calentry *t = *p;
	int v;
	while (t->next != NULL)
	{
		if (t->sym == '+' || t->sym == '-')
		{
			pre = t->prev;
			two = t->next;
			v = (t->sym == '+') ? (t->value + two->value) : (t->value - two->value);
			if (t == *p)
				*p = two;
			free(t);
			if (pre != NULL)
				pre->next = two;
			two->value = v;
			t = two;
		}

		else if (t->next != NULL)
		{
			t = t->next;
		}
	}
	//putlist();
}
int ASMD(struct Calentry *head)
{
	int value;
	MD(&head);
	AS(&head);
	value = (head)->value;
	free(head);
	return value;
}
void putlist(struct Calentry *head)
{
	for (struct Calentry *t = head; t != NULL; t = t->next)
	{
		printf("%d %c\n", t->value, t->sym);
	}
	printf("\n");
}
//现在只有上帝了