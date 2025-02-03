#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matriz_leds.h"
#include <stdio.h>
#include <stdlib.h>

// Declaração de pinos
#define BOTAO_A 5
#define BOTAO_B 6
#define LED_VERMELHO 13
#define DEBOUNCE_TIME 200 // Tempo de debounce em milissegundos

int number = 0;                       // Numero para matriz
bool mudarMatriz = false;             // Flag para atualizar matriz no main
uint32_t tempo_botao_pressionado = 0; // Tempo de pressionamento do botão em ms

void setup_pins()
{
    // Configura os pinos
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);
}

void action(int key, PIO pio, uint sm)
{
    const RGB_cod red = {20, 0, 0};
    const RGB_cod blk = {0, 0, 0};
    if (key == 1)
    {
        Matriz_leds_config frame = {
            {blk, blk, red, blk, blk},
            {blk, red, red, blk, blk},
            {blk, blk, red, blk, blk},
            {blk, blk, red, blk, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 2)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, red, red, blk, blk},
            {blk, red, blk, blk, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 3)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, blk, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 4)
    {
        Matriz_leds_config frame = {
            {blk, red, blk, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, blk, blk, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 5)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, red, blk, blk, blk},
            {blk, red, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 6)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, red, blk, blk, blk},
            {blk, red, red, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 7)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, blk, blk, red, blk},
            {blk, blk, blk, red, blk},
            {blk, blk, blk, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 8)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, red, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 9)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, red, red, blk},
            {blk, blk, blk, red, blk},
            {blk, blk, blk, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
    else if (key == 0)
    {
        Matriz_leds_config frame = {
            {blk, red, red, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, blk, red, blk},
            {blk, red, red, red, blk}};
        imprimir_desenho(frame, pio, sm);
    }
}

void piscar_led()
{
    gpio_put(LED_VERMELHO, !gpio_get(LED_VERMELHO));
}

void proximoNumero()
{
    number = (number + 1) % 10;
}

void anteriorNumero()
{
    number = (number - 1 + 10) % 10;
}

void funcao_botao(uint gpio, uint32_t events)
{
    // O tempo de debounce serve para evitar que o botão seja pressionado muitas vezes seguidas
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    // Verifica se o botão foi pressionado novamente antes do tempo de debounce
    if (current_time - tempo_botao_pressionado < DEBOUNCE_TIME)
        return;

    if (gpio == BOTAO_A)
    {
        // Se o botão A foi pressionado, incrementa o número
        printf("Botão A pressionado, numero: %d\n", number);
        proximoNumero();
    }
    else if (gpio == BOTAO_B)
    {
        // Se o botão B foi pressionado, decrementa o número
        printf("Botão B pressionado, numero: %d\n", number);
        anteriorNumero();
    }

    tempo_botao_pressionado = current_time;
    mudarMatriz = true;
}

int main()
{
    // Configura a matriz
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);

    stdio_init_all();
    setup_pins();

    printf("Sistema Iniciado\n");

    // Configura a interrupção para ambos os botões
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &funcao_botao);
    gpio_set_irq_enabled(BOTAO_B, GPIO_IRQ_EDGE_FALL, true);

    action(0, pio, sm);

    while (true)
    {
        // Uma flag para mudar a matriz uma unica vez quando o botão for acionado
        if (mudarMatriz)
        {
            mudarMatriz = false;
            action(number, pio, sm);
        }
        piscar_led();
        sleep_ms(100);
    }

    return 0;
}
