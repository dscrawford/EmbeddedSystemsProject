import brickpi3 # import the BrickPi3 drivers

def init():
    BP = brickpi3.BrickPi3()
    BP.set_sensor_type(BP.PORT_3, BP.SENSOR_TYPE.NXT_ULTRASONIC)
    brick.BP.offset_motor_encoder(brick.BP.PORT_C,brick.BP.get_motor_encoder(brick.BP.PORT_C))
    return BP

BP = init()
