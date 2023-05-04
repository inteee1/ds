#define QUEUE_SIZE 100

static int queue[QUEUE_SIZE];
static int front;
static int rear;

void push(int data)
{
	queue[rear] = data;
	++rear;
}

int pop(void)
{
	int i = front;
	++front;
	return queue[i];
}



