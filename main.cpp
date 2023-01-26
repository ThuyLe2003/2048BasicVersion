/* 2048 game
 *
 * Desc:
 *   This program generates a game of 2048, a tile combining game
 * where the goal is to get from 2's to a power of two (at least 4,
 * original 2048). The board is SIZE x SIZE (original was 4 x 4) and every
 * round the player chooses a direction to which the tiles should fall by
 * clicking the control buttons. If they collide with a wall or a different
 * value, they will move as close as they can get. If they collide with a tile
 * with same value, they will combine and double the value. The tile will
 * continue to move and combine until a wall or other tile comes along.
 *   Game will end when the GOAL is reached or new tile can't be added to the
 * board.
 *   When the game ends, the program tells if the player won or lost.
 *
 *   At first, the player is asked to provide a seed value, a goal value, and
 * a size for game grid (if the player does not change these value, they will
 * be set as default). Especially, ONLY power-of-two goal value is accepted.
 *   Then, after pressing Start button, the game grid is given for the player.
 * The squares of the grid are labels assigned with corresponding images
 * created by the program author.
 *   The program allows player to pause the game (and resume it later) by
 * using the Pause/ Resume button. At the time game is paused, the control
 * buttons are hiden from the interface. After resuming, these buttons are
 * back to the interface for use.
 *   There is also a timer telling the time spent so far.
 *   The background color of the user interface changes to green when the
 * player win, to red when loses, and to default color after restarting the
 * game.
 *   The player is also allowed to restart the game after the game is over,
 * as well as in the middle of the game by using Reset button.
 *   To avoid possible problems, this program disables the spin boxes after
 * pressing the Start button.
 *
 * Program author
 * Name: Thi Minh Thuy Le
 * Student number: 150533634
 * UserID: rqthle
 * E-Mail: thuy.t.le@tuni.fi
 *
 * */

#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
