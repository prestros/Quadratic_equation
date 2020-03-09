// Programm zur Berechnung von Quadratischen Gleichungen
// Autor: Fabian Prestros
// Datum: 09.03.2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double einlesen(char koef);	// Funktion zum fehlerfreien Einlesen von Zahlen

int main(void)
{
	double a, b, c, D, x1, x2, Re, Im;

	printf("Bitte geben Sie die Koeffizienten der quadratischen Gleichung a*x^2 + b*x + c = 0 ein!\n");
	a = einlesen('a');
	b = einlesen('b');
	c = einlesen('c');

	D = pow(b, 2) - 4 * a * c;	// Berechnen der Diskriminante D

	if (D >= 0)	// Diskriminante D ist positiv => 2 reelle Ergebnisse.
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);

		printf("x1 = %lf\n", x1);
		printf("x2 = %lf\n", x2);
	}
	else		// Diskriminante D ist negativ => 2 komplexe Ergebnisse.
	{
		Re = -b / (2 * a);
		Im = sqrt(abs(D)) / (2 * a);

		printf("x1 = %lf + %lfi\n", Re, Im);
		printf("x2 = %lf - %lfi\n", Re, Im);
	}
}

double einlesen(char koef)	// Funktion zum fehlerfreien Einlesen von Zahlen
{
	double num;		// Einzulesende Zahl
	int chk = 0;	// Rückgabewert zur Fehlermeldung von scanf_s

	do { // In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde.
		printf("%c = ", koef);
		chk = scanf_s("%lf", &num);
		while (getchar() != '\n');	// Tastaturpuffer leeren.
		if (chk == 0)	// Rückgabewert = 0 => scanf_s meldet, dass keine Zahl eingegeben wurde.
			printf("Bitte geben Sie eine Zahl ein!\n");
	} while (chk == 0);
	return num;
}