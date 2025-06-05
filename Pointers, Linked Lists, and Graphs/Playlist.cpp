#include "util.h"

struct song{
    string name;
    song *next, *prev;
};

void addSong(song * &current){
    
    string name = readLine("Please enter the song title: ");
    song *newSong = new song;
    newSong->name = name;
    newSong->next = current;
    newSong->prev = NULL;
    
    if (current != NULL){
        if (current->prev != NULL) {
            current->prev->next = newSong;
            newSong->prev = current->prev;
        }
        current->prev = newSong;
    }

    current = newSong;
}

void printNext(song * &current){
    
    if (current != NULL){
        
        if (current->next != NULL){
            cout << current->next->name << endl;
            current = current->next; // ?
        } else {
            cout << "You are on the last song of the playlist\n";
            return;
        }
    }
}

void printPrev(song * &current){
    
    if (current != NULL){
        
        if (current->prev != NULL){
            cout << current->prev->name << endl;
            current = current->prev; // ?
        } else {
            cout << "You are on the first song of the playlist\n";
            return;
        }
    }
}

int main()
{
    // Enter your code here
    song *playlist_current = NULL;
    
        
        
    while (true){
        
        if (playlist_current == NULL){
            cout << "Your playlist is empty.\n\n";    
        }
        
        cout << "Please select an option: " << endl;
        cout << "1 - Print the previous song" << endl;
        cout << "2 - Add a new song" << endl;
        cout << "3 - Print the next song" << endl;
        cout << "4 - Quit" << endl;
        int choice = readInt(1, 5, ">> ");
        
        if (choice == 1){
            printPrev(playlist_current);
        } else if (choice == 2) {
            addSong(playlist_current);    
        } else if (choice == 3) {
            printNext(playlist_current);
        } else if (choice == 4) {
            break;
        }
        
        if (playlist_current != NULL){
            cout << "Current song: " << playlist_current->name << endl;    
        }
        cout << endl;
    }
    
    return 0;
}