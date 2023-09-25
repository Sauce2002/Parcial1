// C++ code
//

int clockPin = 4;
int data = 2;
int latchPin = 3;

void prenderMatriz(int** matriz);
void imagen(int** matriz);
void publik();
void patrones(int** matriz);
void limpiarMatriz(int** matriz);
void imprimirMatriz(int** matriz);
void eliminarMatriz(int** matriz);
void eliminarMatriz(int** matriz);
void setup()
{
  Serial.begin(9600);
  pinMode(clockPin,OUTPUT);
  pinMode(data,OUTPUT);  
  pinMode(latchPin,OUTPUT);
}

void loop()
{
  publik();
  
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
      verificarMatriz(pMatriz);
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
  	limpiarMatriz(matriz);//por si el usuario ingresa menos de 8 numeros
    Serial.println("ingrese un 1 para encendido y 0 para apagado");
  	Serial.println("ingrese las filas de la siguiente forma, ejemplo(10110110)");
    for(int i=0;i<8;i++){
      	String a ="00000000";
        Serial.print("ingrese la fila [");
        Serial.print(i+1);
      	Serial.print("]: ");
      	while (!Serial.available()){}          
        a = Serial.readString();
      
      
        for(int j=0;j<8;j++){
          Serial.print(a[j]);//si el usuario pone mas de 8 numeros
            int b = 0;		//se imprimiran y tomaran solo los primeros 8
          	b = a[j]-48;
            if(b>=0)*(*(matriz+j)+i) = b;
            //matrizUsuario[i][j]=b;
        }
      	Serial.println("");
    }
    imprimirMatriz(matriz);
  	prenderMatriz(matriz);
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
    prenderMatriz(matriz);
	imprimirMatriz(matriz);
    limpiarMatriz(matriz);

//    patron 3

    
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

void verificarMatriz(int** matriz){
  	int secuencias;
  	int tiempo;
  
  	Serial.print("ingrese tiempo entre encendido y apagado(segundos): ");
  while (!Serial.available()){};
  	tiempo=Serial.parseInt();
  	Serial.println(tiempo);
  
  	Serial.print("ingrese numero de secuencias: ");      
  while (!Serial.available()){};
  	secuencias=Serial.parseInt();
  	Serial.println(secuencias);
  
  for(int i=0;i <secuencias;i++){
    
  	digitalWrite(latchPin,LOW);
  	shiftOut(data,clockPin,LSBFIRST,255);
  	digitalWrite(latchPin,HIGH);
    delay(tiempo*1000);
    	  	
	digitalWrite(latchPin,LOW);
  	shiftOut(data,clockPin,LSBFIRST,0);
  	digitalWrite(latchPin,HIGH);
    delay(tiempo*1000);  	
  }
  	digitalWrite(latchPin,LOW);
  	shiftOut(data,clockPin,LSBFIRST,0);
  	digitalWrite(latchPin,HIGH);
}

void prenderMatriz(int** matriz){
	for(int x=0;x<8;x++){
      int b=7;
      int bytex=1<<(b-x);
      //Serial.println(bytex);
        for(int y=0; y<8;y++){
        	int c=7;
        	int bytey=1<<(c-y);
        if(*(*(matriz+y)+x)==1){
        	digitalWrite(latchPin,LOW);
  			shiftOut(data,clockPin,LSBFIRST,bytey);
          	shiftOut(data,clockPin,LSBFIRST,(255-bytex));
  			digitalWrite(latchPin,HIGH);
        	}
          //delay(500);
        }        
    }
}