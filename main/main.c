#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

// Define GPIO pins for the 7-segment display segments
#define WHITE_L GPIO_NUM_23
#define GREEN_L GPIO_NUM_22
#define YELLOW_L GPIO_NUM_21
#define RED_L GPIO_NUM_19
#define RED_R GPIO_NUM_18
#define YELLOW_R GPIO_NUM_5
#define GREEN_R GPIO_NUM_4
#define WHITE_R GPIO_NUM_15

const gpio_num_t diods[8] = {WHITE_L, GREEN_L, YELLOW_L, RED_L, RED_R, YELLOW_R, GREEN_R, WHITE_R};

void board_config()
{
    for (int i = 0; i < 8; i++) {
        gpio_reset_pin(diods[i]);
        gpio_set_direction(diods[i], GPIO_MODE_OUTPUT);
    }
}

void night_rider_left_to_right() {
    for (int i = 0; i < 8; i++) {
        gpio_set_level(diods[i], 1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(diods[i], 0);
    }
}

void night_rider_right_to_left() {
    for (int i = 7; i >= 0; i--) {
        gpio_set_level(diods[i], 1);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_level(diods[i], 0);
    }
}

void app_main(void) {
    board_config();

    while (1) {
        night_rider_left_to_right();
        // vTaskDelay(1000 / portTICK_PERIOD_MS); 
        night_rider_right_to_left();
        // vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
