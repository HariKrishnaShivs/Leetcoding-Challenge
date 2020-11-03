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
    ListNode* func(ListNode* head,ListNode* temp)
    {
        if(head->val>temp->val)
        {
            temp->next=head;
            return temp;
        }
        ListNode* t=head;
        while((t->next!=NULL)&&(t->next->val<temp->val))
        {
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
        return head;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* nhead=head;
        ListNode* temp=head->next;
        ListNode* temp1;
        nhead->next=NULL;
        while(temp!=NULL)
        {
            temp1=temp->next;
            temp->next=NULL;
            nhead=func(nhead,temp);
            temp=temp1;
        }
        return nhead;
    }
};