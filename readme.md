# Controle de Matriz de LEDs 5x5 WS2812 com Botões

## Descrição

Este projeto utiliza a placa BitDogLab com um microcontrolador RP2040 integrado na Raspberry Pi Pico W para controlar uma matriz de LEDs WS2812 e um LED RGB por meio de dois botões. O sistema exibe números na matriz e permite a sua alteração através dos botões. Os componentes utilizados são:

1. **Matriz 5x5 de LEDs WS2812** - Conectada à GPIO 7.
2. **LED RGB** - Com pinos conectados às GPIOs 11 (vermelho), 12 (verde) e 13 (azul).
3. **Botão A** - Conectado à GPIO 5.
4. **Botão B** - Conectado à GPIO 6.

## Funcionalidades

- O LED vermelho do LED RGB pisca continuamente 5 vezes por segundo.
- O Botão A incrementa o número exibido na matriz de LEDs a cada pressão.
- O Botão B decrementa o número exibido na matriz de LEDs a cada pressão.
- A matriz de LEDs WS2812 exibe os números de **0 a 9** em um formato fixo ou criativo, garantindo clareza na identificação dos caracteres.

## Demonstração (VÍDEO)

[Vídeo de Demonstração](https://youtube.com/shorts/5AZ3WJBEfeg)

## Como compilar e executar

1. Configure o ambiente de desenvolvimento para o Raspberry Pi Pico W.
2. Compile o código utilizando um compilador C compatível para gerar os arquivos `.uf2` e `.elf`.
3. Execute o simulador Wokwi clicando no arquivo `diagram.json` e pressione "Play" para testar as funcionalidades.

## Requisitos

- Compilador C (gcc ou equivalente).
- Sistema operacional compatível com programas C.
- Extensão Raspberry Pi Pico.
- Wokwi configurado no VS Code.

## Desenvolvedores

Equipe 2 - Grupo 3 - EmbarcaTech

- [Luiz Marcelo](https://github.com/devluinix/Tarefa_WLS_U4CAO1)
