#include <kipr/wombat.h>

void drive(float left, float right, int mls)
{
    create_drive_direct(left, right);
    msleep(mls);
    create_stop();
}

int speed = 100;

int main()
{
    create_connect();
    
    while(get_create_rbump() == 0)
    {
        drive(speed, speed, 100);
        speed = speed + 50;
    }
    create_stop();
    speed = 100;
    
    drive(1000, -1000, 750);
    
    while(get_create_rbump() == 0)
    {
        create_drive_direct(speed, speed);
        speed = speed + 50;
    }
    create_stop();
    speed = 100;
    
    create_disconnect();
    
    return 0;
}