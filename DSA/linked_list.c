#include <stdio.h> 
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

    unordered_set<int> seen;
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
void printList(struct Node *node) {
    int i = 0;
    while(node != NULL) {
        printf("Node data %d => %d\n", i, node->data);
        node = node->next;
        i++;
    }
}
int main() 
{ 
    int i;
    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
    struct Node* fourth = NULL; 

    head = (struct Node*)malloc(sizeof(struct Node));  
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    fourth = (struct Node*)malloc(sizeof(struct Node)); 

    head->data = 1;  
    head->next = second; 

    second->data = 2;  
    second->next = third; 

    third->data = 2;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = NULL;

    insertNodeAtFront(&head, 0);
    insertAfterGivenNode(head->next, 6);
    for(i = 9; i < 19; i++)
        insertAtTheEnd(&head, i);
    deleteNode(&head, 6);
    printList(head);
    removeDupsFromSortedList(head);
    removeDupsFromUnSortedList(head);
    printf("<------ Reversed List ------> \n");
    reverseList(&head);
    printList(head);
    bool is_palindrome = checkPalindrome(head);
    if(is_palindrome) 
        printf("List is palindrome\n");
    else
        printf("List is not palindrome\n");
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
    return 0; 
}