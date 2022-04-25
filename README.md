# Binary Data Converter

## Systems Programming Project 1

This program converts the input numbers (signed integer, unsigned integer, floating point number) to hexadecimal and outputs the data.

Example: input.txt

29.109375
<br>
-9

After a valid input file is taken as input, the user will be prompted for the byte ordering type and size:
<br>
Example:
<br>
Byte ordering: l
<br>
Floating point size: 2

Example 1:
<br>
The program will calculate the hexadecimal value of the file content with the given information.
This is a floating point number.
<br>
532.562378 = 1000010100.1000111 = 1.0000101001000111 * 2^9
Mantissa is 1.0000101001000111 However, for 2 bytes we ave 7 bits of fraction part, so we need to round it.
1.0000101001000111 = 1.0000101 The fraction part is 0000101.
E = 9. Exponent is E = exp – Bias, were Bias = 2^(8-1)-1 =127 Therefore the equation is 9 =exp – 127.exp = 136 which is 10001000.
The number is positive, so the sign bit is 0.
The number at total is 0100010000000101 which is 0x4405 in hexadecimal.Byte ordering is little endian, so the floatig point is represented as  05 44 . 
So the first line of the output line has to be Byte ordering is little endian, so the floatig point is represented as  05 44
<br>

Example 2:
<br>
This is a signed integer. Signed integers are 2 bytes:
<br>
-9 = 1111111111110111
1111111111110111 is 0xFFF7 in hexadecimal.
The byte ordering is little endian, so the signed integer will be represented as  F7 FF
