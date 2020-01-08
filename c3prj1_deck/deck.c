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
    print_card(*(hand->cards[i]));
  }
}

int deck_contains(deck_t * d, card_t c)
{
  for(size_t i = 0; i < d->n_cards; ++i)
  {
    if((c.value == d->cards[i]->value) && (c.suit == d->cards[i]->suit))
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
    size_t randomIndex = random()%(i);
    card_t * temp = d->cards[i];
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
      k.value = j;
      k.suit =i;
      assert(deck_contains(d,k) == 1);
    }
  }
}

void add_card_to(deck_t * deck, card_t c)
{
  card_t * card = malloc(sizeof(*card));
  card->value = c.value;
  card->suit = c.suit;
  deck->cards = realloc(deck->cards, (deck->n_cards + 1)*(sizeof(*deck->cards)));
  deck->cards[deck->n_cards] = card;
  ++deck->n_cards;
}

card_t * add_empty_card(deck_t * deck)
{
  card_t * c = malloc(sizeof(*c));
  c->value = 0;
  c->suit = 0;
  add_card_to(deck, *c);
  return deck->cards[deck->n_cards - 1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards)
{
  deck_t * d = malloc(sizeof(*d));
  d->cards = NULL;
  d->n_cards = 0;
  d->cards = malloc(excluded_cards->n_cards * sizeof(*d->cards));
  for(size_t i = 0; i < 52; ++i)
  {
    card_t c = card_from_num(i);
    if(!deck_contains(excluded_cards, c)) add_card_to(d, c);
  }
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands)
{
  deck_t * excluded_cards = malloc(sizeof(*excluded_cards));
  excluded_cards->n_cards = 0;
  excluded_cards->cards = NULL;
  for(size_t i = 0; i < n_hands; ++i)
  {
    for(size_t j = 0; j < hands[i]->n_cards; ++j)
    {
      if(!deck_contains(excluded_cards, *hands[i]->cards[j])) add_card_to(excluded_cards, *hands[i]->cards[j]);
    }
  }
  deck_t * out = make_deck_exclude(excluded_cards);
  return out;
}

void free_deck(deck_t * deck)
{
  for(size_t i = 0; i < deck->n_cards; ++i)
  {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}