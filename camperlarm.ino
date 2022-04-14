
//Input pin configuration
#define RESET_PIN 1
#define STATUS_PIN 2
#define SELECT_PIN 3
#define ENCODER_PIN 4
#define BUZZER_PIN 5

//Output pin configuration
#define FRONT_STATUS_LED_PIN 6
#define BACK_STATUS_LED_PIN 7
#define LEFT_STATUS_LED_PIN 8
#define RIGHT_STATUS_LED_PIN 9

//Shift register pin configuration
#define CLOCK_PIN 10
#define LOAD_PIN 11
#define DATA_PIN 12


//Variables globales
boolean activeSensors[4] = {true, true, true, true};
boolean activeAlarms[4] = {false, false, false, false};
boolean isAlarmActive;
boolean viewStatus;
int statusTimer;
boolean programmingMode;
int sensorTrigger[4] = {100, 100, 100, 100};
int sensorCount = 4;
boolean programmedStatus[4] = {false, false, false, false};

void setup() {
  // Configuramos pines de entrada/salida
  pinMode(RESET_PIN, INPUT);
  pinMode(STATUS_PIN, INPUT);
  pinMode(SELECT_PIN, INPUT);
  pinMode(ENCODER_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  //Configuramos pines de salida led
  pinMode(FRONT_STATUS_LED_PIN, OUTPUT);
  pinMode(BACK_STATUS_LED_PIN, OUTPUT);
  pinMode(LEFT_STATUS_LED_PIN, OUTPUT);
  pinMode(RIGHT_STATUS_LED_PIN, OUTPUT);

  //Configuramos pines de comunicacion con el shift register
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LOAD_PIN, OUTPUT);
  pinMode(DATA_PIN, INPUT);

  //Inicializamos variables
  isAlarmActive = false;
  viewStatus = false;
  statusTimer = 10000;
  programmingMode = false;


}


/*
 * Funcion que resetea las alarmas
 */
void resetAlarms() {
  activeAlarms[0] = false;
  activeAlarms[1] = false;
  activeAlarms[2] = false;
  activeAlarms[3] = false;
  isAlarmActive = false;
}


/*
 * Funcion que comprueba si se ha pulsado reset y en caso afirmativo resetea
 */
void checkReset() {
  if(digitalRead(RESET_PIN)){
    resetAlarms();
  }
}

/*
 * Funcion que comprueba si se debe activar la visualizacion de status
 */
void checkStatus() {
  if(digitalRead(STATUS_PIN) || isAlarmActive){
    viewStatus = true;
    statusTimer = 10000;
  }
}

//Funcion que lee el valor de un sensor
int readSensor(int sensor){
  
}

//Funcion que comprueba si algun sensor detecta algo dentro de su rango
void checkSensors() {
  for (int i = 0; i <= 3; i++){
    if(activeSensors[i]){
      if (readSensor(i) <= sensorTrigger[i]){
        isAlarmActive = true;
        activeAlarms[i] = true;
      }
    }
  }
}

//Funcion que lee del shift register el estado de los switches de configuracion
void updateSwitches() {
  
}

//Funcion que comprueba si se ha pulsado el boton de programacion
boolean checkProgrammingMode() {
  if (digitalRead(SELECT_PIN)){
    programmingMode = true;    
  }
}

//Funcion que comprueba un sensor
void checkSensor (int sensor){
  
}

//Funcion que ilumina el estado de programacion de los sensores
void showProgrammingStatus(){

  
}

//Funcion que hace parpadear un led
void blinkLed(int led){
  
}

//Funcion que lee el movimiento de la rueda
int leerRueda (int encoder){
  
}

//Funcion que controla la programacion
void alarmProgramming(){
  int currentSensor = 0;
  while (programmingMode && currentSensor < sensorCount){
    while (!digitalRead(SELECT_PIN)){
      blinkLed(currentSensor);
      sensorTrigger[currentSensor] = sensorTrigger[currentSensor] + leerRueda(ENCODER_PIN);
      checkSensor(currentSensor);
    }
    programmedStatus[currentSensor] = true;
    currentSensor++;
    
    if(currentSensor >= sensorCount){
      programmingMode = false;
    }
    showProgrammingStatus();
    
    
  }





  
}
void loop() {
    
  checkSensors();

  updateSwitches();
  
  checkReset();
  checkStatus();

  if (checkProgrammingMode()){
    alarmProgramming();
  }


    /*
     * Bucle de programacion
     */

     /*
      * Comprobar pulsación boton PROG y programando = 0
      * si->
      *     todos los leds en rojo
      *     programando ++
      *     sensor activo parpadea en rojo
      *     mientras (!botonPROG)
      *        leerValor
      *        guardarValorAux
      *     fijarValor
      *     sensor activo led fijo verde
      *     progamando ++;
      *     
      * programando = 0
      */





















      

}
