#ifndef BIDIRECTIONAL_LIST_H
#define BIDIRECTIONAL_LIST_H
/**
 * @file Bidirectional Linked-List macro implimentation.
 */

#include <stddef.h>

#define BLIST_INIT(list) \
	{ \
	    (list)->head = NULL; \
	    (list)->tail = NULL; \
	}

#define BLIST_ENTRY_INIT(entry) \
	{ \
	    (entry)->prev = NULL; \
	    (entry)->next = NULL; \
	}


#define BLIST_HEAD(list) \
	(list)->head

#define BLIST_TAIL(list) \
	(list)->tail

#define BLIST_IS_EMPTY(list) \
	((list)->head == NULL)

#define BLIST_IS_TAIL(list, entry) \
	((entry)->next == NULL)

#define BLIST_ADD(list, entry) \
	{ \
	    if (BLIST_IS_EMPTY(list)) { \
		(list)->head = entry; \
		(list)->tail = entry; \
		(entry)->prev = NULL; \
		(entry)->next = NULL; \
	    } else { \
		(list)->tail->next = entry; \
		(entry)->prev = (list)->tail; \
		(list)->tail = entry; \
		(entry)->next = NULL; \
	    } \
	}

#define BLIST_REMOVE(list, entry) \
	{ \
	    if ((entry)->prev == NULL) { \
		(list)->head = (entry)->next; \
	    } \
	    if ((entry)->next == NULL) { \
		(list)->tail = (entry)->prev; \
	    } \
	    if ((entry)->prev != NULL) { \
		(entry)->prev->next = (entry)->next; \
	    } \
	    if ((entry)->next != NULL) { \
		(entry)->next->prev = (entry)->prev; \
	    } \
	    (entry)->prev = NULL; \
	    (entry)->next = NULL; \
	}

#define BLIST_ENTRY_NEXT(entry) \
	(entry)->next

#define BLIST_ENTRY_PREV(entry) \
	(entry)->prev

#define BLIST_ENTRY_HAS_NEXT(entry) \
	((entry)->next != NULL)

#define BLIST_ENTRY_IS_VALID(entry) \
	((entry) != NULL)

#endif /* BIDIRECTIONAL_LIST_H */
