#include <stdio.h>

struct ComplexNumber
{
	int Re;
	int Im;
};
int main()
{
	char operation;
	struct ComplexNumber firstNum, SecondNum, result;
	printf_s("Enter the expression like in the example\n");
	printf_s("(12, 7) + (-7, 4)\n>");
	scanf_s("(%d, %d) %c (%d, %d)", &firstNum.Re, &firstNum.Im, &operation, 1, &SecondNum.Re, &SecondNum.Im);
	switch (operation)
	{
	case '+':
		result.Re = firstNum.Re + SecondNum.Re;
		result.Im = firstNum.Im + SecondNum.Im;
		break;
	case '-':
		result.Re = firstNum.Re - SecondNum.Re;
		result.Im = firstNum.Im - SecondNum.Im;
		break;
	case '*':
		result.Re = firstNum.Re * SecondNum.Re - firstNum.Im * SecondNum.Im;
		result.Im = firstNum.Im * SecondNum.Re + firstNum.Re * SecondNum.Im;
		break;
	default:
		printf("You entered uncorrect opeartion!!");
		return 1;
	}
	printf_s("(%d, %d)", result.Re, result.Im);



	return 0;
}
