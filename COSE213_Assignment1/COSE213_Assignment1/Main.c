#include <stdio.h>

typedef struct {
	float coeff; // ���� ���
	int expon; // ���� ����
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

	������ �Է��� �� �޴´�. �ΰ��� �и��ؼ� ���� ���� ���, ���� ���� ����

	while (�Է��� �����ִ� ����)
	{
		PolyAdd(poly1, front, back);
	}

	�ι�° ���� �Է��� �޴´�.

	while (�Է��� �����ִ� ����)
	{
		PolyAdd(poly2, front, back);
	}

	PolyCombine(polysum, poly1, poly2);
	printf(polysum);
	*/
	return 0;
}
