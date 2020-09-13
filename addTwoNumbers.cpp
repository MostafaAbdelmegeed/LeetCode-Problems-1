#include <iostream>
#include <math.h>


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void printLinkedList(ListNode* l) {
    ListNode* current = l;
    printf("%d", current->val);
    while(current->next != nullptr){
        printf("->%d", current->next->val);
        current = current->next;
    }
    printf("\n");
}

int len(ListNode* l){
    int length = 0;
    ListNode* current = l;
    while(current != nullptr){
        length++;
        current = current->next;
    }
    return length;
}

class Solution {
public:
    int len(ListNode* l){
        int length = 0;
        ListNode* current = l;
        while(current != nullptr){
            length++;
            current = current->next;
        }
        return length;
    }

    void carryOn(ListNode* &l){
        if(l->next != nullptr){
            l->val = l->val % 10;
            l->next->val++;
            if(l->next->val >= 10) carryOn(l->next);
        } else {
            l->val = l->val % 10;
            l->next = new ListNode(1);
        }
        
    }

    void add(ListNode* &c1, ListNode* c2){
        c1->val += c2->val;
        if (c1->val >= 10){
            carryOn(c1);
        }
    }

    ListNode* enforceLargerList(ListNode* l1, ListNode* l2){
        if(len(l1) >= len(l2)) return l1;
        else return l2;
    }

    ListNode* enforceSmallerList(ListNode* l1, ListNode* l2){
        if(len(l1) < len(l2)) return l1;
        else return l2;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sol =  enforceLargerList(l1, l2);
        ListNode* current1 = sol;
        ListNode* current2 = enforceSmallerList(l1, l2);
        while (current2 != nullptr){
            add(current1, current2);
            current1 = current1->next;
            current2 = current2->next;
        }
        return sol;
    }
};


int main(){
    Solution solution = Solution();
    ListNode* first = new ListNode(8, new ListNode(6));
    ListNode* second = new ListNode(6, new ListNode(4, new ListNode(8, nullptr)));

    printf("First List: ");
    printLinkedList(first);
    printf("Second List: ");
    printLinkedList(second);

    ListNode* sol = solution.addTwoNumbers(first, second);
    printf("Solution: ");
    printLinkedList(sol);
    return 0;
}

