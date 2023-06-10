#pragma once
#include <string>
using namespace std;
class clsUtils {
public:
	static string generateLine(short length = 0, char symbol = '_') {
		string line = "";
		while (length != 0) {
			line += symbol;
			length--;
		}
		return line;
	};
	static string generateTabs(short length = 0) {
		string tabs = "";
		while (length != 0) {
			tabs += " ";
			length--;
		}
		return tabs;
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

	}

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
};

