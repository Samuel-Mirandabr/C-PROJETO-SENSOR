#include <Arduino.h>

// --- Definindo os pinos do L298N ---
int IN1 = 5;
int IN2 = 6;
int IN3 = 9;
int IN4 = 10;

char comando; // variável que guarda o comando recebido

// --- Funções de movimento ---

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void re() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void direita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void esquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// --- Configuração inicial (roda uma vez) ---
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600); // inicia comunicação (Bluetooth usa isso)
  Serial.println("Carro pronto!");
}

// --- Loop principal (roda infinitamente) ---
void loop() {
  if (Serial.available()) {        // se chegou algum comando
    comando = Serial.read();       // lê o comando

    if (comando == 'F') frente();
    else if (comando == 'B') re();
    else if (comando == 'R') direita();
    else if (comando == 'L') esquerda();
    else if (comando == 'S') parar();
  }
}