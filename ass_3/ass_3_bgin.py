#!/usr/bin/env python3

import curses

# from move_direction.py import *

def forward ():
    stdscr.addstr("forward\n")

def left ():
    stdscr.addstr("left\n")

def back ():
    stdscr.addstr("back\n")

def right ():
    stdscr.addstr("right\n")

stdscr = curses.initscr()
curses.nl(True)
curses.raw()
curses.noecho()
curses.curs_set(False)

y = 0
key = 0
while key != ord('q'):
    key = stdscr.getch()

    stdscr.move(y, 0)
    if key == ord('w') or key == ord('W'):
        forward()
        if y + 1 == curses.LINES:
            stdscr.scroll()
        else:
            y += 1
    elif key == ord('a') or key == ord('A'):
        left()
        if y + 1 == curses.LINES:
            stdscr.scroll()
        else:
            y += 1
    elif key == ord('s') or key == ord('S'):
        back()
        if y + 1 == curses.LINES:
            stdscr.scroll()
        else:
            y += 1
    elif key == ord('d') or key == ord('D'):
        right()
        if y + 1 == curses.LINES:
            stdscr.scroll()
        else:
            y += 1

    stdscr.refresh()

curses.endwin()
