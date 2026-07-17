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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len= len_ll(head);
        n= len-n+1;
        if (n==1) return head-> next;
        int c=1;
        ListNode *temp= head;
        while (c < n-1 && temp-> next!= NULL){
            temp= temp-> next;
            c++;
        }
        if (temp-> next== NULL){
            return head;
        }
        temp-> next= temp-> next-> next;
        return head;
    }
private:
    int len_ll(ListNode* head){
        ListNode *temp= head;
        int c=0;
        while (temp){
            temp= temp-> next;
            c++;
        }
        return c;
    }
};