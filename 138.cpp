
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *aux = new Node(0); // dummy
        Node *sig = aux;
        Node *head_aux = head;   // apunta al inicio de la lista original

        // Primer recorrido: copiar la lista (sólo next)
        while(head != nullptr){
            sig->next = new Node(head->val);           
            head = head->next;
            sig = sig->next;
        }
        // Reiniciamos sig para recorrer la lista copia
        sig = aux->next;
        // Guardamos el inicio de la lista original en 'orig'
        Node* orig = head_aux;
        
        // Segundo recorrido: asignar los punteros random
        while(head_aux != nullptr){
            if(head_aux->random == nullptr){
                sig->random = nullptr;
            } else {
                int idx = 0;
                // Calculamos el índice del nodo random en la lista original
                Node* temp = orig;
                while(temp != head_aux->random){
                    temp = temp->next;
                    idx++;
                }
                // Recorremos la lista copia hasta el nodo correspondiente al índice
                Node* rptr = aux->next;
                for(int i = 0; i < idx; i++){
                    rptr = rptr->next;
                }
                sig->random = rptr;
            }
            head_aux = head_aux->next;
            sig = sig->next;
        }
        return aux->next;  
    }
};
