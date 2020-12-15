// Copyright (c) 2020, Jiang Yinzuo. All rights reserved.

#ifndef CORN_OS_LIST_H
#define CORN_OS_LIST_H

/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

#define LIST_HEAD_INIT(name)     \
	{                        \
		&(name), &(name) \
	}

#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

struct list_head {
	struct list_head *next, *prev;
};

/**
 * INIT_LIST_HEAD - Initialize a list_head structure
 * @list: list_head structure to be initialized.
 *
 * Initializes the list_head to point to itself.  If it is a list header,
 * the result is an empty list.
 */
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head *new_elem,
			      struct list_head *prev, struct list_head *next)
{
	next->prev = new_elem;
	new_elem->next = next;
	new_elem->prev = prev;
	prev->next = new_elem;
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head *new_elem, struct list_head *head)
{
	__list_add(new_elem, head, head->next);
}

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(struct list_head *new_elem,
				 struct list_head *head)
{
	__list_add(new_elem, head->prev, head);
}

#endif // CORN_OS_LIST_H
