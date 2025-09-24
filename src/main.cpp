/*
*****************************************************************************
*  @file:      main.cpp
*  @brief:     ..
*  @author:    CG
*  Website:    https://...
*  Support:    ...
*  @todo:      ..test todo..
*****************************************************************************
*/

// ****************************************************************************
// ****************************************************************************

//                            DATEI-IO + Serielle Kommunikation

// ****************************************************************************
// ****************************************************************************

// Präprozessor-Anweisungen
#include <iostream>
#include <Windows.h> // ..notwendig für Ausgabe der Umlaute unter Windows..
#include <ctime>
#include <fstream>
#include <conio.h>    // ..notwendig für _kbhit()..
#include "serialib.h" // Plattformunabhängige serielle Kommunikation

using namespace std;

//=============================================================================
//                           MAIN
//=============================================================================

#define SERIAL_PORT "\\\\.\\COM6"

int main(int, char **)
{
    srand((unsigned)time(0));    // ..Zufallsgenerator initialisieren..
    SetConsoleOutputCP(CP_UTF8); // ..notwendig für Ausgabe der Umlaute

    cout << "\nStart..." << endl;

    while (true)
    {

        cout << "Was möchten Sie tun?" << endl;
        cout << "1 = Aufzeichnung starten" << endl;
        cout << "2 = Programm beenden" << endl;
        char choice;
        cin >> choice;

        if (choice == '2')
            break;

        ofstream meineDatei;
        string Dateiname;

        cout << "Gib einen Dateinamen ein: ";
        cin >> Dateiname;
        Dateiname = "..\\src\\" + Dateiname + ".csv";

        meineDatei.open(Dateiname);

        // Serial object
        serialib serial;

        // Connection to serial port
        char errorOpening = serial.openDevice(SERIAL_PORT, 115200);

        // If connection fails, return the error code otherwise, display a success message
        if (errorOpening != 1)
            return errorOpening;
        else
        {
            printf("Successful connection to %s\n", SERIAL_PORT);
            serial.writeChar('m');

            // Read incoming data from the serial device
            char buffer[80];

            cout << "\nDrücke eine beliebige Taste um zu beenden...\n"
                 << endl;
            while (!_kbhit())
            {
                int size = serial.readString(buffer, '\n', sizeof(buffer), 1000);
                cout << buffer;
                buffer[size - 1] = 0; // ..letztes Zeichen löschen..
                meineDatei << buffer; // ..Daten in die Datei schreiben..
            }
            serial.writeChar('s');
        }
        // Close the serial device
        serial.closeDevice();
        meineDatei.close();
    }

    return 0;
}

//=============================================================================
//                           END OF FILE
//=============================================================================
