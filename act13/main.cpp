// =================================================================
//
// File: main.cpp
// Author: Benjamin Arauz
// Date: 11-09-2023
//
// =================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//Declaración de tipo de dato R, q va a guardar el desorden, la posicion en la que se ingreso y la cadena.
typedef pair<int, pair <int, string> > R;

//La clase de desorden su orden de complejidad es O(n^2), puesto que tiene dos for y dentro de estos solo se esta haciendo una suma.

//Funcion para calcular el desorden de la cadena
int desorden(string &v){
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                sum++;
            }
        }
    }
    return sum;
}

//Funcion de comparar para ser utilizada en el sort, si el desorden es igual para las cadenas entonces se ordena por la posicion.
bool compare(const R &left, const R &right){
    //Si el grado de desorden es igual
    if (left.first == right.first){ 
        //Se ordena en base a la posiion
        return left.second.first < right.second.first;
    }
    else {
        //Se ordena de menor a mayor
        return left.first < right.first; 
    }
}

int main(int agrc, char* argv[]){
    
    //Delaraacion de variables
    int n, m, desorden_num;
    string cadena;

    //Pedir datos
    cin >> n >> m;
    
    //Vector para guardar el desorden, la posicion en la que se ingreso y la cadena.
    vector<R> result(m);
    
    //Bucle para almacenar los datos
    for (int i = 0; i < m; i++){
        //Pide datos de la cadena
        cin >> cadena;
        //Calcula el desorden
        desorden_num = desorden(cadena);
        //Guarda en el vector, el desorden, la posicion en la que se ingreso y la cadena
        result[i] = make_pair(desorden_num, make_pair(i+1,cadena));
    }

    //Se ordena con la libreria de algorithm
    sort(result.begin(), result.end(), compare);

    //Se imprime el resultado
    for(auto p : result){
        cout << p.second.second << "\n";
    }

    return 0;
}
