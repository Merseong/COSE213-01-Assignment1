#include <stdio.h>
#include <stdlib.h>
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

// init and reset new polynomial and return its pointer
polyMemory* MakePoly()
{ 
	polyMemory* out = (polyMemory*)malloc(sizeof(polyMemory));
	out->start = avail;
	out->end = avail++;
	terms[out->start].coef = 0;
	terms[out->start].expon = 0;
	return out;
}

// add new term to polynomial 'out'
void AddTerm(polyMemory* out, float _coef, int _expon)
{
	if (avail >= MAX_TERMS)
	{
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[out->end].coef = _coef;
	terms[out->end++].expon = _expon;
	avail++;
	return;
}

void AddPoly(polyMemory* out, polyMemory left, polyMemory right)
{
	// TODO: out = left + right
	return;
}