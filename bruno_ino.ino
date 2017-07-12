int RLED = 2;
int GLED = 3;
int YLED = 4;
int BUZZ = 8;
int continua = 0;
int i;
int len;
String palavra;
String cripta;
String morse;

void setup(){

  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(YLED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  
  if(Serial.available()>0) {
    palavra = Serial.readString();
  }
  delay(500);
  len = palavra.length();

  if (len > 0){
    for (i=0; i<len; i++){
      alfabeto(palavra[i]);
    }
    if (i == len){
      digitalWrite(RLED, HIGH);
      digitalWrite(GLED, HIGH);
      digitalWrite(YLED, HIGH);
      delay(500);
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, LOW);
      digitalWrite(YLED, LOW);
      Serial.println("=====================================================================");
      Serial.print("Você digitou: ");
      Serial.print(palavra);
      Serial.print('\n');
      Serial.print("Codigo Morse: ");
      Serial.print(morse);
      Serial.print('\n'); 
      palavra = Serial.readString();
    }
  } 
}

void dot(){

  digitalWrite(RLED, HIGH); //Acende o LED Vermelho
  delay(500);
  digitalWrite(RLED, LOW);  //Desliga o LED Verde
  delay(500);

}

void dash(){

  digitalWrite(GLED, HIGH); //Acende o LED Verde
  delay(500);
  digitalWrite(GLED, LOW);  //Desliga o LED Verde
  delay(500);

}

void space(){
 
    digitalWrite(YLED, HIGH); //Acende o LED Amarelo
    delay(200);
    digitalWrite(YLED, LOW);  //LED Verde OFF
    delay(200);
  
}

void criptografa(char s){

  int i, j;
  char c; 
  
  i = s;
  if ((i >96) && (i<123)){

    if (i<110){
      j = i + 13;  
    }
    else{
      j = i - 13;
    }
    c = j;
    
  }
  else{
    c = i;
  }

  
}

void alfabeto(char v){

  switch(v){

    case 'a':

      morse.concat(".- ");
      dot();
      dash();
      space();
      break;

    case 'b':

      morse.concat("-... ");
      dash();
      dot();
      dot();
      dot();
      space();
      break;

    case 'c':

      morse.concat("-.-. ");
      dash();
      dot();
      dash();
      dot();
      space();
      break;

    case 'd':

      morse.concat("-.. ");
      dash();
      dot();
      dot();
      space();
      break;

    case 'e':

      morse.concat(". ");
      dot();
      space();
      break;

    case 'f':

      morse.concat("..-. ");
      dot();
      dot();
      dash();
      dot();
      space();
      break;

    case 'g':

      morse.concat("--. ");
      dash();
      dash();
      dot();
      space();
      break;

    case 'h':

      morse.concat(".... ");
      dot();
      dot();
      dot();
      dot();
      space();
      break;

    case 'i':

      morse.concat(".. ");
      dot();
      dot();
      space();
      break;

    case 'j':

      morse.concat(".--- ");
      dot();
      dash();
      dash();
      dash();
      space();
      break;

    case 'k':

      morse.concat("-.- ");
      dash();
      dot();
      dash();
      space();
      break;

    case 'l':

      morse.concat(".-.. ");
      dot();
      dash();
      dot();
      dot();
      space();
      break;

    case 'm':

      morse.concat("-- ");
      dash();
      dash();
      space();
      break;

    case 'n':

      morse.concat("-. ");
      dash();
      dot();
      space();
      break;

    case 'o':

      morse.concat("--- ");
      dash();
      dash();
      dash();
      space();
      break;
    
    case 'p':

      morse.concat(".--. ");
      dot();
      dash();
      dash();
      dot();
      space();
      break;

    case 'q':

      morse.concat("--.- ");
      dash();
      dash();
      dot();
      dash();
      space();
      break;

    case 'r':

      morse.concat(".-. ");
      dot();
      dash();
      dot();
      space();
      break;

    case 's':

      morse.concat("... ");
      dot();
      dot();
      dot();
      space();
      break;

    case 't':

      morse.concat("- ");
      dash();
      space();
      break;

    case 'u':

      morse.concat("..- ");
      dot();
      dot();
      dash();
      space();
      break;

    case 'v':

      morse.concat("...- ");
      dot();
      dot();
      dot();
      dash();
      space();
      break;

    case 'w':

      morse.concat(".-- ");
      dot();
      dash();
      dash();
      space();
      break;

    case 'x':

      morse.concat("-..- ");
      dash();
      dot();
      dot();
      dash();
      space();
      break;

    case 'y':

      morse.concat("-.-- ");
      dash();
      dot();
      dash();
      dash();
      space();
      break;

    case 'z':

      morse.concat("--.. ");
      dash();
      dash();
      dot();
      dot();
      space();
      break;

    case ' ':

      morse.concat(" / ");
      space();
      break;

    default:
      break;
          
  }

}
