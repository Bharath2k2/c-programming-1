#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void assert_card_valid(card_t c);

void print_hand(deck_t * hand)
{
  size_t sizeOfArray = hand->n_cards;
  for(size_t i = 0; i < sizeOfArray; ++i)
  {
    printf(" hello ");
    print_card(*(hand->cards[i]));
    printf(" hello again \n");
  }
}

int deck_contains(deck_t * d, card_t c) 
{
  for(size_t i = 0; i < d->n_cards; ++i)
  {
    if(c.value == d->cards[i]->value && c.suit == d->cards[i]->suit)
    {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d)
{
  size_t sizeOfArray = d->n_cards;
  //Use of the Fisher-Yates algorithm
  for(size_t i = sizeOfArray-1; i > 0 ; --i)
  {
    size_t randomIndex = random()%(i+1);
    card_t *temp = d->cards[i];
    d->cards[i] = d->cards[randomIndex];
    d->cards[randomIndex] = temp;
  }
}

void assert_full_deck(deck_t * d) 
{
  card_t k;
  for(int i = SPADES; i < NUM_SUITS; ++i)
  {
    for(int j= 2; j <= VALUE_ACE; ++j)
    {
      k.value = i,k.suit =j;
      assert(deck_contains(d,k) == 1);
    }
  }
}
