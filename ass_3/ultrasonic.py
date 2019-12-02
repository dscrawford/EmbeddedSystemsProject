import brick
import motor
import time

def us_read(degrees = 0):
    # motor.us_rotate(degrees)
    try:
        value = brick.BP.get_sensor(brick.BP.PORT_3)
        return value
    except:
        return 999
