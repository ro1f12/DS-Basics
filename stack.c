//Integer stack implementation
//@rofi
#include<stdio.h>
#include<stdlib.h>

//stack structure
typedef struct{
	int *arr;
	int size;
	int top;
}stack; 


//operatins
void create(stack *s, int size)
{
	s->arr = (int*)malloc(size*sizeof(int));
	s->size = size;
	s->top = -1;
}

int is_empty(stack *s)
{
	return(s->top == -1);
}


int is_full(stack *s)
{
	return(s->top == s->size-1);
}

//push item
int push(stack *s, int item)
{
	if(!is_full(s)){
		s->arr[++s->top] = item;
		return 1;
	}
	return 0;
}

//free the memory
void stack_dispose(stack *s)
{
	free(s->arr);
}

//pop item
int pop(stack *s)
{
	if(!is_empty(s)){
		return s->arr[s->top--];
	}
	return -1;
}

//display the stack
void display(stack *s)
{
	if(!is_empty(s)){
		int i= s->top;
		while(i>=0){
			printf("\t\t\t|_%d_|\n", s->arr[i--]);
		}
	}else{
		printf("Empty stack!!!\n");
	}
}


//driver code
int main()
{
	stack s;
	//create stack
	create(&s, 10);
	
	//push 
	for(int i=0; i<10; i++){
		push(&s, i);
	}
	//display
	display(&s);
	for(int i=0; i<10; i++){
		printf("Item popped is: %d\n",pop(&s));
		//displaying after popping
		display(&s);
	}
	//free the memory
	stack_dispose(&s);
	//printf("size of %lu", sizeof(s.arr));
	return 0;
}

