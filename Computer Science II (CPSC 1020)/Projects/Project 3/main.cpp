#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {

  // 1. Create a deck of cards and shuffle it.
  Deck deckOfCards;

  deckOfCards.shuffle();
  // Asks the user how many cards should be drawn and makes 
  // sure that it is a proper input
  int numRounds = 0;
  bool amountOfCards = false;
  cout << "How many cards should be drawn from the deck? ";
  cin >> numRounds;

  while(!amountOfCards)
  {
    if(numRounds <= 0 || numRounds > 10){
      cout << "Please select a number of cards that works with only 20 cards! ";
      cin >> numRounds;
      amountOfCards = false;
    }
    else{
      amountOfCards = true;
    }
  }
  
  




  cout << endl;

  Player player(deckOfCards, numRounds);

  Player computer(deckOfCards, numRounds);

  Card compCard;
  Card playerCard;
  int whichCard;
  bool cardInHand = false;
  bool yayComp = false;
  bool yayPlayer = false;

  player.score = 0;
  computer.score = 0;

  // 3. Play five rounds. In each round:
  //    - Have computer deal a card from their hand.
  //    - Show human their hand of cards so that they can make a selection.
  //    - Have human deal their card. 
  //    - Determine who won the round and update points accordingly.
  //    - Print results for current round.
  // 4. Print final game results.  
  for(int i = 0; i < numRounds; i++){
    cout << "Round " << i + 1 << endl;
    cout << "-------" << endl;

    compCard = computer.hand.dealCard(1);

    cout << "The computer plays: " << compCard.printCard() << endl;
    cout << "Your hand: " << player.hand.printHand() << endl;

    cout << "Which card do you want to play? ";
    cin >> whichCard;

    while(!cardInHand){
      if(whichCard - 1 > player.hand.getHandSize()){
        cout << "Please pick a card in your hand";
        cin >> whichCard;
        cardInHand = false;
      }
      else{
        cardInHand = true;
      }
    }
    

    playerCard = player.hand.dealCard(whichCard);
    cout << "You played: " << playerCard.printCard() << endl;

    if(compCard.getValue() == playerCard.getValue()){
      yayComp = false;
      yayPlayer = false;
    }
    else if(compCard.getValue() > playerCard.getValue()){
      yayComp = true;
      yayPlayer = false;
    }
    else if(playerCard.getValue() > compCard.getValue()){
      yayComp = false;
      yayPlayer = true;
    }

    if(!yayComp && !yayPlayer){
      cout << "Tie!" << endl;
    }
    else if(yayComp && !yayPlayer){
      cout << "The computer wins this round!" << endl;
      computer.score += compCard.getValue() + playerCard.getValue();
    }
    else if(!yayComp && yayPlayer){
      cout << "You win this round!" << endl;
      player.score += playerCard.getValue() + compCard.getValue();
    }

    cout << endl;

    cout << "Current scores: " << endl;
    cout << "Human: " << player.score << endl;
    cout << "Computer: " << computer.score << endl;
  }

  cout << endl;
  cout << "FINAL SCORE:" << endl;
  cout << "Human: " << player.score << endl;
  cout << "Computer: " << computer.score << endl;

  if (player.score > computer.score)
  {
    cout << "You won!";
  }
  else if(player.score < computer.score){
    cout << "You lost!";
  }
  else if(player.score == computer.score){
    cout << "Tie!";
  }
  
  return 0;
}
