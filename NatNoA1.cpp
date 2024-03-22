#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

typedef int NatNo;

NatNo Zero();
int   IsZero(NatNo x);
NatNo Succ(NatNo x);
NatNo Pred(NatNo x);
NatNo Add(NatNo x, NatNo y);

// Practise
int   Equal(NatNo x, NatNo y);
int   Greater(NatNo x, NatNo y);
NatNo Sub(NatNo x, NatNo y);		// Error example

// HW
NatNo Mul(NatNo x, NatNo y);
NatNo Div(NatNo x, NatNo y);		// Error case
NatNo Mod(NatNo x, NatNo y);		// Error case

void main()
{
	while (1) {
		int nFtn;
		NatNo x, y, z;
		printf("Is1, Su2, Ad3, Eq4, Gt5, Sb6, Mu7, Di8, Mo9: ? ");
		scanf("%d", &nFtn);
		if (nFtn < 1 || nFtn > 9)
			break;
		printf("x ? ");
		scanf("%d", &x);
		if (nFtn > 2) {
			printf("y ? ");
			scanf("%d", &y);
		}
		switch (nFtn) {
		case 1:
			z = IsZero(x);
			break;
		case 2:
			z = Succ(x);
			break;
		case 3:
			z = Add(x, y);
			break;
		case 4:
			z = Equal(x, y);
			break;
		case 5:
			z = Greater(x, y);
			break;
		case 6:
			z = Sub(x, y);
			break;
		case 7:
			z = Mul(x, y);
			break;
		case 8:
			z = Div(x, y);
			break;
		case 9:
			z = Mod(x, y);
		}
		printf("return %d\n\n", z);
	}
}

NatNo Error()
{
	printf("Error:: not applicable operator!!!\n");
	return Zero();
}

NatNo Zero()
{
	return 0;
}

int IsZero(NatNo x)
{
	// [1]:(Z)	IsZero(Zero) ::= true
	// [2]:(N)	IsZero(Succ(x)) ::= false

	if (x == Zero())	// ==는 어쩔 수 없이
		return true;	// [1]
	return false;		// [2]
}

NatNo Succ(NatNo x)
{
	return x + 1;		// +는 어쩔 수 없이
}

NatNo Pred(NatNo x)
{
	if (IsZero(x))
		return Error();
	return x - 1;		// -는 어쩔 수 없이
}

/***
	구현하기 위하여 여기까지는 어쩔 수 없이
	다른 연산자를 사용하였지만
	여기서부터는 위에서 정의된 연산자 이외에
	다른 연산자는 절대로 사용할 수 없다.
***/

#define ADD	1

NatNo Add(NatNo x, NatNo y)		// x + y
{
#if ADD == 1

	// Method 1
	// (x+1) + y = (x + y) + 1
	// Add(x + 1, y) ::= Add(x, y) + 1
	//     x  y
	//     0  y
	// (1) Add(0, y) ::= y						;; 중단 조건
	// (2) Add(x + 1, y) ::= Add(x, y) + 1		;; 일반 원리
	// [1]:(Z,A)	Add(Zero(), y) ::= y
	// [2]:(N,A)	Add(Succ(x), y) ::= Succ(Add(x, y))
	// [2]:(N,A)	Add(Succ(x), y) ::= Add(x, Succ(y))

	if (IsZero(x))
		return y;
	//return Succ(Add(Pred(x), y));
	return Add(Pred(x), Succ(y));

#else

	// Method 2
	// x + (y+1) ::= x + y + 1
	// Add(x, y + 1) ::= Add(x, y) + 1
	//     x  y
	//     x  0
	// (1) Add(x, 0) ::= x						;; 중단 조건
	// (2) Add(x, y+1) ::= Add(x, y) + 1		;; 일반 원리
	// [1]:(A,Z)	Add(x, Zero()) ::= x
	// [2]:(A,N)	Add(x, Succ(y)) ::= Succ(Add(x, y))
	// [2]:(A,N)	Add(x, Succ(y)) ::= Add(Succ(x), y)

	if (IsZero(y))
		return x;
	//return Succ(Add(x, Pred(y)));
	return Add(Succ(x), Pred(y));
#endif
}

#define EQUAL	1

int Equal(NatNo x, NatNo y)		// x == y
{	// (x+1) == (y+1) ::= x == y
#if EQUAL == 1

	// Equal(x + 1, y + 1) ::= Equal(x, y)		;; 일반 원리
	//     x  y
	// (1) Z  Z --> true						;; 중단 조건
	// (2) Z  N --> false
	// (3) N  Z --> false

	// Method 1
	// (1)과 (2)를 합침(두 결과가 각각 true, false)
	// [1]:(Z,A)	Equal(Zero(), y) ::= IsZero(y)				;; IF IsZero(y) THEN true ELSE false
	// [2]:(N,Z)	Equal(Succ(x), Zero()) ::= false
	// [3]:(N,N)	Equal(Succ(x), Succ(y)) ::= Equal(x, y)

	if (IsZero(x))
		return IsZero(y);
	if (IsZero(y))
		return false;
	return Equal(Pred(x), Pred(y));

#else

	// Method 2
	//     x  y
	// (1) Z  Z --> true						;; 중단 조건
	// (3) N  Z --> false
	// (2) Z  N --> false
	// (1)과 (3)을 합침
	// [1]:(A,Z)	Equal(x, Zero()) ::= IsZero(x)
	// [2]:(Z,N)	Equal(Zero(), Succ(y)) ::= false
	// [3]:(N,N)	Equal(Succ(x), Succ(y)) ::= Equal(x, y)

	if (IsZero(y))
		return IsZero(x);
	if (IsZero(x))
		return false;
	return Equal(Pred(x), Pred(y));
#endif
}

