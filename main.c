#include <kipr/botball.h>
int rm=0;
int lm=3;
int claw=1;
int arm=4;
int back=3;
int claw_close=700;
int back_close=200;
int claw_up=589; 
void counter(int dis);
void starting_position();
int main()
{
    printf("Hello World\n");
    enable_servos();
    //starting positions
   starting_position();
    
    //outward from startbox
    mrp(rm,-1000,-1300);
    mrp(lm,-1000,-1300);
    bmd(rm);
    bmd(lm);
    
    //grab water reclamation unit
    set_servo_position(back,back_close);
    msleep(400);
    
    
    // forward then turn after water reclamation 
    counter(1500);

    mrp(rm,1000,1300);
    mrp(lm,-1000,-1300);
    bmd(rm);
    bmd(lm);
    
    //go foward till black
    
    
    
    disable_servos();
    return 0;
}
//starting positions
void starting_position()
{
    set_servo_position(claw,claw_up);
    msleep(400);
}
// certain distance in ticks/cm
void counter(int dis)
{
    clear_motor_position_counter(rm);
    while(get_motor_position_counter(rm)<dis)
    {
    mrp(rm,1000,3000);
    mrp(lm,1000,3000);
    }
    bmd(rm);
    bmd(lm);
}

