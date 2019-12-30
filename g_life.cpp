#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define w 120
#define h 150

#define for_x for (int x = 0; x < w; x++)
#define for_y for (int y = 0; y < h; y++)



using namespace std;


void g_matrix (int **matrix){
srand (time (NULL));
for_x for_y
matrix[x][y] = rand() < RAND_MAX / 10 ? 1 : 0;
}


//se matriz[][] == 1 printa caracter se n printa espaço
void print (int **matrix){
for_x { for_y { 
		if (matrix[x][y] == 1) cout << "▒";
		else cout << " ";
	}
cout << "\n"; 
}

}


//atribui 0 ou 1 a soma da contagem de vizinhos da posição específica, com relação aos 8 vizinhos da posição 
int neighbour (int i,int j, int **matrix){
int count=0;

if (i > 0 && i < w-1 && j > 0 && j < h-1){
	count += matrix[i-1][j-1] % 2 > 0 ? 1:0;
        count += matrix[i-1][j] % 2 > 0 ? 1:0;
  	count += matrix[i-1][j+1] % 2 > 0 ? 1:0;
	count += matrix[i][j-1] % 2 > 0 ? 1:0;
	count += matrix[i][j+1] % 2 > 0 ? 1:0;
	count += matrix[i+1][j-1] % 2 > 0 ? 1:0;
	count += matrix[i+1][j] % 2 > 0 ? 1:0;
	count += matrix[i+1][j+1] % 2 > 0 ? 1:0;
}

return count;

}


void print_neighbours(int **matrix){
for_x{ for_y{ 
		cout << neighbour(x, y, matrix); 
	}	
	cout << "\n"; 
}
}


//regras do jogo na versao clássica (B3/S23). 
//Se a contagem de vizinhos é 3 e a posição é zero (célula morta), ela vive.
//Se a contagem de vizinhos for menor que 2 ou maior que 3 para uma célula vive, ela morre.
void game(int **matrix){
for_x for_y {
	if (matrix[x][y] == 0){
		if (neighbour(x,y,matrix) == 3 ) matrix[x][y] = 1;
        }
	else if (matrix[x][y] == 1){
		if (neighbour(x,y,matrix) < 2 || neighbour(x,y,matrix) > 3) matrix[x][y] = 0;
	}
}

}

int main(){

//aloca matriz de w linhas de h colunas cada
int **matrix = (int**)malloc(w * sizeof (int*));
for_x
matrix[x] = (int*)malloc(h * sizeof (int));

//função q gera matriz
g_matrix (matrix);

//roda loop infinito a partir da matriz inicial
while (1){
game (matrix);
print (matrix);
usleep(100000);
system("tput reset");
}
//system("tput reset");  system("clear"); (linux)
//system("cls"); (windows) 

return 0;
}