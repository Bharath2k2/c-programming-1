#ifndef DECK_H
#define DECK_H
#include <stdlib.h>
#include "cards.h"
#include "cards.c"

struct deck_tag {
	  card_t ** cards;
	    size_t n_cards;
}
typedef struct deck_tag deck_t;

card_t card_from_num(unsigned c);
void print_hand(deck_t * hand);
int deck_contains(deck_t * d, card_t c) ;
void shuffle(deck_t * d);
void assert_full_deck(deck_t * d) ;
#endif