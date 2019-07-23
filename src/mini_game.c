#include <stdio.h>
#include "arduino.h"
#include "mini_game_function.h"

#define S199 50 // Run Speed[cm/s] for less than 199[cm]
#define S200 70 // Run Speed[cm/s] for 200[cm] or more
#define RS18 50 // Rotation Speed[deg/s] for 180[deg]
#define RS90 50 // Rotation Speed[deg/s] for 90[deg]
#define RS45 30 // Rotation Speed[deg/s] for 45[deg]

int main(){
    if(arduino_open() != 0) return -1;

    mode_select();

    run(S200, 300);
    rotate(RS90, 90);
    run(S200, 350);
    rotate(RS45, 45);
    run(S200, 212);
    rotate(RS45, 45);
    run(S199, 150);

    int u_num = get_number(75); // Uターンエリアの数字を格納
    led_on(u_num);

    rotate(RS18, 180);
    run(S200, 250);
    rotate(RS45, -45);
    run(S199, 71);
    rotate(RS45, -45);
    run(S200, 350);
    rotate(RS90, -90);

    switch(u_num){
        case 3:
            run(S199, 100);
            break;
        case 4:
            run(S200, 200);
            break;
        case 5:
            run(S200, 300);
            break;
        default:
            break;
    }

    arduino_close();
    return 0;
}

