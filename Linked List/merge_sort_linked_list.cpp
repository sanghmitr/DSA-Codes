//  https://leetcode.com/problems/sort-list

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    
    ListNode* getMid(ListNode *head){
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL and fast->next != NULL)
        {
            temp = slow; // Temp will point to the last node of first half;
            slow = slow->next; // slow will point to the first node of second half
            fast = fast->next->next;
        }
        temp->next = NULL;
        return slow;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2){
        ListNode *sorted = new ListNode(0);
        ListNode *cur = sorted;
        
        while(l1 != NULL and l2 != NULL)
        {
            if(l1->val < l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        
        if(l1 != NULL){
            cur->next = l1;
            //l1 = l1->next;
        }
        if(l2 != NULL){
            cur->next = l2;
            //l2 = l2->next;
        }
        return sorted->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return merge(left, right);
    }  
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}