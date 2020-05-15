/*
 * Copyright (C) 2020 Paul Cercueil <paul@crapouillou.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#ifndef __LIGHTREC_SLIST_H__
#define __LIGHTREC_SLIST_H__

#define container_of(ptr, type, member)	\
	((type *)((void *)(ptr) - offsetof(type, member)))

struct slist_elm {
	struct slist_elm *next;
};

static inline void slist_init(struct slist_elm *head)
{
	head->next = NULL;
}

static inline struct slist_elm * slist_first(struct slist_elm *head)
{
	return head->next;
}

static inline _Bool slist_empty(const struct slist_elm *head)
{
	return head->next == NULL;
}

static inline void slist_remove_next(struct slist_elm *elm)
{
	if (elm->next)
		elm->next = elm->next->next;
}

static inline void slist_remove(struct slist_elm *head, struct slist_elm *elm)
{
	struct slist_elm *prev;

	if (head->next == elm) {
		head->next = elm->next;
	} else {
		for (prev = head->next; prev && prev->next != elm; )
			prev = prev->next;
		if (prev)
			slist_remove_next(prev);
	}
}

static inline void slist_append(struct slist_elm *head, struct slist_elm *elm)
{
	elm->next = head->next;
	head->next = elm;
}

#endif /* __LIGHTREC_SLIST_H__ */
