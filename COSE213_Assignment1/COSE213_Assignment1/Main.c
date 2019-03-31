#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

// input은 무조건 내림차순으로 들어온다.

typedef struct _polynomial {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS]; // all terms for all polynomial
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
	/*
	polyMemory* poly1 = MakePoly();
	get poly1 data - AddTerm;

	polyMemory* poly2 = MakePoly();
	get poly2 data - AddTerm;

	polyMemory* polySum = MakePoly();
	AddPoly(polySum, *poly1, *poly2);

	print polySum;

	free all polys;
	*/
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

// out = left + right
void AddPoly(polyMemory* out, polyMemory left, polyMemory right)
{
	float _coef;
	// add left poly and right poly
	while (left.start <= left.end && right.start <= right.end)
	{
		if (terms[left.start].expon < terms[right.start].expon)
		{
			AddTerm(out, terms[right.start].coef, terms[right.start].expon);
			right.start++;
		}
		else if (terms[left.start].expon == terms[right.start].expon)
		{
			_coef = terms[left.start].coef + terms[right.start].coef;

			if (_coef) AddTerm(out, _coef, terms[left.start].expon);
			left.start++;
			right.start++;
		}
		else
		{
			AddTerm(out, terms[left.start].coef, terms[left.start].expon);
			left.start++;
		}
	}

	// add rest terms in left poly and right poly
	for (; left.start <= left.end; left.start++)
	{
		AddTerm(out, terms[left.start].coef, terms[left.start].expon);
	}
	for (; right.start <= right.end; right.start++)
	{
		AddTerm(out, terms[right.start].coef, terms[right.start].expon);
	}
	return;
}