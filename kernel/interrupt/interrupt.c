// Copyright (c) 2020, Jiang Yinzuo. All rights reserved.

#include <arch/x86.h>
#include "interrupt.h"
#include "picirq.h"
#include "../device/timer8253.h"
#include "../io/text/vga.h"

#define NUM_TICKS 100

/* intr_enable - enable irq interrupt */
void intr_enable(void)
{
	sti();
}

/* intr_disable - disable irq interrupt */
void intr_disable(void)
{
	cli();
}

void trap(struct trap_frame *tf)
{
	static int count = 0;
	switch (tf->tf_trapno) {
	case IRQ_BASE_ADDR + IRQ0_TIMER:
		++ticks;
		if(ticks % NUM_TICKS == 0) {
			putchar('0' + count++ % 10);
		}
		break;
	default:
		break;
	}
}
