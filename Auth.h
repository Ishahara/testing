#pragma once
#ifndef AUTH_H
#define AUTH_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "shop.h"

#define MENU_AUTH 7
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Use std::string instead of C-style strings in C++
bool authenticateUser(const std::string& username, const std::string& password, Data* userData);
bool registerUser(const std::string& username, const std::string& password, Data* userData);

void createAuthwin(SDL_Renderer* renderer, TTF_Font* font, const std::string& username, const std::string& password);

#endif // AUTH_H
