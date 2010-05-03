
struct s1 { int x; };
struct s2 { int x; };

struct s1 *f(struct s1 *(*g)(void)) { return (*g)(); }

struct s2 *h(void) { return 0; }

int main(void) { f((struct s1 *(*)(void))h); return 0; }
