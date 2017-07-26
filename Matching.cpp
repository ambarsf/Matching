#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstring>
using namespace std;
char** llenarColumna(int);
void imprimircolumnas(char**,char**,int,int);
int* numerosRandom(int);
int Pareja(char**, char**, char**, int);

int main(int argc,char* argv[]){
	char resp [80];
	srand(time(0));
	do{
		cout<<"Ingrese numero de palabras para la Columna A: "<<endl;
		int numPalabrasA;
		cin>>numPalabrasA;

		cout<<"Ingrese numero de palabras para la columna B: "<<endl;
		int numPalabrasB;
		cin>>numPalabrasB;

		char** columnaA= new char* [numPalabrasA];
		char** columnaB= new char* [numPalabrasB];
		cout<<"Palabras Columna A: "<<endl;
		columnaA=llenarColumna(numPalabrasA);
		cout<<endl;
		cout<<"Palabras Columna B: "<<endl;
		columnaB=llenarColumna(numPalabrasB);

		char** pairs = new char* [numPalabrasA+numPalabrasB];
		int numPairs=0;
		int iterador=0;
		imprimircolumnas(columnaA,columnaB, numPalabrasA, numPalabrasB);
		cout<<"Crear Parejas: "<<endl;
		do{
			cout<<"Columna A: ";
			int columnA;
			cin>>columnA;
			cout<<endl;
			pairs[iterador]= new char[strlen(columnaA[columnA-1])+1];
			strcpy(pairs[iterador],columnaA[columnA-1]);
			iterador++;
			cout<<"Columna B: ";
			int columnB;
			cin>>columnB;
			cout<<endl;
			pairs[iterador]= new char[strlen(columnaB[columnB-1])+1];
			strcpy(pairs[iterador],columnaB[columnB-1]);
			iterador++;
			bool salir;
			numPairs++;
			do{
				salir=false;
				cout<<"Desea emparejar otra palabra? (S/N):"<<endl;
				cin>>resp;
				if (strlen(resp)>1){
					cout<<"Opcion no valida"<<endl;
					salir=true;
				}else if(!(resp[0]=='s'||resp[0]=='S'||resp[0]=='n'||resp[0]=='N')){
					cout<<"Opcion no valida"<<endl;
					salir=true;
				}
			}while(salir==true);
		}while (resp[0]=='s'||resp[0]=='S'||iterador>numPalabrasA+numPalabrasB);

		int* randomA= new int [numPalabrasA];
		int* randomB= new int [numPalabrasB];
		randomA=numerosRandom(numPalabrasA);
		randomB=numerosRandom(numPalabrasB);

		char** NewA = new char*[numPalabrasA];
		for (int i = 0; i < numPalabrasA; i++)
		{
			NewA[i]= new char[strlen(columnaA[randomA[i]])+1];
			strcpy(NewA[i],columnaA[randomA[i]]);
		}

		char** NewB = new char*[numPalabrasB];
		for (int i = 0; i < numPalabrasB; i++)
		{
			NewB[i]= new char[strlen(columnaB[randomB[i]])+1];
			strcpy(NewB[i],columnaB[randomB[i]]);
		}


		imprimircolumnas(NewA,NewB,numPalabrasA,numPalabrasB);

		int parejasAcertadas=0;
		do{
			cout<<"Emparejamiento de Palabras"endl;
			parejasAcertadas+=Pareja(NewA, NewB, pairs, iterador);

			bool salir;
			do{
				salir=false;
				cout<<"Desea emparejar otra palabra? (S/N):"<<endl;
				cin>>resp;
				if (strlen(resp)>1){
					cout<<"Opcion no valida"<<endl;
					salir=true;
				}else if(!(resp[0]=='s'||resp[0]=='S'||resp[0]=='n'||resp[0]=='N')){
					cout<<"Opcion no valida"<<endl;
					salir=true;
				}
			}while(salir==true);
		}while (resp[0]=='s'||resp[0]=='S');

		int porcentaje=(parejasAcertadas*100)/numPairs;
		cout<<"El porcentaje de ganados es:"<<porcentaje<<endl;


		bool salida;
		do{
			salida=false;
			cout<<"Desea volver a jugar? (S/N):"<<endl;
			cin>>resp;
			if (strlen(resp)>1){
				cout<<"Opcion no valida"<<endl;
				salida=true;
			}else if(!(resp[0]=='s'||resp[0]=='S'||resp[0]=='n'||resp[0]=='N')){
				cout<<"Opcion no valida"<<endl;
				salida=true;
			}
		}while(salida==true);

	}while (resp[0]=='s'||resp[0]=='S');
	return 0;
}

char** llenarColumna(int numPalabras){
	char** columna = new char*[numPalabras];
	for (int word = 0; word < numPalabras; word++)
	{
		cout<<"Ingrese una palabra: "<<endl;
		char palabra[80];
		cin>>palabra;
		columna[word]= new char[strlen(palabra)+1];
		strcpy(columna[word],palabra);
	}
	return columna;
}

void imprimircolumnas(char** columnaA, char** columnaB, int numA, int numB){
	cout<<"Columna A:"<<endl;
	for (int word = 0; word < numA; word++)
	{
		cout<<word+1<<"."<<columnaA[word]<<endl;
	}

	cout<<"Columna B:"<<endl;
	for (int word = 0; word < numB; word++)
	{
		cout<<word+1<<"."<<columnaB[word]<<endl;
	}
}

int* numerosRandom(int numero){
	bool esta;
	int random;
	int* numeros= new int[numero];
	int iterador=0;
	while(iterador<numero){
		do{
			esta=false;
			random=rand()%numero;
			for (int i = 0; i < iterador; i++)
			{
				if (random==numeros[i]){
					esta=true;
					break;
				}
			}
		}while (esta==true);
		numeros[iterador]=random;
		iterador++;
	}
	return numeros;
}

int Pareja (char** NewA, char** NewB, char** pairs, int palabras){
	int pair=0;
	int numb=0;
	int numA, numB;
	cout<<"Columna A: ";
	cin>>numA;
	cout<<endl;
	cout<<"Columna B: ";
	cin>>numB;
	cout<<endl;
	char palabraA[80];
	char palabraB[80];

	strcpy(palabraA,NewA[numA-1]);
	strcpy(palabraB,NewB[numB-1]);
	bool esta=false;
	for (int i = 0; i < palabras; i++)
	{
		if (strcmp(pairs[i],palabraA)==0){
			 numb=i+1;
			esta=true;
			break;
		}
	}

	if (esta==true){
		if (strcmp(pairs[numb],palabraB)==0){
			pair=1;
		}else{
			pair=0;

			
		}
	}else if (esta==false){
		pair=0;
	}
	return pair;

}
