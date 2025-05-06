/* SPDX-License-Identifier: GPL-3.0-or-later */
/* ** ** ** ** ** ** ** ** ** ** ** ** **

---
Copyright (C) 2021~2025 David SPORN
---
This is part of **Animated values**.
Created to help you go beyond a simple blinking led.
* ** ** ** ** ** ** ** ** ** ** ** ** **/

#ifndef CMSPK__ANIMVAL__ANIMATED_BOOL__HPP
#define CMSPK__ANIMVAL__ANIMATED_BOOL__HPP

// interfaces
// Animated values library
// An animated value is a collection of values that can be iterated upon.

#include <string>
#include <vector>

namespace cmspk {};

namespace cmspk::animval {
/**
 * Animated boolean, typically used to blink a status LED ; to instanciate animations
 * more easily, it also provide a helper method `createAnimation(...)`.
 */
class AnimatedBool {
  private:
    std::vector<std::vector<bool> *> animationList;
    int current = 0;
    bool ready = false;
    std::vector<bool>::iterator animationIterator;
    void handleCurrentChanged();

  public:
    /**
     * Helper to create an animation from a codified string.
     *
     * @param asTrue char for coding a true, any other char will be coding a false ; e.g. `"*"`.
     * @param sequence string to parse, e.g. `".*.*......"`.
     * @returns a `std::vector<bool>` that can be used to create or update an `AnimatedBool`.
     */
    static std::vector<bool> *createAnimation(char asTrue, std::string sequence);

    /**
     * Create an animated boolean with a first animation.
     */
    AnimatedBool(std::vector<bool> *animation);

    /**
     * Add another animation in the animation list.
     */
    AnimatedBool *append(std::vector<bool> *animation);

    /**
     * Get the animation list size, one cannot set the current animation outside this range.
     */
    int getAnimationCount();

    /**
     * Change the active animation, nothing happens if the value is out of range.
     *
     * @param value the index of the animation in the list.
     * @returns the actual animation index in the list.
     */
    int setCurrentAnimation(int value);

    /**
     * Advance/loop the current animation.
     *
     * @returns the current value.
     */
    bool run();
    /**
     * Advance the current animation until the end, without looping ; when at the end, return the last value.
     *
     * @returns the current value.
     */
    bool runOnce();
    /**
     * Get the current value.
     *
     * @returns the current value.
     */
    bool value();
};

};  // namespace cmspk::animval

#endif
