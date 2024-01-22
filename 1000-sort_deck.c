#include "deck.h"

#include <stdio.h>
void sort_suit(deck_node_t **deck);
void sort_val(deck_node_t **deck);
void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2);
int vcmp(const card_t *card1, const card_t *card2);
/**
 * sort_deck - Arranges a 52-card deck in a specific order.
 * @deck: Pointer to the deck to be sorted.
 *
 * Return: Always 0 (indicating success).
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_suit(deck);
	sort_val(deck);
}

/**
 * sort_suit - Organizes a 52-card deck by suit.
 * @deck: Pointer to the deck to be sorted.
 */

void sort_suit(deck_node_t **deck)
{
	deck_node_t *forw, *tmp;

	for (forw = (*deck)->next; forw && forw->prev; forw = forw->next)
	{
		for (; forw && forw->prev && forw->card->kind <
			     forw->prev->card->kind; forw = forw->prev)
		{
			tmp = forw->prev;
			swap(deck, tmp, forw);
			forw = forw->next;
		}
	}
}

/**
 * sort_val - Arranges a 52-card deck statically by card value.
 * @deck: Pointer to the deck to be sorted.
 */

void sort_val(deck_node_t **deck)
{
	deck_node_t *f, *tmp;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && vcmp(f->card, f->prev->card) &&
			     f->card->kind == f->prev->card->kind;
		     f = f->prev)
		{
			tmp = f->prev;
			swap(deck, tmp, f);
			f = f->next;
		}
	}
}
/**
 * swap - swaps the positions of two consecutive cards in a doubly linked list.
 * Used in the insertion algorithm.
 * @deck: Pointer to the head node of the deck.
 * @card1: Pointer to the first card to be swapped.
 * @card2: Pointer to the second card to be swapped.
 */

void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2)
{
	deck_node_t *prev, *next;

	prev = card1->prev;
	next = card2->next;

	if (prev != NULL)
		prev->next = card2;
	else
		*deck = card2;
	card1->prev = card2;
	card1->next = next;
	card2->prev = prev;
	card2->next = card1;
	if (next)
		next->prev = card1;
}

/**
 * vcmp - Compares the values of two cards.
 * @card1: Pointer to the first card to compare.
 * @card2: Pointer to the second card to compare.
 *
 * Return: 1 if the value of card1 is less than that of card2, else 0
 */

int vcmp(const card_t *card1, const card_t *card2)
{
	char char1 = card1->value[0], char2 = card2->value[0];
	const char *ord[14] = {"Ac", "1", "2", "3", "4", "5", "6",
			       "7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int idx1 = 0, idx2 = 0, i;

	if ((char1 >= 48 && char1 <= 57) && (char2 >= 49 &&
					     char2 <= 57))
	{
		if (card1->value[1] == '0')
			char1 = 58;
		if (card2->value[1] == '0')
			char2 = 58;
		return (char1 < char2);
	}
	else
	{
		for (i = 0; i < 14; i++)
		{
			if (card1->value[0] == ord[i][0] &&
			    card1->value[1] == ord[i][1])
				idx1 = i;
			if (card2->value[0] == ord[i][0] &&
			    card2->value[1] == ord[i][1])
				idx2 = i;
		}
		return (idx1 < idx2);
	}
}
