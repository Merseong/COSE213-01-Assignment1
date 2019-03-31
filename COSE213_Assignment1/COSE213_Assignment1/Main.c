/// The output is also displayed in normal descending order 
/// only when the input is in descending order.
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct _polynomial {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS]; // all terms for all polynomial
int avail = 0;

typedef struct _polyMemory {
	int start;
	int end;
	int count;
} polyMemory;

polyMemory* _MakePoly();
void AddTerm(polyMemory* out, float _coef, int _expon);
void AddPoly(polyMemory* out, polyMemory left, polyMemory right);

int main()
{
	polyMemory* poly1 = _MakePoly();
	//get poly1 data;
	printf("첫번째 다항식을 입력하세요.\n");
	while (1)
	{
		float front;
		int back;
		scanf("%f %d", &front, &back);
		AddTerm(poly1, front, back);
		if (getchar() == '\n') break;
	}

	polyMemory* poly2 = _MakePoly();
	//get poly2 data;
	printf("두번째 다항식을 입력하세요.\n");
	while (1)
	{
		float front;
		int back;
		scanf("%f %d", &front, &back);
		AddTerm(poly2, front, back);
		if (getchar() == '\n') break;
	}

	polyMemory* polySum = _MakePoly();
	AddPoly(polySum, *poly1, *poly2);

	//print polySum;
	for (int i = polySum->start; i <= polySum->end; i++)
	{
		if (i != polySum->start) printf(" + ");
		if (terms[i].coef != 0 && terms[i].expon != 0) printf("%0.3fx^%d", terms[i].coef, terms[i].expon);
		else if (terms[i].expon == 0) printf("%0.3f", terms[i].coef);
	}

	//free all polys;
	free(polySum);
	free(poly1);
	free(poly2);

	getchar();
	return 0;
}

// init and reset new polynomial and return its pointer
polyMemory* _MakePoly()
{ 
	polyMemory* out = (polyMemory*)malloc(sizeof(polyMemory));
	out->start = avail;
	out->end = avail++;
	out->count = 0;
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
	if (out->count != 0)
	{
		out->end++;
		avail++;
	}

	terms[out->end].coef = _coef;
	terms[out->end].expon = _expon;
	out->count++;
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