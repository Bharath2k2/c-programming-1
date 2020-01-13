#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>
#include "input.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc)
{
    deck_t* deck=malloc(sizeof(*deck));
    deck->cards = NULL;
    deck->n_cards=0;
    for(int i=0;i<strlen(str);i++){
        if((str[i] == '\n')||(str[i] == ' '))continue;
        else{
        if(str[i] == '?'){
            i++;
            char num[strlen(str)];
            int n=0;
            while(!((str[i] == '\n')||(str[i] == ' '))) {
            num[n]=str[i];
            i++;n++;}
            num[n]='\0';
            add_future_card(fc,atoi(num),add_empty_card(deck)) ;

        }
        else{
            card_t x = card_from_letters(str[i],str[i+1]);
            add_card_to(deck,x);
            i++;}
        }
    }
    if (deck->n_cards < 5 ){
        return NULL;
        fprintf(stderr,"asas");}
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
