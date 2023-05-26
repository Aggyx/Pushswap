/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:52:32 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/26 14:25:32 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	void	printnode(t_Node *cpy)
{
	t_Node	*node;

	node = cpy;
	printf("\tPrint stack partition after partition\n");
	while (node != NULL)
	{
		printf("\tnode: %d\n", node->data);
		node = node->next;
	}
	printf("\n");
}

// Partition the linked list using the last element as the pivot
static	t_Node	*partition(t_Node	*head, t_Node	*end, t_Node	**newhead, t_Node	**newend)
{
	t_Node	*pivot;
	t_Node	*prev;
	t_Node	*current;
	t_Node	*tail;
	t_Node	*tmp;

	pivot = end;
	prev = NULL;
	current = head;
	tail = pivot;
	printf("Partitioning:\n");
	while (current != pivot)
	{
		if (current->data < pivot->data)
		{
			printf("\t\tCurrent %d is LOWER than pivot %d\n", current->data, pivot->data);
			if ((*newhead) == NULL)
			{	
				(*newhead) = current;
				printf("\t\tNewhead: %d\n", (*newhead)->data);
			}
			prev = current;
			current = current->next;
			printf("\t\tAvanzando current y prev\n");
		}
		else
		{
			printf("\t\tCurrent %d is GREATER than pivot %d\n", current->data, pivot->data);
			if (prev)
			{
				printf("\t\tPrev %d ", prev->data);
				printf("Prev->next %d is setting to one forward node ", prev->next->data);
				prev->next = current->next;
				printf("Prev->next is %d now. skipping %d\n", prev->next->data, current->data);
			}
			printf("\t\tsaving current->next %d into tmp\n", current->next->data);
			tmp = current->next;
			current->next = NULL;
			printf("\t\tSetting current->next to NULL now that is saved\n");
			if (tail->next != NULL)
				printf("\t\ttail->next %d",tail->next->data);
			else
				printf("\t\ttail->next is NULL\n");
			tail->next = current;
			printf("\t\ttail->next %d is set to current %d\n", tail->next->data, current->data);
			tail = current;
			printf("\t\ttail %d is set to current %d\n", tail->data, current->data);
			current = tmp;
			printf("\t\tCurrent %d is set to saved tmp %d\n", current->data, tmp->data);
		}
		printf("\n");
	}
	printnode(head);

	if ((*newhead) == NULL)
		(*newhead) = pivot;

	(*newend) = tail;
	printf("\tPivot: %d\n", pivot->data);
	return (pivot);
}

// The main function that implements QuickSort for a linked list
void	quickSortLinkedList(t_Node	**head, t_Node	**tail)
{
	t_Node	*newhead;
	t_Node	*newend;
	t_Node	*pivot;
	t_Node	*tmp;

	(void)tmp;
	if (*head == NULL || *head == *tail)
		return ;
	newhead = NULL;
	newend = NULL;
	pivot = partition(*head, *tail, &newhead, &newend);
	if (newhead != pivot)
	{
		tmp = newhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		quickSortLinkedList(&newhead, &tmp);
		tmp = newhead;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = pivot;
	}
	// pivot->next = NULL;
	// quickSortLinkedList(&pivot->next, tail);
	(*head) = newhead;
}

// // Driver code
// int main() {
//     t_Node* head = NULL;
//     push(&head, 10);
//     push(&head, 7);
//     push(&head, 8);
//     push(&head, 9);
//     push(&head, 1);
//     push(&head, 5);

//     printf("Linked List before sorting: \n");
//     printstack(head);

//     t_Node* tail = head;
//     while (tail->next != NULL)
//         tail = tail->next;

//     quickSortLinkedList(&head, &tail);

//     printf("Linked List after sorting: \n");
//     printstack(head);
//     return 0;
// }



/* hubi partition function la de arriba es la de Lomuto
 This function takes first element as pivot, and places
      all the elements smaller than the pivot on the left side
      and all the elements greater than the pivot on
      the right side. It returns the index of the last element
      on the smaller side '''
 
 
def partition(arr, low, high):
 
    pivot = arr[low]
    i = low - 1
    j = high + 1
 
    while (True):
 
        # Find leftmost element greater than
        # or equal to pivot
        i += 1
        while (arr[i] < pivot):
            i += 1
 
        # Find rightmost element smaller than
        # or equal to pivot
        j -= 1
        while (arr[j] > pivot):
            j -= 1
 
        # If two pointers met.
        if (i >= j):
            return j
 
        arr[i], arr[j] = arr[j], arr[i]*/