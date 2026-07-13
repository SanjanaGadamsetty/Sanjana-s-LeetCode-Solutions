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
    int pairSum(ListNode* head) {
        ListNode *temp= head;
        ListNode *rev_head= rev_mid(head);
        int ms_ll=0;
        while (rev_head!=NULL){
            ms_ll= max(ms_ll, temp->val+ rev_head->val);
            temp= temp-> next;
            rev_head= rev_head->next;
        }
        return ms_ll;
    }
private:
    ListNode* find_mid(ListNode* &head){
        ListNode *slow= head;
        ListNode *fast= head;
        while (fast!= NULL && fast->next!=NULL){
            slow= slow-> next;
            fast= fast-> next-> next;
        }
        return slow;	
    }

    ListNode* rev_mid(ListNode* &head){
        ListNode *mid_head= find_mid(head);
        ListNode *prev= NULL;
        ListNode *curr= mid_head;
        while (curr != NULL){
            ListNode *next= curr-> next;
            curr-> next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }
};