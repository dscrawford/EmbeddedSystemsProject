#!/usr/bin/env python3

import curses
import time

import brick
import motor
import ultrasonic

# Ncurses initialization stuff
stdscr = curses.initscr()
output = curses.newwin(curses.LINES - 4, curses.COLS, 0, 0)
commands = curses.newwin(4, curses.COLS, curses.LINES - 4, 0)
curses.nl(True)
curses.raw()
curses.noecho()
curses.curs_set(False)
output.scrollok(True)
output.move(0, 0)
stdscr.nodelay(True)
stdscr.refresh()

commands.border(curses.ACS_VLINE, curses.ACS_VLINE, curses.ACS_HLINE,
    curses.ACS_HLINE, curses.ACS_ULCORNER, curses.ACS_URCORNER,
    curses.ACS_LLCORNER, curses.ACS_LRCORNER)
inc = int((curses.COLS - 2) / 5)
x = 1
commands.addstr(2, x, "[WASD]: direction")
x += inc
commands.addstr(2, x, "[Space]: stop")
x += inc
commands.addstr(2, x, "[Q]: quit")
x += inc
commands.addstr(2, x, "[M]: enable manual control")
x += inc
commands.addstr(2, x, "[R]: reset")

# Keeps track of the ultrasonic sensor reading
read = 999
# Keeps track of if the train is in front
in_front = False
# Counts how long the train has been in front of the sensor
in_front_count = 0
# Tracks if the train has crossed the track
crossed = False
# Stores keypresses
key = 0
# Toggle flag for manual control mode
manual = False

# Main loop (loop until q presses)
brick.init()
while key != ord('q'):
    # Print status
    commands.addstr(1, 1, "Manual control: %s" % ("on " if manual else "off"))

    output.refresh()
    commands.refresh()

    # Get a reading from the ultrasonic sensor if the train hasn't crossed
    if not crossed:
        read = ultrasonic.us_read()
        output.addstr("%d" % (read))
        if read == 999:
            output.addstr("Invalid Read\n")
        elif read < 60:
            in_front_count += 1
            output.addstr("\n")
        else:
            in_front_count -= 1 if in_front_count > 0 else 0
            output.addstr("\n")

    # What to do if the train is in front or not
    if not in_front and in_front_count >= 3:
        output.addstr("Train in front\n")
        in_front = True
    elif in_front and in_front_count == 0:
        output.addstr("Train not in front\n")
        in_front = False
        # move over tracks
        motor.forward()
        time.sleep(2.7)
        motor.stop()
        crossed = True

    # Wait for input in between loops
    time.sleep(0.05)
    key = stdscr.getch()

    # Parse input
    if key == ord('m') or key == ord('M'):
        manual = not manual
    elif manual and (key == ord('w') or key == ord('W')):
        output.addstr("Going forwards\n")
        motor.stop()
        motor.forward()
    # elif manual and (key == ord('a') or key == ord('A')):
    #     motor.left(90)
    elif manual and (key == ord('s') or key == ord('S')):
        output.addstr("Going backwards\n")
        motor.stop()
        motor.back()
    # elif manual and (key == ord('d') or key == ord('D')):
    #     motor.right(90)
    elif key == ord(' '):
        output.addstr("Stopping\n")
        motor.stop()
    elif key == ord('r') or key == ord('R'):
        # Reset all variables to initial state
        read = 999
        in_front = False
        in_front_count = 0
        crossed = False

# Closing tasks
brick.close()
curses.endwin()
