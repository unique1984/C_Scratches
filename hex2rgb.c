/*****************************************
 * App		: hex color to rgb values RGB888 & RGB565
 * File		: hex2rgb.c
 * Date		: Wed Aug  8 01:46:01 +03 2018
 * Version	: 1.0.0
 * Email	: yasinkarabulak@gmail.com
 * 
 * MIT License
 * Copyright (c) 2018 Yasin KARABULAK
*******************************************/
#include <stdio.h>
typedef struct hex2rgb
{
	unsigned int hexValue;
	unsigned short r, g, b;
} hex2rgb;

hex2rgb parseRgb888( hex2rgb  hexValue );
hex2rgb parseRgb565( hex2rgb  hexValue );

int main( int argc, char *argv[] )
{
	hex2rgb hex24, hexParsed565, hexParsed888;
	if ( argc > 1 )
	{
		sscanf( argv[1] , "%06x", &hex24.hexValue );
	}
	else
	{
		printf("Enter 24bit hexValue: ");
		scanf("%06x", &hex24.hexValue);
	}
	hexParsed888 = parseRgb888( hex24 );
	hexParsed565 = parseRgb565( hex24 );
	printf ( "Hex24\t#%06X\nRGB888 (%d, %d, %d)\n\n", hex24.hexValue ,hexParsed888.r, hexParsed888.g, hexParsed888.b );
	printf ( "Hex16\t#%04X\nRGB565 (%d, %d, %d)\n", hexParsed565.hexValue, hexParsed565.r, hexParsed565.g, hexParsed565.b );
	return 0;
}

hex2rgb parseRgb565 ( hex2rgb hexParse )
{
	hex2rgb hexParsed888, parsed;
	hexParsed888 = parseRgb888( hexParse );
	parsed.hexValue = ( ( hexParsed888.r >> 3 ) << 11 ) | ( ( hexParsed888.g >> 2 ) << 5 ) | ( hexParsed888.b >> 3 );
	parsed.r = ( ( parsed.hexValue >> 11 ) & 0x1F );
	parsed.g = ( ( parsed.hexValue >> 5 ) & 0x3F );
	parsed.b = ( parsed.hexValue & 0x1F );
	//printf( "Output\nHex 565: #%04X\n", parsed.hexValue );
return parsed;
}


hex2rgb parseRgb888( hex2rgb hexParse )
{
	hex2rgb parsed;
	parsed.r = ( ( hexParse.hexValue >> 16 ) & 0xff );
	parsed.g = ( ( hexParse.hexValue >> 8 ) & 0xff );
	parsed.b = ( ( hexParse.hexValue >> 0 ) & 0xff );
	//printf( "Output\nHex 888: #%06X\n", hexParse.hexValue );
	//printf( "RGB (%d, %d, %d)\n", parsed.r, parsed.g, parsed.b );
return parsed;
}
