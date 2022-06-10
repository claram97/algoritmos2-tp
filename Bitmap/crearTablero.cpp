#include <iostream>
#include <string>
#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"

using namespace std;

int creacionTablero( int tamanio){
	RGBApixel LightGray;
	LightGray.Red = 192;
	LightGray.Green = 192;
	LightGray.Blue = 192;
	BMP Window;
	Window.SetSize(1000, 1000);
	for( int j=0 ; j < Window.TellHeight() ; j++ )
	{
	for( int i=0 ; i < Window.TellWidth() ; i++ )
	{
	*Window(i,j) = LightGray;
	}
	}
	RGBApixel FontColor; 
	FontColor.Red = (ebmpBYTE) ebmpRound( (double) 3 * 255.0 / (double) Window.TellHeight() );
	FontColor.Green = 0;
	FontColor.Blue = 255 - FontColor.Red; 
	for (int i = 20; i <= tamanio*tamanio; i = i+20){
		for (int j = 0; j <= tamanio*tamanio; j = j+20){
			DrawLine(Window, i, j, i, 400, FontColor);
			DrawLine(Window, j, i, 400, i, FontColor);
		}
	}
	Window.WriteToFile( "tablero.bmp" );
	return 0;
}
