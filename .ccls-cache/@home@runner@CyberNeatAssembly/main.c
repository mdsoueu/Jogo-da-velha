#include <stdio.h>

int main(void) {
 /*Faça um programa para jogar o jogo da velha. Ao final imprima o resultado do jogo e pergunte se deseja jogar novamente.
Uma lista dos possíveis passos a serem seguidos pode ser:*/

// 1 - qual estrutura de dados será utilizadas?
  char jogo[3][3];
  
// 2 - como inicializar nossa estrutura de dados?
  for(int l=0; l<3; l++){ // l --> linha
    for(int c=0; c<3; c++){ // c --> coluna
      jogo[l][c]= ' ';
    }
  }
  
// 3 - imprimir jogo (tabuleiro)
  printf("\n");
  printf("\t 0   1   2 \n"); /*Imprimi os índices emcima do jogo, para facilitar a localização do espaço para jogar.*/
  for(int l=0; l<3; l++){
    for(int c=0; c<3; c++){
      if(c==0)
        printf("\t"); // \t --> serve para tabular
        printf(" %c ", jogo[l][c]);
      if(c<2) /*Vou colocar a barra '|', se o nosso índice de coluna for menor que 2*/
        printf("|");  /*(coluna 0, coloco uma barra; coluna 1, coloco uma barra; coluna 2, não coloco uma barra)*/
      if(c==2)
        printf(" %d",l); /*Quero imprimir os índices de linha, para facilitar a visualização.*/
    }
    if(l<2) /*As linhas horizontais eu vou colocar, se linha for menor que 2.*/
      printf("\n\t----------"); /*(linha 0, coloco uma linha; linha 1, coloco uma linha; linha2, não preciso colocar)*/
      printf("\n");
  }
  
// 4 - ler coordenadas
  /*As coordenadas que o jogador quer jogar são os índices de linha e coluna.*/
  int linha, coluna;
  do{ //Validação da entrada de dados
    printf("\nDigite linha: ");
    scanf("%d", &linha);
    printf("Digite coluna: ");
    scanf("%d", &coluna);
  } while(linha<0 || linha>2 || coluna<0 || coluna>2 || jogo[linha][coluna]!=' ');
  
// 5 - salvar coordenadas
  int jogador=1;
  if( jogador==1){
    jogo[linha][coluna] = 'O';
    jogador++;
  }
  else{
    jogo[linha][coluna] = 'X';
    jogador=1; /*A próxima jogada vai ser do jogador 1, por isso retorna*/
  }
  
// 6 - alguém ganhou por linhas?
  if (jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||  //linha 0, coluna 0 / coluna 1 / coluna 2
      jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||  //linha 1, coluna 0 / coluna 1 / coluna 2
      jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O' )   //linha 2, coluna 0 / coluna 1 / coluna 2
    printf("\nParabéns! Jogador 1 ganhou o jogo!\n");

  if (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
      jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
      jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X' )
    printf("\nParabéns! Jogador 2 ganhou o jogo!\n");
  
// 7 - alguém ganhou por coluna?
  if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||  //linha 0, coluna 0 / linha 1, coluna 0 / linha 2, coluna 0
      jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||  //linha 0, coluna 1 / linha 1, coluna 1 / linha 2, coluna 1
      )   
// 8 - alguém ganhou por diagonal rincipal?
// 9 - alguémm ganhou na diagonal secundária?
// 10 - repetir os passos a partir de 3 até alguém ganhar ou atingir 9 jogadas.
}