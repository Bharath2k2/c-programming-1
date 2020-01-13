#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>
#include "input.h"

deck_t * hand_from_string(const char * lineptr, future_cards_t * fc)
{
    deck_t * deck = NULL;
    card_t * card = malloc(sizeof(*card));
    deck->cards = NULL;
    deck->n_cards = 0;
    char * index = NULL;
    for(size_t i = 0; i < strlen(lineptr); ++i)
    {
        if(lineptr[i] == '\n' || lineptr[i] == ' ') continue;
        if(i == '?')
        {
            ++i;
            index = malloc(strlen(lineptr) * sizeof(*index));
            strcpy(index, &lineptr[i]);
            size_t j = 0;
            while(index[j] != '\0')
            {
                if(index[j] == ' ' || index[j] == '\n')
                {
                    index[j] = '\0';
                }
                ++j;
            }
            card = add_empty_card(deck);
            assert_card_valid(*card);
            add_future_card(fc,atoi(index), card);
            i += j;
        }  else {
            *card = card_from_letters(lineptr[i], lineptr[i+1]);
            assert_card_valid(*card);
            add_card_to(deck, *card);
            ++i;
        }
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
    char * lineptr  = NULL;
    size_t n  = 0;
    deck_t ** decks = NULL;
    deck_t * deck = NULL;
    size_t count = 0;
    size_t i = 0;
    while (getline(&lineptr, &n, f) >= 0)
    {
        decks = realloc(decks, (count + 1) * sizeof(*decks));
        deck = hand_from_string(lineptr, fc);
        if(deck == NULL) continue;
        decks[count] = deck;
        ++i;
        ++count;
    }
    free(lineptr);
    return decks; 
}