#define GREATER	1

int Greater(NatNo x, NatNo y)		// x > y
{	// (x+1) > (y+1) ::= x > y
#if GREATER == 1

	// Greater(x + 1, y + 1) ::= Greater(x , y)	;; 일반 원리
	// Method 1
	//     x  y
	// (1) Z  Z --> false						;; 중단 조건
	// (2) Z  N --> false
	// (3) N  Z --> true
	// (1)과 (2)를 합침
	// [1]:(Z,A)	Greater(Zero(), y) ::= false
	// [2]:(N,Z)	Greater(Succ(x), Zero()) ::= true
	// [3]:(N,N)	Greater(Succ(x), Succ(y)) ::= Greater(x, y)

	if (IsZero(x))
		return false;
	if (IsZero(y))
		return true;
	return Greater(Pred(x), Pred(y));

#else

	// Method 2
	// (1) Z  Z --> false						;; 중단 조건
	// (3) N  Z --> true
	// (2) Z  N --> false
	// (1)과 (3)을 합침
	// [1]:(A,Z)	Greater(x, Zero()) ::= IF IsZero(x) THEN false ELSE true
	// [2]:(Z,N)	Greater(Zero(), Succ(y)) ::= false
	// [3]:(N,N)	Greater(Succ(x), Succ(y)) ::= Greater(x, y)

	if (IsZero(y))
		return IsZero(x) ? false : true;		// NOT IsZro(x)
	if (IsZero(x))
		return false;
	return Greater(Pred(x), Pred(y));
#endif
}

#define SUB	1

NatNo Sub(NatNo x, NatNo y)		// x - y
{	// (x+1) - (y+1) ::= x - y
#if SUB == 1
	// Sub(x + 1, y + 1) ::= Sub(x, y)			;; 일반 원리
	// Method 1
	// (1) Z  Z --> 0							;; 중단 조건
	// (2) Z  N --> error
	// (3) N  Z --> x
	// (1)과 (2)를 합침
	// [1]:(Z,A)	Sub(Zero(), y) ::= IF IsZero(y) THEN Zero() ELSE error
	// [2]:(N,Z)	Sub(Succ(x), Zero()) ::= Succ(x)
	// [3]:(N,N)	Sub(Succ(x), Succ(y)) ::= Sub(x, y)

	if (IsZero(x))
		return IsZero(y) ? Zero() : Error();
	if (IsZero(y))
		return x;
	return Sub(Pred(x), Pred(y));

#else

	// Method 2
	//     x  y
	// (1) Z  Z --> 0						;; 중단 조건
	// (3) N  Z --> x
	// (2) Z  N --> error
	// (1)과 (3)을 합침
	// [1]:(A,Z)	Sub(x, Zero()) ::= x
	// [2]:(Z,N)	Sub(Zero(), Succ(y)) ::= error
	// [3]:(N,N)	Sub(Succ(x), Succ(y)) ::= Sub(x, y)

	if (IsZero(y))
		return x;
	if (IsZero(x))
		return Error();
	return Sub(Pred(x), Pred(y));
#endif
}

//#define MUL	1

NatNo Mul(NatNo x, NatNo y)		// x * y
{
#if MUL == 1

	// Method 1
	// (x+1) * y ::= x * y + y
	// Mul(x + 1, y) ::= Mul(x, y) + y			;; 일반 원리
	//     x  y
	// (1) ?  ? --> ?						;; 중단 조건
	// (2) 
	// [1]:(?,?)	Mul(?, ?) ::= ?
	// [2]:(?,?)	Mul(?, ?) ::= ?

	return Zero();

#else

	/*** Method 2 ***/
	// x * (y+1) ::= x * y + x
	// Mul(x, y + 1) ::= Mul(x, y) + x			;; 일반 원리
	//     x  y
	// (1) ?  ? --> ?						;; 중단 조건
	// (2) 
	// [1]:(?,?)	Mul(?, ?) ::= ?
	// [2]:(?,?)	Mul(?, ?) ::= ?

	return Zero();
#endif
}

NatNo Div(NatNo x, NatNo y)		// x / y
{	// (x+y) / y ::= x / y + 1
	// Div(x + y, y) ::= Div(x, y) + 1			;; 일반 원리
	//     x  y
	// (1) ?  ? --> ?						;; 중단 조건
	// (2) 
	// [1]:(?,?)	Div(?, ?) ::= ?
	// [2]:(?,?)	Div(?, ?) ::= ?

	return Zero();
}

NatNo Mod(NatNo x, NatNo y)		// x % y
{	// (x+y) % y ::= x % y
	// Mod(x + y, y) ::= Mod(x, y)				;; 일반 원리
	//     x  y
	// (1) ?  ? --> ?						;; 중단 조건
	// (2) 
	// [1]:(?,?)	Mod(?, ?) ::= ?
	// [2]:(?,?)	Mod(?, ?) ::= ?

	return Zero();
}
