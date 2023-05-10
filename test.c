#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	unsigned int		nb;
	int					sign;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (nb > 2147483647 && sign == 1)
		return (-1);
	else if (nb > 2147483648 && sign == -1)
		return (0);
}


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;


void initialize(Stack *stack) {
    stack->top = NULL;
}

int is_empty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int x) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = stack->top;
    stack->top = new_node;
}
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    int x = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return x;
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->top->data;
}

void swap(Stack *stack) {
    if (stack->top && stack->top->next) {
        int temp = stack->top->data;
        stack->top->data = stack->top->next->data;
        stack->top->next->data = temp;
    }
}

void rotate(Stack *stack) {
    if (stack->top && stack->top->next) {
        Node *last_node = stack->top;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = stack->top;
        stack->top = stack->top->next;
        last_node->next->next = NULL;
    }
}

void reverse_rotate(Stack *stack) {
    if (stack->top && stack->top->next) {
        Node *prev_node = NULL;
        Node *curr_node = stack->top;
        while (curr_node->next != NULL) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        curr_node->next = stack->top;
        stack->top = curr_node;
        prev_node->next = NULL;
    }
}

void push_a_to_b(Stack *stack_a, Stack *stack_b) {
    if (!is_empty(stack_a)) {
        int x = pop(stack_a);
        push(stack_b, x);
    }
}

void push_b_to_a(Stack *stack_a, Stack *stack_b) {
    if (!is_empty(stack_b)) {
        int x = pop(stack_b);
        push(stack_a, x);
    }
}

void execute_instruction(Stack *stack_a, Stack *stack_b, const char *instruction) {
    if (strcmp(instruction, "sa") == 0) {
        swap(stack_a);
    } else if (strcmp(instruction, "sb") == 0) {
        swap(stack_b);
    } else if (strcmp(instruction, "ss") == 0) {
        swap(stack_a);
        swap(stack_b);
    } else if (strcmp(instruction, "pa") == 0) {
        push_b_to_a(stack_a, stack_b);
    } else if (strcmp(instruction, "pb") == 0) {
        push_a_to_b(stack_a, stack_b);
    } else if (strcmp(instruction, "ra") == 0) {
        rotate(stack_a);
    } else if (strcmp(instruction, "rb") == 0) {
        rotate(stack_b);
	} //faltan comandos
}


void sort_stack(Stack *stack_a, Stack *stack_b) {
    // Step 1: Create an empty stack B
    initialize(stack_b);

    // Step 2: Pop elements from stack A and push them onto stack B
    while (!is_empty(stack_a)) {
        int x = pop(stack_a);
        push(stack_b, x);
    }

    // Step 3: Pop elements from stack B and sort them into stack A
    while (!is_empty(stack_b)) {
        int x = pop(stack_b);

        // Step 5: Compare element from stack B with top element of stack A
        while (!is_empty(stack_a) && peek(stack_a) < x) {
            int y = pop(stack_a);
            push(stack_b, y);
        }

        // Step 6: Push element from stack B onto stack A
        push(stack_a, x);

        // Step 8: Repeat for all remaining elements in stack B
    }
}

int main(int argc, char *argv[]) {
    Stack stack_a, stack_b;
    initialize(&stack_a);
    initialize(&stack_b);

    // Read numbers from command line arguments and push them onto stack A
    for (int i = 1; i < argc; i++) {
        int x = ft_atoi(argv[i]);
        push(&stack_a, x);
    }
    
    // Print initial state of stack A
    printf("Stack A (initial state): ");
    Node *curr_node = stack_a.top;
    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
    printf("Sorted Stack;");
	sort_stack(&stack_a, &stack_b);
	Node *curr_node1 = stack_a.top;
    while (curr_node1 != NULL) {
        printf("%d ", curr_node1->data);
        curr_node1 = curr_node1->next;
    }
	printf("\n");

    return 0;
}

