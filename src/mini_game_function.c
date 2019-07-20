#include <stdio.h>
#include "request.h"

static int R_Direction;

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

void run(int speed, int dist){
    int speed = speed, dist = dist;
    run_state_t state;
    request_set_runmode(STR, speed, dist);
    while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
    }
}

void rotate(int speed, int angle){
    int speed = speed, dist = R_Direction * angle;
    request_set_runmode(ROT, speed, dist);
    while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
    }
}

int get_number(int dist) {
    return 3;
}

void led_on(int u_num){
}
