#include <iostream> 
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <unordered_set>

struct Node  
{ 
  int data; 
  struct Node *next; //Pointer to next node
}; 

//url => https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
void insertNodeAtFront(struct Node **head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}
//url => https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
void insertAfterGivenNode(struct Node *prev, int new_data) {
    if(prev == NULL) {
        printf("Given Previous node cannot be null.\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
}
//url => https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
void insertAtTheEnd(struct Node **head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct Node* temp = *head;

    if(*head == NULL) {
        *head = new_node;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
//url => https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
void deleteNode(struct Node **head, int key) {
    struct Node* temp = *head, *prev;

    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
//url => https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
int getCount(struct Node *head) {
    if(head == NULL)
        return 0;
    return 1 + getCount(head->next);
}
//url => https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
bool search(struct Node* head, int x) 
{ 
    if (head == NULL) 
        return false;       
    if (head->data == x) 
        return true; 
    return search(head->next, x); 
} 
// url => https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
int nthNodeInList(struct Node *head, int index, bool recursion) {
    
    if(recursion) {
    /**
    *   Using recursion
    */
        int count = 0; 

        if(count == index) 
            return head->data; 
        return nthNodeInList(head->next, index - 1, true);
    }
    else {
        struct Node* current = head; 
        
        int count = 0; 
        while (current != NULL) 
        { 
            if (count == index) 
                return(current->data); 
            count++; 
            current = current->next; 
        } 
        assert(0);
    }         
}
//url => https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
void getNthNodeFromEnd(struct Node *head, int index) {
    /*
        Two ways to do it.
        [1]. Calculate the length of Linked List. Let the length be len then, Print the (len – n + 1)th node from the begining of the Linked List.
        [2]. Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. First move reference pointer to n nodes from head. Now move both pointers one by one until reference pointer reaches end. Now main pointer will point to nth node from the end. Return main pointer.
    */
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    int count = 0;
    if(head != NULL) {
        while(count < index) {
            if(ref_ptr == NULL) {
                printf("%d is greater than the no. of nodes in the list", index);
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
        while(ref_ptr != NULL) {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        printf("Node no. %d from last is %d \n",  index, main_ptr->data);
    }
}
//url => https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
struct Node *getMiddleElement(struct Node *head) {
    struct Node* ptr = head;
    struct Node* sec_ptr = head;

    if(head == NULL)
        return 0;
    while(sec_ptr != NULL && sec_ptr->next != NULL) {
        ptr = ptr->next;
        sec_ptr = sec_ptr->next->next;
    }
    printf("Middle Element is => %d\n", ptr->data);
    return ptr;
}
//url=> https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
int getCountOfAElement(struct Node *head, int element) {
    int count = 0;
    if(head == NULL)
        return 0;
    while(head != NULL){
        if(head->data == element)
            count++;
        head = head->next;
    }
    return count;
}
//url => https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
int detectLoop(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            printf("Loop Detected at %d\n",slow->data);
            return 1;
        }
    }
    return 0;
}
/*----START-----*/
//url => https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/
int countElements(struct Node *n) {
    int result = 1;
    struct Node *temp = n;
    while(temp != NULL) {
        result++;
        temp = temp->next;
    }
    return result;
}
int countNodesinLoop(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return countElements(slow);
        }
    }
    return 0;
}
/*----END-----*/
/*----START----*/
// url => https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
void reverseList(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *next;
    struct Node *current = *head;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

bool compareLists(struct Node *f_head, struct Node *s_head) {
    struct Node* f_temp = f_head; 
    struct Node* s_temp = s_head; 
  
    while (f_temp && s_temp) 
    { 
        if (f_temp->data == s_temp->data) 
        { 
            f_temp = f_temp->next; 
            s_temp = s_temp->next; 
        } 
        else return false; 
    } 
    if (f_temp == NULL && s_temp == NULL) 
        return true; 
  
    return false; 
}

bool checkPalindrome(struct Node *head) {
    struct Node *slow_ptr = head, *fast_ptr = head, *mid_node = NULL, *prev_of_slow_ptr = head, *second_half;
    bool result = false;
    if(head == NULL)
        return false;
    if (head!=NULL && head->next!=NULL) 
    { 
        while(fast_ptr != NULL && fast_ptr->next != NULL) {
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        if(fast_ptr != NULL) {
            mid_node = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL;
        reverseList(&second_half);
        result = compareLists(head, second_half);
        reverseList(&second_half);
        if(mid_node != NULL) {
            prev_of_slow_ptr->next = mid_node; 
            mid_node->next = second_half; 
        } 
        else  
            prev_of_slow_ptr->next = second_half;
    }
    return result;
}
/*----END----*/
// url => https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
void removeDupsFromSortedList(struct Node *head) {
    struct Node *current = head, *next_node;
    if(head == NULL)
        return;
    while(current->next != NULL) {
        if(current->data == current->next->data){
            next_node = current->next->next;
            free(current->next);
            current->next = next_node;
        }
        else {
            current = current->next;
        }
    }
}

//url => https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
void removeDupsFromUnSortedList(struct Node *head) {
    struct Node *current = head;
    struct Node *prev = NULL;

    std::unordered_set<int> seen;
    while(current != NULL) {
        if(seen.find(current->data) != seen.end()) {
            prev->next = current->next; 
            delete(current);
        }
        else {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

//url => https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
/**
*  Simple solution is available at above url.
*/

void swapNodes(struct Node *first, struct Node *second) {
    struct Node *temp = first->next;
    first->next = second->next;
    second->next = temp;
}
void swapNodesInlist(struct Node **head, int x, int y) {
    struct Node *currentX = *head;
    struct Node *prev_currentX = NULL;

    if(x == y)
        return;

    while(currentX->data != x) {
        prev_currentX = currentX;
        currentX = currentX->next;
    }

    struct Node *currentY = *head;
    struct Node *prev_currentY = NULL;
    while(currentY->data != y) {
        prev_currentY = currentY;
        currentY = currentY->next;
    }
    if(currentX == NULL || currentY == NULL)
        return;
    if(prev_currentX != NULL)
        prev_currentX->next = currentY;
    else
        *head = currentY;

    if(prev_currentY != NULL)
        prev_currentY->next = currentX;
    else
        *head = currentX;

    //swap next pointers
    swapNodes(currentX, currentY);
    // struct Node *temp = currentY->next;
    // currentY->next = currentX->next;
    // currentX->next = temp;
}

//url => https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
/**
*  Tip :: If there are 2 or more than 2 nodes in Linked List then swap the first two nodes and recursively call for rest of the list.
*/
void swapIntegers(int a, int b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
}
void pairWiseSwapNodesInlist(struct Node *head) {
    struct Node *temp = head;

    if(head == NULL)
        return;
    while(temp != NULL && temp->next != NULL) {
        swapIntegers(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}

//url => https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
void moveLastElementToFront(struct Node **head) {
    struct Node *last = *head, *prev_last = NULL;

    if(head == NULL)
        return;
    while(last->next != NULL) {
        prev_last = last;
        last = last->next;
    }
    prev_last->next = NULL;
    last->next = *head;
    *head = last;
}

//url => https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
void intersectionOfSortedLists(struct Node *a, struct Node *b) {
    if(a == NULL || b == NULL)
        return;

    struct Node *temp_node = NULL;
    struct Node *dummy_head = NULL;
    printf("Here is the intersection of list => ");    
    while(a != NULL && b != NULL) {
        if(a->data == b->data) {
            insertAtTheEnd(&temp_node, a->data);
            printf("%d -> ",temp_node->data);
            a = a->next;
            b = b->next;
            temp_node = temp_node->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            b = b->next;
        }
    }
    printf("NULL\n");
}

//url => https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
int _intersection(struct Node *a, struct Node *b, int d) {
    struct Node *currentA = a, *currentB = b;
    for(int i = 0; i < d; i++) {
        if(currentA == NULL)
            return -1;
        currentA = currentA->next;
    }
    while(currentA != NULL && currentB != NULL) {
        if(currentA == currentB)
            return currentA->data;
        currentA = currentA->next;
        currentB = currentB->next;        
    }
    return -1;
}
int getInterSectionNode(struct Node *a, struct Node *b) {
    int c1 = getCount(a);
    int c2 = getCount(b);
    int d;
    if(c1 > c2) {
        d = c1 - c2;
        return _intersection(a, b, d);
    } else {
        d = c2 - c1;
        return _intersection(b, a, d);        
    }
}

//url => https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
void evenOddList(struct Node **head) {
    struct Node *end = *head; 
    struct Node *prev = NULL; 
    struct Node *curr = *head; 
  
    while (end->next != NULL) 
        end = end->next; 
  
    struct Node *new_end = end; 
  
    while (curr->data %2 != 0 && curr != end) 
    { 
        new_end->next = curr; 
        curr = curr->next; 
        new_end->next->next = NULL; 
        new_end = new_end->next; 
    } 
    if (curr->data%2 == 0) 
    { 
        *head = curr; 
        while (curr != end) 
        { 
            if ( (curr->data)%2 == 0 ) 
            { 
                prev = curr; 
                curr = curr->next; 
            } 
            else
            { 
                prev->next = curr->next; 
                curr->next = NULL; 
                new_end->next = curr; 
                new_end = curr; 
                curr = prev->next; 
            } 
        } 
    } 
    else prev = curr; 
    if (new_end!=end && (end->data)%2 != 0) 
    { 
        prev->next = end->next; 
        end->next = NULL; 
        new_end->next = end; 
    } 
    return; 
} 

void push(struct Node **head, int new_data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(struct Node *node) {
    printf("Printing List : ");
    while(node != NULL) {
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("NULL\n");    
}
int main() 
{ 
    int i;
    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
    struct Node* fourth = NULL; 

    head   = (struct Node*)malloc(sizeof(struct Node));  
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third  = (struct Node*)malloc(sizeof(struct Node)); 
    fourth = (struct Node*)malloc(sizeof(struct Node)); 

    head->data = 1;  
    head->next = second; 

    second->data = 2;  
    second->next = third; 

    third->data = 4;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = NULL;

    insertNodeAtFront(&head, 0);
    insertAfterGivenNode(head->next, 6);
    for(i = 9; i < 19; i++)
        insertAtTheEnd(&head, i);
    deleteNode(&head, 6);
    printList(head);
    swapNodesInlist(&head, 4, 15);
    printf("<------ Nodes 4 and 15 swapped and first to last ------> \n"); 
    moveLastElementToFront(&head);   
    printList(head);
    pairWiseSwapNodesInlist(head);    
    printf("<------ pair wise swapped ------> \n");
    printList(head);    
    removeDupsFromSortedList(head);
    removeDupsFromUnSortedList(head);
    printf("<------ Reversed List ------> \n");
    reverseList(&head);
    printList(head);
    bool is_palindrome = checkPalindrome(head);
    if(is_palindrome) 
        printf("List is palindrome.\n");
    else
        printf("List is not palindrome.\n");
    int len = getCount(head);
    printf("Length is :: %d\n", len);
    int x = 7;
    bool found = search(head, x);
    if(found)
        printf("Element %d present in list.\n", x);
    else
        printf("Element %d not present in list.\n", x);
    int index = 4;
    int node_data = nthNodeInList(head, index, true);
    printf("Element at index => %d is %d.\n", index, node_data);
    getNthNodeFromEnd(head, 2);
    struct Node *mid_node = getMiddleElement(head);
    int count = getCountOfAElement(head, 3);
    printf("Count of element is :: %d\n", count);
    head->next->next->next = head;
    detectLoop(head);
    struct Node *a = NULL;
    struct Node *b = NULL;

    push(&a, 8); 
    push(&a, 6); 
    push(&a, 4); 
    push(&a, 3); 
    push(&a, 2); 
    push(&a, 1); 

    push(&b, 8); 
    push(&b, 6); 
    push(&b, 4); 
    push(&b, 2); 
    
    intersectionOfSortedLists(a, b);
    /** 
        Create two linked lists 
        1st 3->6->9->15->30 
        2nd 10->15->30 
        15 is the intersection point 
    */
    struct Node* newNode; 
    struct Node* head1 = 
              (struct Node*) malloc(sizeof(struct Node)); 
    head1->data  = 10; 
    
    struct Node* head2 = 
              (struct Node*) malloc(sizeof(struct Node)); 
    head2->data  = 3; 
    
    newNode = (struct Node*) malloc (sizeof(struct Node)); 
    newNode->data = 6; 
    head2->next = newNode; 
    
    newNode = (struct Node*) malloc (sizeof(struct Node)); 
    newNode->data = 9; 
    head2->next->next = newNode; 
    
    newNode = (struct Node*) malloc (sizeof(struct Node)); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next  = newNode; 
    
    newNode = (struct Node*) malloc (sizeof(struct Node)); 
    newNode->data = 30; 
    head1->next->next= newNode; 
    
    head1->next->next->next = NULL; 
    int intersect_node = getInterSectionNode(head1, head2);
    ( intersect_node == -1 ) ? printf("No intersection.\n") : printf("Intersection Node is :: %d\n", intersect_node);

    struct Node *head11 = NULL;
    push(&head11, 11); 
    push(&head11, 10); 
    push(&head11, 7); 
    push(&head11, 6); 
    push(&head11, 3); 
    push(&head11, 2); 
    push(&head11, 0); 

    evenOddList(&head11);
    printList(head11);
    return 0; 
}