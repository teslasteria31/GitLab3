#pragma once

#include "MusicaLibrary.h"

namespace functions {

	// main functions

	MusicLibrary* create(int& n);
	MusicLibrary* addMusicLibrary(MusicLibrary** arr, int& n, int& m);
	MusicLibrary* print_arr(MusicLibrary* arr, const int& n);
	MusicLibrary* deleteID(MusicLibrary* arr, const int& n);
	void save(MusicLibrary* arr, const int& n);
	//void change(MusicLibrary* arr, const int& n);
	//void search_(MusicLibrary* arr, const int& n);
	//MusicLibrary* deleteByID(MusicLibrary* arr, const int& n, int &id);

	MusicLibrary * load(int& n);

	// text messages

	void greeting();

	void select_an_option();

	void exit();

}