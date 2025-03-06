/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2021~2025 David SPORN
---
This is part of **Animated values**.
Created to help you go beyond a simple blinking.
****************************************/
#include <criterion/criterion.h>
// FIXME includes your hpp files from ../include
// e.g. #include "whatever.hpp"
#include "AnimatedBool.hpp"

Test (AnimatedBool, createAnimation_should_create_a_runnable_animation) {
    AnimatedBool beat = AnimatedBool::createAnimation('*', ".*.*......") ; // blink twice

    cr_assert_eq(beat.value(),false);
    cr_assert_eq(beat.runOnce(),true);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),true);
    cr_assert_eq(beat.runOnce(),false);

    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
}


Test (AnimatedBool, runOnce_never_loops) {
    AnimatedBool beat = AnimatedBool::createAnimation('*', ".*.*......") ; // blink twice

    cr_assert_eq(beat.value(),false);
    cr_assert_eq(beat.runOnce(),true);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),true);
    cr_assert_eq(beat.runOnce(),false);

    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);

    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
    cr_assert_eq(beat.runOnce(),false);
}


Test (AnimatedBool, run_always_loops) {
    AnimatedBool beat = AnimatedBool::createAnimation('*', ".*.*......") ; // blink twice

    cr_assert_eq(beat.value(),false);
    cr_assert_eq(beat.run(),true);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),true);
    cr_assert_eq(beat.run(),false);

    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);

    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),true);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),true);
    cr_assert_eq(beat.run(),false);

    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);

    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),true);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),true);
    cr_assert_eq(beat.run(),false);

    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
    cr_assert_eq(beat.run(),false);
}