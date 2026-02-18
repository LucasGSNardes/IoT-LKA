# Projeto IoT – Internet of Things


---

## Desenvolvimento

---

## 👥 Autores


| <img loading="lazy" src="https://avatars.githubusercontent.com/u/255575500?v=4" width="115"><br><sub><a href="https://github.com/luclc13241">Lucas G. S. Nardes</a><br><span style="color:#00BFFF">💻 Desenvolvedor</span></sub> | <img loading="lazy" src="https://github.com/kauamdsouza.png" width="115"><br><sub><a href="https://github.com/kauamdsouza">Kaua M. De Souza</a><br><span style="color:#00BFFF">💻 Desenvolvedor</span></sub> | <img loading="lazy" src="https://avatars.githubusercontent.com/u/260971572?v=4" width="115"><br><sub><a href="https://github.com/AdrianEccel">Adrian Rebinski</a><br><span style="color:#00BFFF">🛵 Front-end</span></sub> | 
| :---: | :---: | :---: |

## Commit Leaderboard (últimos 30 dias)

| Rank | Commits | Author |
|------|---------|--------|
| 1 | 7 | Lucas Gabriel Da Silva Nardes |
| 2 | 6 | Kaua Martins De Souza |
| 3 | 1 | Adrian Rebinski |
---

## Overview

Este projeto consiste em um sistema de monitoramento de dados ambientais e de controle utilizando o microcontrolador ESP32. O sistema realiza a leitura de múltiplos sensores (analógicos e digitais) e envia as informações via protocolo MQTT para um fluxo no Node-RED. O objetivo final é o armazenamento e histórico desses dados em uma planilha do Google Sheets, garantindo uma gestão eficiente do banco de dados através de um script de limpeza automática que mantém apenas os últimos 100 registros.

---

## Funcionalidades

Monitoramento em Tempo Real: Coleta de temperatura, umidade, luminosidade e posição de potenciômetro.
Comunicação Eficiente: Uso do protocolo MQTT, ideal para dispositivos de baixo consumo e redes instáveis.
Armazenamento na Nuvem: Integração direta com Google Sheets para visualização remota.
Auto-Gerenciamento: Script integrado para evitar sobrecarga de dados na planilha (limite de 100 linhas).

---

### Ferramentas e Tecnologias

O projeto foi construído utilizando o seguinte ecossistema:
Hardware / Simulação

ESP32: Microcontrolador principal com Wi-Fi nativo.

Wokwi: Plataforma de simulação para validação do circuito e código.

Protoboard Física: Para implementação e testes em ambiente real.

### Sensores Utilizados
DHT22: Sensor digital de temperatura e umidade.

LDR (Light Dependent Resistor): Sensor analógico de luminosidade.

Potenciômetro: Componente analógico para simulação de controle de variáveis.

### Software e Protocolos
Arduino IDE: Ambiente de desenvolvimento para programação do ESP32 (C++).

Node-RED: Ferramenta de desenvolvimento baseada em fluxo (Low-code) para orquestração dos dados.

MQTT (Broker HiveMQ): Protocolo de transporte de mensagens.

Google Apps Script: Backend em JavaScript para receber requisições HTTP POST e manipular a planilha.



---

###Esquema de Ligação (Pinagem)
Componente
Pino ESP32
Tipo de Sinal
DHT22 (Dados)
GPIO 15
Digital
Potenciômetro
GPIO 34
Analógico (ADC)
LDR
GPIO 35
Analógico (ADC)
VCC
3.3V
Alimentação
GND
GND
Terra💻 Estrutura do Fluxo (Node-RED)
O fluxo no Node-RED segue a seguinte lógica:
MQTT In: Subscreve ao tópico meu_projeto/sensores no broker HiveMQ.
JSON Node: Converte o payload recebido (String) em um objeto JavaScript.
HTTP Request: Envia um método POST com os dados formatados para a URL do Google Apps Script.
📄 Como Usar
Planilha: Crie uma planilha no Google e adicione o script fornecido no repositório em Extensões > Apps Script.
Implantação: Publique o script como "App da Web" e configure o acesso para "Qualquer pessoa".
Node-RED: Importe o fluxo (JSON disponível na pasta /node-red) e configure a URL do seu App da Web no nó HTTP Request.
Hardware: Carregue o código (.ino) no seu ESP32, ajustando as credenciais de Wi-Fi.
```
