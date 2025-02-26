/*
 * main.c
 *
 *  Created on: 16 de out de 2017
 *      Author: pabloemanuell
 */
#include <stdio.h>
typedef struct {
	int r;
	int g;
	int b;
}Pixel;
typedef struct{
	int altura;
	int largura;
	int valorMaximoCor; // valor maximo para as componentes de cor
	Pixel *pixel;
}Imagem;
void ignorarComentarios(FILE *f);
int lerImagemPPM();

Imagem imagem;
int main(int argc, char **argv) {// exemplo de entrada ​ ./catarata​ ​ -i​ ​ ​ imagem.bmp​ ​ ​ -f​ ​ bmp​ ​ -o​ ​ diagnostico.txt
	FILE *fimagem;
	//FAZER: Tratar argumentos de entrada
	fimagem = fopen("img/Catarata.ppm", "r");
	//FAZER: Usar metodo correspondento ao tipo de imagem
	lerImagemPPM(fimagem);
	return 0;
}
void ignorarComentarios(FILE *f){
	char c[2];
	while(fscanf(f, "%1[#]%*[^\n]\n", &c) > 0);
}
int lerImagemPPM(FILE *file){
		char tipo[3];
		char *t;
		fscanf(file, "%2s\n", tipo); // le o especificador de tipo da imagem (Magic Number)
		ignorarComentarios(file); // ignora comentarios imediatamente seguintes
		fscanf(file, "%d %d", &imagem.largura, &imagem.altura);
		fscanf(file, "%d", &imagem.valorMaximoCor);
		printf("formato: %s\n", tipo);
		printf("Largura: %d, altura: %d\n", imagem.largura, imagem.altura);
		// FAZER: preencher imagem
		return 0;
}

