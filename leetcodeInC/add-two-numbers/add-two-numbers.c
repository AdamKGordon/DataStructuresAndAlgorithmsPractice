
// Definition for singly-linked list.
typedef struct ListNode node_t;



node_t* newNode(int val) {
    node_t *n;
    n = (node_t *) malloc(sizeof(node_t));
    n->val = val;
    //n->next = NULL;
    return n;
}


node_t* addTwoNumbers(node_t* l1, node_t* l2){
    int tmp, carry;
    node_t *head;
    head = NULL;
    node_t *tail;
    tail = NULL;

    carry=0;
    while(l1!=NULL || l2!=NULL || carry) {
        if(carry){
            tmp = 1;
            carry = 0;
        }
        else {
            tmp = 0;
        }
        if(l1!=NULL) {
            tmp += l1->val; 
            l1 = l1->next;
        }
        if(l2!=NULL) {
            tmp += l2->val; 
            l2 = l2->next;
        }
        if(tmp>9) {
            carry=1;
            tmp-=10;
        }
         
        if(head == NULL) { // create head
            head = newNode(tmp);
            tail = head;
        }
        else {
            tail->next = newNode(tmp);
            tail = tail->next;
        } 
    }
    tail->next = NULL;
    return head;
}