#!/usr/bin/env python3

import curses

from motor import *

stdscr = curses.initscr()
output = curses.newwin(curses.LINES - 4, curses.COLS, 0, 0)
commands = curses.newwin(4, curses.COLS, curses.LINES - 4, 0)
curses.nl(True)
curses.raw()
curses.noecho()
curses.curs_set(False)
output.scrollok(True)
output.move(0, 0)
stdscr.refresh()

commands.border(curses.ACS_VLINE, curses.ACS_VLINE, curses.ACS_HLINE, curses.ACS_HLINE,
    curses.ACS_ULCORNER, curses.ACS_URCORNER, curses.ACS_LLCORNER, curses.ACS_LRCORNER)
inc = int((curses.COLS - 2) / 4)
x = 1
commands.addstr(2, x, "[WASD]: direction")
x += inc
commands.addstr(2, x, "[Space]: stop")
x += inc
commands.addstr(2, x, "[Q]: quit")
x += inc
commands.addstr(2, x, "[M]: enable manual control")

key = 0
manual = False
while key != ord('q'):
    commands.addstr(1, 1, "Manual control: %s" % ("on " if manual else "off"))

    output.refresh()
    commands.refresh()

    key = stdscr.getch()

    if key == ord('m') or key == ord('M'):
        manual = not manual
    elif manual and (key == ord('w') or key == ord('W')):
        forward()
    elif manual and (key == ord('a') or key == ord('A')):
        left(90)
    elif manual and (key == ord('s') or key == ord('S')):
        back()
    elif manual and (key == ord('d') or key == ord('D')):
        right(90)
    elif key == ord(' '):
        stop()

curses.endwin()
