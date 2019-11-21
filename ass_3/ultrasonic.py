import brick
import motor
import time

def us_read():
    return brick.BP.get_sensor(BP.PORT_3)

def us_read(degrees):
    motor.us_rotate(degrees)
    return us_read()
