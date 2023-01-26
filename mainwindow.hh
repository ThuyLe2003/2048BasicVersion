/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project4: 2048 game                                                       #
# File: mainwindow.hh                                                       #
# Description: user interface of the game, displays numbertiles as labels.  #
#############################################################################
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "gameboard.hh"
#include "numbertile.hh"
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QVector>
#include <QMap>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Initializes the attributes of the game
    void init_game_board();
    void init_images();
    void init_timer();

    // Display the control buttons and control label
    void control_buttons_display(bool val = true);

    // Display the gameboard on the interface
    void board_display(bool val = true);

private slots:

    // Handle the value of seed, goal, and size
    void seed_value_changed(int arg1);
    void goal_value_changed(unsigned int arg1);
    void size_value_changed(int arg1);

    // Handle the push buttons
    void start_button_released();
    void reset_button_released();
    void pause_button_clicked();

    // Handle control buttons, notify the player
    // if the game ends
    void handle_control_button_clicked();

    // Display the timer
    void set_display();

private:

    Ui::MainWindow *ui_;

    GameBoard* board_; // The gameboard

    QTimer* timer_;

    QVector<QVector<QLabel*>> GUI_board_; // Gameboard on GUI as system of labels

    QMap<unsigned int, QPixmap> image_number_; // Images corresponding to the numbers

    // Parameters for a game
    int seed_;
    int goal_;
    int size_;

    // Minutes and seconds
    int min_;
    int sec_;

    const int MAX_SIZE = 6; // The maximum size of the game grid

    const int TILE_SIZE = 81; // The size of each tile

    // Margins for displaying the gameboard
    const int TOP_MARGIN = 180;
    const int LEFT_MARGIN = 50;

    const QString DEFAULT_NOTI = "Press Start to start the game!";

    // Coordinates for moving steps
    const Coords DEFAULT_DIR = {0, 0};
    const Coords LEFT = {0, -1};
    const Coords UP = {-1, 0};
    const Coords RIGHT = {0, 1};
    const Coords DOWN = {1, 0};
    const QMap<QString, Coords> DIRECTIONS = {{"LEFT", LEFT}, {"UP", UP},
                                             {"RIGHT", RIGHT}, {"DOWN", DOWN}};

    // Status of the game
    bool is_on_;

    // Group of widgets
    QVector<QPushButton*> control_buttons_; // Direction control button
    QVector<QWidget*> group_widgets_; // Includes the start button and
                                      // spin boxes (they are disabled and
                                      // enabled at the same time).
};
#endif // MAINWINDOW_HH
