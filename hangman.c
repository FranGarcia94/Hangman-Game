// Ahorcado 2

#include<stdio.h>
#include<string.h>
#define N 50
#define M 22

typedef char tipo_1[N];
typedef char matriz[M][M];

void cambio(char palabra[N]);
void mostrar(char guion[N],int *cont);
void mostrar2(char comprobar[N]);
void ganador(char dibujo[M][M]);
void cabeza(char dibujo[M][M]);
void cuerpo(char dibujo[M][M]);
void pizq(char dibujo[M][M]);
void pdcha(char dibujo[M][M]);
void bizq(char dibujo[M][M]);
void bdcho_todo(char dibujo[M][M]);
void muerto(char dibujo[M][M]);

int main(){
	
	int i,j,aux,cont,vida,win,cont2,aux2;
	char letra,key;
	
	tipo_1 palabra,guion,comprobar;
	matriz dibujo;
	
	do{
		system("COLOR F"); // Blanco brillante
		printf("\t\t~~Juego del Ahorcado~~\n");
		printf("\t\t======================\n\n");
		printf("Introduce la palabra para jugar: ");
		fflush(stdin);
		fgets(palabra,N,stdin);
		system("cls");
		
		cont=0; // Para saber cuantas letras tiene la palabra
		
		i=0;
		while(i<N){
			if(palabra[i]=='\n'){
				i=N;
			}
			else{
				guion[i]='_';
				cont+=1;
				i++;
			}
		}
		
		i=0;
		while(i<N){
			comprobar[i]='0';
			i++;
		}
		
		cont2=0;	// Compara con el primer contador para saber que est�n todas las letras
		win=0;	// Comprueba si se gana 
		vida=6;
		do{	
			aux=0;
			aux2=0;	// Para saber que la letra NO est� seleccionada
			do{
				
				//
			switch(vida){
				case 6:{
					printf("\n");
					bdcho_todo(dibujo);
					printf("\n");
					break;
				}
				case 5:{
					printf("\n");
					bizq(dibujo);
					printf("\n");
					break;
				}
				case 4:{
					printf("\n");
					pdcha(dibujo);
					printf("\n");
					break;
				}
				case 3:{
					printf("\n");
					pizq(dibujo);
					printf("\n");
					break;
				}
				case 2:{
					printf("\n");
					cuerpo(dibujo);
					printf("\n");
					break;
				}
				case 1:{
					printf("\n");
					cabeza(dibujo);
					printf("\n");
					break;
				}
			}
			//
				
				mostrar(guion,&cont);
				printf("\n\tVidas: %i\n\n",vida);
				mostrar2(comprobar);
				
				printf("\tLetra: ");
				scanf(" %c",&letra);
				i=0;
				while(i<N){
					if(letra==comprobar[i]){
						system("cls");
						printf("\n\tEsa letra ya estaba seleccionada\n");
						i=(N+1);
					}
					else{
						i++;
					}
				}
				
				if(i==N){
					aux2=1;
				}
				
			}while(aux2==0);
			
			
			system("cls");
			
			i=0;
			while(i<cont){
				if(letra==palabra[i]){
					guion[i]=letra;
					comprobar[i]=letra;
					cont2+=1;
					aux=1;
					i++;
				}
				else{
					i++;
				}
			}
			
			if(aux==0){
				comprobar[cont+vida]=letra;
				vida-=1;
			}
			
			if(cont2==cont){
				win=1;
			}
			
		}while(vida>0 && win==0);
		
		system("cls");
		
		if(win==1){
			ganador(dibujo);
			mostrar(guion,&cont);
			printf("\t---HAS GANADO--- \n\n");
		}
		else{
			//system("COLOR C"); // Rojo claro
			printf("\n\t~~HAS PERDIDO~~\n\n");
			printf("La palabra es: %s\n",palabra);
			muerto(dibujo);
			printf("\n\n");
		}
		
		printf("�Otra?:(s/n)\n");
		printf(" ");
		scanf(" %c",&key);
		system("cls");
	}while(key=='s');
	
	return 0;
}

void cambio(char palabra[N]){ // Para quitar el salto de l�nea al final de un string
	int i;
	for(i=0;i<N;i++){
		if(palabra[i]=='\n'){
			palabra[i]='\0';
		}
	}
}

