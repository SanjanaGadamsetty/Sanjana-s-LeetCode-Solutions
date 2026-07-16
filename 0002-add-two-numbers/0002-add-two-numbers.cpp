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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1= l1;
        ListNode *temp2= l2;
        ListNode *result= NULL;

        int carry=0;
        while (temp1!= NULL || temp2!=NULL){
            int sum= carry;
            if (temp1!= NULL){
                sum+= temp1-> val;
                temp1= temp1-> next;
            }
            if (temp2!= NULL){
                sum+= temp2-> val;
                temp2= temp2-> next;
            }
            carry = sum/10;
            insert_end(result, sum%10);
        }
        if (carry!= 0) insert_end(result, carry);
        return result;
    }
private:
    void insert_end(ListNode* &result, int v){
        ListNode *newNode= new ListNode(v);
        if (result== NULL){
            result= newNode;
            return;
        }
        ListNode *temp= result;
        while (temp-> next != NULL){
            temp= temp-> next;
        }
        temp-> next= newNode;
    }
};