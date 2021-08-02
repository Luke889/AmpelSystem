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
    pinMode (AMPEL1ROT, OUTPUT);
    pinMode (AMPEL1GELB, OUTPUT);
    pinMode (AMPEL1GRUEN, OUTPUT);
    pinMode (AMPEL2ROT, OUTPUT);
    pinMode (AMPEL2GELB, OUTPUT);
    pinMode (AMPEL2GRUEN, OUTPUT);
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
     setzeAmpel (1, ROT);
     setzeAmpel (2, ROT);
     Timer = millis() + 2000;
     Phase++;               //Weiterschaltung der Ampelphase
    break;

    case 1: //Ampel 1 rotgelb
     setzeAmpel1 (1, ROTGELB);
     Timer = millis () + 1000;
     Phase++;
    break;

    case 2: //Ampel 1 grün
     setzeAmpel (1, GRUEN);
     Timer = millis() + 8000;
     Phase++;
    break;

    case 3: //Ampel 1 Gelb
     setzeAmpel (1, GELB);
     Timer = millis() + 2000;
     Phase++;
    break;

    case 4: //Beide Ampeln rot
     setzeAmpel (1, ROT);
     Timer = millis() + 2000;
     Phase++;
    break;

    case 5: //Ampel 2 Grün
     setzeAmpel (2, GRUEN);
     Timer = millis() + 2000;
     Phase++;
    break;

    case 6: //Ampel 2 gelb 
     setzeAmpel (2, GELB);
     Timer = millis() + 2000;
     Phase = 0;   //nache Phase 7 beginnt Zyklus von vorn
    break;

    case 10: //beide Ampeln gelb
     setzeAmpel (1, GELB);
     setzeAmpel (2, GELB);
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
        rotPin = AMPEL1ROT;
        gelbPin = AMPEL1GELB;
        gruenPin = AMPEL1GRUEN;
    }
    if(Ampelnummer == 2)
    {
        rotPin = AMPEL1ROT;
        gelbPin = AMPEL1GELB;
        gruenPin = AMPEL1GRUEN;
    }

    switch (Zustand)
    {
        case AUS:
         digitalWrite(rotPin, LOW);
         digitalWrite(gelbPin, LOW);
         digitalWrite(gruenPin, LOW);
        break;
        case GRUEN:
         digitalWrite(rotPin, LOW);
         digitalWrite(gelbPin, LOW);
         digitalWrite(gruenPin, HIGH);
        break;
        case GELB:
         digitalWrite(rotPin, LOW);
         digitalWrite(gelbPin, HIGH);
         digitalWrite(gruenPin, LOW);
        break;
        case ROTGELB:
         digitalWrite(rotPin, HIGH);
         digitalWrite(gelbPin, HIGH);
         digitalWrite(gruenPin, LOW);
        break;
        case ROT: default:
         digitalWrite(rotPin, HIGH;
         digitalWrite(gelbPin, LOW);
         digitalWrite(gruenPin, LOW);
        break;
    }
}
  



