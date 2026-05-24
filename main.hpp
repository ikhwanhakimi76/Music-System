#pragma once
#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<windows.h>
#include "musiccontroller.hpp"

int addNote(int frequency, int duration, int delay);
void playNote(int i);
int reset();
int getNoteCount();
int removeNote(int i);
int addNoteFromFile(int frequency, int duration, int delay);
void SaveToFile(const string& filename, const MusicController& musicController);
void LoadFromFile(const string& filename, MusicController& musicController);
void mainDisplay();
void removeDisplay();