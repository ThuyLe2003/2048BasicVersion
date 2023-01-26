#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    min_(0), sec_(0),
    is_on_(false)
{
    ui_->setupUi(this);

    // Set default background color for the window
    setStyleSheet("background-color: rgb(243, 243, 243)");

    // Set up the attributes of the game
    timer_ = new QTimer(this);
    seed_ = time(NULL);
    goal_ = DEFAULT_GOAL;
    size_ = SIZE;

    ui_->size_spin_box->setValue(4);;
    ui_->size_spin_box->setRange(2, MAX_SIZE);
    ui_->pause_button->setText("Pause");
    ui_->goal_spin_box->setRange(0, 8192);

    init_game_board();
    init_images();
    init_timer();

    // Initialize control buttons attribute
    control_buttons_ = {ui_->up_button, ui_->down_button,
                       ui_->left_button, ui_->right_button};
    for (QPushButton* button : control_buttons_)
        connect(button, &QPushButton::clicked, this,
                &MainWindow::handle_control_button_clicked);

    // Initialize spin boxes attribute
    group_widgets_ = {ui_->seed_spin_box, ui_->goal_spin_box, ui_->size_spin_box,
                      ui_->start_button, ui_->start_button};

    ui_->noti_label->setText(DEFAULT_NOTI);

    // Connect the slots
    connect(ui_->seed_spin_box, &QSpinBox::valueChanged, this,
            &MainWindow::seed_value_changed);
    connect(ui_->goal_spin_box, &QSpinBox::valueChanged, this,
            &MainWindow::goal_value_changed);
    connect(ui_->size_spin_box, &QSpinBox::valueChanged, this,
            &MainWindow::size_value_changed);
    connect(ui_->start_button, &QPushButton::clicked, this,
            &MainWindow::start_button_released);
    connect(ui_->reset_button, &QPushButton::clicked, this,
            &MainWindow::reset_button_released);
    connect(ui_->pause_button, &QPushButton::clicked, this,
            &MainWindow::pause_button_clicked);
    connect(timer_, &QTimer::timeout, this,
            &MainWindow::set_display);

    // The reset, pause buttons and control buttons are disabled at first
    ui_->reset_button->setDisabled(true);
    ui_->pause_button->setDisabled(true);
    control_buttons_display(false);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::init_game_board()
{
    // Initialize the GUI_board_ with empty labels based on MAX_SIZE
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        QVector<QLabel*> labels;
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            QLabel* label = new QLabel(this);
            label->hide();
            labels.push_back(label);
        }
        GUI_board_.push_back(labels);
    }
}

void MainWindow::init_images()
{
    // Setup image_number_ with corresponding images from resource
    QVector<int> data = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    for (int i : data)
    {
        QString source = "../resources/tile_";
        source.append(QString::number(i));
        source.append(QString(".png"));
        image_number_[i] = QPixmap(source);
    }
}

void MainWindow::init_timer()
{
    timer_->stop();
    // Setting the initial display for the timer
    ui_->lcd_number_min->display(0);
    ui_->lcd_number_sec->display(0);
}

void MainWindow::control_buttons_display(bool val)
{
    if (val)
    {
        ui_->controlLabel->show();
        for (QPushButton* button : control_buttons_)
            button->show();
    }
    else
    {
        ui_->controlLabel->hide();
        for (QPushButton* button : control_buttons_)
            button->hide();
    }
}

void MainWindow::board_display(bool val)
{
    // Show the game grid
    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
        {
            if (val)
            {
                int number = board_->get_item({i, j})->get_value();
                QPixmap image = image_number_[number];
                GUI_board_[i][j]->setGeometry(LEFT_MARGIN + j*TILE_SIZE,
                                              TOP_MARGIN + i*TILE_SIZE,
                                              TILE_SIZE, TILE_SIZE);
                GUI_board_[i][j]->setPixmap(image);
                GUI_board_[i][j]->show();
            }
            else
                GUI_board_[i][j]->hide();
        }
}


void MainWindow::seed_value_changed(int arg1)
{
    seed_ = arg1;
}


