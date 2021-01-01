#ifndef CIRCULARLY_LIST_H
#define CIRCULARLY_LIST_H

#define CLIST_INIT(list) \
	{ \
	    (list)->head = NULL; \
	}

#define CLIST_ENTRY_INIT(entry) \
	{ \
	    (entry)->prev = entry; \
	    (entry)->next = entry; \
	}

#define CLIST_HEAD(list) \
	(list)->head

#define CLIST_TAIL(list) \
	(((list)->head != NULL) ? (list)->head->prev : NULL)

#define CLIST_IS_EMPTY(list) \
	((list)->head == NULL)

#define CLIST_IS_TAIL(list, entry) \
	(((list)->head != NULL) ? ((list)->head->prev == (entry)) : 0)

#define CLIST_ADD(list, entry) \
	{ \
	    if (CLIST_IS_EMPTY(list)) { \
		(entry)->next = entry; \
		(entry)->prev = entry; \
		(list)->head = entry; \
	    } else { \
		(entry)->next = (list)->head; \
		(entry)->prev = CLIST_TAIL(list); \
		(entry)->prev->next = (entry); \
		(entry)->next->prev = (entry); \
	    } \
	}

#define CLIST_REMOVE(list, entry) \
	{ \
	    if ((list)->head == (entry)) { \
		(list)->head = ((entry)->next != (entry)) ? (entry)->next : NULL; \
	    } \
	    (entry)->prev->next = (entry)->next; \
	    (entry)->next->prev = (entry)->prev; \
	}

#define CLIST_ENTRY_NEXT(entry) \
	(entry)->next

#define CLIST_ENTRY_PREV(entry) \
	(entry)->prev

#define CLIST_HAS_NEXT(list, entry) \
	((list)->head != (entry)->next)

#endif /* CIRCULARLY_LIST_H */
