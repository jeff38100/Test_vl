// -----------------------------
// the setup routine runs once when you press reset:
void setup() {
    //Initialisation des pin d'E/S.
            pinMode(led, OUTPUT);
            pinMode(bp1_up, INPUT);
            pinMode(bp1_down, INPUT);
            pinMode(led1_up, OUTPUT);
            pinMode(led1_down, OUTPUT);
            pinMode(switch_1, INPUT);
            pinMode(switch_2, INPUT);
            pinMode(switch_3, INPUT);

    //Initialisation du serial
            Serial.begin(9600);                   //Activation de la liaison serie
            
            for (int i=0; i <= 10; i++){          //Saut de 10 ligne pour nettoyer la console au demarrage
                  Serial.println("");
            }
            Serial.println("=================");
            Serial.println("NOUVEAU DEMARRAGE");
            Serial.println("=================");
            Serial.println("");
           

            

    //Mise à zero des sorties au demarrage
            raz_output();
    

    //Passage du volet en condition initiale (position basse)
            raz_position_volets();
    
    //Determination du volet roulant
            deep_switch();
    
    //Gestion des interrupts sur les entrée BP.
          attachInterrupt (digitalPinToInterrupt(bp1_up), comptage_bp_up, RISING);      //Appel de la fonction sur front descendant du BP UP
          attachInterrupt (digitalPinToInterrupt(bp1_down), comptage_bp_down, RISING);  //Appel de la fonction sur front descendant du BP DOWN
  
  
    //Calcul du nombre de millis pour atteindre 1%
          millis_pour_un_pourcent = interval_course_totale_volet/100;   // Temps de manoeuvre totale d'un volet divisée/100
          //Serial.print ("millis_pour_un_pourcent:   ");
          //Serial.println (millis_pour_un_pourcent);


          timeElapsed_decalage_arret_volet = 0;

  
  Serial.println ("");
  Serial.println ("##################################");
  Serial.println ("DEBUT DU PROGRAMME");
  Serial.println ("");
  
  }
//Fin du setup
// -----------------------------
  
