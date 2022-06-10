#include <iostream>
#include <string>
#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"

using namespace std;

int creacionTablero(BMP &Image, int tamanio){
	RGBApixel LightGray;
	LightGray.Red = 192;
	LightGray.Green = 192;
	LightGray.Blue = 192;
	for( int j=0 ; j < Image.TellHeight() ; j++ )
	{
	for( int i=0 ; i < Image.TellWidth() ; i++ )
	{
	*Image(i,j) = LightGray;
	}
	}
	RGBApixel FontColor; 
	FontColor.Red = 0;
	FontColor.Green = 0;
	FontColor.Blue = 0; 
	for (int i = 20; i <= tamanio*tamanio; i = i+20){
		for (int j = 0; j <= tamanio*tamanio; j = j+20){
			DrawLine(Image, i, j, i, 400, FontColor);
			DrawLine(Image, j, i, 400, i, FontColor);
		}
	}
	DrawArc(Image, 10, 10, 5, 0, 360, FontColor);
	Image.WriteToFile( "tablero.bmp" );
	return 0;
}
int pintarCuadrado(BMP &Image, int xi,int yi, int xf, int yf){
	RGBApixel FontColor; 
	FontColor.Red = 255;
	FontColor.Green = 0;
	FontColor.Blue = 0; 
	for (yi; yi <= yf ; yi++){
		DrawLine(Image, xi, yi, xf, yi, FontColor);
	}
	Image.WriteToFile( "tablero.bmp" );	
}

int main(){
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
	creacionTablero(Window, 20);
	
	pintarCuadrado(Window, 40, 0, 60, 20);
	return
