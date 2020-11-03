#include<bits/stdc++.h>
using namespace std;
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
        }
        if(head1->val<=head2->val)
        {
            head1->next=merge(head1->next,head2);
              return head1;
        }
        head2->next=merge(head1,head2->next);
        return head2;
    }
    
    ListNode* sortList(ListNode* head) {
        if((head==NULL)||(head->next==NULL))
            return head;
        ListNode *slow=head,*fast=head->next;
        while((fast!=NULL)&&(fast->next!=NULL))//Traversing using fast and slow pointer technique to bring the slow pointer to middle of the linkedlist
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* h2=slow->next;
        slow->next=NULL;
        ListNode* temp=sortList(head);//Sort left Linked list
        ListNode* temp1=sortList(h2);//Sort Right Linked list
        ListNode* retval=merge(temp,temp1);//Merge both in O(1) space merging linked list technique
        return retval;
    }
};