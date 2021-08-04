#define AMPEL1RED 6  //Die Pins der einzelnen LEDs und der Taste 
                     //werden zur
#define AMPELYELLOW 5 //besseren Übersicht als Konstantennamen
                     //angelegt
#define AMPEL1GREEN 4
#define AMPEL2RED 10
#define AMPEL2YELLOW 9
#define AMPEL2GREEN 8

#define TASTE 2

#define AUS 0       //Hier werden Zahlen vereinabrt,
                    //welche ein
#define ROT 1       //bestimmtes Lichtzeichen
                    //darstellen sollen.
#define ROTGELB 2   //Wir verwenden sie später im Zusammenhang
#define GRUEN 3     //mit der Funktion setzeAmpel1().
#define GELB 4

long Timer = 0;     //dient der Zeitmessung
byte Phase = 0;     //repräsentiert die aktuelle Ampelphase 

void setup() {
    pinMode (AMPEL1RED, OUTPUT);
    pinMode (AMPEL1YELLOW, OUTPUT);
    pinMode (AMPEL1GREEN, OUTPUT);
    pinMode (AMPEL2RED, OUTPUT);
    pinMode (AMPEL2YELLOW, OUTPUT);
    pinMode (AMPEL2GREEN, OUTPUT);
    pinMode (TASTE, INPUT_PULLUP);
}

void loop() {

    while(millis() < Timer)
    {
        if(!digitalRead(TASTE))  //Wird die Taste betätigt?
        {                        //falls ja -> Betriebsmodus
                                 //umschalten:
                                 //Befinden wir uns gerade im Normalen 
                                 //Betrieb?
             if(Phase < 10)      //ja -> auf gelbes Blinken schalten
                                 //else
               Phase = 10);      //nein -> den normalen Betrieb
                                 //starten
               Phase = 0;

   
            Timer = 0;           //Timer zurücksetzen, damit
                                 //übergeordnete
                                 //while-Schleife verlassen wird.

            while(!digitalRead(TASTE));
        }
    }
}


switch (Phase)                   
{
    case 0: //Beide Ampeln rot
     setzeAmpel (1, RED);
     setzeAmpel (2, RED);
     Timer = millis() + 2000;
     Phase++;               //Weiterschaltung der Ampelphase
    break;

    case 1: //Ampel 1 rotgelb
     setzeAmpel1 (1, REDYELLLOW);
     Timer = millis () + 1000;
     Phase++;
    break;

    case 2: //Ampel 1 grün
     setzeAmpel (1, GREEN);
     Timer = millis() + 8000;
     Phase++;
    break;

    case 3: //Ampel 1 Gelb
     setzeAmpel (1, YELLOW);
     Timer = millis() + 2000;
     Phase++;
    break;

    case 4: //Beide Ampeln rot
     setzeAmpel (1, RED);
     Timer = millis() + 2000;
     Phase++;
    break;

    case 5: //Ampel 2 Grün
     setzeAmpel (2, GREEN);
     Timer = millis() + 2000;
     Phase++;
    break;

    case 6: //Ampel 2 gelb 
     setzeAmpel (2, YELLOW);
     Timer = millis() + 2000;
     Phase = 0;   //nache Phase 7 beginnt Zyklus von vorn
    break;

    case 10: //beide Ampeln gelb
     setzeAmpel (1, YELLOW);
     setzeAmpel (2, YELLOW);
     Timer = millis() + 1000;
     Phase = 11;  //Phase 10 und 11 wechseln einander ab 
    break;        //und erzeugen so das gelbe Blinken

    case 11: default: //beide Ampeln aus
     setzeAmpel (1, AUS);
     setzeAmpel (2, AUS);
     Timer = millis() + 1000;
     Phase = 10;
    break;

  }

}

void setzeAmpel (byte Ampelnummer, byte Zustand)
{
    byte rotPin = 0; byte gelbPin = 0; byte gruenPin
    
    if(Ampelnummer == 1)
    {
        rotPin = AMPEL1RED;
        gelbPin = AMPEL1YELLOW;
        gruenPin = AMPEL1GREEN;
    }
    if(Ampelnummer == 2)
    {
        rotPin = AMPEL1RED;
        gelbPin = AMPEL1YELLOW;
        gruenPin = AMPEL1GREEN;
    }

    switch (Zustand)
    {
        case AUS:
         digitalWrite(redPin, LOW);
         digitalWrite(yellowPin, LOW);
         digitalWrite(greenPin, LOW);
        break;
        case GRUEN:
         digitalWrite(redPin, LOW);
         digitalWrite(yellowPin, LOW);
         digitalWrite(greenPin, HIGH);
        break;
        case GELB:
         digitalWrite(redPin, LOW);
         digitalWrite(yellowPin, HIGH);
         digitalWrite(greenPin, LOW);
        break;
        case ROTGELB:
         digitalWrite(redPin, HIGH);
         digitalWrite(yellowPin, HIGH);
         digitalWrite(greenPin, LOW);
        break;
        case ROT: default:
         digitalWrite(redPin, HIGH;
         digitalWrite(yellowPin, LOW);
         digitalWrite(greenPin, LOW);
        break;
    }
}
  



