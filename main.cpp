#include <iostream>

using namespace std;
void imagen();
void publik();
void patrones(int matriz[8][8]);
int matrizPatrones[8][8]={};
int main()
{


    cout << matrizPatrones<< endl;
    publik();
    return 0;
}

void publik(){
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
        imagen();
    case 3:
        patrones(matrizPatrones);
    default:
        break;
    }

}

void imagen(){//matriz del usuario
    int matrizUsuario[8][8]={};

    cout<<"ingrese un 1 para encendido y 0 para apagado"<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int a=0;
            cout << "ingrese estado del led en la posici0on ["<<i+1<<"]["<<j+1<<"]: "<<endl;
            cin >>a;
            *(*(matrizUsuario+j)+i) =a;
            //matrizUsuario[i][j]=a;
        }
    }
    for(int x=0;x<8;x++){
        for(int z=0; z<8;z++){
            cout << *(*(matrizUsuario+z)+x)<<" ";
            //cout << matrizUsuario[x][z]<< " ";
        }
        cout<<endl;
    }
}

void patrones(int matriz[8][8]){
    cout << matriz;
}
