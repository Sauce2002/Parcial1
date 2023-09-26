#include <iostream>

using namespace std;
void imagen(int** matriz);
void publik();
void patrones(int** matriz);
void limpiarMatriz(int** matriz);
void imprimirMatriz(int** matriz);
void eliminarMatriz(int** p);
int main()
{

    publik();
    return 0;
}

void publik(){
//    inicializamos un puntero de una matriz
    int **pMatriz;
    pMatriz = new int* [8];
    for (int i = 0; i <8; i++) {
        pMatriz[i] = new int[8];
    }
//creamos el menu del usuario
    cout << pMatriz<<endl;
    int opcion;
    cout <<"ingrese el numero de la opcion"<<endl;
    cout << "1- verificar funcionamiento de leds."<<endl;
    cout << "2- ingresar imagen personalizada."<<endl;
    cout << "3- patrones de ejemplo."<<endl;
    cin >>opcion;
    switch (opcion) {
    case 1:
        break;
    case 2:
        imagen(pMatriz);
    case 3:
        patrones(pMatriz);
    default:
        break;
    }

}

void imagen(int** matriz){//matriz del usuario
    limpiarMatriz(matriz);
    cout<<"ingrese un 1 para encendido y 0 para apagado"<<endl;
    cout<<"ingrese las filas de la siguiente forma, ejemplo(10110110)"<<endl;

    for(int i=0;i<8;i++){
        string a ="00000000";
        cout<<"ingrese la fila [";
        cout<<i+1;
        cout<<"]: ";
        cin >>a;

    for(int j=0;j<8;j++){
            cout<<a[j];//si el usuario pone mas de 8 numeros
        int b = 0;		//se imprimiran y tomaran solo los primeros 8
        b = a[j]-48;
        if(b>=0)*(*(matriz+j)+i) = b;
        //matrizUsuario[i][j]=b;
    }
    cout<<endl;
    }
    imprimirMatriz(matriz);
    eliminarMatriz(matriz);
        cout<<endl;

}

void patrones(int** matriz){
    cout << matriz <<endl;
    limpiarMatriz(matriz);
//    patron 1

    imprimirMatriz(matriz);
    limpiarMatriz(matriz);
//    patron 2
    for (int i = 0; i < 8; ++i) {
        //matriz[i][i]=1;
        *(*(matriz+i)+i)=1;
        //matriz[i][7-i]=1;
        *(*(matriz+(7-i))+i)=1;
    }
    imprimirMatriz(matriz);

    limpiarMatriz(matriz);

//    patron 3
    for (int columna = 0; columna < 8; columna++) {
        for (int fila = 0; fila < 8; fila++) {

        }
    }


//    patron 4

    for (int fila = 0; fila < 4; fila++) {
        int tope = 4+fila;
        for (int columna = fila; columna < tope; columna++) {
        *(*(matriz+columna)+fila)=1;//matriz[fila][columna]=1;
        }
    }
    int tope =4;
    for (int fila = 7; fila > 3; fila--) {
        for (int columna =7-fila; columna < tope; columna++) {
        *(*(matriz+columna)+fila)=1;//matriz[fila][columna]=1;
        }
        tope+=1;
    }

    imprimirMatriz(matriz);
    eliminarMatriz(matriz);

}

void imprimirMatriz(int** matriz){
    for(int x=0;x<8;x++){
        for(int z=0; z<8;z++){
            cout << *(*(matriz+z)+x)<<" ";
        }
        cout<<endl;
    }
}

void limpiarMatriz(int** matriz){
    cout<<endl;
    for(int x=0;x<8;x++){
        for(int z=0; z<8;z++){
            *(*(matriz+z)+x)=0;
        }
    }
}

void eliminarMatriz(int** matriz){
    cout <<matriz<<endl;
    for (int i = 0; i < 8; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;
}
