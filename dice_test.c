#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "dice.h"
#include "types.h"

int main (int argc , char *argv[]){
  Dice *dice;
  dice = dice_create(1);
  Id id_dice;
  int ultima_tirada;

  if (dice == NULL){
    return 0;
  }
  if ((id_dice = dice_get_id(dice)) != NO_ID){
    fprintf(stdout,"%d",(int)id_dice);
  }
  else {
    dice_destroy(dice);
    return 1;
  }

  if (dice_roll(dice)==ERROR){
    dice_destroy(dice);
    return 2;
  }

  if ((ultima_tirada=dice_get_last_shot(dice))!=0){
    fprintf(stdout,"Ultima tirada: %d",ultima_tirada);
  }
  else {
    dice_destroy(dice);
    return 3;
  }

  fprintf(stdout,"Ultima prueba: ");

  if (dice_print(dice) == ERROR){
    dice_destroy(dice);
    return 4;
  }
  return 0;
}
