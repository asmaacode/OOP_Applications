#pragma once
#include <string>
#include <iostream>
#include "clsDate.h"
#include "clsDrawer.h"
using namespace std;

class clsUtils {
public:
	static string generateLine(short length = 0, char symbol = '_') {
		clsDrawer::generateLine(length, symbol);
	};
	static string generateTabs(short length = 0) {
		clsDrawer::generateTabs(length);
	};

	static void swap(int& A, int& B) {
		int temp = A;
		A = B;
		B = temp;
	};
	static void swap(int* A, int* B) {
		int temp = *A;
		*A = *B;
		*B = temp;
	};
	static  void swap(double& A, double& B)
	{
		double temp = A;
		A = B;
		B = temp;
	};
	static  void swap(bool& A, bool& B) {
		bool temp = A;
		A = B;
		B = temp;
	};
	static  void swap(char& A, char& B)
	{
		char temp = A;
		A = B;
		B = temp;
	}
	static  void swap(string& A, string& B)
	{
		string temp = A;
		A = B;
		B = temp;
	}
	static  void swap(clsDate& A, clsDate& B)
	{
		clsDate::swapDates(A, B);
	};

	enum enCharType { smallLetter, capitalLetter, specialCharacter, digit };
	static void  sRand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}
	static int generateRandomNumbers(int from, int to) {
		//in main call 	srand(time(NULL));
		return rand() % (to - from + 1) + from;
	};
	static char getRandomCharachter(enCharType randomType) {
		switch (randomType) {
		case enCharType::smallLetter:
			return char(generateRandomNumbers(int('a'), int('z')));
		case enCharType::capitalLetter:
			return char(generateRandomNumbers(int('A'), int('Z')));
		case enCharType::specialCharacter:
			return (char)generateRandomNumbers(int('Z') + 1, 128);
		case enCharType::digit:
			return generateRandomNumbers(48, 57);
		}
	}
	static string generateWord(enCharType charType, int lettersCount) {
		string word = "";
		for (int i = 4;i != 0; i--) {
			word = word + getRandomCharachter(charType);
		}
		return word;
	}
	static string generateKey(int wordsCount) {
		string key = "";
		for (int i = wordsCount;i != 0; i--) {
			key = key + generateWord(enCharType::capitalLetter, 4);
			if (i != 1)
				key = key + "-";
		}
		return key;
	}
	static void generateKeys(int keyCount) {
		for (int i = 0; i < keyCount;i++) {
			cout << "Key[" << i + 1 << "]: " << generateKey(4) << "\n";
		}
	};
	static void fillArrayWithRandomNumbers(int arr[], int arrLength) {
		for (int i = 0;i < arrLength;i++) {
			arr[i] = generateRandomNumbers(1, 100);
		}
	};
	static void fillArrayWithRandomKeys(string arr[], int& keyCount) {
		for (int i = 0; i < keyCount;i++) {
			arr[i] = generateKey(4);
		}
	};
	static void fillArrayWithRandomWords(string arr[], int arrLength, enCharType charType, short wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = generateWord(charType, wordlength);

	};
	static  void shuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[generateRandomNumbers(1, arrLength) - 1], arr[generateRandomNumbers(1, arrLength) - 1]);
		}
	};
	static  void shuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[generateRandomNumbers(1, arrLength) - 1], arr[generateRandomNumbers(1, arrLength) - 1]);
		}
	};
	static string  encryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	};
	static string  decryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	};
	static string NumberToText(long int Number) {
		if (Number == 0) { return""; }
		if (Number >= 1 && Number <= 19) {
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen",
				"Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return  arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {
			return"One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {
			return"One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999) {
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999) {
			return"One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999) {
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999) {
			return"One Billion " + NumberToText(Number % 1000000000);
		}
		else { return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000); }

	}
};

