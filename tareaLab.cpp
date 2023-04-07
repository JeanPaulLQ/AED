#include <iostream>
using namespace std;
struct Nodo {
	int a[3]{};
	Nodo *next;
};
struct LinkedList {

	Nodo* header = nullptr;
	int size = 0;
	int cantNodos = 0;
	int* pointer;
	void add(int value) {
		if (!find(value)) {
			/*CREAMOS 1 NODO SOLO SI LA LISTA ESTA LLENA O EL HEADER ES NULO*/
			if (header == nullptr) {
				Nodo* temp = new Nodo;
				temp->a[size] = value;
				temp->next = nullptr;
				header = temp;
			}
			/*AGREGARMOS EL VALOR A LA SIGUIENTE POSICION,SOLO SI EL TAM DE LA LISTA NO ES 0 */
			else if (size != 0 && size % 3 != 0 && cantNodos == 0) {
				header->a[size] = value;
				sort(header->a);
			}
			else if (size % 3 == 0) {
				Nodo* temp = new Nodo;
				temp->a[size % 3] = value;
				temp->next = nullptr;
				Nodo* recorrido = header;

				while (recorrido->next != nullptr) {
					recorrido = recorrido->next;
				}
				recorrido->next = temp;
				sort(recorrido->a);
				cantNodos++;
			}
			else {
				Nodo* recorrido = header;
				while (recorrido->next != nullptr) {
					recorrido = recorrido->next;
				}
				recorrido->a[size % 3] = value;
				sort(recorrido->a);
			}
			size++;
		}		
	} 

	void del(int value) {

	}
	
	void sort(int a[]) {
		int* pivot = a;
		for (int i = size%3; i > 0; i--) {
			for (int* pivot = a; pivot < a + i; pivot++) {
				if (*pivot > *(pivot + 1)) {
					int temp = *pivot;

					*pivot = *(pivot + 1);
					*(pivot + 1) = temp;
				}
			}
		}
	}
	int* find(int value) {
		Nodo* nodo = header;

		int* pivot = nodo->a;
		while (nodo != nullptr) {
			for (int* pointer = nodo->a, count = 0; pointer < pivot + 3; pointer++, count++) {
				
				if (*pointer == value) { 
					cout << "located dont add : "<<value<<endl; 
					return pivot;
				}

			}
			nodo = nodo->next;
			pivot = nodo->a;
		}
		return nullptr;
	}
    void print() {
        
		Nodo* nodo = header;

		int* pivot = nodo->a;
		cout << "H->";
		while (nodo != nullptr) {
			cout << "[";
			for (int* pointer = nodo->a ,count = 0 ; pointer < pivot + 3; pointer++,count++) {
				cout << *pointer;
				if (count < 2){cout << ",";}
					
			}
			cout << "]";
			nodo = nodo->next;
			pivot = nodo->a;
		}
		cout << "->NULL" << endl;
    }

};
int main() {
	LinkedList list;
	
	list.add(5);
	list.print();
	list.add(1);
	list.print();
	list.add(7);
	list.print();
	list.add(9);
	list.print();
	list.add(3);
	list.print();
	return 0;
}
