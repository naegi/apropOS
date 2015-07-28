#include <kernel/idt.h>
#include <kernel/isr.h>

#include <stdint.h> 
#include <stdbool.h> 
#include <stddef.h> 

bool idt_initialize(void)
{
    kidtr.limit = IDTSIZE * sizeof(struct idtgate) - 1;
    kidtr.size = (uint32_t)&kidt;
        
    asm("lidt (kidtr)");

    // init exceptions
    idt_set_gate(0,(uint32_t) isr0, 0x8, 0x8E);
    idt_set_gate(1,(uint32_t) isr1, 0x8, 0x8E);
    idt_set_gate(2,(uint32_t) isr2, 0x8, 0x8E);
    idt_set_gate(3,(uint32_t) isr3, 0x8, 0x8E);
    idt_set_gate(4,(uint32_t) isr4, 0x8, 0x8E);
    idt_set_gate(5,(uint32_t) isr5, 0x8, 0x8E);
    idt_set_gate(6,(uint32_t) isr6, 0x8, 0x8E);
    idt_set_gate(7,(uint32_t) isr7, 0x8, 0x8E);
    idt_set_gate(8,(uint32_t) isr8, 0x8, 0x8E);
    idt_set_gate(9,(uint32_t) isr9, 0x8, 0x8E);
    idt_set_gate(10,(uint32_t) isr10, 0x8, 0x8E);
    idt_set_gate(11,(uint32_t) isr11, 0x8, 0x8E);
    idt_set_gate(12,(uint32_t) isr12, 0x8, 0x8E);
    idt_set_gate(13,(uint32_t) isr13, 0x8, 0x8E);
    idt_set_gate(14,(uint32_t) isr14, 0x8, 0x8E);
    idt_set_gate(15,(uint32_t) isr15, 0x8, 0x8E);
    idt_set_gate(16,(uint32_t) isr16, 0x8, 0x8E);
    idt_set_gate(17,(uint32_t) isr17, 0x8, 0x8E);
    idt_set_gate(18,(uint32_t) isr18, 0x8, 0x8E);
    idt_set_gate(19,(uint32_t) isr19, 0x8, 0x8E);
    idt_set_gate(20,(uint32_t) isr20, 0x8, 0x8E);
    idt_set_gate(21,(uint32_t) isr21, 0x8, 0x8E);
    idt_set_gate(22,(uint32_t) isr22, 0x8, 0x8E);
    idt_set_gate(23,(uint32_t) isr23, 0x8, 0x8E);
    idt_set_gate(24,(uint32_t) isr24, 0x8, 0x8E);
    idt_set_gate(25,(uint32_t) isr25, 0x8, 0x8E);
    idt_set_gate(26,(uint32_t) isr26, 0x8, 0x8E);
    idt_set_gate(27,(uint32_t) isr27, 0x8, 0x8E);
    idt_set_gate(28,(uint32_t) isr28, 0x8, 0x8E);
    idt_set_gate(29,(uint32_t) isr29, 0x8, 0x8E);
    idt_set_gate(30,(uint32_t) isr30, 0x8, 0x8E);
    idt_set_gate(31,(uint32_t) isr31, 0x8, 0x8E);

    return true;
}

void idt_set_gate(uint8_t num,uint32_t offset,
        uint16_t selector, uint8_t type_attr)
{
    kidt[num].offset0_15 = (offset & 0xFFFF);
    kidt[num].selector = selector;
    kidt[num].zero = 0;
    kidt[num].type_attr = type_attr;
    kidt[num].offset16_31 = (offset & 0xFFFF0000) >> 16;
    return;
}
