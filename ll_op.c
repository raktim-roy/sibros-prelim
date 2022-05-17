#include "ll_op.h"


void InsertatBeginning(linked_list_s** head_ref, void* new_data)
{
    linked_list_s* newNode = (linked_list_s*)malloc(sizeof(linked_list_s));
    if(newNode == NULL)return;
    newNode->data = new_data;
    newNode->next = (*head_ref);
    (*head_ref)  = newNode;

}

void InsertatEnd(linked_list_s** head_ref, void* new_data)
{
    linked_list_s* newNode = (linked_list_s*)malloc(sizeof(linked_list_s));

    linked_list_s* curr = *head_ref;

    newNode->data = new_data;
    newNode->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    while(curr->next != NULL)
    {
        curr=curr->next;
    }

    curr->next = newNode;
    return;
}

void deleteNode(linked_list_s** head_ref, int position)
{
    if(*head_ref == NULL) return;
    
    int i;
    linked_list_s* temp = *head_ref;

    if (position == 0)
    {
        *head_ref = temp->next;

        free(temp);
        return;
    }

    for(i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
        return;
    
    linked_list_s* next = temp->next->next;

    free(temp->next);
    temp->next = next;
}


// }
int getCount(linked_list_s* head_ref)
{
    int count = 0;
    linked_list_s* curr = head_ref;
    while(curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    return count;
}

int main()
{
    linked_list_s* head = NULL;
    int data = 6;
    InsertatBeginning(&head, &data);
    data = 9;
    InsertatEnd(&head, &data);
    printf("%d\n",getCount(head));
    deleteNode(&head, 0);
    printf("%d\n",getCount(head));
}