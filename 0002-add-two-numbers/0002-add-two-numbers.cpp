/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//         ListNode* dummy = new ListNode(0);
//         ListNode* temp = dummy;
//         int carry = 0;
        
//         while(l1 || l2 || carry){
            
//             int sum = 0;
            
//             if(l1){
//                 sum+=l1->val;
//                 l1 = l1->next;
//             }
//             if(l2){
//                 sum+=l2->val;
//                 l2 = l2->next;
//             }
            
//             sum += carry;
            
//             //push node to dummy node;
//             carry = sum/10;
            
//             ListNode* node = new ListNode(sum%10);
//             temp->next = node;
//             temp = temp->next;
            
//         }
//         return dummy->next;
//     }
    
    //using recursion
    
    ListNode* add(ListNode* l1, ListNode* l2, int carry){
        if(l1==NULL && l2==NULL && carry==0) return NULL;
        
        int sum = carry;
        
        sum += l1?l1->val:0;
        sum += l2?l2->val:0;
        
        //new node
        ListNode* newNode = new ListNode(sum%10);
        carry = sum/10;
        
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        
        newNode->next = add(l1, l2, carry);
        
        return newNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        return add(l1, l2, 0); //carry -> 0
    }
};