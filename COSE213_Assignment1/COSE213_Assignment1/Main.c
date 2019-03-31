#include <stdio.h>
#define MAX_TERMS 100

// input은 무조건 내림차순으로 들어온다.

typedef struct _polynomial {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;

typedef struct _polyMemory {
	int start;
	int end;
} polyMemory;

polyMemory* MakePoly();
void AddTerm(polyMemory* out, float _coef, int _expon);
void AddPoly(polyMemory* out, polyMemory left, polyMemory right);

int main()
{
	printf("hello world!");
	return 0; 
}

polyMemory* MakePoly()
{
	// TODO: init and reset polyMemory and return its pointer
	return NULL;
}

void AddTerm(polyMemory* out, float _coef, int _expon)
{
	// TODO: add new term to polynomial 'out'
	return;
}

void AddPoly(polyMemory* out, polyMemory left, polyMemory right)
{
	// TODO: out = left + right
	return;
}