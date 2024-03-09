#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int croupier();
int player();
void winnings();

int bet,total = 0;
float multiplyer;



int main() {
  char response = ' ';
  int player_score = 0;
  int croupier_score = 0;
  printf("How much do you want to bet\n: ");
  scanf("%d",&bet);
  printf("How much multiplyer to your bet\n: ");
  scanf("%f",&multiplyer);
  do{
  player_score = 0;
  croupier_score = 0;
  player_score = player();
  croupier_score = croupier();
  winnings(player_score, croupier_score);
  printf("Do you want to play again(y-n)\n: ");
  scanf("%s",&response);
  }while(response == 'y' || response == 'Y');
}

int player() {
  char response = ' ';
  srand(time(NULL));
  int card1 = rand() % 10 + 1;
  int card2 = rand() % 10 + 1;
  printf("Player | Card 1: %d\n", card1);
  printf("Player | Card 2: %d\n", card2);
  total = card1+card2;
  if(total == 21) {
    return 21;
  } else if(total > 21) {
    return 0;
  } else {
    printf("Do you want to Hit or Stand(h/s):\n ");
    scanf(" %c", &response);
    while(response == 'h' || response == 'H'){
        int card3 = rand() % 10 + 1;
        total = total + card3;
        printf("Player | Total Card Values: %d\n", total);
        if(total > 21) {
          return 0;
        } else if(total == 21) {
          return 21;
        }
      printf("Do you want to Hit or Stand(h/s):\n ");
      scanf(" %c", &response);
      } 
    if(total > 21) {
      return 0;
    }
    return total;
  }
}

int croupier() {
  srand(time(NULL));
  int card1 = rand() % 10 + 1;
  int card2 = rand() % 10 + 1;
  printf("Croupier | Card 1: %d\n", card1);
  printf("Croupier | Card 2: %d\n", card2);
  int totalCard = card1 + card2;
  if(totalCard > 21) {
    return 0;
  } else if(totalCard == 21) {
    return 21;
  } else {
    if(total > totalCard) {
    do {
      int card3 = rand() % 10 + 1;
      totalCard = totalCard + card3;
      printf("Croupier | Total Card Values %d\n", totalCard);
      card3 = 0;
      if(totalCard > 21) {
        return 0;
      } else if(totalCard == 21) {
        return 21;
      } else {
        continue;
      }
    }while(totalCard < 21);
  }
}
  if(totalCard > 21) {
    return 0;
  }
  return totalCard;
}

void winnings(int player_score, int croupier_score) {
  if(player_score == 21 && croupier_score != 21) {
    printf("You win %f money\n", bet*multiplyer);
  } else if(player_score == 21 && croupier_score == 21) {
    printf("It's a tie you get your money back\n");
  } else if(player_score != 21 && croupier_score == 21) {
    printf("You lose %f money\n", bet*multiplyer);
  } else if(player_score > croupier_score) {
    printf("You win %f money\n", bet*multiplyer);
  } else if(player_score < croupier_score) {
    printf("You lose %f money\n", bet*multiplyer);
  } else if(player_score == 0 && croupier_score == 0) {
    printf("You and Croupier both lose you get your money back");
  }
}