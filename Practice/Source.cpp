#include <iostream>
#include <conio.h>
using namespace std;

/* Check if 2 Numbers are equal without using comparative operator  */
void CheckEquality(int a, int b) 
{
	if (a^b)
		cout << "Not Equal";
	else
		cout << "Equal";

}

/* Set a Bit 
Example:  if you want to set the 2nd bit ON in a number say 8 which in binary is (1 0 0 0).
By giving the index as 2 and Value as 8 (your input number). It will bit-shift and turn the index ON. If you set the bit 2, the above number becomes 8 + 4 = 12 as the index starts from 0.
*/
void SetBit(int index, int Value) {

	Value |= (1 << index);			
	cout <<"The value after setting the"<< index << "bit is: "<< Value;
}


/*Find binary format of a decimal number*/
void FindBinary(int a) {					// Considering a 16 bit Int.
	int ceiling;
	if (a < 256)						// If the input is less than 255 (less than 8 bit, then we cap the ceiling to 128 as sum of all the 8 bits = 255. 
		ceiling = 128;
	else								// If the number is greater than or equal to 256, then we can raise the ceiling to 32768 which is 16 bits.
		ceiling = 32768;

	for (int i = ceiling; i > 0; i = i / 2)
	{
		if (a&i)
			cout << "1 ";
		else
			cout << "0 ";
	}
}

/* Using Bit Shifting*/
void DecimalToBinary(int k)			
{
	const int BITS = sizeof(int) *CHAR_BIT;	// If you don't know if INT is 16 or 32 Bits, find it using this line.

	// using right shift
	for (int i = BITS - 1; i >= 0; i--)  	// We & with every bit to see if it is 1 or 0 and display it.
	{
		cout << ((k >> i) & 1);
	}
}


/* Convert Decimal to Hex using Bit shifting*/
void DecimalToHex(int n) {
	const int BITS = 4;
	char *hexString = "0123456789ABCDEF";

	/*bit shift to right by 4 places and & with 0xff (which is 1 1 1 1 in binary) using this mask, we find the Hex value BYTE By BYTE.
	Each Hexadecimal values represent 8 bits, thus the max value of a hex is 15 which is 1 1 1 1 . */

	cout << "decimal: " << n << endl;
	cout << "hex    : ";
	for (int i = BITS - 1; i >= 0; i--)
		cout << hexString[(n >> i * 4) & 0xF];			
}

/*Convert Little Endian to Big Endian or vice versa */
void EndianConversion(uint32_t  value) {
	uint32_t  a0, a1, a2, a3;
	// Assume value is 8.  It is represented as 00000000 00000000 00000000 00001000  in binary format  - 4 Bytes format
	a0 = (value & 0x000000ff) << 24u; // & with a mask which is a hexademical number. After & operation move this by 24 bits to the left
	a1 = (value & 0x0000ff00) << 8u;  // & with a mask which is a hexademical number. After & operation move this by 8 bits to the left
	a2 = (value & 0x00ff0000) >> 8u;  // & with a mask which is a hexademical number. After & operation move this by 8 bits to the right
	a3 = (value & 0xff000000) >> 24u; // & with a mask which is a hexademical number. After & operation move this by 24 bits to the right

	value = (a0 | a1 | a2 | a3);      // Add the above values you will get the converted Endian


	// The reason why we & with the mask is to filter out exactly 1 Byte from the input which is 8 bits, get its value and shift it to the other position.
}

/* Find if a machine is Little Endian or big endian */
void endian() {
	int one = 1;
	char *ptr;
	ptr = (char *)&one;
	if (*ptr)
		cout << "Little Endian";
	else
		cout << "Big endian";
}



int main() {

	/* Check Equality of a number without using comparator operator */
	//CheckEquality(0, 6);

	/*Set the X bit of a number */
	//SetBit(2, 8);

	// Check Endian-ness of a machine
	// endian();

	/*Convert Little Endian to Big Endian*/
	//EndianConversion(8);

	/*Find binary using any bitwise operation*/
	//FindBinary(355);

	/*Find binary using bit shift operations*/
	//DecimalToBinary(8);

	/*Find Decimal to Hex using bit shifting*/
	//DecimalToHex(32768);
	
	
	getchar();
	return 0;
}
