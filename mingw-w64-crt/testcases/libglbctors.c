static int ctor_count = 0;
static int *dtor_count_var = (void *)0;

__attribute__((constructor))
static void
ctor (void)
{
  ctor_count++;
}

__attribute__((destructor))
static void
dtor (void)
{
  if (dtor_count_var)
    (*dtor_count_var)++;
}

__attribute__((dllexport))
int get_ctor_count(void)
{
  return ctor_count;
}

__attribute__((dllexport))
void set_dtor_count_var(int *var)
{
  dtor_count_var = var;
}
