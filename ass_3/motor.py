import brick

speed = 60

def stop():
    # print("STOP called!")
    brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A, 0)


def forward():
    # print("Forward called")
    brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A, speed)


def back():
    # print("back called")
    brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A, -speed)


def right(turn):
    # print("right called")
    brick.BP.offset_motor_encoder(brick.BP.PORT_A, brick.BP.get_motor_encoder(brick.BP.PORT_A))  # reset encoder A
    brick.BP.offset_motor_encoder(brick.BP.PORT_D, brick.BP.get_motor_encoder(brick.BP.PORT_D))  # reset encoder D
    brick.BP.set_motor_position(brick.BP.PORT_D, turn / 2)
    brick.BP.set_motor_position(brick.BP.PORT_D, -(turn / 2))


def left(turn):
    # print("left called")
    brick.BP.offset_motor_encoder(brick.BP.PORT_A, brick.BP.get_motor_encoder(brick.BP.PORT_A))  # reset encoder A
    brick.BP.offset_motor_encoder(brick.BP.PORT_D, brick.BP.get_motor_encoder(brick.BP.PORT_D))  # reset encoder D
    brick.BP.set_motor_position(brick.BP.PORT_D, -(turn / 2))
    brick.BP.set_motor_position(brick.BP.PORT_D, turn / 2)

def us_rotate(degrees):
    # print("ultrasonic motor called")
    brick.BP.set_motor_position(brick.BP.PORT_C, degrees)
    
    
