#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

const gpio_num_t A = GPIO_NUM_4;
const gpio_num_t B = GPIO_NUM_5;
const gpio_num_t C = GPIO_NUM_18;
const gpio_num_t D = GPIO_NUM_19;
const gpio_num_t E = GPIO_NUM_21;
const gpio_num_t F = GPIO_NUM_22;
const gpio_num_t G = GPIO_NUM_23;

const gpio_num_t BUTTON_change = GPIO_NUM_15;

const TickType_t TIME_WAITING = 1000;

void board_config()
{
    gpio_reset_pin(A);
    gpio_reset_pin(B);
    gpio_reset_pin(C);
    gpio_reset_pin(D);
    gpio_reset_pin(E);
    gpio_reset_pin(F);
    gpio_reset_pin(G);
    gpio_reset_pin(BUTTON_change);

    gpio_set_direction(A, GPIO_MODE_OUTPUT);
    gpio_set_direction(B, GPIO_MODE_OUTPUT);
    gpio_set_direction(C, GPIO_MODE_OUTPUT);
    gpio_set_direction(D, GPIO_MODE_OUTPUT);
    gpio_set_direction(E, GPIO_MODE_OUTPUT);
    gpio_set_direction(F, GPIO_MODE_OUTPUT);
    gpio_set_direction(G, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_change, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUTTON_change, GPIO_PULLUP_ONLY);
}

bool is_button_pressed()
{
    return (gpio_get_level(BUTTON_change) == 0);
}

void fullLight()
{
    gpio_set_level(A, 1);
    gpio_set_level(B, 1);
    gpio_set_level(C, 1);
    gpio_set_level(D, 1);
    gpio_set_level(E, 1);
    gpio_set_level(F, 1);
    gpio_set_level(G, 1);
}

void fullLightNo()
{
    gpio_set_level(A, 0);
    gpio_set_level(B, 0);
    gpio_set_level(C, 0);
    gpio_set_level(D, 0);
    gpio_set_level(E, 0);
    gpio_set_level(F, 0);
    gpio_set_level(G, 0);
}

void app_main(void)
{
    board_config();

    if(gpio_get_level(BUTTON_change) == 1){
        fullLight();
    }
    else{
        fullLightNo();
    }
}