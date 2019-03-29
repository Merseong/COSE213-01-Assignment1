#include <stdio.h>

typedef struct {
	float coeff; // 항의 계수
	int expon; // 항의 차수
	term* next;
} term, *term;

term* MakePoly();
int PolyAdd(term* out, float _coeff, int _expon);
int PolyCombine(term* out, term* _in1, term* _in2);

int main()
{
	printf("hello world!");
	/*
	term* poly1 = MakePoly();
	term* poly2 = MakePoly();

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

	PolyCombine(polysum, poly1, poly2);
	printf(polysum);
	*/
	return 0;
}
