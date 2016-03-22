// ��Ч�����������룬�ĳ�while���� 
#include <stdio.h>

int convertedNumber[64];
long int numberToConvert;
int base;
int digit = 0;

void getNumberAndBase(void){
	printf("Number to be converted? ");
	scanf("%li", &numberToConvert);
	
	printf("Base? ");
	scanf("%i", &base);
	
	while(base < 2 || base > 16){
		printf("���������������������:\n");
		scanf("%i", &base);
	}
} 

void convertNumber(void){
	do{
		convertedNumber[digit] = numberToConvert % base;
		++digit;
		numberToConvert /= base;
	}
	while(numberToConvert != 0);
}

void displayConvertedNumber(void){
	const char baseDigits[16] = 
		{'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int nextDigit;
	
	printf("Converted number = ");
	
	for(--digit; digit >= 0; --digit){
		nextDigit = convertedNumber[digit];
		printf("%c", baseDigits[nextDigit]);
	}
	
	printf("\n");
}

int main(void){
	void getNumberAndBase(void), convertNumber(void),
		displayConvertedNumber(void);
		
	// ������Ҫת�������ֺͻ��� 
	getNumberAndBase();
	// ת�����֣�������浽���� 
	convertNumber();
	// ��ʾת����� 
	displayConvertedNumber();
	
	return 0;
}