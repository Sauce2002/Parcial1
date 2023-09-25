// C++ code
//
void imagen(int** matriz);
void publik();
void patrones(int** matriz);
void limpiarMatriz(int** matriz);
void imprimirMatriz(int** matriz);
void eliminarMatriz(int** p);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  publik();
  delay(1000);
}
void publik(){
//    inicializamos un puntero de una matriz
    int **pMatriz;
    pMatriz = new int* [8];
    for (int i = 0; i <8; i++) {
        pMatriz[i] = new int[8];
    }
  // ponemos todas las posiciones de la funcion en 0
  limpiarMatriz(pMatriz);
  
  
//creamos el menu del usuario
    
    int opcion=0;
    Serial.println("ingrese el numero de la opcion");
    Serial.println("1- verificar funcionamiento de leds.");
    Serial.println("2- ingresar imagen personalizada.");
    Serial.println("3- patrones de ejemplo");
  	while (!Serial.available()){}
    opcion = Serial.parseInt();  	
  	
    switch (opcion) {
    case 1:
        break;
    case 2:
        imagen(pMatriz);
      break;
    case 3:
        patrones(pMatriz);
      	break;
    default:
        break;
    }
	delay(10);
}
void imagen(int** matriz){//matriz del usuario
    Serial.println("ingrese un 1 para encendido y 0 para apagado");
  	Serial.println("ingrese las filas de la siguiente forma, ejemplo(10110110)");
    for(int i=0;i<8;i++){
      	String a ="";
        Serial.print("ingrese la fila [");
        Serial.print(i+1);
      	Serial.print("]: ");
      	while (!Serial.available()){}          
        a = Serial.readString();
      
      
        for(int j=0;j<8;j++){
          Serial.print(a[j]);//si el usuario pone mas de 8 numeros
            int b = 0;		//se imprimiran y tomaran solo los primeros 8
          	b = a[j]-48;
            *(*(matriz+j)+i) = b;
            //matrizUsuario[i][j]=b;
        }
      	Serial.println("");
    }
    imprimirMatriz(matriz);
    eliminarMatriz(matriz);
    Serial.println("");

}
void patrones(int** matriz){
    
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
          Serial.print(*(*(matriz+z)+x));
          Serial.print(" ");           
        }
        Serial.println("");
    }
}

void limpiarMatriz(int** matriz){
    Serial.println("");
    for(int x=0;x<8;x++){
        for(int z=0; z<8;z++){
            *(*(matriz+z)+x)=0;
        }
    }
}

void eliminarMatriz(int** matriz){
    
    for (int i = 0; i < 8; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;
}