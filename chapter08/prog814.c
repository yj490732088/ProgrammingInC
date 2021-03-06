// 将一个正整数转换为其他基数的函数，全局变量 
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
	
	if(base < 2 || base > 16){
		printf("Bad base - must be between 2 and 16\n");
		base = 10;
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
		
	// 接收需要转换的数字和基数 
	getNumberAndBase();
	// 转换数字，结果保存到数组 
	convertNumber();
	// 显示转换结果 
	displayConvertedNumber();
	
	return 0;
}
