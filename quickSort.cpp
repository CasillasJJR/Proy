//Casillas Rendón Jennyfher Jacquelinne
#include <iostream>
using namespace std;

void quickSort(int *arr, int start, int end){
  int size=end-start+1;
  if(size<2){
    return;
  }
  int index=start;
  int pivot=arr[end];
  for(int i=start; i<end; i++){ 
      if (arr[i]<=pivot){
          swap(arr[i], arr[index]);
          index++;
      }
  }
  swap(arr[end], arr[index]);
  if(index>start){
    quickSort(arr, start, index-1);
  }
  if(index<end){
    quickSort(arr, index+1, end);
  }
}
// Definición de la estructura del nodo
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    // Constructor
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

// Definición de la clase ListaLigadaDoble
template <typename T>
class ListaLigadaDoble {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    // Constructor
    ListaLigadaDoble() : head(nullptr), tail(nullptr) {}

    // Método para agregar un elemento al final de la lista
    void agregarAlFinal(T value) {
        Node<T>* nuevoNodo = new Node<T>(value);

        if (!head) {
            head = tail = nuevoNodo;
        } else {
            tail->next = nuevoNodo;
            nuevoNodo->prev = tail;
            tail = nuevoNodo;
        }
    }

    // Método para imprimir la lista de principio a fin
    void imprimirDesdeInicio() {
        Node<T>* current = head;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    // Método para imprimir la lista de fin a principio
    void imprimirDesdeFinal() {
        Node<T>* current = tail;

        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }

        std::cout << std::endl;
    }
};
int main(){
  int array[]={3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
  int last=(sizeof(array)/sizeof(int))-1;
  quickSort(array, 0, last);
  ListaLigadaDoble<int> lista;
  for(int i=0; i<=last;i++){
      lista.agregarAlFinal(array[i]);
  }
  lista.imprimirDesdeInicio();
  lista.imprimirDesdeFinal();
  return 0;
}