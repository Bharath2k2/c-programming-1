#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>
#include "input.h"

deck_t * hand_from_string(const char * lineptr, future_cards_t * fc)
{
    deck_t * deck = malloc(sizeof(*deck));
    deck->cards = NULL;
    deck->n_cards = 0;
    size_t length = strlen(lineptr);
    char * index = malloc(length * sizeof(char));
    for(size_t i = 0; i < length; ++i)
    {
        if(lineptr[i] == '\n' || lineptr[i] == ' ') continue;
        if(lineptr[i] == '?')
        {
            ++i;
            size_t j = 0;
            while(lineptr[i] != '\n' && lineptr[i] != ' ')
            {
                index[j] = lineptr[i];
                ++j; 
                ++i;
            }
            index[j] = '\0';
            add_future_card(fc,atoi(index), add_empty_card(deck));
        }  else {
            card_t c = card_from_letters(lineptr[i], lineptr[i+1]);
            add_card_to(deck, c);
            ++i;
        }
    }
    free(index);
    if(deck->n_cards < 5){
        perror("not enough cards in the hand");
        return NULL;
    }
    return deck;
}


deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc)
{
    char * lineptr  = NULL;
    size_t n  = 0;
    deck_t ** decks = NULL;
    size_t count = 0;
    while (getline(&lineptr, &n, f) >= 0)
    {
        decks = realloc(decks, (count + 1) * sizeof(*decks));
        deck_t * deck = hand_from_string(lineptr, fc);
        if(deck == NULL) continue;
        decks[count] = deck;
        ++count;
    }
    free(lineptr);
    return decks;
}
