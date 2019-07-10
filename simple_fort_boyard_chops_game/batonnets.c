#include <stdio.h>
#include <stdlib.h>

void printbar(int n)
{
  int i;
  int j;
    
  i = 4;
  printf("chops count : %d\n", n);
  while (i > 0)
    {
      j = n;
      while (j > 0)
        {
	  printf(" | ");
	  j--;
        }
      i--;
      printf("\n");
    }
}

int main(int argc, char **argv)
{
  int nb;
  int mode;
  int joueur;
  int choix;
    
  if (argc != 2)
    {
      printf("invalid arguments\n");
      return (0);
    }
  if (atoi(argv[1]) < 1)
    {
      printf("put at least 1 chop\n");
      return (0);
    }
  joueur = 1;
 choose:
  printf("choose gamemode\n0 - player versus AI\n1 - player versus player\n");
  scanf("%d", &mode);
  if (mode != 0 && mode != 1)
    {
      printf("incorrect choice\n");
      goto choose;
    }
  nb = atoi(argv[1]);
 tour:
  printbar(nb);
  printf("player %d turn\n", joueur);
  printf("choose between 1 and 3 chops\n");
  scanf("%d", &choix);
  if (choix < 1 || choix > 3)
    {
      printf("incorrect choice\n");
      goto tour;
    }
  nb = nb - choix;
  if (nb < 1)
    {
      printf("the player %d lost, RIP\n", joueur);
      return (0);
    }
  if (mode == 1)
    {
      if (joueur == 1)
	joueur = 2;
      else
	joueur = 1;
      goto tour;
    }
  if (mode == 0)
    {
      printf("AI turn\n");
      if (nb >= 20)
	choix = 3;
      else if (nb >= 18)
	choix = nb - 17;
      else if (nb == 17)
	choix = 2;
      else if (nb >= 14)
	choix = nb - 13;
      else if (nb == 13)
	choix = 1;
      else if (nb >= 10)
	choix = nb - 9;
      else if (nb == 9)
	choix = 3;
      else if (nb >= 6)
	choix = nb - 5;
      else if (nb == 5)
	choix = 2;    
      else if (nb >= 2)
	choix = nb - 1;
      else if (nb == 1)
      {
	  choix = 1;
	  nb = nb - choix;
	  printf("AI takes %d chops\n", choix);
	  printf("AI lost, RIP\n");
	  return (0);
      }
      nb = nb - choix;
      printf("AI takes %d chops\n", choix);
      goto tour;
    }
  return 0;
}
