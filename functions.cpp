#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


struct clientData {
    int accNum;
    char Sur[15];
    char Name[10];
    float balance;
};

clientData data[100]; // kopa simts ieraksti

	clientData client;
   	fstream fails; 


// ----------------------------- Funkcija ieraksta pievienosanai -------------------------

void Pievienot_ierakstu ()  

{
	cout << "1      Pievienot ierakstu" << endl <<
			"----------------------------------------------------------------------------------------------------------------------" << endl;

   
	fails.open("credit.dat", ios::out | ios::in | ios::binary);  
   	cout << "Enter account number (1 to 100, 0 to end input)" << endl;
   	cin >> client.accNum;
   	while (client.accNum != 0)
   {
      cout << "Enter lastname, firstname, balance" << endl;
      cin >> client.Sur >> client.Name >> client.balance;
      fails.seekp((client.accNum-1) * sizeof(clientData), ios::beg);
      fails.write((char*)&client, sizeof(clientData));
      cout << "Enter account number" << endl;
      cin >> client.accNum;
   }
   
   fails.close();
	
	
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
}

void Dzest_ierakstu ()
{
	cout << "2      Dzest ierakstu" << endl <<
            "----------------------------------------------------------------------------------------------------------------------" << endl;       
            
	cout << "Ievadiet konta Nr., kuru velaties dzest" << endl;
   int i;
   int k = 0;
   
   fails.open("credit.dat", ios::out | ios::in | ios::binary);  
   cin >> i;  


   fails.read((char*)&client, sizeof(client));
   while ((client.accNum = i) && fails)
   {      
       fails.read((char*)&client, sizeof(client));
   }
   fails.seekp(-sizeof(clientData), ios::cur);
   (client.accNum = k);
   fails.write((char*)&client, sizeof(client));
   
   fails.close();

	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
	
	
}

void Izvadit_visus_ierakstus ()  

{
	cout <<	"3      Izvadit visus ierakstus (tikai tos kuri eksiste)" << endl <<
			"----------------------------------------------------------------------------------------------------------------------" << endl;
				
	   fails.open("credit.dat", ios::in | ios::binary);  
     
   cout << setw(10) << "Account" << setw(10) << "Surname"  << setw(10) << "Name" << setw(10) << "Ballance" << endl;
   fails.read((char*)&client, sizeof(clientData));
   while(fails)
   {      
       if (client.accNum !=0)
			cout << setw(10) << client.accNum << setw(10) << client.Sur << setw(10) << client.Name << setw(10) << client.balance << endl; 
       fails.read((char*)&client, sizeof(clientData));
   } 
   
   fails.close();
		
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
}

void Restartet_datu_bazi ()
{
	int k;
	clientData blankClient = {0, "", "", 0.0};
   
   fails.open("credit.dat", ios::out | ios::binary);  
   for (k=1; k<=100; k++)
    fails.write((char*)&blankClient, sizeof(clientData));
   
   fails.close();
}
