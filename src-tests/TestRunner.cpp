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
#include "cmspk/animval.hpp"

using cmspk::animval::AnimatedBool;

Test(AnimatedBool, getAnimationCount_should_return_the_number_of_different_animations) {
    AnimatedBool multipleAnimations = AnimatedBool::createAnimation('*', ".*.*......");
    multipleAnimations.append(AnimatedBool::createAnimation('*', "****...."));

    cr_assert_eq(multipleAnimations.getAnimationCount(), 2, "Expected 2 animations, got %d", multipleAnimations.getAnimationCount());
}

Test(AnimatedBool, createAnimation_should_create_a_runnable_animation) {
    AnimatedBool blinkTwiceEveryTenSteps = AnimatedBool::createAnimation('*', ".*.*......");

    cr_assert_eq(blinkTwiceEveryTenSteps.value(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
}

Test(AnimatedBool, setCurrentAnimation_should_select_the_animation_to_replay) {
    AnimatedBool multipleAnimations = AnimatedBool::createAnimation('*', ".*.*......");
    multipleAnimations.append(AnimatedBool::createAnimation('*', "****...."));
    multipleAnimations.append(AnimatedBool::createAnimation('*', "**...."));  // animation number 2
    multipleAnimations.append(AnimatedBool::createAnimation('*', "*.."));     // animation number 3

    multipleAnimations.setCurrentAnimation(3);

    cr_assert_eq(multipleAnimations.value(), true);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);

    cr_assert_eq(multipleAnimations.run(), true);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);

    cr_assert_eq(multipleAnimations.run(), true);

    multipleAnimations.setCurrentAnimation(2);

    cr_assert_eq(multipleAnimations.value(), true);
    cr_assert_eq(multipleAnimations.run(), true);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);

    cr_assert_eq(multipleAnimations.run(), true);
    cr_assert_eq(multipleAnimations.run(), true);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);

    cr_assert_eq(multipleAnimations.run(), true);
    cr_assert_eq(multipleAnimations.run(), true);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
    cr_assert_eq(multipleAnimations.run(), false);
}

Test(AnimatedBool, runOnce_never_loops) {
    AnimatedBool blinkTwiceEveryTenSteps = AnimatedBool::createAnimation('*', ".*.*......");

    cr_assert_eq(blinkTwiceEveryTenSteps.value(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.runOnce(), false);
}

Test(AnimatedBool, run_always_loops) {
    AnimatedBool blinkTwiceEveryTenSteps = AnimatedBool::createAnimation('*', ".*.*......");

    cr_assert_eq(blinkTwiceEveryTenSteps.value(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), true);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);

    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
    cr_assert_eq(blinkTwiceEveryTenSteps.run(), false);
}
