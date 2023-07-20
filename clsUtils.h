#pragma once
#include <string>
#include <iostream>
#include <fstream>
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

	static void Swap(int& A, int& B) {
		int temp = A;
		A = B;
		B = temp;
	};
	static void Swap(int* A, int* B) {
		int temp = *A;
		*A = *B;
		*B = temp;
	};
	static  void Swap(double& A, double& B)
	{
		double temp = A;
		A = B;
		B = temp;
	};
	static  void Swap(bool& A, bool& B) {
		bool temp = A;
		A = B;
		B = temp;
	};
	static  void Swap(char& A, char& B)
	{
		char temp = A;
		A = B;
		B = temp;
	}
	static  void Swap(string& A, string& B)
	{
		string temp = A;
		A = B;
		B = temp;
	}
	static  void Swap(clsDate& A, clsDate& B)
	{
		clsDate::swapDates(A, B);
	};

	enum enCharType { smallLetter, capitalLetter, specialCharacter, digit };
	static void  sRand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}
	static int GenerateRandomNumbers(int from, int to) {
		//in main call 	srand(time(NULL));
		return rand() % (to - from + 1) + from;
	};
	static char GetRandomCharachter(enCharType randomType) {
		switch (randomType) {
		case enCharType::smallLetter:
			return char(GenerateRandomNumbers(int('a'), int('z')));
		case enCharType::capitalLetter:
			return char(GenerateRandomNumbers(int('A'), int('Z')));
		case enCharType::specialCharacter:
			return (char)GenerateRandomNumbers(int('Z') + 1, 128);
		case enCharType::digit:
			return GenerateRandomNumbers(48, 57);
		}
	}
	static string GenerateWord(enCharType charType, int lettersCount) {
		string word = "";
		for (int i = 4;i != 0; i--) {
			word = word + GetRandomCharachter(charType);
		}
		return word;
	}
	static string GenerateKey(int wordsCount) {
		string key = "";
		for (int i = wordsCount;i != 0; i--) {
			key = key + GenerateWord(enCharType::capitalLetter, 4);
			if (i != 1)
				key = key + "-";
		}
		return key;
	}
	static void GenerateKeys(int keyCount) {
		for (int i = 0; i < keyCount;i++) {
			cout << "Key[" << i + 1 << "]: " << GenerateKey(4) << "\n";
		}
	};
	static void FillArrayWithRandomNumbers(int arr[], int arrLength) {
		for (int i = 0;i < arrLength;i++) {
			arr[i] = GenerateRandomNumbers(1, 100);
		}
	};
	static void FillArrayWithRandomKeys(string arr[], int& keyCount) {
		for (int i = 0; i < keyCount;i++) {
			arr[i] = GenerateKey(4);
		}
	};
	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType charType, short wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(charType, wordlength);

	};
	static  void ShuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[GenerateRandomNumbers(1, arrLength) - 1], arr[GenerateRandomNumbers(1, arrLength) - 1]);
		}
	};
	static  void ShuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[GenerateRandomNumbers(1, arrLength) - 1], arr[GenerateRandomNumbers(1, arrLength) - 1]);
		}
	};
	static string  Encrypt(string Text, short EncryptionKey=123456789)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	};
	static string  Decrypt(string Text, short EncryptionKey=123456789)
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
	static void AddNewLineToFile(string FileName,string NewLine) {
		fstream File;
		File.open(FileName, ios::out | ios::app);
		if (File.is_open()) {
			File << NewLine << endl;
		}
		File.close();
	}
};

