#include <iostream>
#include "functions.h"
#include <fstream>

using namespace std;

struct clientData {   // piemers no majasdarba
    int accNum;
    char Sur[15];
    char Name[10];
    float balance;
};

int main()
{
  	int k;
   	fstream fails;
	
	int i = 0;   // mainigais prieks operacijam
	
	while (i != 8)    // cikls, lai atkartotu visas operacijas, kamer user neospiez 8, lai iziety
	{
		
		// interfeis prieks user
		cout 	<< "1      Pievienot ierakstu" << endl <<
				 "----------------------------------------------------------------------------------------------------------------------" << endl <<
				
            	 "2      Dzest ierakstu" << endl <<
            	"----------------------------------------------------------------------------------------------------------------------" << endl <<
            	
				"3      Izvadit visus ierakstus (tikai tos kuri eksiste)" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl <<
				
				"4      Atrast ierakstu (pec konta numura)" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl <<
				
				"5      Izmainit konta balansu (ievadot konta numuru, un pozitivo vai negativo vertibu, kas japiesumme esosai summai)" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl <<
				
				"6      Izvadit paradniekus (jaizvada visi ieraksti ar negativo balansu)" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl <<
				
				"7      Saskaitit ierakstus (izvadit esosu ierakstu skaitu)" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl <<
				
				"8      Iziet (izeja no programmas)" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl <<   
				
				"9      Restartet datu bazi" << endl <<
				"----------------------------------------------------------------------------------------------------------------------" << endl; 
    
    cin >> i;    // user ievada operaciju

// Operacijas.  Atkariba no ta, ko user ievada - tas tiek izpildits
// Visas funkcijas ir aprakstitas atseviska functions.cpp fails
    if(i == 1)
    
		Pievienot_ierakstu ();   
		
	else if(i == 2)
	
		Dzest_ierakstu ();
		
	else if(i == 3)
	
		Izvadit_visus_ierakstus ();
		



// ------------------ Izeja no programmas -------------------------
	else if(i == 8)
	
		break;
// ------------------ Izeja no programmas -------------------------
		
	else if (i == 9)
	
		Restartet_datu_bazi ();
			
	else  // ja user ievada pavisam citu skaitli
		cout << "Operacija neeksiste" << endl <<
		"----------------------------------------------------------------------------------------------------------------------" << endl; 
	}
	
 
	
    system("pause");
    
    return 0;
}
