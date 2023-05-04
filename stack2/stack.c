
#define STACK_SIZE 100

static int stack[STACK_SIZE];
static int tos; 					// top of stack

void push(int data)
{
	stack[tos] = data;
	++tos;	
}

int pop(void)
{
	--tos;
	return stack[tos];
}

