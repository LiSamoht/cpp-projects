/*
 Thomas Li
  C-Style string processing...
*/
#include <iostream>
#include <cctype>
using namespace std;

int lastIndexOf(/*in*/const char* inString,/*in*/ char target);
void reverse(/*in/out*/char* inString);
int replace(/*in/out*/char* inString, /*in*/char target, /*in*/ char replacementChar);
bool isPalindrome(/*in*/const char* inString);
void toupper(/*in/out*/char* inString);
int numLetters(/*in*/const char* inString);

int main() {
	// Testing lastIndexOf() function
	cout << "Testing the lastIndexOf() function.\n\n";
	const char str1[] = "0123456789a1";
	cout << "The last index in the cstring 0123456789a1 with the character '0' is " << lastIndexOf(str1, '0') << endl;
	cout << "The last index in the cstring 0123456789a1 with the letter 'a' is " << lastIndexOf(str1, 'a') << endl;
	cout << "The last index in the cstring 0123456789a1 with the character '1' is " << lastIndexOf(str1, '1') << endl;
	cout << "The last index in the cstring 0123456789a1 with the letter 'x' is " << lastIndexOf(str1, 'x') << endl << endl;

	// Testing reverse() function
	cout << "Testing the reverse() function.\n\n";
	char str2[] = "reverse";
	cout << "The original string is \"" << str2 << "\". The reversed string is \"";
	reverse(str2);
	cout << str2 << "\".\n";

	char str3[] = "13 dwarves";
	cout << "The original string is \"" << str3 << "\". The reversed string is \"";
	reverse(str3);
	cout << str3 << "\".\n\n";

	// Testing replace() function
	cout << "Testing the replace() function.\n\n";
	char str4[] = "abaadabcd";
	cout << "The number of replacements of 'a' for 'z' in abaadabcd is " << replace(str4, 'a', 'z') << endl;
	cout << "Now the string is " << str4 << endl << endl;

	cout << "The number of replacements of 'a' for 'z' in " << str4 << " is " << replace(str4, 'a', 'z') << endl;
	cout << "Now the string is " << str4 << endl << endl;

	// Testing isPalindrome() function
	cout << "Testing the isPalindrome() function.\n\n";
	const char str5[] = "wertytre";
	cout << str5 << " is " << (isPalindrome(str5) ? "" : "not ") << "a palindrome\n";

	const char str6[] = "radar";
	cout << str6 << " is " << (isPalindrome(str6) ? "" : "not ") << "a palindrome\n";

	const char str7[] = "abc ba";
	cout << str7 << " is " << (isPalindrome(str7) ? "" : "not ") << "a palindrome\n";

	const char str8[] = "ra ar";
	cout << str8 << " is " << (isPalindrome(str8) ? "" : "not ") << "a palindrome\n";

	const char str9[] = "abccBa";
	cout << str9 << " is " << (isPalindrome(str9) ? "" : "not ") << "a palindrome\n";

	const char str10[] = "abcdefgha";
	cout << str10 << " is " << (isPalindrome(str10) ? "" : "not ") << "a palindrome\n";

	const char str11[] = "";
	cout << "(an empty string) is " << (isPalindrome(str11) ? "" : "not ") << "a palindrome\n\n";

	// Testing toupper() function
	cout << "Testing the toupper() function.\n\n";
	char str12[] = "Lord of the Strings";
	cout << "Before: " << str12 << endl;
	toupper(str12);
	cout << "After: " << str12 << endl << endl;

	// Testing numLetters() function
	cout << "Testing the numLetters() function.\n\n";
	const char str13[] = "0123456789a1";
	cout << str13 << " has this many letters: " << numLetters(str13) << endl;

	return 0;
}



/*
 Finds the last index of the target character in the input string. This function traverses the input string to find the last occurrence 
 of the target character, checking each occurrence of target and saving its index. If the target character is found, the function returns its last index.
 If the target character is not found, the function returns -1.

 pre: inString points to a null-terminated array of characters, target is a valid character
 post: the lastIndex of target is returned
*/
int lastIndexOf(/*in*/const char* inString, /*in*/char target) {
	int charIndex = 0;
	int lastIndex = -1;
	while (*(inString + charIndex) != '\0') {
		if (*(inString + charIndex) == target) {
			lastIndex = charIndex;
		}
		charIndex++;
	}
	return lastIndex;
}



/*
 Reverses the input string in place. It begins by iterating through the entire string to determine its length (stringSize). Then, it uses a swap algorithm
 that iterates stringSize / 2 times to reverse the entire string without creating a new array.

 pre: inString points to a null-terminated array of characters
 post: inString is reversed
*/
void reverse(/*in*/char* inString) {
	//find the size of the string
	int charIndex = 0;
	int stringSize;
	while (*(inString + charIndex) != '\0') {
		charIndex++;
	}
	stringSize = charIndex;
	//Swap algorithm to reverse the string
	
	for (int i = 0; i < (stringSize / 2); i++) {
		swap(*(inString + i), *(inString + stringSize - 1 - i));
	}
}