void mostrar(char guion[N],int *cont){
	int i;
	printf("\n\t");
	i=0;
	while(i<*cont){
		if(guion[i]=='\n'){
			i=N;
		}
		else{
			printf("%c ",guion[i]);
			i++;
		}
	}
	printf("\n\n");
}

void mostrar2(char comprobar[N]){
	int i,j;
	printf("\n");
	printf("Letras ya seleccionadas:\n");
	i=0;
	while(i<N){
		if(comprobar[i]=='\n'){
			i=N;
		}
		else{
			if(comprobar[i]=='0'){
				i++;
			}
			else{
				j=i-1;
				while(j>=0){
					if(comprobar[i]==comprobar[j]){
						comprobar[i]='0';
						j--;
					}
					else{
						j--;
					}
				}
				if(comprobar[i]=='0'){
					i++;
				}
				else{
					printf("%c, ",comprobar[i]);
					i++;	
				}
			}
		}
	}
	printf("\n\n");
}

void ganador(char dibujo[M][M]){
	int i,j,k;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	k=0;
	while(k<16){
		if((k%2)==0){
			i=0;
			while(i<M){
				j=0;
				while(j<M){
					dibujo[i][j]=' ';
					j++;
				}
				i++;
			}
			// Dibujo 2 Ganador
			// Cabeza
			dibujo[4][8]=c;
			dibujo[4][9]=c;
			dibujo[4][10]=c;
			dibujo[8][8]=c;
			dibujo[8][9]=c;
			dibujo[8][10]=c;
			
			dibujo[5][7]=c;
			dibujo[6][7]=c;
			dibujo[7][7]=c;
			dibujo[5][11]=c;
			dibujo[6][11]=c;
			dibujo[7][11]=c;
			
			dibujo[5][8]='o';
			dibujo[5][10]='o';
			dibujo[7][9]='.';
			
			// Cuerpo
			dibujo[9][9]=c;
			dibujo[10][9]=c;
			dibujo[11][9]=c;
			dibujo[12][9]=c;
			dibujo[13][9]=c;
			
			// Piernas
			dibujo[14][8]=c;
			dibujo[16][7]=c;
			dibujo[17][7]=c;
			dibujo[18][7]=c;
			dibujo[15][7]=c;
			
			dibujo[14][10]=c;
			dibujo[16][11]=c;
			dibujo[17][11]=c;
			dibujo[18][11]=c;
			dibujo[15][11]=c;
			
			// Brazos
			dibujo[9][8]=c;
			dibujo[10][7]=c;
			dibujo[11][6]=c;
			dibujo[10][5]=c;
			dibujo[9][4]='O';
			
			dibujo[9][10]=c;
			dibujo[10][11]=c;
			dibujo[11][12]=c;
			dibujo[10][13]=c;
			dibujo[9][14]='O';
			
			i=0;
			while(i<M){
				j=0;
				while(j<M){
					printf(" %c",dibujo[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
			usleep(90000);
			system("cls");
			k++;
		}
		else{
			i=0;
			while(i<M){
				j=0;
				while(j<M){
					dibujo[i][j]=' ';
					j++;
				}
				i++;
			}
			// Dibujo 3 ganador
			// Cabeza
			dibujo[4][8]=c;
			dibujo[4][9]=c;
			dibujo[4][10]=c;
			dibujo[8][8]=c;
			dibujo[8][9]=c;
			dibujo[8][10]=c;
			
			dibujo[5][7]=c;
			dibujo[6][7]=c;
			dibujo[7][7]=c;
			dibujo[5][11]=c;
			dibujo[6][11]=c;
			dibujo[7][11]=c;
			
			dibujo[5][8]='o';
			dibujo[5][10]='o';
			dibujo[7][9]='O';
			
			// Cuerpo
			dibujo[9][9]=c;
			dibujo[10][9]=c;
			dibujo[11][9]=c;
			dibujo[12][9]=c;
			dibujo[13][9]=c;
			
			// Piernas
			dibujo[14][8]=c;
			dibujo[16][7]=c;
			dibujo[17][7]=c;
			dibujo[18][7]=c;
			dibujo[15][7]=c;
			
			dibujo[14][10]=c;
			dibujo[16][11]=c;
			dibujo[17][11]=c;
			dibujo[18][11]=c;
			dibujo[15][11]=c;
			
			// Brazos
			dibujo[9][8]=c;
			dibujo[8][7]=c;
			dibujo[7][6]=c;
			dibujo[6][5]=c;
			dibujo[5][5]=c;
			dibujo[4][5]='O';
			
			dibujo[9][10]=c;
			dibujo[8][11]=c;
			dibujo[7][12]=c;
			dibujo[6][13]=c;
			dibujo[5][13]=c;
			dibujo[4][13]='O';
			
			i=0;
			while(i<M){
				j=0;
				while(j<M){
					printf(" %c",dibujo[i][j]);
					j++;
				}
				printf("\n");
				i++;
			}
			if(k<15){
				system("cls");	// Para que al final se quede el dibujo en pantalla
				k++;
			}
			else{
				k++;
			}
			
			usleep(90000);
		}
	}
}

void cabeza(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	// Cabeza
	dibujo[4][12]=c;
	dibujo[4][13]=c;
	dibujo[4][14]=c;
	dibujo[8][12]=c;
	dibujo[8][13]=c;
	dibujo[8][14]=c;
	dibujo[5][11]=c;
	dibujo[6][11]=c;
	dibujo[7][11]=c;
	dibujo[5][15]=c;
	dibujo[6][15]=c;
	dibujo[7][15]=c;
	
	// Expresi�n, (alt+166).
	dibujo[5][12]='O';
	dibujo[5][14]='O';
	dibujo[7][13]='.';
	
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}

void cuerpo(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	// Cabeza
	dibujo[4][12]=c;
	dibujo[4][13]=c;
	dibujo[4][14]=c;
	dibujo[8][12]=c;
	dibujo[8][13]=c;
	dibujo[8][14]=c;
	dibujo[5][11]=c;
	dibujo[6][11]=c;
	dibujo[7][11]=c;
	dibujo[5][15]=c;
	dibujo[6][15]=c;
	dibujo[7][15]=c;
	
	// Expresi�n
	dibujo[5][12]='o';
	dibujo[5][14]='o';
	dibujo[7][13]='-';
	
	// Cuerpo
	dibujo[9][13]=c;
	dibujo[10][13]=c;
	dibujo[11][13]=c;
	dibujo[12][13]=c;
	dibujo[13][13]=c;
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}

void pizq(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	// Cabeza
	dibujo[4][12]=c;
	dibujo[4][13]=c;
	dibujo[4][14]=c;
	dibujo[8][12]=c;
	dibujo[8][13]=c;
	dibujo[8][14]=c;
	dibujo[5][11]=c;
	dibujo[6][11]=c;
	dibujo[7][11]=c;
	dibujo[5][15]=c;
	dibujo[6][15]=c;
	dibujo[7][15]=c;
	
	// Expresi�n
	dibujo[5][12]='o';
	dibujo[5][14]='o';
	dibujo[7][13]='~';
	
	// Cuerpo
	dibujo[9][13]=c;
	dibujo[10][13]=c;
	dibujo[11][13]=c;
	dibujo[12][13]=c;
	dibujo[13][13]=c;
	// Pierza izq
	dibujo[14][12]=c;
	dibujo[15][11]=c;
	dibujo[16][11]=c;
	dibujo[17][11]=c;
	dibujo[18][11]=c;
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}

void pdcha(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	// Cabeza
	dibujo[4][12]=c;
	dibujo[4][13]=c;
	dibujo[4][14]=c;
	dibujo[8][12]=c;
	dibujo[8][13]=c;
	dibujo[8][14]=c;
	dibujo[5][11]=c;
	dibujo[6][11]=c;
	dibujo[7][11]=c;
	dibujo[5][15]=c;
	dibujo[6][15]=c;
	dibujo[7][15]=c;
	
	// Expresi�n
	dibujo[5][12]='o';
	dibujo[5][14]='o';
	dibujo[7][13]='~';
	
	// Cuerpo
	dibujo[9][13]=c;
	dibujo[10][13]=c;
	dibujo[11][13]=c;
	dibujo[12][13]=c;
	dibujo[13][13]=c;
	// Pierza izq
	dibujo[14][12]=c;
	dibujo[15][11]=c;
	dibujo[16][11]=c;
	dibujo[17][11]=c;
	dibujo[18][11]=c;
	// Pierna dcha
	dibujo[14][14]=c;
	dibujo[15][15]=c;
	dibujo[16][15]=c;
	dibujo[17][15]=c;
	dibujo[18][15]=c;
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}

void bizq(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	// Cabeza
	dibujo[4][12]=c;
	dibujo[4][13]=c;
	dibujo[4][14]=c;
	dibujo[8][12]=c;
	dibujo[8][13]=c;
	dibujo[8][14]=c;
	dibujo[5][11]=c;
	dibujo[6][11]=c;
	dibujo[7][11]=c;
	dibujo[5][15]=c;
	dibujo[6][15]=c;
	dibujo[7][15]=c;
	
	// Expresi�n
	dibujo[5][12]='o';
	dibujo[5][14]='o';
	dibujo[7][13]='~';
	
	// Cuerpo
	dibujo[9][13]=c;
	dibujo[10][13]=c;
	dibujo[11][13]=c;
	dibujo[12][13]=c;
	dibujo[13][13]=c;
	// Pierza izq
	dibujo[14][12]=c;
	dibujo[15][11]=c;
	dibujo[16][11]=c;
	dibujo[17][11]=c;
	dibujo[18][11]=c;
	// Pierna dcha
	dibujo[14][14]=c;
	dibujo[15][15]=c;
	dibujo[16][15]=c;
	dibujo[17][15]=c;
	dibujo[18][15]=c;
	// Brazo izq
	dibujo[9][12]=c;
	dibujo[10][11]=c;
	dibujo[11][10]=c;
	dibujo[12][9]=c;
	dibujo[13][9]='O';
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}

void bdcho_todo(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	// Cabeza
	dibujo[4][12]=c;
	dibujo[4][13]=c;
	dibujo[4][14]=c;
	dibujo[8][12]=c;
	dibujo[8][13]=c;
	dibujo[8][14]=c;
	dibujo[5][11]=c;
	dibujo[6][11]=c;
	dibujo[7][11]=c;
	dibujo[5][15]=c;
	dibujo[6][15]=c;
	dibujo[7][15]=c;
	
	// Expresi�n
	dibujo[5][12]='o';
	dibujo[5][14]='o';
	dibujo[7][13]='O';
	
	// Cuerpo
	dibujo[9][13]=c;
	dibujo[10][13]=c;
	dibujo[11][13]=c;
	dibujo[12][13]=c;
	dibujo[13][13]=c;
	// Pierza izq
	dibujo[14][12]=c;
	dibujo[15][11]=c;
	dibujo[16][11]=c;
	dibujo[17][11]=c;
	dibujo[18][11]=c;
	// Pierna dcha
	dibujo[14][14]=c;
	dibujo[15][15]=c;
	dibujo[16][15]=c;
	dibujo[17][15]=c;
	dibujo[18][15]=c;
	// Brazo izq
	dibujo[9][12]=c;
	dibujo[10][11]=c;
	dibujo[11][10]=c;
	dibujo[12][9]=c;
	dibujo[13][9]='O';
	// Brazo dhco
	dibujo[9][14]=c;
	dibujo[10][15]=c;
	dibujo[11][16]=c;
	dibujo[12][17]=c;
	dibujo[13][17]='O';
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}

void muerto(char dibujo[M][M]){
	int i,j;
	char c;
	
	c='0';
	
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			dibujo[i][j]=' ';
			j++;
		}
		i++;
	}
	
	// L�nea H 1
	dibujo[0][1]=c;
	dibujo[0][2]=c;
	dibujo[0][3]=c;
	dibujo[0][4]=c;
	dibujo[0][5]=c;
	dibujo[0][6]=c;
	dibujo[0][7]=c;
	dibujo[0][8]=c;
	dibujo[0][9]=c;
	dibujo[0][10]=c;
	dibujo[0][11]=c;
	dibujo[0][12]=c;
	dibujo[0][13]=c;
	dibujo[0][14]=c;
	//L�nea H 2
	dibujo[2][1]=c;
	dibujo[2][3]=c;
	dibujo[2][4]=c;
	dibujo[2][5]=c;
	dibujo[2][6]=c;
	dibujo[2][7]=c;
	dibujo[2][8]=c;
	dibujo[2][9]=c;
	dibujo[2][10]=c;
	dibujo[2][11]=c;
	dibujo[2][12]=c;
	dibujo[2][13]=c;
	dibujo[2][14]=c;
	//L�nea V 1
	dibujo[1][1]=c;
	dibujo[3][1]=c;
	dibujo[4][1]=c;
	dibujo[5][1]=c;
	dibujo[6][1]=c;
	dibujo[7][1]=c;
	dibujo[8][1]=c;
	dibujo[9][1]=c;
	dibujo[10][1]=c;
	dibujo[11][1]=c;
	dibujo[12][1]=c;
	dibujo[13][1]=c;
	dibujo[14][1]=c;
	dibujo[15][1]=c;
	dibujo[16][1]=c;
	dibujo[17][1]=c;
	dibujo[18][1]=c;
	dibujo[19][1]=c;
	//L�nea V 2
	dibujo[3][3]=c;
	dibujo[4][3]=c;
	dibujo[5][3]=c;
	dibujo[6][3]=c;
	dibujo[7][3]=c;
	dibujo[8][3]=c;
	dibujo[9][3]=c;
	dibujo[10][3]=c;
	dibujo[11][3]=c;
	dibujo[12][3]=c;
	dibujo[13][3]=c;
	dibujo[14][3]=c;
	dibujo[15][3]=c;
	dibujo[16][3]=c;
	dibujo[17][3]=c;
	dibujo[18][3]=c;
	dibujo[19][3]=c;
	// Base y otros
	dibujo[18][0]=c;
	dibujo[18][2]=c;
	dibujo[18][4]=c;
	dibujo[18][5]=c;
	dibujo[18][6]=c;
	dibujo[19][0]=c;
	dibujo[19][2]=c;
	dibujo[19][4]=c;
	dibujo[19][5]=c;
	dibujo[19][6]=c;
	dibujo[1][14]=c;
	dibujo[3][13]=c;
	
	// Muerto
	dibujo[4][13]=c;
	dibujo[5][13]=c;
	dibujo[5][12]=c;
	dibujo[5][11]=c;
	dibujo[6][10]=c;
	dibujo[7][10]=c;
	dibujo[8][10]=c;
	dibujo[9][11]=c;
	dibujo[9][12]=c;
	dibujo[9][13]=c;
	dibujo[8][13]=c;
	dibujo[7][14]=c;
	dibujo[6][14]=c;
	
	dibujo[10][13]=c;
	dibujo[11][13]=c;
	dibujo[12][13]=c;
	dibujo[13][13]=c;
	
	dibujo[10][12]=c;
	dibujo[11][11]=c;
	dibujo[12][11]=c;
	dibujo[13][11]=c;
	
	dibujo[13][12]=c;
	dibujo[14][12]=c;
	dibujo[15][12]=c;
	dibujo[16][12]=c;
	dibujo[17][12]=c;
	dibujo[18][12]=c;
	
	dibujo[10][14]=c;
	dibujo[11][15]=c;
	dibujo[12][15]=c;
	dibujo[13][15]=c;
	
	dibujo[13][14]=c;
	dibujo[14][14]=c;
	dibujo[15][14]=c;
	dibujo[16][14]=c;
	dibujo[17][14]=c;
	dibujo[18][14]=c;
	
	dibujo[13][13]=c;
	dibujo[14][11]='O';
	dibujo[14][15]='O';
	
	// Expresi�n
	dibujo[7][11]='X';
	dibujo[6][12]='X';
	
	// RIP
	dibujo[16][17]=c;
	dibujo[17][17]=c;
	dibujo[18][17]=c;
	dibujo[19][17]=c;
	dibujo[16][21]=c;
	dibujo[17][21]=c;
	dibujo[18][21]=c;
	dibujo[19][21]=c;
	dibujo[15][18]=c;
	dibujo[15][19]=c;
	dibujo[15][20]=c;
	dibujo[19][18]=c;
	dibujo[19][19]=c;
	dibujo[19][20]=c;
	dibujo[17][18]='R';
	dibujo[17][19]='I';
	dibujo[17][20]='P';
	
	printf("\t\t");
	i=0;
	while(i<M){
		j=0;
		while(j<M){
			printf(" %c",dibujo[i][j]);
			j++;
		}
		printf("\n");
		printf("\t\t");
		i++;
	}
}
