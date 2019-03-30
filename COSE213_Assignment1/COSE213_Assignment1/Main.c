#include <stdio.h>
#include <stdlib.h>

typedef struct _term {
	float coeff; // 항의 계수
	int expon; // 항의 차수
	struct _term * next;
} term;

typedef struct _polynomial {
	term* start;
	term* head;
	int length;
} polynomial;

polynomial* MakePoly();
void PolyAdd(polynomial* out, float _coeff, int _expon);
void PolyCombine(polynomial* out, polynomial* _in1, polynomial* _in2);

int main()
{
	polynomial* poly1 = MakePoly();
	polynomial* poly2 = MakePoly();

	printf("첫번째 다항식을 입력해주세요.\n");
	// get first polynomial, first one is coeffecient, second is exponential
	while (1)
	{
		float front;
		int back;
		scanf("%f %d", &front, &back);
		PolyAdd(poly1, front, back);
		if (getchar() == '\n') break;
	}

	printf("두번째 다항식을 입력해주세요.\n");
	// get second polynomial
	while (1)
	{
		float front;
		int back;
		scanf("%f %d", &front, &back);
		PolyAdd(poly2, front, back);
		if (getchar() == '\n') break;
	}

	polynomial* outPoly = MakePoly();

	PolyCombine(outPoly, poly1, poly2);

	for (term* pTerm = outPoly->start; pTerm != NULL; pTerm = pTerm->next)
	{
		if (pTerm->coeff != 0)
		{
			if (pTerm != outPoly->start) printf("+");

			if (pTerm->expon != 0) printf(" %0.3fx^%d ", pTerm->coeff, pTerm->expon);
			else printf(" %0.3f", pTerm->coeff);
		}
	}

	getchar();
	return 0;
}

polynomial* MakePoly()
{
	polynomial* out = (polynomial*)malloc(sizeof(polynomial));

	out->start = NULL;
	out->head = NULL;
	out->length = 0;

	return out;
}

void PolyAdd(polynomial* out, float _coeff, int _expon)
{
	term* newTerm = (term*)malloc(sizeof(term));

	newTerm->coeff = _coeff;
	newTerm->expon = _expon;
	newTerm->next = NULL;

	if (out->start == NULL)
	{ // if there are no term, add first term
		out->head = newTerm;
		out->start = newTerm;
		out->length++;
		return;
	}
	else
	{ // find where to put in this term (big number to small number)
		term* beforePlace = NULL;
		term* nextPlace = out->start;

		for (int i = 0; i < out->length; i++)
		{
			if ((nextPlace->expon < _expon))
			{
				newTerm->next = nextPlace;
				break;
			}
			else if (nextPlace->expon == _expon)
			{ // if already have same exponential, add to it
				nextPlace->coeff += _coeff;
				free(newTerm);
				return;
			}
			else
			{
				beforePlace = nextPlace;
				nextPlace = nextPlace->next;
			}
		}
		if (beforePlace != NULL) beforePlace->next = newTerm; // if this is not a start of list
		else out->start = newTerm;

		if (newTerm->next == NULL) out->head = newTerm; // if this is end of list
	}
	out->length++;
	return;
}

void PolyCombine(polynomial* out, polynomial* _in1, polynomial* _in2)
{
	for (term* term1 = _in1->start; term1 != NULL; term1 = term1->next)
	{
		PolyAdd(out, term1->coeff, term1->expon);
	}

	for (term* term2 = _in2->start; term2 != NULL; term2 = term2->next)
	{
		PolyAdd(out, term2->coeff, term2->expon);
	}

	return;
}
