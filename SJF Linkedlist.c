#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int pid, at, bt, st, wt, tat;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int pid, int at, int bt)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->at = at;
    newnode->bt = bt;
    newnode->pid = pid;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void pop(int pid)
{
    Node *temp = head;
    if (head->pid == pid)
    {
        head = head->next;
        return;
    }
    while (temp != NULL)
    {
        if (temp->next->pid == pid)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

// void print() {
//     Node *temp = head;
//      if (head->pid==pid)
//      {
//         head=NULL;
//         return;
//      }
//       while (temp!=NULL)
//         {
//             if (temp->next->pid==pid)
//             {
//                 temp->next = temp->next->next;
//                 return;
//             }
//             temp=temp->next;
//         }
// }

int lenList()
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *min_process(int clk)
{
    Node *ptr = head;
    Node *min_p = head;
    while (ptr != NULL)
    {
        if (ptr->bt <= min_p->bt && ptr->at <= clk)
        {
            min_p = ptr;
        }
        ptr = ptr->next;
    }
    return min_p;
}

void printList()
{
    Node *ptr = head;
    printf("\n[ ");

    // start from the beginning
    while (ptr != NULL)
    {
        printf("(%d, %d, %d) , ", ptr->pid, ptr->at, ptr->bt);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

int main()
{
    insert(1, 0, 2);
    insert(2, 1, 4);
    insert(3, 3, 6);
    printList();
    int clk = 0;
    Node *run = NULL;
    printf("len: %d\n", lenList());
    printf("PID\tAT\tBT\tST\tTAT\tWT\t\n");
    while (lenList() != 0)
    {
        // printf("%d\n", clk);
        Node *min = min_process(clk);
        if (run == NULL)
        {
            if (clk >= min->at)
            {
                min->st = clk;
                run = min;
            }
        }
        else
        {
            if (clk - run->st == run->bt)
            {
                Node *cp = run;
                pop(run->pid);
                run = NULL;
                cp->tat = clk - cp->at;
                cp->wt = cp->tat - cp->bt;
                printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", cp->pid, cp->at, cp->bt, cp->st, cp->tat, cp->wt);
                free(cp);
                clk--;
            }
        }
        clk++;
    }
    printf("%d\n", lenList());
    return 0;
}
