#include <iostream>

using namespace std;
void imagen();
int main()
{
    cout << "Hello World!" << endl;
    imagen();
    return 0;
}

void imagen(){//matriz del usuario
    int matrizUsuario[8][8]={};
    //int *pMatrizPuntero = &matrizUsuario[8][8];
    cout<<"ingrese un 1 para encendido y 0 para apagado"<<endl;
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
            int a=0;
            cout << "ingrese estado del led en la posici0on ["<<i+1<<"]["<<j+1<<"]: "<<endl;
            cin >>a;
            matrizUsuario[i][j]=a;
        }
    }
    for(int x=0;x<8;x++){
        for(int z=0; z<8;z++){
            cout<< matrizUsuario[x][z];
        }
        cout<<endl;
    }
}
