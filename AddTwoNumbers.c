/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    struct ListNode *mylist = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(mylist == NULL) return NULL;
     
    mylist->next = NULL;
    
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *ReturnNode = mylist;
    
    int v1=0;
    int v2=0;
    int carry=0;
    
    while(1)
    {
        if(p1!=NULL){
            v1 = p1->val; 
            p1 = p1->next;
        } else
        {
            v1=0;
        }
        
        if(p2!=NULL){
            v2 = p2->val; 
            p2 = p2->next;
        } else
        {
            v2=0;
        }
        
        mylist->val = (v1 + v2 +carry)%10; 
        
        carry = (v1 + v2 +carry)/10;
        
        if(p1!=NULL || p2!=NULL || carry){
            mylist->next = ( struct ListNode *)malloc(sizeof(struct ListNode));
            
            mylist =  mylist->next;
            
            mylist->next = NULL;
            
            if(mylist == NULL) break;
            
             mylist->val = carry;
            
            continue;
        }
        
        break;
    }
    
    return ReturnNode;
}
