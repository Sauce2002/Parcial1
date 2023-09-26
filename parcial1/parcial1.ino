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
    prenderMatriz(pMatriz);
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
  	int *secuencias = new int;
  	int *tiempo = new int;
  	Serial.print("ingrese tiempo entre encendido y apagado(segundos): ");
  	
  	while (!Serial.available()){}
  	*tiempo=Serial.parseInt();
  	Serial.println(*tiempo);
  
  	Serial.print("ingrese numero de secuencias: ");      
  	while (!Serial.available()){};
  	*secuencias=Serial.parseInt();
  	Serial.println(*secuencias);
  	
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
  for(int i=0;i < *secuencias;i++){
    imprimirMatriz(matriz);
  	encenderIntervalo(matriz,tiempo);   
    Serial.println("");
    delay(*tiempo*1000);
  }  
  eliminarMatriz(matriz);
  delete tiempo;
  tiempo=nullptr;
  delete secuencias;
  secuencias=nullptr;

}
void patrones(int** matriz){
    
  	int *tiempo = new int;
  
  	Serial.print("ingrese tiempo entre encendido y apagado(segundos): ");
  	while (!Serial.available()){};
  	*tiempo=Serial.parseInt();
  	Serial.println(*tiempo);
  	
//    patron 1

    for (int fila = 0; fila <8; fila++) {
        for (int columna = 0; columna < 8; columna++) *(*(matriz+columna)+fila)=1;
    }
    int a=0;
    for (int fila = 0; fila <8; fila++) {

        a++;
        for (int columna = 0; columna < 8; columna++) {
        if(fila+columna<3)*(*(matriz+columna)+fila)=0;
        else if(fila+columna>4+fila && fila+columna<10 && columna>3+a)*(*(matriz+columna)+fila)=0;
        else if(fila+columna<10 && columna<3&& fila>4+columna) *(*(matriz+columna)+fila)=0;
        else if(fila+columna<10 && fila>4+columna && fila+columna>4+fila)*(*(matriz+columna)+fila)=0;
        }

    }
  	encenderIntervalo(matriz, tiempo);
	imprimirMatriz(matriz);  
    limpiarMatriz(matriz);
  	delay(*tiempo*1000);
//    patron 2
    for (int i = 0; i < 8; ++i) {        
        *(*(matriz+i)+i)=1;//matriz[i][i]=1;        
        *(*(matriz+(7-i))+i)=1;//matriz[i][7-i]=1;
    }
    encenderIntervalo(matriz, tiempo);
	imprimirMatriz(matriz);
    limpiarMatriz(matriz); 	
	delay(*tiempo*1000);
//    patron 3
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
  	encenderIntervalo(matriz, tiempo);
	imprimirMatriz(matriz);
  	limpiarMatriz(matriz);
  	delay(*tiempo*1000);
    
    eliminarMatriz(matriz);
	delete tiempo;
  	tiempo=nullptr;
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
  	int *secuencias = new int;
  	int *tiempo = new int;
  
  	Serial.print("ingrese tiempo entre encendido y apagado(segundos): ");
  while (!Serial.available()){};
  	*tiempo=Serial.parseInt();
  	Serial.println(*tiempo);
  
  	Serial.print("ingrese numero de secuencias: ");      
  while (!Serial.available()){};
  	*secuencias=Serial.parseInt();
  	Serial.println(*secuencias);
  
  for(int i=0;i <*secuencias;i++){
    
  	digitalWrite(latchPin,LOW);
  	shiftOut(data,clockPin,LSBFIRST,255);
  	digitalWrite(latchPin,HIGH);
    delay(*tiempo*1000);
    	  	
	digitalWrite(latchPin,LOW);
  	shiftOut(data,clockPin,LSBFIRST,0);
  	digitalWrite(latchPin,HIGH);
    delay(*tiempo*1000);  	
  }
  	digitalWrite(latchPin,LOW);
  	shiftOut(data,clockPin,LSBFIRST,0);
  	digitalWrite(latchPin,HIGH);
  delete tiempo;
  delete secuencias;
  tiempo = nullptr;
  secuencias=nullptr;
  
}

void prenderMatriz(int** matriz){
  	int *b = new int;
  	int *c = new int;
	for(int x=0;x<8;x++){
      	*b=7;
      	int *bytex = new int;
       *bytex=1<<(*b-x);
      //Serial.println(bytex);
        for(int y=0; y<8;y++){
        	*c=7;
          	int *bytey=new int;
        	*bytey=1<<(*c-y);
        if(*(*(matriz+y)+x)==1){
        	digitalWrite(latchPin,LOW);
  			shiftOut(data,clockPin,LSBFIRST,*bytey);
          	shiftOut(data,clockPin,LSBFIRST,(255-*bytex));
  			digitalWrite(latchPin,HIGH);
        	}
          delete bytey;
          bytey=nullptr;
          //delay(1);
        } 
      delete bytex;
      bytex=nullptr;
    }
  	delete b;
  	b=nullptr;
  	delete c;
  	c=nullptr;
}
void encenderIntervalo(int** matriz, int* tiempo){
  unsigned long *tiempoInicio=new unsigned long; 
  *tiempoInicio=millis();
  while(millis()-*tiempoInicio<*tiempo*1000){
  	prenderMatriz(matriz);
  }
  
  delete tiempoInicio;
  tiempoInicio=nullptr;   
}