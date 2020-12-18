// Copyright (c) 2020, Jiang Yinzuo. All rights reserved.

#ifndef CORNOS_KERNEL_MM_PMM_H
#define CORNOS_KERNEL_MM_PMM_H

#include "layout.h"

#define MEMMAP_ADDR 0x8000 // add KERN_BASE when enabling paging

#ifndef __ASSEMBLER__

#include <corn_os/list.h>

/* Flags describing the status of a page frame */
#define PG_reserved 0 // the page descriptor is reserved for kernel or unusable
#define PG_property 1 // the member 'property' is valid

struct Page {
	int ref_cnt; // page frame's reference counter
	uint32_t flags; // array of flags that describe the status of the page frame
	unsigned int
		property; // the num of free block, used in first fit pm manager
	struct list_head page_link; // free list link
};

/* free_area_t - maintains a doubly linked list to record free (unused) pages */
typedef struct {
	struct list_head free_list; // the list header
	unsigned int nr_free; // # of free pages in this free list
} free_area_t;

void pmm_init(void);

#endif

#endif // CORNOS_KERNEL_MM_PMM_H
