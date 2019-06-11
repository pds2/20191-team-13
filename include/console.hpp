#ifndef CONSOLE_H
#define CONSOLE_H
#pragma once
class Console{
public:
Console();
~Console();
void Move(int mover);
};

extern char map[20][80];
extern int x;
extern int y;

#endif