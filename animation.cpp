#include <iostream> 
#define CIMGGIP_MAIN 
#include "CImgGIP05.h" 
using namespace std;

int main() {
	// Für das "blaue Spielfeld" ...  
	const int left_border = 100;
	const int right_border = 500;

	// Für Ausdehnung und Position des weißen Quadrats ...  
	int x = 200, y = 300;
	const int rectangle_size = 50;
	int delta = 10;
	gip_white_background();

/*
	//eingener Spass, Hoch und runter bewegen
	int delta_y = 10;
*/
	
	while (gip_window_not_closed()) {
		// Blaues "Spielfeld" neu zeichnen   
		// (übermalt dann auch das letzte weiße Quadrat) ...   
		gip_draw_rectangle(left_border, 100, // linke obere Ecke    
			right_border, 500, // rechte untere Ecke    
			blue);

		// Weißes Quadrat neu zeichnen an der Position x,y ...   
		gip_draw_rectangle(x, y,    // linke obere Ecke    
			x + rectangle_size,		// rechte untere Ecke   
			y + rectangle_size, 
			white);

		// Nächste Position des weißen Quadrats berechnen.   
		// Dabei berücksichtigen, dass das Quadrat von den Rändern des   
		// blauen "Spielfelds" abprallen muss ... 

		/* Ihr Code zur Berechnung der neuen Werte von x und y hier */
		x = x + delta; // Position um delta verschieben, des Weißes Quadrat in x Richtung
		if (x <= left_border || x >= right_border - rectangle_size) //Falls der linke oder rechte Rand berührt wird, das Vorzeichen von delta gewechselt
		{
			delta = delta * (-1);
		}

/*
		//eingener Spass, Hoch und runter bewegen
		y = y + delta_y; // Position um delta_y verschieben, des Weißes Quadrat in y Richtung
		if (y <= left_border || y >= right_border - rectangle_size) //Falls der linke oder rechte Rand berührt wird, das Vorzeichen von delta gewechselt
		{
			delta_y = 0 - delta_y;
		}
*/
		// Ende der Änderungen
		gip_wait(100);
	}  return 0;
}
