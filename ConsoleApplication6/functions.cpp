#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"

using namespace std;

    // creating a new array

MusicLibrary* functions::create(int& n) {
    MusicLibrary* arr = nullptr;
    arr = new MusicLibrary[n];

    for (int i = 0; i < n; i++) {
        string title, artist, album;
        cout << "\n|id: " << i << "\n|Title: ";
        cin >> title;
        cout << "|id: " << i << "\n|Artist: ";
        cin >> artist;
        cout << "|id: " << i << "\n|Album: ";
        cin >> album;
        arr[i].setTitle(title);
        arr[i].setArtist(artist);
        arr[i].setAlbum(album);
    }

    return arr;
}

    // add new elements to array

MusicLibrary* functions::addMusicLibrary(MusicLibrary** arr, int& n, int& m) {
    MusicLibrary* newArr = new MusicLibrary[n + m];

    for (int i = 0; i < n; i++) {
        newArr[i] = *arr[i];
    }

    for (int i = n; i < n + m; i++) {
        string title, artist, album;
        cout << "\n|id: " << i << "\n|Title: ";
        cin >> title;
        cout << "|id: " << i << "\n|Artist: ";
        cin >> artist;
        cout << "|id: " << i << "\n|Album: ";
        cin >> album;
        newArr[i].setTitle(title);
        newArr[i].setArtist(artist);
        newArr[i].setAlbum(album);
    }
    
    delete[] * arr;
    *arr = newArr; 
    n += m; // Увеличиваем счетчик элементов

    return *arr;
}

    // print created array in terminal

MusicLibrary* functions::print_arr(MusicLibrary* arr, const int& n) {
    cout << "\n|Created array is:\n" << endl;
    for (int i = 0; i < n; i++) {
        cout << "|id: " << i << " |Title: " << arr[i].getTitle() << endl;
        cout << "|id: " << i << " |Artist: " << arr[i].getArtist() << endl;
        cout << "|id: " << i << " |Album: " << arr[i].getAlbum() << endl;
    }

    return arr;
}

    // delete element by ID

MusicLibrary* functions::deleteID(MusicLibrary* arr, const int& n) {
    return 0;
}

    // saving new elements to file

void functions::save(MusicLibrary* arr, const int& n) {
    ofstream file("test.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (int i = 0; i < n; i++)
        file << arr[i].getTitle() << " " << arr[i].getArtist() << " " << arr[i].getAlbum() << endl;
    file.close();
}


    // load data from file

MusicLibrary* functions::load(int& n) {
    ifstream file("test.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }

    MusicLibrary* arr = new MusicLibrary[n];
    for (int i = 0; i < n; i++) {
        string title, album, artist;
        file >> title >> artist >> album;
        arr[i].setTitle(title);
        arr[i].setArtist(artist);
        arr[i].setAlbum(album);
    }
    file.close();

    return arr;
}

    // adding new elements


/* MusicLibrary* functions::deleteByID(MusicLibrary* arr, const int& n, int& id) {
    ifstream file("test.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }

    file.close();
} */

//void functions::search_(MusicLibrary* arr, const int& n) {
    /*
    int option;
    system("cls");
    cout << "|Search:\n|1. By title\n|2. By artist\n|3. By album\n\n Enter your option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        string tag;
        int found = 0;
        cout << "|Enter a title: ";
        cin >> tag;


        for (int i = 0; i < n; i++) {
            if (arr[i].getTitle() != tag)
            {
                cout << "A match has been found:\n" << arr[i].getTitle().c_str() << arr[i].getArtist().c_str() << arr[i].getAlbum().c_str() << endl;
                found = 1;
            }

        }

        if (!found) cout << "Couldn't find any song, try again!\n\n";
        break;

    case 2:
        string tag;
        int found = 0;
        cout << "|Enter an artist: ";
        cin >> tag;


        for (int i = 0; i < n; i++) {
            if (arr[i].getTitle() != tag)
            {
                cout << "A match has been found:\n" << arr[i].getTitle().c_str() << arr[i].getArtist().c_str() << arr[i].getAlbum().c_str() << endl;
                found = 1;
            }

        }
        if (!found) cout << "Couldn't find any song, try again!\n\n";
        break;

    case 3:
        string tag;
        int found = 0;
        cout << "|Enter an album: ";
        cin >> tag;


        for (int i = 0; i < n; i++) {
            if (arr[i].getTitle() != tag)
            {
                cout << "A match has been found:\n" << arr[i].getTitle().c_str() << arr[i].getArtist().c_str() << arr[i].getAlbum().c_str() << endl;
                found = 1;
            }

        }
        if (!found) cout << "Couldn't find any song, try again!\n\n";
        break;

    default:
        cout << "|Sorry, but we haven't got this option" << endl;
        break;
    }

    delete[] arr;
    */


    // exit

void functions::exit() {
    system("cls");
    cout << "=======================\n";
    cout << "See you soon, bye (^_*)\n";
    cout << "=======================\n";
}

    // greeting

void functions::greeting() {
    cout << "==========================================\n"
        "Hello, welcome to Spotify db, let's start!\n"
        "==========================================\n";
}

    // navigation pannel

void functions::select_an_option() {
    cout << "\n|Select an option:\n"
        "|1 - create new db array\n"
        "|2 - extend new created array\n"
        "|3 - print db array in terminal\n"
        "|4 - search current track by ID\n"
        "|5 - delete current track by ID\n"
        "|6 - change current track by ID\n"
        "|7 - load to file\n"
        "|8 - load from file\n";
    cout << "\n|What's your choise? ";
}

