import time

import brick

# Top speed
speed = 60
# Direction of travel
direction = 1
# In motion or not
going = False

# Stops the robot
def stop():
    global going
    global direction

    # If in motion, taper speed to 0
    if going:
        for i in range(10,-1,-1):
            brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A,
                (i / 10) * speed * direction)
            time.sleep(0.05)
        going = False

# Makes the robot go forwards
def forward():
    global going
    global direction

    # If standing still, bring up to speed
    if not going:
        for i in range(11):
            brick.BP.set_motor_power(brick.BP.PORT_D + brick.BP.PORT_A,
                (i / 10) * speed)
            time.sleep(0.05)
        going = True
        direction = 1

# Makes the robot go backwards
def back():
    global going
    global direction

    # If standing still, bring up to speed (but in reverse)
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
    
    
