import brickpi3 # import the BrickPi3 drivers

BP = None

def init():
    global BP
    BP = brickpi3.BrickPi3()
    BP.set_sensor_type(BP.PORT_3, BP.SENSOR_TYPE.NXT_ULTRASONIC)
    # BP.offset_motor_encoder(BP.PORT_C, BP.get_motor_encoder(BP.PORT_C))

def close():
    BP.reset_all()
