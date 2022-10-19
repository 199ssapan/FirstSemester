#include <stdio.h>
#include <complex.h>

int main()
{
	int realFirstOperand, imagFirstOperand, realSecondOperand, imagSecondOperand;
	int realResult, imagResult;
	char operation;

	printf_s("Enter the expression like in the example\n");
	printf_s("(12, 7) + (-7, 4)\n>");
	scanf_s("(%d, %d) %c (%d, %d)", &realFirstOperand, &imagFirstOperand, &operation, 1, &realSecondOperand, &imagSecondOperand);
	switch (operation)
	{
	case '+':
		realResult = realFirstOperand + realSecondOperand;
		imagResult = imagFirstOperand + imagSecondOperand;
		break;
	case '-':
		realResult = realFirstOperand - realSecondOperand;
		imagResult = imagFirstOperand - imagSecondOperand;
		break;
	case '*':
		realResult = realFirstOperand * realSecondOperand;
		imagResult = imagFirstOperand * imagSecondOperand;
		break;
	default:
		printf("You entered uncorrect opeartion!!");
		return 1;
	}
	printf_s("(%d, %d)", realResult, imagResult);



	return 0;
}