#pragma once

#include <string>

class MusicLibrary {
private:
    std::string _title;
    std::string _artist;
    std::string _album;

public:
    std::string getTitle() const;
    void setTitle(const std::string& title);

    std::string getArtist() const;
    void setArtist(const std::string& artist);

    std::string getAlbum() const;
    void setAlbum(const std::string& album);
};