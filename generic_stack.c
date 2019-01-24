//@rofi
//generic stack implementation


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//generic stack structure
typedef struct{
	void *elems;
	int elemSize;
	int logLength;
	int allocLength;
}stack;


//functions declarations
void StackNew(stack *s,int elemSize);
void StackDispose(stack *s);
int StackEmpty(const stack *s);
void StackPush(stack *s, const void *elemAddr);
void StackPop(stack *s, void *elemAddr);

//definitions
#define kInitialAllocationSize 4
void StackNew(stack *s,int elemSize)
{
	assert(elemSize > 0);
	s->elemSize = elemSize;
	s->logLength = 0;
	s->allocLength = kInitialAllocationSize;
	s->elems = malloc(kInitialAllocationSize * elemSize);
	assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
	free(s->elems);
}



int StackEmpty(const stack *s)
{
	return s->logLength == 0;
}


void StackPush(stack *s, const void *elemAddr)
{
	void *destAddr;
	if(s->logLength == s->allocLength){
		s->allocLength *= 2;
		s->elems = realloc(s->elems, s->allocLength * s->elemSize);
		assert(s->elems != NULL);
	}
	destAddr = (char *)s->elems + s->logLength * s->elemSize;
	memcpy(destAddr, elemAddr, s->elemSize);
	s->logLength++;
	
}




void StackPop(stack *s, void *elemAddr)
{
	const void *sourceAddr;
	assert(!StackEmpty(s));
	//
	s->logLength--;
	sourceAddr = (const char *)s->elems + s->logLength * s->elemSize;
	memcpy(elemAddr, sourceAddr, s->elemSize);
}

void display(stack *s)
{
	/**
	if(!StackEmpty(s)){
		for(int i=s->logLength; i>0; i--){
			printf("\t\t|_%d_|\n", *(int*)(s->elems)+i);
		}
	}else{
		printf("\t\tEmpty Stack\n");
	}
	**/
	//generic display function
	//can be added extended for
	//more types 
	if(!StackEmpty(s)){
		//switch case to determine type of stack
		switch(s->elemSize){
			case sizeof(int):{
						 for(int i=s->logLength; i>=0; i--){
                        				printf("\t\t|_%d_|\n", *(int*)(s->elems)+i);
                				}
						 break;

					 }
			case sizeof(char):{
                                                 for(int i=s->logLength; i>0; i--){
                                                        printf("\t\t|_%c_|\n", *(int*)(s->elems)+i);
                                          		}
                                                 break;

                                         }
		       default: {
					printf("invalid type !!!!");
					break;
				}

		}

        
        }else{
                printf("\t\tEmpty Stack\n");
        }
}




//driver code
int main(int argc, char *argv[])
{
	//testing for int stack
	printf("\t\t\t\t\tInteger Stack\t\t\t\t\n");
	int val;
	stack intStack;
	StackNew(&intStack, sizeof(int));
	//StackNew(&intStack, 0);
	//display(&intStack);
	for(val = 0; val < 8; val++)
		StackPush(&intStack, &val);
	while (!StackEmpty(&intStack)){
		StackPop(&intStack, &val);
		display(&intStack);
		printf("\t\tPopped item is: %d\n", val);
		//display(&intStack);
	}
	//display(&intStack);
	StackDispose(&intStack);
	


	//testing for char stack
	/**
	printf("\t\t\t\t\tCharacter Stack\t\t\t\t\n");
	char item;
        stack charStack;
        StackNew(&charStack, sizeof(char));
        display(&charStack);
	for(int i=67; i<=75; i++){
		char pushChar = (char)i;
		//push item
        	StackPush(&charStack, &pushChar);
	}
	display(&charStack);
        while (!StackEmpty(&charStack)){
                StackPop(&charStack, &item);
                printf("\t\tPopped item is: %c\n", item);
                display(&charStack);
        }
        StackDispose(&charStack);
	**/
	return 0;
}
