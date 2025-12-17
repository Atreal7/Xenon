

ENTRY(efi_main)
OUTPUT_FORMAT("pei-x86-64")
SECTIONS
{

.text  : { *(.text*) } :text
.data  : { *(.data*) } :data
.bss   : { *(.bss COMMON) } :data
.reloc : { *(.reloc) } :data

}
PHDRS
{
    text PT_LOAD FLAGS(5); /* R-X */
    data PT_LOAD FLAGS(6); /* RW- */
}

