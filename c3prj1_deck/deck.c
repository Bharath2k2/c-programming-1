#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void assert_card_valid(card_t c);

void print_hand(deck_t * hand)
{
  size_t sizeOfArray = (hand->n_cards)-1;
  for(size_t i = 0; i < sizeOfArray; ++i)
  {
    print_card(*(hand->cards[i]));
    printf(" ");
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
  size_t sizOfArray = (d->n_cards)-1;
  //Use of the Fisher-Yates algorithm
  for(size_t i = sizOfArray; i > 0 ; --i)
  {
    size_t randomIndex = random()%i;
    card_t *temp = d->cards[i];
    d->cards[i] = d->cards[randomIndex];
    d->cards[randomIndex] = temp;
  }
}

void assert_full_deck(deck_t * d) 
{
  size_t numberOfComparisons = d->n_cards;
  for(size_t i = 0; i < (numberOfComparisons-1); ++i)
  {
    if(i != numberOfComparisons-2){
      assert_card_valid(*(d->cards[i]));
    } else {
      assert_card_valid(*(d->cards[i+1]));
    }
    for(size_t j = i + 1; j < numberOfComparisons; ++j)
    {
      assert((d->cards[i]->value != d->cards[j]->value) && (d->cards[i]->suit != d->cards[j]->suit));
    }
  }
}
