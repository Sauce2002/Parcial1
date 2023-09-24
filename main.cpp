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
    cout << "3- patrones de ejemplo"<<endl;
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
    cout<<"ingrese un 1 para encendido y 0 para apagado"<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int a=0;
            cout << "ingrese estado del led en la posici0on ["<<i+1<<"]["<<j+1<<"]: "<<endl;
            cin >>a;
            *(*(matriz+j)+i) =a;
            //matrizUsuario[i][j]=a;
        }
    }
    imprimirMatriz(matriz);
    eliminarMatriz(matriz);
        cout<<endl;

}

void patrones(int** matriz){
    cout << matriz <<endl;
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
}
