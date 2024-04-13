#include "MusicaLibrary.h"

using namespace std;

string MusicLibrary::getTitle() const{
	return _title;
}

void MusicLibrary::setTitle(const string &title) {
	if (_title != title)
		_title = title;
}

string MusicLibrary::getArtist() const {
	return _artist;
}

void MusicLibrary::setArtist(const string &artist) {
	if (_artist != artist)
		_artist = artist;
}

string MusicLibrary::getAlbum() const {
	return _album;
}

void MusicLibrary::setAlbum(const string &album) {
	if (_album != album)
		_album = album;
}
