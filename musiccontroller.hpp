#pragma once
#include <vector>

struct Note
{
    int frequency;
    int duration;
    int delay;
};

class MusicController
{
    public:
    std::vector<Note> Notes;
    int mark = 0;
    int addNote(int frequency, int duration, int delay);
    void playNote(int i);
    int reset();
    int getNoteCount();
    int removeNote(int i);
    int addNoteFromFile(int frequency, int duration, int delay);
    void display();
};