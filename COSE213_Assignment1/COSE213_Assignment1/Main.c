#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float coeff; // 항의 계수
	int expon; // 항의 차수
	term* next;
} term;

typedef struct {
	term* start;
	term* head;
	int length;
} polynomial;

polynomial* MakePoly();
void PolyAdd(polynomial* out, float _coeff, int _expon);
void PolyCombine(polynomial* out, polynomial* _in1, polynomial* _in2);

int main()
{
	printf("hello world!");
	/*
	polynomial* poly1 = MakePoly();
	polynomial* poly2 = MakePoly();

	한줄의 입력을 쭉 받는다. 두개씩 분리해서 앞의 수는 계수, 뒤의 수는 차수

	while (입력이 남아있는 동안)
	{
		PolyAdd(poly1, front, back);
	}

	두번째 줄의 입력을 받는다.

	while (입력이 남아있는 동안)
	{
		PolyAdd(poly2, front, back);
	}

	polynomial* outPoly = MakePoly();

	PolyCombine(polysum, poly1, poly2);
	printf(polysum);
	*/
	return 0;
}

polynomial* MakePoly()
{
	polynomial* out = malloc(sizeof(polynomial));

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

	if (out->head == NULL)
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
			if ((nextPlace->expon > _expon))
			{
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
		if (out->start == nextPlace) out->start = newTerm;
		if (newTerm->next == NULL) out->head = newTerm;

		beforePlace->next = newTerm;
		newTerm->next = nextPlace;
	}
	out->length++;
	return;
}