#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr)
{
   if(fc->n_decks <= index)
   {
      for(; fc->n_decks <= index; ++fc->n_decks)
      {
         fc->decks = realloc(f->decks, (fc->n_decks+1) * sizeof(*fc->decks));
         fc->decks[fc->n_decks].cards = NULL;
         fc->decks[fc->n_decks].n_cards = 0;
         ++fc->n_decks;
      }
      fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards + 1) * sizeof(fc->decks[index].cards));
      fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
      ++fc->decks[index].n_cards;
   } else {
      fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards) * sizeof(fc->decks[index].cards));
      fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
      ++fc->decks[index].n_cards;
   }
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc)
{
   if(deck->n_cards < fc->n_decks)
   {
      perror("Invalid number of cards");
      return;
   }
   for(size_t i = 0; i < fc->n_decks; ++i)
   {
      for(size_t j = 0; j < deck->n_cards; ++j)
      {
         fc->decks[i].cards[j]->value = deck->cards[i]->value;
         fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
      }
   }

}