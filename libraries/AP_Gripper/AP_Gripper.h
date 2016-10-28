/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <AP_Param/AP_Param.h>

class AP_Gripper_Backend;

class AP_Gripper {
public:
    AP_Gripper();

    // initialise the gripper
    void init();

    // grab - move the servo to the grab position
    void grab();

    // release - move the servo output to the release position
    void release();

    // update - should be called at at least 10hz
    void update();

    static const struct AP_Param::GroupInfo        var_info[];

    // parameters
    AP_Int8     _enabled;               // grabber enable/disable

    struct Backend_Config {
        AP_Int8     type;                  // grabber type (e.g. EPM or servo)
        AP_Int16    grab_pwm;              // PWM value sent to Gripper to initiate grabbing the cargo
        AP_Int16    release_pwm;           // PWM value sent to Gripper to release the cargo
    } config;

private:

    AP_Gripper_Backend *backend;
};
