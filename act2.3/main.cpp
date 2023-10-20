// =================================================================
//
// File: main.cpp
// Author: Benjamin Arauz
// Date: 12/08/2023
//
// =================================================================
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

//Función que le permite al iterador avanzar
//Complejidad de esta función es O(1)
void advance_itr(list<int>::iterator &itr, list<int> &lst){
	if (itr == --(lst.end())){
		//Si el iterador se encuentra en el último elemento vuelve al primer elemento.
		itr = lst.begin();
	} else {
		//Si no, avanza al siguiente.
		itr++;
	}
}

//Función para encontrar la posicion
//Complejidad de esta función es O(n^2)
int find_position(list<int> lst, int k, int n){
	//Creación de variables
	list<int>::iterator kill; //Creamos un iterador para guardar la posición de quien murió.
	int i = 1; //Donde se inicia a contar
	int survive; //Se va a guardar el sobreviviente

	//Se va a parar el ciclo cuando exista solo un sobreviviente
	for (auto itr = lst.begin(); lst.size() != 1; advance_itr(itr, lst), i++){
		//Se busca a la persona que muere
		if (i == k){
			kill = itr; //Se guarda a la persona que muere
			advance_itr(itr, lst); //Avanza el iterador
			i = 1;//Se reinicia el indicador de la persona que va a morir.
			
			//Se busca a la persona que entierra
			for (;itr != lst.end();advance_itr(itr, lst)){
				//Se verifica si la persona no es el muerto
				if (itr != kill){
					//Se encuentra a la persona que entierra
					if (i == k){
						//Se hace el cambio entre la persona que entierra y la que muere
						lst.insert(kill, *itr);
						lst.erase(kill);
						lst.erase(itr);
						//Se reinicia el indicador de la persona que va a morir.
						i = 0;
						//Se busca a la persona que entierra, para iniciar la lista.
						itr = find(lst.begin(), lst.end(), *itr);
						break;
					}
					//Aumenta el indicador
					i++;
				}	
			}
		}
	}
	//La persona sobreviviente es 
	survive = *lst.begin();
	if (survive != 1){
		//Si la persona no es el primero, se hace el calculo
		//La posición es igual al numero de personas menos la distancia del sobreviente al primer lugar
		survive = n - (survive - 2);
	}
	return survive;
}

int main(int argc, char* argv[]) {
	//Creación de variables
	int n, k;
	//Pedir variables al usuario
	cin >> n >> k;
	//Creación de lista
	list<int> lst;
	//Llena la lista de numeros desde 1 hasta n
	for (int i = 1; i <= n; i++){
		lst.push_back(i);
	}
	//Se imprime y llama a la función
	cout << find_position(lst, k, n);
	//Se elimina la lista
	lst.clear();
	return 0;
}
