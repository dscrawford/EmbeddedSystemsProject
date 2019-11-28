#!/usr/bin/env python3

import curses
import time

import brick
import motor
import ultrasonic

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
inc = int((curses.COLS - 2) / 4)
x = 1
commands.addstr(2, x, "[WASD]: direction")
x += inc
commands.addstr(2, x, "[Space]: stop")
x += inc
commands.addstr(2, x, "[Q]: quit")
x += inc
commands.addstr(2, x, "[M]: enable manual control")

read = 255
in_front = 0
key = 0
manual = False
brick.init()
while key != ord('q'):
    commands.addstr(1, 1, "Manual control: %s" % ("on " if manual else "off"))

    output.refresh()
    commands.refresh()

    read = ultrasonic.us_read()
    # Handle invalid read
    if read == 255:
        output.addstr("Invalid Read\n")
    elif read < 25:
        in_front += 1
    else:
        in_front -= 1 if in_front > 0 else 0

    if in_front >= 5:
        output.addstr("Train in front\n")
    elif in_front == 0:
        output.addstr("Train not in front\n")

    # Wait for input in between loops
    time.sleep(0.05)
    key = stdscr.getch()

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

brick.close()
curses.endwin()
