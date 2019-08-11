class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int c = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(c || l1 || l2)
        {
            int x1 = (l1 == NULL ? 0 : l1->val);
            int x2 = (l2 == NULL ? 0 : l2->val);
            cur ->next = new ListNode((x1 + x2 + c) % 10);
            cur = cur->next;
            c = (x1 + x2 + c) / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;
    }
};