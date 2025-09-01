#include <gtest/gtest.h>
#include <QThread>
#include "playlist.h"
#include "song.h"

TEST(SongTest, GetSongW) {
    Song s(":/images/placeholder1.png", "The Suburbs", "Arcade Fire");
    EXPECT_EQ(s.getImagePath(), ":/images/placeholder1.png");
    EXPECT_EQ(s.getTitle(), "The Suburbs");
    EXPECT_EQ(s.getAuthor(), "Arcade Fire");
}

TEST(PlaylistTest, AddSongW) {
    Playlist p;

    p.addSong(":/images/placeholder1.png", "The Suburbs", "Arcade Fire");
    EXPECT_EQ(p.currentIndex(), 0);

    const Song& song = p.currentSong();
    EXPECT_EQ(song.getImagePath(), ":/images/placeholder1.png");
    EXPECT_EQ(song.getTitle(), "The Suburbs");
    EXPECT_EQ(song.getAuthor(), "Arcade Fire");
}

TEST(PlaylistTest, NextSongW) {
    Playlist p;

    p.addSong(":/images/placeholder1.png", "The Suburbs", "Arcade Fire");
    p.addSong(":/images/placeholder2.png", "The Look", "Metronomy");
    p.addSong(":/images/placeholder3.png", "Just Like Heaven", "The Cure");

    EXPECT_EQ(p.currentIndex(), 0);
    EXPECT_EQ(p.currentSong().getTitle(), "The Suburbs");
    EXPECT_EQ(p.currentSong().getAuthor(), "Arcade Fire");

    p.nextSong();
    EXPECT_EQ(p.currentIndex(), 1);
    EXPECT_EQ(p.currentSong().getTitle(), "The Look");
    EXPECT_EQ(p.currentSong().getAuthor(), "Metronomy");

    p.nextSong();
    EXPECT_EQ(p.currentSong().getTitle(), "Just Like Heaven");
    EXPECT_EQ(p.currentSong().getAuthor(), "The Cure");

    p.nextSong();
    EXPECT_EQ(p.currentIndex(), 0);
}

TEST(PlaylistTest, TempSlideW) {
    Playlist p;
    p.addSong(":/images/placeholder1.png", "The Suburbs", "Arcade Fire");
    p.startTempSlide(3);
    EXPECT_EQ(p.getIntervalSeconds(), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