void MainWindow::goal_value_changed(unsigned int arg1)
{
    // Create the vector of power of two allowed to be the goal
    QVector<unsigned int> data = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048,
                         4096, 8192};

    // Check if the changed goal is acceptable
    // If not, notify the player
    if (not data.contains(arg1))
    {
        ui_->noti_label->setText("The goal should be a power of two and greater"
                                " or equal to 4!");
        ui_->start_button->setDisabled(true);
    }
    else
    {
        goal_ = arg1;
        ui_->noti_label->setText(DEFAULT_NOTI);
        ui_->start_button->setEnabled(true);
    }
}


void MainWindow::size_value_changed(int arg1)
{
    size_ = arg1;
}

void MainWindow::set_display()
{
    if (sec_ < 59)
        sec_ += 1;
    else
    {
        min_ += 1;
        sec_ = 0;
    }
    ui_->lcd_number_min->display(min_);
    ui_->lcd_number_sec->display(sec_);
}

void MainWindow::start_button_released()
{
    // Set spin boxes and start button disabled
    for (auto& widget : group_widgets_)
        widget->setDisabled(true);

    // Set the reset and pause buttons enabled and display the control buttons
    ui_->reset_button->setEnabled(true);
    ui_->pause_button->setEnabled(true);
    is_on_ = true;
    control_buttons_display(true);

    delete board_; // Delete the last board so that we can start a new game

    board_ = new GameBoard();
    board_->update_size(size_);
    board_->init_empty();
    board_->fill(seed_);

    board_display();
    timer_->start(1000);

    ui_->noti_label->setText("Try your best to get our " +
                            QString::number(goal_) + " goal!");
}


void MainWindow::reset_button_released()
{
    // Set spin boxes and start button enabled
    for (auto& widget : group_widgets_)
        widget->setEnabled(true);

    // Set the reset and pause buttons disabled and hide the control buttons
    ui_->reset_button->setDisabled(true);
    ui_->pause_button->setDisabled(true);
    ui_->pause_button->setText("Pause");
    control_buttons_display(false);

    ui_->noti_label->setText(DEFAULT_NOTI);
    is_on_ = false;

    // Reset timer
    timer_->stop();
    min_ = 0;
    sec_ = 0;
    ui_->lcd_number_min->display(min_);
    ui_->lcd_number_sec->display(sec_);

    // Hide the board before the game restart
    board_display(false);

    // Set the background to gray
    setStyleSheet("background-color: rgb(243, 243, 243)");
}

void MainWindow::handle_control_button_clicked()
{
    for (QPushButton* button : control_buttons_)
        if (button == sender())
        {
            // Check if the game doesn't end
            if (not board_->move(DIRECTIONS[button->text()], goal_)
                    and (not board_->is_full()))
            {
                // Add new value and display the board
                board_->new_value(false);
                board_display();

                break;
            }
            else
            {
                // The game is ended.
                // Display the gameboard, stop timer and hide control buttons
                board_display();
                control_buttons_display(false);
                timer_->stop();

                // Check if the player lost the game
                if (board_->is_full())
                {
                    // Notify the player
                    ui_->noti_label->setText("Can't add new tile, you lost! "
                                            "Please reset the game!");

                    // Change the background color
                    setStyleSheet("background-color: rgb(189, 61, 61)");
                    break;
                }
                // The player won the game
                else
                {
                    // Notify the player
                    ui_->noti_label->setText("WIN!!! You reached the goal of " +
                                            QString::number(goal_) + "! "
                                            "Please reset the game!");

                    // Change the background color
                    setStyleSheet("background-color: rgb(97, 193, 28)");

                    break;
                }
            }

            return; // For efficiency reasons
                    // (only one button can be clicked at a time)
        }
}

void MainWindow::pause_button_clicked()
{
    is_on_ = !is_on_;

    // Check if the game is paused
    if (not is_on_)
    {
        // Hide the control buttons so that the user cannot use them
        control_buttons_display(false);

        // Notify the user
        ui_->noti_label->setText("Press Resume to play the game.");
        ui_->pause_button->setText("Resume");
        timer_->stop();
    }
    // The game is resumed
    else
    {
        // Show the control buttons for the user to play
        control_buttons_display(true);

        // Notify the user
        ui_->noti_label->setText("Try your best to get our " +
                                QString::number(goal_) + " goal!");
        timer_->start(1000);
        ui_->pause_button->setText("Pause");
    }
}
