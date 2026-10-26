#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;
LiquidCrystal_I2C lcd (0x27, 20, 4);

String nome;
int idade;
bool habilitado;

unsigned long intervalo = 2000;
unsigned long tempoAnterior = 0;

JsonDocument doc;

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(5000);
    // lcd.init();
    // lcd.backlight();
    

    if (BT.begin("BtSlaveGi"))
    {
        Serial.println("Bluetooth iniciado com sucesso");
        Serial.print("Endereco bluetooth: ");
        Serial.println(BT.getBtAddressString());
    }
    else
    {
        Serial.println("Erro ao iniciar o bluetooth");
    }


}

void loop() {
    //EX. 1
    // unsigned long tempoAtual = millis();

    // if (BT.available()) //verifica se tem info no bt e mostra na serial
    // {

        

    //     String mensagem = BT.readStringUntil('\n');
    //     mensagem.trim();

    //     DeserializationError erro = deserializeJson(doc, mensagem);

    //     if (erro)
    //     {
    //         Serial.println("Erro ao interpretar o JSON");
    //         Serial.println(erro.c_str());
    //     }
    //     else
    //     {
    //         float temperatura = doc["temp"];
    //         float umidade = doc["umi"];


    //         if(tempoAtual - tempoAnterior >= intervalo){

    //             lcd.clear();
    //             lcd.setCursor(0,0);
    //             lcd.print("Temp C: " + String(temperatura));
    //             lcd.setCursor(0,1);
    //             lcd.print("Umi: " + String(umidade));

    //             tempoAnterior = tempoAtual;

    //         }
    //     }
    // }
    
    Serial.println("Digite seu nome: ");
    if (Serial.available()){
    
        String nomeEnviado = Serial.readStringUntil('\n');
        nomeEnviado.trim();
        doc["nome"] = nomeEnviado;
    }

    if (Serial.available()){
    
        String idadeEnviada = Serial.readStringUntil('\n');
        idadeEnviada.trim();
        doc["idade"] = idadeEnviada;
    }

    Serial.println("Habilitado? (S/N)");
    if (Serial.available()){
    
        String habilitadoEnviado = Serial.readStringUntil('\n');
        habilitadoEnviado.trim();
        doc["habilitado"] = habilitadoEnviado;
    }
       

       


        serializeJsonPretty(doc, mensagemEnviada);

        BT.println(mensagemEnviada);


}

