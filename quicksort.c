/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:52:32 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/25 16:44:16 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

// C code to implement quicksort

#include <stdio.h>
#include <stdlib.h>

// Partition the linked list using the last element as the pivot
static t_Node* partition(t_Node* head, t_Node* end, t_Node** newHead, t_Node** newEnd) {
    t_Node* pivot = end;
    t_Node* prev = NULL;
    t_Node* current = head;
    t_Node* tail = pivot;

    while (current != pivot) {
        if (current->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = current;
            prev = current;
            current = current->next;
        } else {
            if (prev)
                prev->next = current->next;
            t_Node* tmp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

// The main function that implements QuickSort for a linked list
void quickSortLinkedList(t_Node** head, t_Node** tail) {
    if (*head == NULL || *head == *tail)
        return;

    t_Node* newHead = NULL;
    t_Node* newEnd = NULL;

    t_Node* pivot = partition(*head, *tail, &newHead, &newEnd);

    if (newHead != pivot) {
        t_Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        quickSortLinkedList(&newHead, &tmp);
        tmp = newHead;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = pivot;
    }

    pivot->next = NULL;

    quickSortLinkedList(&pivot->next, tail);
    (*head) = newHead;
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