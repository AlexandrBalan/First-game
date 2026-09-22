#include <bn_backdrop.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_dot.h"

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 0));

    auto dot = bn::sprite_items::dot.create_sprite(0, 0);

    bn::fixed speed = 5.5;

    double gravity = 13 / 60;

    dot.set_scale(2);

    while(true) {
        if(bn::keypad::left_held()) {
            dot.set_x(dot.x() - speed);
        }

        if(dot.x() > 105 ) {
            dot.set_x(105);
        }

        if(dot.y() > 40) {
            dot.set_y(40);
            dot.set_vertical_scale(2);
        }

        if(bn::keypad::right_held()) {
            dot.set_x(dot.x() + speed);
        }
        if(bn::keypad::up_held()) {
            dot.set_y(dot.y() + 20);
        }
        if(bn::keypad::down_held()) {
            dot.set_y(dot.y() + speed);
        }

        if(bn::keypad::any_pressed()) {
            dot.set_y(dot.y() + gravity);
        }


        dot.set_rotation_angle_safe((dot.rotation_angle() + 10));


        dot.set_y(dot.y() + gravity);
        bn::core::update();
    }

}