#include <stdio.h>
#include <stdlib.h>
#define MAX 11
#define mal (struct Calentry*)malloc(sizeof(struct Calentry));
static struct Calentry * head = NULL;
struct Calentry
{
    int value;
    char sym;
    struct Calentry * prev;
    struct Calentry * next;

};
struct Calentry * insert(int V,char S)
{
	if (head == NULL)
	{
		head = mal;
		head->prev = NULL;
		head->next = NULL;
		head->value = V;
		head->sym = S;
	}
	else
	{
		struct Calentry *end=head;
		for (; end->next!= NULL; end = end->next);
		struct Calentry * temp = end;
		end = end->next;
		end = mal;
		end->prev = temp;
		end->next = NULL;
		end->sym = S;
		end->value = V;
		temp->next = end;
	}
}
void foo(const char *in)
{
	char num[MAX];
	int Cn=0;
	for (int i = 0; in[i] != '\n'; ++i)
	{
		if (in[i] >= '0'&&in[i] <= '9')
		{
			num[Cn++] = in[i];
		}
		else if (in[i] == '+' || in[i] == '-' || in[i] == 'x' || in[i] == '/')
		{
			num[Cn] = '\0';
			insert(atoi(num), in[i]);
			Cn = 0;
		}
	}
	if (Cn==0)
		exit(1);
	else
		insert(atoi(num), '0');
}
void putlist()
{
	for (struct Calentry *t = head; t != NULL; t = t->next)
	{
		printf("%d %c\n", t->value, t->sym);
	}

}
int main()
{
	foo("123+123");
	putlist();
	getchar();
}