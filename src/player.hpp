#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player {
private:
    int current_x;
    int current_y;
    std::string myAvatar;
    int maxX;
    int maxY;
public:
    explicit Player(const std::string &pAvatar);
    Player();
    int getX() const;
    int getY() const;
    void move_up();
    void move_down();
    void move_right();
    void move_left();
    void set_bounds(int xBound, int yBound);
    std::string getAvatar();
    void setUpCheck() const;
    void better_start_position();
    void change_avatar(char n);
};
#endif