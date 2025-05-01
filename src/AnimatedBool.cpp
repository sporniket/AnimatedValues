/* SPDX-License-Identifier: GPL-3.0-or-later */
/****************************************

---
Copyright (C) 2021~2025 David SPORN
---
This is part of **Animated values**.
Created to help you go beyond a simple blinking.
****************************************/

#include "cmspk/animval/AnimatedBool.hpp"

using cmspk::animval::AnimatedBool ;

std::vector<bool> *AnimatedBool::createAnimation(char asTrue, const std::string sequence)
{
    std::vector<bool> *result = new std::vector<bool>();
    result->reserve(sequence.size());
    for (const char &c : sequence)
    {
        bool item = (c == asTrue);
        result->push_back(item);
    }
    return result;
}

void AnimatedBool::handleCurrentChanged() { animationIterator = animationList.at(current)->begin(); }

AnimatedBool::AnimatedBool(std::vector<bool> *animation)
{
    append(animation);
    handleCurrentChanged();
};

AnimatedBool *AnimatedBool::append(std::vector<bool> *animation)
{
    animationList.push_back(animation);
    return this;
}

int AnimatedBool::getAnimationCount() { return animationList.size(); }

int AnimatedBool::setCurrentAnimation(int value)
{
    if (value < 0 || value >= getAnimationCount())
    {
        return current;
    }
    current = value;
    handleCurrentChanged();
    return current;
}

bool AnimatedBool::run()
{
    if (0 == animationList.at(current)->size())
    {
        return false;
    }
    ++animationIterator;
    if (animationIterator == animationList.at(current)->end())
    {
        animationIterator = animationList.at(current)->begin();
    }
    return value();
}

bool AnimatedBool::runOnce()
{
    if (0 == animationList.at(current)->size())
    {
        return false;
    }
    if (animationIterator != animationList.at(current)->end())
    {
        ++animationIterator;
    }
    return value();
}

bool AnimatedBool::value() { return *animationIterator; }
