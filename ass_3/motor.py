import time

import brick

speed = 60
direction = 1
going = False

def stop():
    # print("STOP called!")
    global going
    global direction

    if going:
        for i in range(10,-1,-1):
            brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A,
                (i / 10) * speed * direction)
            time.sleep(0.05)
        going = False


def forward():
    # print("Forward called")
    global going
    global direction

    if not going:
        for i in range(11):
            brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A,
                (i / 10) * speed)
            time.sleep(0.05)
        going = True
        direction = 1


def back():
    # print("back called")
    global going
    global direction

    if not going:
        for i in range(11):
            brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A,
                (i / 10) * speed * -1)
            time.sleep(0.05)
        going = True
        direction = -1


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
    
    
