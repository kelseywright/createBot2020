#include <kipr/wombat.h>

int speed = 100;

void drive(float left, float right, int mls)
{
    create_drive_direct(left, right);
    msleep(mls);
    create_stop();
}
void speedIncrease(float left, float right, int mls, int speedUp)
{
    create_drive_direct(left, right);
    msleep(mls);
    speed = speed + speedUp;
    create_stop();
}

int main()
{
	create_connect();
    int x = 1;
    while(x==1)
    {
        drive(speed, speed, 100);
	    speed = speed + 10;
		create_stop();
    	if(get_create_rbump()==1)
        {
        	create_stop();
            while(get_create_rbump()==1)
            {
            	speedIncrease(-speed, speed, 100, 10);
            	create_stop();
            }
            create_stop();
        }
        else if(get_create_lbump()==1)
        {
            create_stop();
            while(get_create_lbump()==1)
            {
            	speedIncrease(speed, -speed, 100, 10);
            	create_stop();
            }
        }
        else if(get_create_lbump()==1&&get_create_rbump()==1)
        {
            speedIncrease(1000,-1000, 750, 10);
            create_stop();
        }
        if(speed>1000)
        {
            speed = 1000;
        }
	}
    create_disconnect();
    return 0;
}