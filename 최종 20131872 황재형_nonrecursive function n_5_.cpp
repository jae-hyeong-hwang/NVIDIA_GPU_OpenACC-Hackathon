#include<iostream>
using namespace std;
#define MAXSTACK 100
struct details {
	int number;
	char beg;
	char end;
	char aux;
};
struct stack {
	int top;
	struct details item[MAXSTACK];
};
void push(struct stack *s, struct details *current)
{
	if (s->top == MAXSTACK - 1)
	{
		cout << "Overflow";
		exit(1);
	}
	else
		s->item[++(s->top)] = *current;
	return;
}
void popandtest(struct stack *s, struct details *current, int *flag)
{
	if (s->top == -1) {
		*flag = 1;
		return;
	}
	*flag = 0;
	*current = s->item[s->top--];
	return;
}
void towers(int n, char begpeg, char endpeg, char auxpeg)
{
	struct stack s;
	struct details current;
	int flag;
	char temp;
	s.top = -1;
	current.number = n;
	current.end = endpeg;
	current.beg = begpeg;
	current.aux = auxpeg;
	while (1) {
		while (current.number != 1)
		{
			push(&s, &current);
			--current.number;
			temp = current.end;
			current.end = current.aux;
			current.aux = temp;
		}
		cout << "Move Disc 1 from " << current.beg << " to " << current.end << endl;
		popandtest(&s, &current, &flag);
		if (flag == 1)
			return;
		cout << "Move Disc " << current.number << " from " << current.beg << " to " << current.end << endl;
		--current.number;
		temp = current.beg;
		current.beg = current.aux;
		current.aux = temp;
	}
}
int main()
{
	int N;
	cout << "Enter the number of disk: ";
	N = 5;
	towers(N, 'b', 'c', 'a');
	return 0;
}