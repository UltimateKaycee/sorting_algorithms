#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - For card suits.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - For playing
 *
 * @value: Card value
 * From "Ace" to "King"
 * @kind: Card kind
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Struct of deck of card
 *
 * @card: Pointer card
 * @prev: Pointer to previous node
 * @next: Pointer to next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
