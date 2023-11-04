// =================================================================
//
// File: main.cpp
// Author: Benjamin Arauz
// Date: 26/10/2023
//
// =================================================================
#include <iostream>
#include <vector>
#include <map>

using namespace std;
//Complexity O(n)
//Funcion que determina si es abeto
bool abeto(vector<int> arr, int n){
	//Variables
	map<int, int> mp; //Mapa que va a contar cuantas hojas existe
	map<int, int>::iterator itr; //Iterator que va a guardar el nodo

	for (int i = 0; i < n-1; i++){
		itr = mp.find(arr[i]); //Actualiza el nodo
		//Si el valor no se encuentra en el mapa
		if (itr == mp.end()){
			//Se inserta una nueva llave en el mapa
			mp.insert(pair<int, int>(arr[i], 1));
			if (arr[i] != 1){
				//Se reduce el numero de hojas en el padre
				mp[arr[arr[i]-2]] = mp[arr[arr[i]-2]] - 1;
			}
		} else {
			//Si no suma uno al diccionario
			itr->second = itr->second + 1;
		}
	}

	//Se verifica si las hojas son mayores a 3
	for (const auto& p : mp) {
        if (p.second < 3){
            return false;
        }
    }
	return true;
}

int main(int argc, char* argv[]) {

	int n;
	cin >> n;
	vector<int> arr(n-1); //Vector del input del usuario

	//Se rellena el vector
	for (int i = 0; i < n-1; i++){
		cin >> arr[i];
	}
	
	//Se llama a la función y se determina si es abeto o no
	cout << ((abeto(arr, n))? "Yes" : "No") << "\n";

	return 0;

}
