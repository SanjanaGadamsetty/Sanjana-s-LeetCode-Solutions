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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head== NULL || k==0) return head;
        ListNode *tail= head;
        int count=1;
        while (tail!= NULL && tail-> next!= NULL){
            count++;
            tail= tail-> next;
        }
        int len= count;
        k= k% len;
        if (k==0) return head;

        ListNode *temp= head;
        for (int i=1; i<len- k; i++){
            temp= temp-> next;
        }
        ListNode *newhead= temp-> next;
        temp-> next= NULL;
        tail-> next= head;
        return newhead;
    }
};