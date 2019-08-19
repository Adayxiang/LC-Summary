//Solution1:
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return helper(lists, 0, lists.size() - 1);
    }
    
    ListNode *helper(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right) return lists[left];
        //if(left == right + 1) return merge(lists[left], lists[right]);
        int mid = left + (right - left) / 2;
        auto leftL = helper(lists, left, mid);
        auto rightL = helper(lists, mid + 1, right);
        return merge(leftL, rightL);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1&&l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy->next;
    }
};

Solution2:
