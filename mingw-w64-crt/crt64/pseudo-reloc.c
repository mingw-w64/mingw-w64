#include <windows.h>

extern char __RUNTIME_PSEUDO_RELOC_LIST__;
extern char __RUNTIME_PSEUDO_RELOC_LIST_END__;
extern char _image_base__;

typedef struct {
  DWORD addend;
  DWORD target;
} runtime_pseudo_reloc;

static void
do_pseudo_reloc (void* start,void *end,void *base)
{
  ptrdiff_t reloc_target;
  runtime_pseudo_reloc *r;
  
  for (r = (runtime_pseudo_reloc*) start; r < (runtime_pseudo_reloc*) end; r++)
    {
      reloc_target = (ptrdiff_t) base + r->target;
      *((ptrdiff_t*) reloc_target) += r->addend;
    }
}

void
_pei386_runtime_relocator ()
{
  do_pseudo_reloc (&__RUNTIME_PSEUDO_RELOC_LIST__,&__RUNTIME_PSEUDO_RELOC_LIST_END__,&_image_base__);
}
