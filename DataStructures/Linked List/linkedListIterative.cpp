#include <iostream>
struct Node {
    int value;
    Node* next;
    Node(int value): value(value), next(nullptr) {}
    Node(int value, Node* ponteiroProx) {
        this->value = value;
        this->next = ponteiroProx;
    }
};
class ListaEncadeada {
private:
    Node* head;
    Node* tail;
public:
    ListaEncadeada(): head(nullptr), tail(nullptr) {}
    ListaEncadeada(int value): head(new Node(value)), tail(head) {}
    bool empty() { return this->head == nullptr; }
    void push_front(int value) {
        // criar um node Auxiliar para inserção
        Node* aux = new Node(value);
        if (empty()) {
            this->head = aux;
            this->tail = aux;
        }
        else {
            // faz o novo Node receber o ponteiro de head,
            // assim, tornando-se o primeiro elemento
            aux->next = head;
            head = aux;
        }
    }
    void push_back(int value) {
        Node* aux = new Node(value);
        // se não tiver elementos, head e tail são iguais
        if (empty()) {
            head = aux;
            tail = aux;
        }
        else {
            // o novo Node agora será o tail, pois agora ele é o último elemento
            tail->next = aux;
            tail = aux;
        }
    }
    void pop_back() {
        if (!empty()) {
            if (!head->next)
                head = nullptr;
            else {
                // anterior_anterior é igual a head 
                Node* anterior_anterior = head;
                // anterior recebe o próximo elemento em relação a "anterior_anterior" 
                Node* anterior = head->next;
                // serve como um interceptador do último elemento
                // já que precisa de pelo menos dois nós para realizarem as operações
                Node* iterator = head->next->next;
                // itera até iterator ser nullptr
                while (iterator) {
                    Node* aux = anterior;
                    anterior = iterator;
                    anterior_anterior = aux;
                    // iterando para não ficar um loop infinito
                    iterator = iterator->next;
                }
                // desalocando o próximo elemento
                delete anterior_anterior->next;
                // setando para nullptr
                anterior_anterior->next = nullptr;
                // faz a cauda ser o nó "anterior_anterior"
                tail = anterior_anterior;
            }
        }
    }
    void pop_front() {
        if (!empty()) {
            if (!head->next) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* aux = head->next;
                delete head;
                head = aux;
            }
        }
    }
    void remove(int value) {
        // casos base
        if (head->value == value) {
            pop_front();
            return;
        }  
        if (tail->value == value) {
            pop_back();
            return;
        }
        Node* iterator = head;
        // enquanto iterator e seu próximo Nó não forem nulos
        while (iterator && iterator->next) {
            if (iterator->next->value == value) {
                Node* removido = iterator->next;
                iterator->next = removido->next;
                delete removido;
                return;
            }
            else
                iterator = iterator->next;
        }
    }
    void printar() {
        // cria um Nó auxiliar para iterar de Head até Tail
        Node* iterator = head;
        if (empty())
            std::cout << "Lista vazia!" << std::endl;
        else {
            while (iterator) {
                std::cout << iterator->value << " ";
                iterator = iterator->next;
            }
            std::cout << std::endl;
        }
    }
    
    int getTamanho() {
        if (empty())
            return 0;
        Node* iterator = head;
        int tamanho = 0;
        // vai verificando até que seja nullptr
        while(iterator) {
            // vai navegando entre os ponteiros para o próxim elemento
            iterator = iterator->next;
            ++tamanho;
        }
        return tamanho;
    }
};

int main() {
    ListaEncadeada* lista = new ListaEncadeada(1);
    lista->push_back(2);
    lista->push_back(3);
    lista->push_front(-900);
    lista->printar();
    lista->remove(-900);
    lista->printar();
    lista->remove(1);
    lista->printar();
    lista->push_back(666);
    lista->push_back(666);
    lista->printar();
    lista->remove(-900);
    lista->printar();
    lista->remove(3);
    lista->printar();
    lista->remove(666);
    lista->printar();
}