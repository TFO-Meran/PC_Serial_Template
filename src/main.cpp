// ****************************************************************************
// ****************************************************************************

//                     Vorlage für serielle Kommunikation

// ****************************************************************************
// ****************************************************************************

// Präprozessor-Anweisungen
#include <iostream>
#include <Windows.h>  // ..notwendig für Ausgabe der Umlaute unter Windows..
#include <ctime>      // ..notwendig für Zeit-Funktionen (Zufallsgenerator)..
#include <fstream>    // ..notwendig für Verwendung von Dateien..
#include <conio.h>    // ..notwendig für _kbhit()..
#include "serialib.h" // ..Plattformunabhängige serielle Kommunikation

using namespace std;

//=============================================================================
//                           MAIN
//=============================================================================

#define SERIAL_PORT "\\\\.\\COM6" // <---- Hier den seriellen Port angeben!!!
#define BAUDRATE 115200           // <---- Hier die Baudrate angeben!!!

int main(int, char **)
{
    srand((unsigned)time(0));    // ..Zufallsgenerator initialisieren..
    SetConsoleOutputCP(CP_UTF8); // ..notwendig für Ausgabe der Umlaute

    cout << "\nStart..." << endl;

    ofstream meineDatei; // Datei-Objekt instanzieren..
    string Dateiname;

    cout << "Gib einen Dateinamen ein: ";
    cin >> Dateiname;
    Dateiname = "..\\src\\" + Dateiname + ".csv";

    meineDatei.open(Dateiname);

    // Serial Objektinstanzierung
    serialib serial;

    // Connection to serial port
    char errorOpening = serial.openDevice(SERIAL_PORT, BAUDRATE);

    if (errorOpening != 1)
    {
        cout << "\n\n<Fehler beim öffnen des seriellen Ports..>\n\n";
        return errorOpening;
    }
    else
    {
        // Your Code here!!!
    }

    serial.closeDevice(); // Close the serial device
    meineDatei.close();   // Close file

    return 0;
}

//=============================================================================
//                           END OF FILE
//=============================================================================
