#include <stdio.h>
#include "request.h"
#include <wiringPi.h>
#include "io.c"

int R_Direction;

// 赤、黄色、緑のLED用のピン番号
#define PIN_LED_R 10
#define PIN_LED_Y 10
#define PIN_LED_G 10

void mode_select(){
    int mode;
    printf("北コースの場合は「0」を南コースの場合は「1」を入力して下さい\n");
    scanf("%d", &mode);

    switch(mode){
        case 0:
            R_Direction = (1);
            break;
        case 1:
            R_Direction = (-1);
            break;
        default:
            mode_select();
            break;
    }
}

void run(int speed_, int dist_){
    //int speed = speed, dist = dist;
    run_state_t state;
    request_set_runmode(STR, speed, dist);
    while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
    }
}

void rotate(int speed, int angle){
    //int speed = speed, dist = R_Direction * angle;
    request_set_runmode(ROT, speed, R_Direction * angle);
    while(1){
        request_get_runmode(&state, &speed, &angle);
        if( state == STP ) break;
    }
}

int get_number(int dist) {
    int ans[NUM_LEN];

    number_detect(dist);
    number_get(ans);

    if(
        (ans[0] == 3) ||
        (ans[0] == 4) ||
        (ans[0] == 5)
        ){
        return ans[0];
    }
    return -1;
}

void led_on(int u_num){
    io_open();

    pinMode(PIN_LED_R, OUTPUT);
    pinMode(PIN_LED_Y, OUTPUT);
    pinMode(PIN_LED_G, OUTPUT);

    switch(u_num){
        case 3:
            digitalWrite(PIN_LED_R, HIGH);
            break;
        case 4:
            digitalWrite(PIN_LED_Y, HIGH);
            break;
        case 5:
            digitalWrite(PIN_LED_G, HIGH);
            break;
        default:
            break;
    }
}
