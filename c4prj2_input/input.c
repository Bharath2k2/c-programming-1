#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>
#include "input.h"

deck_t * hand_from_string(const char * lineptr, future_cards_t * fc)
{
    deck_t * deck = malloc(sizeof(*deck));
    card_t * card = malloc(sizeof(*card));
    deck->cards = NULL;
    deck->n_cards = 0;
    char * index = NULL;
    for(size_t i = 0; i < strlen(lineptr); ++i)
    {
        if(lineptr[i] == '\n' || lineptr[i] == '\0' || lineptr[i] == ' ') continue;
        if(i == '?')
        {
            ++i;
            index = malloc(strlen(lineptr)sizeof(*index));
            strcpy(index, &lineptr[i]);
            size_t j = 0;
            while(index[j] != '\0')
            {
                if(index[j] == ' ' || index[j] == '\n')
                {
                    index[j] = '\0';
                }
            }
            card = add_empty_card(deck);
            assert_card_valid(*card);
            add_future_card(fc,(size_t)atoi(index), add_empty_card(deck));
            ++i;
        }
        if(lineptr[i+1] == '\n' || lineptr[i+1] == '\0' || lineptr[i+1] == ' ' || lineptr[i+1] == EOF)
        {
            perror("invalid card value, please provide valid card");
            return NULL;
        }
        card = card_from_letters(lineptr[i], lineptr[i+1]);
        assert_card_valid(*card);
        add_card_to(deck, card);
    }
    free(card);
    free(index);
    if(deck->n_cards < 5){
        perror("not enough cards in the hand");
        return NULL;
    }
    return deck;
}


deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc)
{
    const char * lineptr  = NULL;
    size_t n  = 0;
    deck_t ** decks = NULL;
    if(*n_hands != 0) *n_hands = 0; 
    size_t i = 0;
    while (getline(&lineptr, &n, f) >= 0)
    {
        decks = realloc(decks, ((*n_hands) + 1) * sizeof(*decks));
        decks[i] = hand_from_string(lineptr, fc);
        ++i;
        ++(*n_hands);
    }
    free(lineptr);
    return decks; 
}