/*
 This function replaces all instances of the character target with the character replacementChar in the inString. It does this very simply
 by traversing through the entire cstring and checking if any character in the string is ever equal to target...if so, it is replaced accordingly. It
 also counts how many replacements have taken place and returns that value as well (if no replacements were made, 0 is returned).

 pre: inString points to a null-terminated array of characters, target and replacement Char are valid characters.
 post: every instance of target in inString is replaced by replacementChar, and the number of replacements are returned.
*/
int replace(/*in/out*/char* inString, /*in*/ char target, /*in*/ char replacementChar) {
	int charIndex = 0;
	int numReplacements = 0;
	while (*(inString + charIndex) != '\0') {
		if (*(inString + charIndex) == target) {
			*(inString + charIndex) = replacementChar;
			numReplacements++;
		}
		charIndex++;
	}
	return numReplacements;
}


/*
 Checks if the input string is a palindrome, meaning it reads the same forwards and backwards. The comparison is case-insensitive and ignores non-character
 letters. It begins by finding the length of the string again, and it then performs a for loop that will iterate the length of the string divided by 2.
 It then compares the character at i indices from the beginning and i indices from the end, checking if their lowercase equivalents are NOT equal...if this
 is ever the case, then it isn't a palindrome. Checking lowercase equivalents is a good way to be case-insensitive. tolower() returns the lower version
 of any character, and it won't change the character if a lower version of a character doesn't exist.

 pre:inString points a null-terminated array of characters.
 post: return true (if it is a palindrome), return false (if it isn't a palindrome)
*/
bool isPalindrome(/*in*/const char* inString) {
	//find the length of the string
	int charIndex = 0;
	int stringSize;
	while (*(inString + charIndex) != '\0') {
		charIndex++;
	}
    stringSize = charIndex;

	//check if the string is a palindrome
	for (int i = 0; i < (stringSize / 2); i++) {
		char current = *(inString + i);
		char Tailcurrent = *(inString + stringSize - 1 - i);

		//always compare the "lower" version of each character to be case insensitive. tolower won't change the character if a lower version of the character doesn't exist.
		if (tolower(current) != tolower(Tailcurrent)) {
			return false;
		}
	}

	return true;
}

/*
 Converts all characters in the input string to uppercase through using toupper(character) in <cctype>. This really just extends the usage to strings.
 
 pre: inString points to a null-terminated array of characters.
 post: all characters in inString are converted to their upper equivalents, yielding a fully uppercase string
*/
void toupper(/*in/out*/char* inString) {
	int charIndex = 0;
	while (*(inString + charIndex) != '\0') {
		*(inString + charIndex) = toupper(*(inString + charIndex));
		charIndex++;
	}
}



/*
 Returns the number of letters that are in the string. It does this by simply iterating through the entire string and checking if each character is an
 alphabetical letter...if so, a counter is incremented and the final count is returned to the caller.

 pre: inSTring points to a null-terminated array of characters.
 post: the number of letters in the string is returned.
*/
int numLetters(/*in*/const char* inString) {
	int charIndex = 0;
	int countLetters = 0;
	while (*(inString + charIndex) != '\0') {
		if (isalpha(*(inString + charIndex))) {
			countLetters++;
		}
		charIndex++;
	}

	return countLetters;
}


/*SAMPLE OUTPUT :
Testing the lastIndexOf() function.

The last index in the cstring 0123456789a1 with the character '0' is 0
The last index in the cstring 0123456789a1 with the letter 'a' is 10
The last index in the cstring 0123456789a1 with the character '1' is 11
The last index in the cstring 0123456789a1 with the letter 'x' is -1

Testing the reverse() function.

The original string is "reverse". The reversed string is "esrever".
The original string is "13 dwarves". The reversed string is "sevrawd 31".

Testing the replace() function.

The number of replacements of 'a' for 'z' in abaadabcd is 4
Now the string is zbzzdzbcd

The number of replacements of 'a' for 'z' in zbzzdzbcd is 0
Now the string is zbzzdzbcd

Testing the isPalindrome() function.

wertytre is not a palindrome
radar is a palindrome
abc ba is not a palindrome
ra ar is a palindrome
abccBa is a palindrome
abcdefgha is not a palindrome
(an empty string) is a palindrome

Testing the toupper() function.

Before: Lord of the Strings
After: LORD OF THE STRINGS

Testing the numLetters() function.

0123456789a1 has this many letters: 1
*/