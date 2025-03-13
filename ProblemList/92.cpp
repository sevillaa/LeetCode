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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    if (!head || left == right) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    // 1️⃣ Mover 'prev' al nodo antes de 'left'
    for (int i = 0; i < left - 1; i++)
        prev = prev->next;

    ListNode* start = prev->next;  // Primer nodo que se va a invertir
    ListNode* then = start->next; 
    
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;  // Saltar `then`
        then->next = prev->next;   // Conectar `then` al inicio de la sublista
        prev->next = then;         // Conectar `prev` con `then`
        then = start->next;        // Mover `then` al siguiente nodo
    }

    return dummy.next;
    }
};
