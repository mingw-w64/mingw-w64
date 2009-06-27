#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef double	vec_t;
typedef vec_t	vec3_t[3];
#undef true
#undef false
#if defined(__cplusplus)
typedef int	qboolean;
#else
typedef enum {
	false = 0,
	true  = 1
} qboolean;
#endif
typedef struct
{
	qboolean	original;       // don't free, it's part of the portal
	qboolean	fixedsize;      // allocated to 16;
	int	numpoints;
	vec3_t	points[8];              // variable sized
} winding_t;

#define MAX_POINTS_ON_WINDING	64
#define MAX_FREE_WINDINGS	(10000)
#define MAX_FAST_ALLOC_WINDINGS	(16)

int GilMode = 1;

static winding_t *OldNewWinding (int points)
{
	winding_t	*w;
	size_t			size;

//	if (points > MAX_POINTS_ON_WINDING)
//		Error ("%s: %i points", __thisfunc__, points);

	size = (size_t)((winding_t *)0)->points[points];
	w = (winding_t *) malloc (size);
//	memset (w, 0, size);
	w->fixedsize = 0;
	w->original = 0;
	w->numpoints = 0;

	return w;
}

static void OldFreeWinding (winding_t *w)
{
	if (!w->original)
		free (w);
}

static __thread int nFreeWindings = 0;
static __thread winding_t *FreeWindings[MAX_FREE_WINDINGS];

winding_t *NewWinding (int points)
{
	winding_t	*ret;

	if (points > MAX_FAST_ALLOC_WINDINGS || !GilMode)
	{
		ret = OldNewWinding(points);
		ret->fixedsize = 0;
	}
	else if (nFreeWindings)
		ret = FreeWindings[--nFreeWindings];
	else
	{
		ret = OldNewWinding(MAX_FAST_ALLOC_WINDINGS);
		ret->fixedsize = 1;
	}
	ret->original = 0;
	ret->numpoints = 0;
	return ret;
}

void FreeWinding (winding_t *w)
{
	if (!w->original)
	{
		if (nFreeWindings >= MAX_FREE_WINDINGS || !w->fixedsize)
			OldFreeWinding(w);
		else
			FreeWindings[nFreeWindings++] = w;
	}
}

int main ()
{
	int i;
	winding_t	*ww;
	puts("Alloc for 2 points..");
	ww = NewWinding(2);
	puts("   .. done.");
	puts("Exiting....");
	exit (0);
}

