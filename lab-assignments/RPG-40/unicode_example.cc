#include <stdio.h>
#include <wchar.h>
#include <curses.h>
#include <cursesw.h>
#include <stdlib.h>
#include <wctype.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "");

    initscr();
    cbreak();

    WINDOW *win = newwin(0, 0, 0, 0);
    refresh();
    wrefresh(win);

    const wchar_t* star = L"\x2605";
    mvaddwstr(3, 3, star);

    getch();
    endwin();
}