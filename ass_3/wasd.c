#include <curses.h>

void forward () {
    printw("forward\n");
}

void left () {
    printw("left\n");
}

void back () {
    printw("back\n");
}

void right () {
    printw("right\n");
}

int main () {
    int key;
    
    initscr();
    raw();
    noecho();
    curs_set(0);
    setscrreg(0, LINES);
    scrollok(stdscr, 1);

    while ((key = getch()) != 'q') {
        switch (key) {
        case 'w':
        case 'W':
            forward();
            break;
        case 'a':
        case 'A':
            left();
            break;
        case 's':
        case 'S':
            back();
            break;
        case 'd':
        case 'D':
            right();
            break;
        default:
            break;
        }
    }

    endwin();
}
